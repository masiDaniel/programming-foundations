class Person:
    """this is a method and it has to have the self variable as one of its parameters"""
    def greet(self):
        print("hi! Welcome to methods")

p = Person()
p.greet()
"""the above two lines can be written as below"""
p = Person().greet()