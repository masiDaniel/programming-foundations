name = "daniel"
grade = "A"
first_name = "daniel "
#this is another method of creating strings 
name1 = str() #creates an empty string object
name2 = str("new string ") # string object containing 'new string'

print(name+"\n",grade+"\n",name1+"\n", name2)

#using the id function to get the memry address
print(id(name))
print(id(grade))
print(id(first_name))

# you will notice both name and first name are pointing to the same location hence same object 


#string operations 
middle_name = input("enter your middle name ")
last_name = input("enter your last name ")

s = name + "scored a " + grade
print(s)

s = name2 * 3
print(s)

full_name = name + middle_name + last_name
print(full_name)

#slicing 
print(full_name[0:6]) # this will return from 0 to 6 -1


# ord and ch functions
ch = 'A'
print(ord(ch))

print(chr(65))

#membershi operators 
s ="welcome"
print("come" in s)

print("come" not in s)


#string comparison
print("dan" == "Dan")

for x in s:
    print(x, end="")# this prints it out without a new line 


for x in s:
    print(x, end="\n") # prints with new line 
print("welcome", end="\n")

for x in s:
    print(x, end="foo")
print("welcome", end="foo")