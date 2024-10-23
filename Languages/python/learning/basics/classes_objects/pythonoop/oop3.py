# we are dealing with static class methods and attributes 

class Person:
    no_of_people = 0 #class attributes (is not specific to an instance)

    def __init__(self, name):
        self.name = name
        Person.add_num_of_people()

    @classmethod
    def number_of_people(cls):
        return cls.no_of_people
    
    @classmethod
    def add_num_of_people(cls):
        cls.no_of_people += 1

p1 = Person("dan")
p2 = Person("evin")

print(Person.number_of_people())

        