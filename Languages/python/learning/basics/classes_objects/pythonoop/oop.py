# object oriented programming in python 
# almost everything in python is an object of a class 

x = 1
print(type(x)) # x is an object of the int class 


string = "hello world "

print(string.upper())


class Dog:

    #instantiates the object right when it is created 
    def __init__(self, name, age):
        #below we have created an attribute of the dog class which is name
        self.name = name
        self.age = age
    

    def get_name(self):
        return self.name
    

    def get_age(self):
        return self.age
    
    def set_age(self, age):
        self.age = age
        

    def add(self, x):
        return x + 3
    
    

    def bark(self):
        print("bark")


d = Dog("dan", 5) # instantiation of the dog class 

d2 = Dog("bill", 7)

print(d.get_name())

d.set_age(2)
print(d.get_age())

# d.bark()
# print(d.add(8))
# print(type(d))
