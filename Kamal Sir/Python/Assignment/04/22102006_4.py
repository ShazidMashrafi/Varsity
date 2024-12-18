# A program to find factorial with function 
# having parameters but no return value
def fact(n):
    r=1
    for i in range (n):
        r=r*(i+1)
    print(r)

n=int(input("Enter N: "))
fact(n)