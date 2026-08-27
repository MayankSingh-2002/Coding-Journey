unit = int(input('Enter the no. of unit: '))
if unit>600:
    a = unit - 600
    b = unit - 300 - a
    c = unit - 500 - a
    d = unit - 600 - a

    total = a*11 + b*8 + c*6 + d*4.50
    print(f"You electricity bill is: {total}")
elif unit>300:
    unit = unit - 300
    total = unit*8 + 200*6 + 100*4.50
    print(f"You electricity bill is: {total}")
elif unit>200:
    unit = unit - 200
    total = unit*6 + 100*4.50
    print(f"You electricity bill is: {total}")
elif unit>0:
    total = unit*4.50
    print(f"You electricity bill is: {total}")
