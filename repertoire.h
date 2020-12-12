#ifndef REPERTOIRE_H
#define REPERTOIRE_H

/*
Nom: void lire_dossier(char *)
Détail: Procédure permettant de lire un dossiers et d'afficher
        les fichiers/répertoires présents (comme "ls")
Paramètre: Le chemin du dossier
*/
void lire_dossier(char *);

/*
Nom: void lire_dossier_recursif(char *)
Détail: Procédure permettant de lire un dossiers et d'afficher
        les fichiers/répertoires présents de facon récurcive (comme "ls -R")
Paramètre: Le chemin du dossier
*/
void lire_dossier_recursif(char *);

/*
Nom: void exercice1()
Détail: Procédure contenant l'exercice 1
*/
void exercice1();

/*
Nom: void exercice2()
Détail: Procédure contenant l'exercice 2
*/
void exercice2();
#endif