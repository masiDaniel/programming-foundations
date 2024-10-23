



x = int(input("please key in a number: "))
if (x < 0):
    print("the number is less than 0")
    x = 0
    print(x)
elif x == 0:
    print("zero")
else:
    print("greater than zero")


#fibonacci sequence 
a, b = 0, 1
while (a < 100):
    print(a, end=',')
    a, b = b, a+b



my_list = [ "c", "java", "python", "c++"]
for y in my_list:
    print(y)
    print(len(y))
