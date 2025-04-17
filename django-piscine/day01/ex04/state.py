import sys

def find_state_by_capital(capital):
    states = {
        "Oregon": "OR",
        "Alabama": "AL",
        "New Jersey": "NJ",
        "Colorado": "CO"
    }
    
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
    }

    state_abbreviation = None
    for abbrev, city in capital_cities.items():
        if city == capital:
            state_abbreviation = abbrev
            break

    if state_abbreviation:

        for state, abbrev in states.items():
            if abbrev == state_abbreviation:
                print(state)
                return
    else:

        print("Unknown capital city")

def main():
    if len(sys.argv) != 2:
        print("Usage: python state.py <capital>")
        sys.exit(1)
    
    find_state_by_capital(sys.argv[1])

if __name__ == '__main__':
    main()
