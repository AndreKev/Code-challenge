#given a set of values FIRST and PRIME, determine the generated FIRST PRIME OF THE NEXT
def trans(first: set = None, prime : set = {}, min:int=None, max:int=None): #  -> (set, set)
	if not prime:
		prime = {0}
	if not first:
		first = {i for i in range(1, 10)}
	if not max:
		max = 10
	else : max += 1
	if not min:
		min=0
	afirst, aprime = set(), set()
	for numberf in first:
		for numberp in prime:
			aux = (4*numberf+numberp)
			auxfirst = aux%10
			auxprime = aux//10
			if min <= auxfirst < max:
				afirst.add(auxfirst)
				aprime.add(auxprime)
	return afirst, aprime

def main():
	# number 0f digits
	length_digits = 7
	# The digits
	number = [(None, None) for i in range(length_digits)]
	# We will continuously process the digits utils there is no more change in processing
	# The aim is to select the possible numbers the digits can take
	changing = length_digits; aux = None
	while changing	:
		for i in range(length_digits):
			prime = None if i==0 else number[i-1][1]
			max = 5 if i==1 else (2 if i==0 else None)
			min = 1 if i in (0, length_digits-1) else None
			#
			aux = number[i]
			number[i] = trans(number[length_digits-1-i][0], prime, min, max)
			if aux[0] and aux[1] and list(aux[0]) == list(number[i][0]) and list(aux[1])==list(number[i][1]):
				changing -= 1
				if not changing: break
			else:
				changing = length_digits
	total = [0]
	for num in number:
		total = add(total, num[0])
	length = len(total)-1
	while length!=0:
		if compare_mirror(total[length], total[length]*4):
			print(total[length])
			break
		length -= 1

def main2():
	number = 250000000
	while number >0:
		if compare_mirror(number, number*4):
			print(number)
			break
		number -=1

def add(list1, list2):
	aux = []
	for i in list1:
		i*=10
		for j in list2:
			aux.append(i+j)
	return aux

def timeit(func, *args):
	t = time.time()
	func(*args)
	return time.time()-t

def compare_mirror(number1: int, number2: int) -> bool:
	stack = []
	while number1:
		stack.append(number1%10)
		number1 //=10
	while number2 and stack:
		if stack.pop()!=number2%10:
			return False
		number2//=10
	return not number2
	
if __name__ == "__main__":
	import time
	print("Problem 11: ", end='')
	print(timeit(main))
	

		
"""
number[0] = trans(number[6][0], None, 1, 2)
		number[1] = trans(number[5][0], number[0][1], max=5)
		number[2] = trans(number[4][0], number[1][1])
		number[3] = trans(number[3][0], number[2][1])
		number[4] = trans(number[2][0], number[3][1])
		number[5] = trans(number[1][0], number[4][1])
		number[6] = trans(number[0][0], number[5][1], min=1)
		if n ==3:
			break
		n+=1
"""
