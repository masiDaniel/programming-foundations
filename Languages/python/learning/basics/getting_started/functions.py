def fibonacci(n):
    a, b = 0, 1

    while (a < n):
        print(a, end=', ')
        a, b = b , a+b

fibonacci(100)

x = int(input("enter the number you want to use for fibonacci: "))
fibonacci(x)

#keyword arguments

def my_function(arg1, *argv):
    print("the first argument is: ", arg1)
    for arg in argv:
        print("the next arguments are ", arg)

my_function('Hello', 'Welcome', 'to', 'GeeksforGeeks')
