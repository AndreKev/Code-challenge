# leetcode 1

def binary_search(val, nums):
	start, end = 0, len(nums)-1
	while start <= end:
		s = end + start 
		mid = (s)//2
		if nums[mid][0] == val:
			return nums[mid][1]
		elif nums[mid][0]<val:
			start = mid+1
		else:
			end = mid -1
	return -1


def two_sums(nums, target):
	l = len(nums)
	nums = sorted(zip(nums, range(l)), key=lambda x: x[0])
	for i in range(l):
		pair = target-nums[i][0]
		if pair == nums[i][0] and i+1<l and pair == nums[i+1][0]:
			return [nums[i][1], nums[i+1][1]]
		else:
			index = binary_search(pair, nums)
			if index > -1:
				return [nums[i][1], index]