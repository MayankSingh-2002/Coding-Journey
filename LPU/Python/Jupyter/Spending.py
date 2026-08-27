total = 0
def MorningSpend(x=10):
    global total
    print(f"You spend Rs. {x} in the morning.")
    total += x
def AfternoonSpend(y):
    global total
    print(f"You spend Rs. {y} in the afternoon.")
    total += y
def EveningSpend(z):
    global total
    print(f"You spend Rs. {z} in the evening.")
    total += z
def TotalSpend():
    global total
    print(f"Your total spending for the day is: {total}")