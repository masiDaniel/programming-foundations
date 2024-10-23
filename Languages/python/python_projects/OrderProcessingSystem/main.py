def menu():
    """
    Returns a dictionary of menu items 
    and their prices
    """
    return {
        "ugali": 50,
        "mboga": 30,
        "chai":40,
        "mandazi":20
    }

def orders():
    """ 
    this accepts input from the user and returns a list of tuples
    that contain the orders (item, quantity)
    """

    my_orders = []
    while True:
        item = input("Enter the item you want to order (or 'done' to finish): ").lower()
        if item == "done":
            break
        quantity = input(f"Enter the quantity of {item}: ")

        try:
            quantity = int(quantity)
            if quantity < 1:
                print("Quantity must be a positive integer. Try again.")
                continue
        except ValueError:
            print("Please enter a valid number. try again.")
            continue

        my_orders.append((item, quantity))

    
    return my_orders



def Totals(orders, menu, tax_rate = 0.07):
    """
    this calculates the total cost of the order 
    including tax
    """

    total = 0
    receipt = []

    for item, quantity in orders:
        if item in menu:
            price = menu[item] * quantity
            receipt.append((item, quantity, price))
            total += price

        else:
            print(f"Item '{item}' is not available on the menu. Skipping...")

    
    total_with_tax = total * (1 + tax_rate)
    return total_with_tax, receipt

def printRecipt(receipt, total):
    """
    Prints the receipt in a structured form
    """
    print("\nReceipt: ")
    for item, quantity, price in receipt:
        print(f"{item.capitalize()} (x{quantity}): KES{price:.2f}")
    print(f"Total (with tax): KES{total:.2f}")

    

def main():
    while True:

        #get the menu
        menu_items = menu()

        #input of the tuple for orders from the user
        print("\n\t\tWelcome to our restaurant! Here is our menu:")
        for item, price in menu_items.items():
            print(f"{item.capitalize()}: KES {price}")
        
        my_orders = orders()


        #calculate the total and print the reciept
        totalCost, receipt = Totals(my_orders, menu_items)
        printRecipt(receipt, totalCost)

        option = input("Enter ('close' to finish): ").lower()
        if option == "done":
            break
        else:
            continue
    


if __name__ == "__main__":
    main()
