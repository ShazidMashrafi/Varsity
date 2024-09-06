def fact(n):
    if n<0:
        return -1
    if n==1 or n==0:
        return 1
    else:
        return n*fact(n-1)

num= int(input("Enter a number: "))
res=fact(num)
print(res)