class Robot:
    """this is a class object which counts the number of robots"""
    num = 0

    def __init__(self, name):
        """initializes the data"""
        self.name = name
        print(f"intitializes {self.name}")

        Robot.num += 1
    
    def die(self):
        """kill them """
        print(f"i am being destroyed {self.name}")

        Robot.num -= 1
        if Robot.num == 0:
            print(f"{self.num} was the last one")
        else:
            print(f"there are still {Robot.num}")
        
    def greet(self):
        """greeting by the robot"""
        print(f"greetings, my masters call me {Robot.num}")

    


rob1 = Robot("d2-0")
rob1.greet()