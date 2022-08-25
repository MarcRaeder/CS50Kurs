import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        database = list(reader)

    with open(sys.argv[2]) as file2:
        sequence = file2.read()

    matches = {}
    for i in database[0]:
        matches[i] = (longest_match(sequence, i))

    suspect = 'No Match'
    suspect_counter = 1

    for i in range(len(database)):
        for j in matches:

            if str(matches[j]) == database[i][j]:
                suspect_counter += 1
        if suspect_counter == len(matches):

            suspect = database[i]['name']
            break
        else:
            suspect_counter = 1

    print(suspect)

    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1

            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

main()
