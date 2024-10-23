class Person:
    def __init__(self, name):
        self.name = name
    
    def greet(self):
        print("hi " + self.name + " welcome to methods")

p = Person('dan').greet()