#! /usr/bin/python3
'''
fd = open("text.txt","r")
print(fd.read())
print(fd.read()) #empty becaus at the last time the cursor was at the end of the last line
fd.close()

fd = open("text.txt","a")
fd.write("hello world adding new line\n")
fd.close()
'''
'''
Character	Meaning
'r'	open for reading (default)
'w'	open for writing, truncating the file first
'x'	create a new file and open it for writing
'a'	open for writing, appending to the end of the file if it exists
'b'	binary mode
't'	text mode (default)
'+'	open a disk file for updating (reading and writing)
'U'	universal newline mode (deprecated)
'''

'''
with open("text.txt") as f:
    print(f.read())
fd = open("text.txt","r")
x = fd.readlines()
fd.close()
for i in x:
    print(i)
'''

#Quick tasks
#1.Write a Python program to count the number of lines in a text file.
'''
fd = open("text.txt","r")
x = fd.readlines()
print(len(x))
fd.close()
'''

#2.write a Python program to count the Number of words in a file. 
fd = open("text.txt","r")
x = fd.read().split()
print(len(x))
fd.close()

#3.Write a Python program to write a “list” to a file.
ls = ['hello','this','is','a','simple','exampe']

fd = open("text.txt","a")
text = " ".join(ls)
fd.write(text)
fd.close()

