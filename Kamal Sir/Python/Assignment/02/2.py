'''
-----------------------------------------------Assalamu alaikum--------------------------------------------------------
--------------------------------------------Name: Shazid Mashrafi------------------------------------------------------
----------------------------------------------Roll no: 22102006--------------------------------------------------------
--------------------------------------------Registration no: 10820-----------------------------------------------------

---------------------------------------------------Assignment----------------------------------------------------------
-----Assignment: Read the range value from user. Read and show marks of 2 subjects from user for every student---------
'''

n=int(input("Enter the range value: "))
nums=[]
for i in range (1, n+1):
    print("Enter the numbers of Student", i)
    x=int(input("Enter the number of Python: "))
    y=int(input("Enter the number of Python Lab: "))
    nums.append(x+y)
for i in range (1,n+1):
    print("Student", i, "Obtained", nums[i-1])