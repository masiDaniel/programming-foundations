def myFunc():
    pass
# this function finds the sumoa all the numbers in the range
def sum(x, y):
    result = 0
    for i in range(x, y+1):
        result += i
    
    #print(result)
    return(result)

#this is how we call the function  
s = sum(1,5)

print(s)

global_var = 10

def function():
    local_var = 100
    print(global_var)

function()
#print(local_var)

