import sys


def find_state_or_capital(expr_lower, original_expr):
    states = {
        "Oregon": "OR",
        "Alabama": "AL",
        "New Jersey": "NJ",
        "Colorado": "CO"
    }

    # Dictionnaire des abréviations des états et leurs capitales
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
    }
    found = False  # Indicateur pour savoir si on a trouvé quelque chose

    # Vérifier si l'expression est un état
    for state, abbrev in states.items():
        if state.lower() == expr_lower:
            # Trouver la capitale associée
            capital = capital_cities[abbrev]
            print(f"{original_expr} is the capital of {state}")
            found = True
            break

    # Vérifier si l'expression est une capitale (si ce n'est pas un état)
    if not found:
        for abbrev, capital in capital_cities.items():
            if capital.lower() == expr_lower:
                # Trouver l'état associé
                for state, abbr in states.items():
                    if abbr == abbrev:
                        print(f"{original_expr} is the capital of {state}")
                        found = True
                        break

    # Si ce n'est ni une capitale ni un état
    if not found:
        print(f"{original_expr} is neither a capital city nor a state")

def process_input(input_string):
    # Diviser la chaîne d'entrée par des virgules et nettoyer chaque expression
    expressions = input_string.split(',')

    # Parcourir chaque expression nettoyée
    for expr in expressions:
        expr = expr.strip()  # Supprimer les espaces en trop
        expr_lower = expr.lower()  # Conversion en minuscules pour comparaison insensible à la casse

        if not expr:
            continue  # Ignorer les chaînes vides (s'il y a des espaces ou des virgules en trop)

        find_state_or_capital(expr_lower, expr)

def main():
    # Vérifier qu'un seul argument est fourni
    if len(sys.argv) != 2:
        return

    # Récupérer la chaîne d'entrée
    input_string = sys.argv[1]

    # Si deux virgules consécutives existent, ne rien afficher
    if ",," in input_string:
        return

    # Appeler la fonction pour traiter l'entrée
    process_input(input_string)

if __name__ == '__main__':
    main()
