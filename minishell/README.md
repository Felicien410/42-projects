# minishell 42 project


#Lancer le programme  :
1) ### Make
2) ### ./minishell



Caractéristiques Techniques:

Exécution de Commandes : en mesure de construire un programme capable d'exécuter des commandes basiques telles que ls, echo ou encore pwd.

Gestion des Path : Le shell doit connaître l'emplacement des programmes exécutables. Pour cela, il faudra exploiter la variable d'environnement $PATH.

Implémentation de Builtin : Certaines commandes classiques, comme cd, exit, env, etc., doivent être intégrées (ou "builtin") directement dans le shell.

Redirections & Pipes : Le shell devra supporter les redirections basiques (>, >>, <) et les pipes (|).

Gestion des Signaux : Cela comprend la gestion de Ctrl-C pour interrompre une commande en cours d'exécution et Ctrl-\ pour quitter le shell.

Variables d'Environnement : Le shell doit gérer les variables d'environnement internes, ce qui signifie pouvoir les afficher, les modifier ou même en ajouter.
