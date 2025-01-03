# Open File method 1
file1 = open("test.txt","r")

# Opening file method 2
with open("test.txt", "r") as file2:
    read_content2 = file2.read()

# Reading file content
read_content=file1.read()
print(read_content)

# File close
file1.close()