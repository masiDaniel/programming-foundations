def MyItems():
    return {
        101: {'name': 'Laptop', 'category': 'Electronics', 'quantity':5},
        102: {'name': 'Table', 'category': 'Furniture', 'quantity': 10},
        103: {'name': 'Pen', 'category': 'Stationery', 'quantity': 50},
    }

def checkIds():
    items = MyItems()
    ids =  list(items.keys())

    # Use a set to check for duplicates
    if len(ids) == len(set(ids)):
        print("No duplicate IDs found.")
        return True
    else:
        print("Duplicate IDs found.")
        return False

def addItems(items):
    """
    method to add items to the list of items 
    """

    items[104] = {"name": 'calculator', "category": "Stationery", "quantity": 2}
    print(items)
    

def removeItems(items):
    """
    method to remove items from the list of items 
    """

    #del removes the item with the specified key name
    del items[104]
    print(items)

def updateItems(items):
    """
    method to update items in the list of items 
    """

    items.update({103: {"quantity": 500}})
    print(items)

def searchItem(searchTerm, searchBy="name"):
    """
    function to search for an item
    """

    

    items = MyItems()
    results = []

    #loop through each item and check if the search term matches
    for item_id, details in items.items():
        if searchBy == "name" and details["name"].lower() == searchTerm.lower():
            results.append((item_id, details))
        elif searchBy == "category" and details['category'].lower() == searchTerm.lower():
            results.append((item_id, details))
    
    return results

def main():
    items = MyItems()
    addItems(items)

    removeItems(items)

    updateItems(items)

    result = searchItem('Pen', searchBy='name')
    print(result)

if __name__ == "__main__":
    main()
