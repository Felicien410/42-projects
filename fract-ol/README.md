# fract-ol
fractol 42 project

![Screen Shot 2023-03-15 at 6 43 31 PM](https://user-images.githubusercontent.com/97636902/225397128-a8d1ec70-5116-49ea-9d90-af63eff4ebdf.png)

Pour le lancer;

1-> compiler le Makefile en utilisant la commande 'make'

2-> lancer l'executable en mettant la fractal que vous voulez (ex ; ./fractol Julia)

vous pouvez changer les valeurs de corx depuis le lancement du programme (ex ; ./fractol Julia 0.2 0.8)
ou avec les fleches du clavier quand le programme est lancee


Un ensemble de Julia est un type de fractale qui peut être représenté en utilisant une fonction mathématique simple, souvent sous la forme de z^2 + c. Cette fonction prend en entrée un nombre complexe z et un autre nombre complexe c, et renvoie un nouveau nombre complexe.

L'ensemble de Julia est créé en itérant cette fonction à plusieurs reprises pour chaque point dans le plan complexe. Si le résultat de l'itération dépasse une certaine limite, on considère que le point appartient à l'ensemble de Julia. Sinon, il n'en fait pas partie. Les points qui appartiennent à l'ensemble sont colorés, tandis que les autres sont laissés en blanc.

Ce processus peut être répété pour chaque point dans le plan complexe, créant ainsi une image complexe et fascinante. Chaque point de l'image représente un point dans le plan complexe, et la couleur de ce point est déterminée par le nombre d'itérations nécessaires pour déterminer s'il appartient ou non à l'ensemble de Julia.

En effet, le niveau de détail d'une fractale peut être ajusté en modifiant les valeurs des paramètres de la fractale. Dans le cas de l'ensemble de Julia, ces paramètres sont la valeur de la constante complexe c, ainsi que la plage de valeurs des parties réelle et imaginaire de z (le point sur lequel on itère la fonction). En modifiant ces valeurs, on peut obtenir des fractales avec des niveaux de détails différents. Par exemple, en augmentant le nombre d'itérations de la fonction, on peut obtenir des fractales avec plus de détails, mais cela peut également augmenter le temps de calcul nécessaire pour générer l'image de la fractale.

Lorsqu'on génère une fractale de Julia, on associe un nombre complexe à chaque pixel de l'image. Ce nombre complexe est composé d'une partie réelle et d'une partie imaginaire. La valeur de "cr" dans le code que tu m'as montré correspond à la partie réelle de ce nombre complexe associé à un pixel donné. Autrement dit, pour chaque pixel de l'image, le programme calcule une valeur de "cr" qui dépend de la position du pixel sur l'axe horizontal de l'image. Cette valeur est ensuite utilisée dans le calcul pour déterminer si le point associé au pixel fait partie ou non de l'ensemble de Julia.
![Screen Shot 2023-03-15 at 6 44 42 PM](https://user-images.githubusercontent.com/97636902/225397315-8ba0cf78-58d9-4b10-9c65-4dc5d346c638.png)
