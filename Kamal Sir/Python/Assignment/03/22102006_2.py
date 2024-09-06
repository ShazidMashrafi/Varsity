# A program to take age from user and group them in their corresponding order

n = int(input("Enter age: "))

if(n>=0 and n<=12):
    print("Child")
elif(n>=13 and n<=19):
    print("Teenager")
elif(n>=20 and n<=59):
    print("Adult")
elif(n>=60):
    print("Senior Citizen")
else:
    print("Invalid age")