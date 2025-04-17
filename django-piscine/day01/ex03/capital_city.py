import sys

def find_capital(argv):
    states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
        }
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
    }

    if len(argv) == 1:
        if argv[0] in states:
            print(capital_cities[states[argv[0]]])
        else:
            print("Unknown state")

def main():
    if len(sys.argv) < 2:
        print("Usage: python script.py argument1")
        sys.exit(1)
    find_capital(sys.argv[1:])

if __name__ == '__main__':
    main()
