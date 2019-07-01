# GagnerDesMillions
c'est un jeu basé sur le celebre jeu "qui veut gagner des millions" implementé en langage C en faisant des interfaces
graphiques avec GTK2.0
aprés l'installation de GTK2.0 vous pouvez compiler et executer cette jeu en tappant 
sur le TERMINAL les commandes suivantes :
situez vous dans le dossier du jeu.. en utilisant la commande " cd " (LINUX), puis:

--> gcc `pkg-config gtk+-2.0 --flags`A -w  -c Statistiques.c Admin.c joueur.c QUESTION.c  ACCUEIL.c LOGIN.c JEU.c  MSGBOX.c  `pkg-config gtk+-2.0 --libs`
-->gcc `pkg-config gtk+-2.0 --cflags`A -w main.c  -o main Statistiques.o Admin.o joueur.o QUESTION.o  ACCUEIL.o LOGIN.o JEU.o MSGBOX.o  `pkg-config gtk+-2.0 --libs`
-->./main ..
