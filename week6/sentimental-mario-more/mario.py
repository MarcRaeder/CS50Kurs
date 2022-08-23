while True:
    try:
        Height = int(input("Height: "))
    except ValueError:
        print("Height have to be an integer!")
    if Height < 9 and Height > 0:
        break
    else:
        print("Height have to be between 1 - 8")

for i in range(Height):
    print(" " * (Height - i), "#" * (i + 1), " ", "#" * (i + 1))
