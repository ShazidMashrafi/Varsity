# A program to count the number of occurrences of substring 
# in a string using function with having parameters and return value

def subOccurrences(s3, s4):
    count = 0
    start = 0
    end = len(s3)
    l = len(s4)
    while True:
        pos=s3.find(s4, start, end)
        if(pos != -1):
            count += 1
            start = pos + 1
        else:
            break
    return count

s = input("Enter string: ")
s1 = input("Enter substring: ")
c=subOccurrences(s,s1)
print(c) 
