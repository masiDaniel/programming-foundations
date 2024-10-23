# now we will deal with inheritance 

class Pet:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def show(self):
        print(f"i am {self.name} and i am {self.age} years old")
    
    def speak(self):
        print("i don tknow what to say")


class Cat(Pet):
    def __init__(self, name, age, color):
        super().__init__(name, age)
        self.color = color
        
    def speak(self):
        print("meow")
    
    def show(self):
        print(f"i am {self.name} and i am {self.age} years old and i am {self.color}")


class Dog(Pet):

    def speak(self):
        print("bark")

p = Pet("tim", 19)
p.show()
p.speak()

c = Cat("bill", 20, "blue")
c.show()
c.speak()

d = Dog("spike", 21)
d.show()
d.speak()
# cat_1 = Cat("tom", 6)
# gog_1 = Dog("Spike", 7)

# print(cat_1.name)
# cat_1.speak()