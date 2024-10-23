print("hello world")

with open("myfile.txt", "w") as f:
    f.write("im begining to learn python")

with open("myfile.txt") as f:
    print(f.read())