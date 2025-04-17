def to_dict(file):
    elements = file.read()
    all_elements = elements.split("\n")
    all_elements = list(filter(None, all_elements))

    periodic_table = {}
    for element in all_elements:
        name = element.split("=")[0]
        caracteristics = element.split("=")[1]
        detailled_caracteristics = caracteristics.split(",")

        periodic_table[name] = {
            "name": name,
            "position": int((detailled_caracteristics[0]).split(":")[1]),
            "number": int((detailled_caracteristics[1]).split(":")[1]),
            "small": (detailled_caracteristics[2]).split(":")[1],
            "molar": (detailled_caracteristics[3]).split(":")[1],
            "electron": (detailled_caracteristics[4]).split(":")[1]
        }
    return periodic_table

def generate_html(periodic_table):
    html_content = """
    <!DOCTYPE html>
    <html lang="fr">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Tableau Périodique des Éléments</title>
        <link rel="stylesheet" href="periodic_table.css">
    </head>
    <body>
        <h1>Tableau Périodique des Éléments</h1>
        <table>
    """

    # Structure du tableau périodique
    table_structure = [
        [1, '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', 2],  # Première ligne
        [3, 4, '', '', '', '', '', '', '', '', '', '', '', '', 5, 6, 7, 8],     # Deuxième ligne
        [11, 12, '', '', '', '', '', '', '', '', '', '', '', 13, 14, 15, 16, 17],  # Troisième ligne
        [19, 20, '', '', '', '', '', '', '', '', '', '', '', 31, 32, 33, 34, 35], # Quatrième ligne
        [37, 38, '', '', '', '', '', '', '', '', '', '', '', 49, 50, 51, 52, 53], # Cinquième ligne
        [55, 56, '', '', '', '', '', '', '', '', '', '', '', 81, 82, 83, 84, 85], # Sixième ligne
        [87, 88, '', '', '', '', '', '', '', '', '', '', '', 113, 114, 115, 116, 117],  # Septième ligne
    ]

    # Générer le contenu du tableau HTML
    for row in table_structure:
        html_content += "            <tr>\n"
        for cell in row:
            if cell == '':  # Case vide
                html_content += "                <td class='empty'></td>\n"
            else:
                element_found = False
                for element in periodic_table.values():
                    if element['number'] == cell:
                        html_content += f"""
                        <td class="element">
                            <h4>{element['name']}</h4>
                            <ul>
                                <li>{element['number']}</li>
                                <li>{element['small']}</li>
                                <li>{element['molar']}</li>
                            </ul>
                        </td>
                        """
                        element_found = True
                        break
                if not element_found:
                    html_content += "                <td class='empty'></td>\n"
        html_content += "            </tr>\n"

    # Clôture du tableau et du fichier HTML
    html_content += """
        </table>
    </body>
    </html>
    """

    # Écrire le contenu complet dans un nouveau fichier HTML
    with open("periodic_table.html", "w") as html_file:
        html_file.write(html_content)

    print("Le fichier periodic_table.html a été généré avec succès.")

def main():
    # Lire les éléments du fichier periodic_table.txt
    with open("periodic_table.txt", "r") as file:
        periodic_table = to_dict(file)
    
    # Générer le fichier HTML avec le tableau périodique
    generate_html(periodic_table)

if __name__ == '__main__':
    main()
