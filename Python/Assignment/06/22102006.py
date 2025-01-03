while True:
    op = input("What operation you want to do? Give input as: \
               '+' or '-' or '*' or '/' : ")

    if op == '+':
        a=int(input("Enter first number: "))
        b=int(input("Enter second number: "))
        print(f"{a} + {b} = {a+b}")
    elif op == '-':
        a=int(input("Enter first number: "))
        b=int(input("Enter second number: "))
        print(f"{a} - {b} = {a-b}")
    elif op == '*':
        a=int(input("Enter first number: "))
        b=int(input("Enter second number: "))
        print(f"{a} x {b} = {a*b}")
    elif op == '/':
        a=int(input("Enter first number: "))
        b=int(input("Enter second number: "))
        print(f"{a} / {b} = {a/b}")
    else:
        print("Invalid Operator.")

    again=input("Do you want to continue? Type in 'y' or \
                \"Y\" to continue and any other key to exit: ")
    if again.lower() != 'y':
        break