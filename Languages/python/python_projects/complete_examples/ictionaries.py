friends = {
    'dan': '0909',
    'masi': '0808',
    'orango': '0707'
}

#retrieval of a value 
print(friends['dan'])

#to add an item 
friends['evin'] = '0606'
friends['brian'] = '0505'
friends['charlse'] = '0404'
friends['pamela'] = '0303'
#to modify an item 
friends['dan'] = '09090'
print(friends)

#to elete an element 
del friends['evin']
print(friends)

# to loop through the ictionary 

for key in friends:
    print(key, ":", friends[key])