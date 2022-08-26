def main():

    while True:
        try:
            card = int(input("Card: "))
            if card > 0:
                break
        except ValueError:
            print("Card has to be an number")


    def luhn_checksum(card: int) -> int:
        def digits_of(n):
            return [int(d) for d in str(n)]
        digits = digits_of(card)
        odd_digits = digits[-1:: -2]
        even_digits = digits[-2:: -2]
        checksum = 0
        checksum += sum(odd_digits)
        
        for d in even_digits:
            checksum += sum(digits_of(d * 2))
        return checksum % 10


    length = 0
    visa = card
    master = card
    amex = card

    length = len(str(card))

    while visa >= 10:
        visa = int(visa/10)

    while amex >= 10 ** 13:
        amex = int(amex / 10 ** 13)

    while master >= 10 ** 14:
        master = int(master / 10 ** 14)

    if luhn_checksum(card) == 0:
        if visa == 4 and (length == 13 or length == 16):
            print("VISA")
        elif length == 15 and (amex == 34 or amex == 37):
            print("AMEX")
        elif length == 16 and (51 <= master <= 55):
            print("MASTERCARD")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
