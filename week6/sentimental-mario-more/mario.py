while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Height have to be an integer!")
    if height < 9 and height > 0:
        break
    else:
        print("Height have to be between 1 - 8")

for i in range(height):
    print(" " * (height - i), "#" * (i + 1), " ", "#" * (i + 1))
