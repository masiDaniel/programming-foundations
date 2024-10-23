class Dog:
    """class to define a dog"""

    kind = "cainine"

    def __init__(self, name):
        self.name = name
        self.tricks = []

    def add_trick(self, trick):
        self.tricks.append(trick)




a = Dog("bruno")
b = Dog("chichi")
a.add_trick("jump")
b.add_trick("sit")


print(a.kind, a.name, a.tricks)
print(b.kind, b.name, b.tricks)
