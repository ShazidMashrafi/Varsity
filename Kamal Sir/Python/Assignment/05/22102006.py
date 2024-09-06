n = int(input("Enter the number of students: "))
f = open("results.txt", 'w')

for _ in range(n):
    name = input("Enter name: ")
    roll = int(input("Enter roll: "))
    cgpa = float(input("Enter cgpa: "))
    f.write(f"Name: {name}, Roll: {roll}, CGPA: {cgpa}\n")

f.close()

results = {}
f = open("results.txt", 'r')

for line in f:
    name, roll, cgpa = line.strip().split(', ')
    results[name] = (roll, cgpa)

f.close()

print(results)