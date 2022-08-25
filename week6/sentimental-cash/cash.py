from shelve import DbfilenameShelf


def main():

    while True:
        try:
            cents = float(input("Change owed: ")) * 100
            if cents > 0:
                break
            else:
                print("cents have to be bigger than 0")
        except ValueError:
            print("only use numbers")

    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    nickles = calculate_nickles(cents)
    cents -= nickles * 5

    pennies = cents

    coins = int(quarters + dimes + nickles + pennies)

    print(coins)


def calculate_quarters(cents):
    quarters = cents // 25

    return quarters


def calculate_dimes(cents):
    dimes = cents // 10

    return dimes


def calculate_nickles(cents: int) -> int:
    nickles = cents // 5

    return nickles


main()
