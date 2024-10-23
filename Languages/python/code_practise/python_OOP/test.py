class Person:
    def __init__(self, name, age):
        self.name = name 
        self.age = age

    def say_hello(self):
        print(f"{self.name} says hello")
person_1 = Person("daniel", 21)
print(f" i am {person_1.name.capitalize()} and i am {person_1.age} years old")
person_1.say_hello()


class BankAccount:
    balance = 0

    def deposit(self, x):
        deposit = x
        self.balance = self.balance + deposit
        print(f"the amount deposite is {deposit} and the balance is {self.balance}")
    
    def withdraw(self, x):
        self.balance = self.balance - x
        print(f"the new balance is {self.balance}")

    def final_balance(self):
        print(f"the final balance is {self.balance}")

acc_1 = BankAccount()
acc_1.deposit(50000)
acc_1.withdraw(20000)

class Animal:
    def __init__(self, name, sound):
        self.name = name
        self.sound = sound
    

class Bird(Animal):
    def __init__(self, name, sound, flight_speed):
        super().__init__(name, sound)
        self.flight_speed = flight_speed

animal_1 = Animal("dog", "bark")
bird_1 = Bird("eagle", "skwak", 300)

print(f"the {animal_1.name} {animal_1.sound}")
        
print(f"the {bird_1.name} {bird_1.sound} and flies at {bird_1.flight_speed} km/hr")


class Shape:

    @classmethod
    def area(cls,):
        pass

