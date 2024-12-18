#A program that takes height and weight as input and measures BMI

height = float(input("Enter height in meters: "))
weight = float(input("Enter weight in kilograms: "))

bmi=weight/(height*height)

if(bmi<18.5):
    print("Underweight")
elif(bmi>=18.5 and bmi<=24.9):
    print("Normal Weight")
elif(bmi>=25 and bmi<=29.9):
    print("Overweight")
else:
    print("Obese")