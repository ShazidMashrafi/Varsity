import math
n=int(input("Enter a number: "))
r=math.eil(math.sqrt(n))
flag=0
for i in range(2,r+1):
    if n%i==0:
        flag=1
        break;
if flag:
    print(n,"is not a prime number")
else:
    print(n,"is a prime")