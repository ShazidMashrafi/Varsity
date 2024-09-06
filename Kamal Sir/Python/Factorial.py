def fact(n):
    res=1
    for i in range(n):
        res=res*(i+1)
    print(res)

num= int(input("Enter a number: "))
fact(num)