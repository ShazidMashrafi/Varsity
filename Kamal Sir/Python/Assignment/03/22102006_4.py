s=input("Enter a string: ")
substr=input("Enter a substring: ")
l=len(s)
lsub=len(substr)
start=count=0
end=l
while True:
    position=s.find(substr,start,end)
    if position!=-1:
        count+=1
        start=position+lsub
    else:
        break
    if start>=l:
        break
print(count)

'''
-------------------------------Code Explanation----------------------------------
This program takes two input from user, one string and one substring. 
Then the program finds the number of occurrences of the substring in the string and prints the number.

The program stores the main string in "s" and stores the substring in "substr"
"l" stores the length of main string and "lsub" stores the length of substring.
Then the program declares and sets two variables named "start" and "count" as 0.

Then the program goes into a loop with having the condition true.
Then the program uses a built in function ".find()" in "s" with parameters "substr", "start", "end".
This function finds "substr" in "s" from "start" to "end", if it is found then the function returns 0, else it returns -1 and stores the value in "position".

If position is not -1 then the program sets count = count+1 and start = position + lsub. Else the loop breaks.
if start is >=l then also the loops breaks

Then program prints the value of "count".
'''