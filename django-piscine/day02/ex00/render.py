import sys
import os
import re
import settings  # Importing the settings file for variables

def render_template(template_file):
    # Vérification de l'extension
    if not template_file.endswith(".template"):
        print("Erreur : le fichier doit avoir l'extension .template")
        return

    # Vérification de l'existence du fichier
    if not os.path.isfile(template_file):
        print(f"Erreur : le fichier '{template_file}' n'existe pas.")
        return

    # Lecture du contenu du fichier template
    with open(template_file, 'r') as file:
        content = file.read()

    # Remplacement des motifs dans le contenu
    variables = {attr: getattr(settings, attr) for attr in dir(settings) if not attr.startswith("__")}
    for key, value in variables.items():
        content = re.sub(r"\{" + key + r"\}", str(value), content)

    # Écriture dans le fichier de sortie .html
    output_file = template_file.replace('.template', '.html')
    with open(output_file, 'w') as file:
        file.write(content)

    print(f"Le fichier '{output_file}' a été généré avec succès.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage : python3 render.py <nom_du_fichier_template>")
    else:
        render_template(sys.argv[1])
