class myFirst:
    pass

class myClass:
    """a simple class"""
    def __init__(self, first, last):
        self.first = first
        self.last = last

    i = 1234

    def f(self):
        return "hello world"
#attribute referencing 
print(myClass.i)

#class instantiation 
x = myClass("daniel", "masi")
print(x.first , x.last)

print(x.f())
