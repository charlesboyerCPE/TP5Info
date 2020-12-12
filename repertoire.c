#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include "repertoire.h"

void exercice1()
{
    //On alloue la mémorie pour scanf
    char *cheminDossier = malloc(sizeof(char));

    //Saisi de l'utilisateur
    printf("Veuillez saisir le chemin du dossier: ");
    scanf("%s", cheminDossier);

    lire_dossier(cheminDossier);
}

void lire_dossier(char *cheminDossier)
{
    DIR *dossier = NULL;
    struct dirent *dir = NULL;
    
    //Ouverture du dossier
    dossier = opendir(cheminDossier);
    if (dossier != NULL) 
    {
        printf("Fichier et dossier dans %s:\n", cheminDossier);
        while ((dir = readdir(dossier)) != NULL) 
        {
            printf("%s\n", dir->d_name); //La structure dirent possède un champ pour le nom du fichier
        }

        closedir(dossier);
    }
}

int main(void) 
{
    

    return(0);
}