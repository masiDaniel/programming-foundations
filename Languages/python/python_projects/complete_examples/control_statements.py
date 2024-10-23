#we will start with if statements 

i = 10

if i % 2 == 0:
    print("number is even")
else:
    print("number is odd")

# elif statements 

today = "tuesday"

if today == "monday":
    print("this is a monday")
elif today == "tuesday":
    print("this is a tuesday")
elif today == "wednesday":
    print("this is a wednesday")
elif today == "thursday":
    print("this is a thursday")
elif today == "friday":
    print("this is a friday")
else:
    print("it the motherfuckin weekend")


#nested if statement

day = "holiday"
balance = 400000

if day =="holiday":
    if balance < 350000:
        print("look for 50000")
    else:
        print("enjoy your holiday sir")
else:
    print("please go to work")