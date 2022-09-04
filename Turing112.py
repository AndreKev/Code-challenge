from itertools import combinations_with_replacement

from zmq import ContextTerminated

numbers = [i for i in range(0, 10)]

def main():
    print(len(numbers))
    trouvee = False
    for a in numbers: 
        for b in numbers:
            for c in numbers:
                for d in numbers:
                    for e in numbers:
                        for f in numbers:
                            for g in numbers:
                                for h in numbers:
                                    for i in numbers:
                                        for j in numbers:
                                            if a != (c+b+1)/4:
                                                continue
                                            if b != (1+d+a)/4:
                                                continue
                                            if c != (2+a+e+d)/4:
                                                continue
                                            if d != (f+b+1+c)/4: 
                                                continue
                                            #print("passed d")
                                            if e != (c+g+1+f)/4: 
                                                continue
                                            if f != (h+d+7+e)/4: 
                                                continue
                                            if g != (7+e+i+h)/4: 
                                                continue
                                            if h != (j+f+2+g)/4: 
                                                continue
                                            if i != (14+g+j)/4: 
                                                continue
                                            if j != (10+h+i)/4: 
                                                continue
                                            print("passed j")
                                            product = 1
                                            current_var = [a, b, c, d, e, f, g, h, i, j]
                                            print(current_var)
                                            for i in  current_var:
                                                if i!=0:
                                                    product *= i
                                            print(product)
                                            trouvee = True
                                            return (product, current_var)
    print("End")

if __name__=="__main__":
    print("The answer is", main())