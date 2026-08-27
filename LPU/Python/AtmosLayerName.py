dis = int(input('Enter the distance in KMS: '))

if dis>100:
    print('You are outside of Karman line')
    if dis>10000:
        print('Outer Space')
    elif dis>690:
        print('EXOSPHERE')
    elif dis>85:
        print('THERMOSPHERE')
    else:
        print('Invalid Input')
elif dis>0:
    print('You are inside of Karman line')
    if dis>85:
        print('THERMOSPHERE')
    elif dis>50:
        print('MESOSPHERE')
    elif dis>20:
        print('STRETOSPHERE')
    elif dis>0:
        print('TROPHOSPHERE')
else:
    
    print('Invalid Input')