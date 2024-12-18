# A program to find the bth power of a using function with no parameters but return value

def power():
    a=int(input("Enter a: "))
    b=int(input("Enter b: "))
    res=1
    for i in range(b):
        res=res*a
    return res

ans=power()
print(ans)