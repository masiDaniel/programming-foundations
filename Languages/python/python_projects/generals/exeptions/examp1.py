while True:
    try:
        x = int(input("please enter a number: "))
        break
    except ValueError:
        print("opps! that was not a valid number, try again ...")
