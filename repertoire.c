#include <dirent.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "repertoire.h"

void exercice1()
{
    //On alloue la mémorie pour scanf
    char *cheminDossier = malloc(sizeof(char));

    //Saisi de l'utilisateur
    printf("Veuillez saisir le chemin du dossier: ");
    scanf("%s", cheminDossier);

    lire_dossier(cheminDossier);

    free (cheminDossier);
}

void exercice2()
{
    //On alloue la mémorie pour scanf
    char *cheminDossier = malloc(sizeof(char));

    //Saisi de l'utilisateur
    printf("Veuillez saisir le chemin du dossier: ");
    scanf("%s", cheminDossier);

    lire_dossier_recursif(cheminDossier);

    free (cheminDossier);
}

void lire_dossier(char *cheminDossier)
{
    DIR *dossier = NULL;
    struct dirent *entree = NULL;
    
    //Ouverture du dossier
    dossier = opendir(cheminDossier);
    if (dossier != NULL) 
    {
        printf("Fichier et dossier dans %s:\n", cheminDossier);
        while ((entree = readdir(dossier)) != NULL) 
        {
            printf("%s\n", entree->d_name); //La structure dirent possède un champ pour le nom du fichier
        }

        closedir(dossier);
    }
}

void lire_dossier_recursif(char *cheminDossier)
{
    DIR *dossier = NULL;
    struct dirent *entree = NULL;
    char *cheminActuel = malloc(1000 * sizeof(char));

    //Ouverture du dossier
    dossier = opendir(cheminDossier);
    if (dossier != NULL) 
    {
        printf("%s:\n", cheminDossier);

        //On affiche les choses présentes dans le dossier
        while ((entree = readdir(dossier)) != NULL) 
        {
            //On enlève les . et ..
            if (strcmp(entree->d_name, ".") != 0 && strcmp(entree->d_name, "..") != 0)
            {
                printf("\t%s\n", entree->d_name);

                // On construit un nouveau chemin
                strcpy(cheminActuel, cheminDossier);
                strcat(cheminActuel, "/");
                strcat(cheminActuel, entree->d_name);

                lire_dossier_recursif(cheminActuel);
            }
        }
        closedir(dossier);
    }

    free (cheminActuel);
}

int main(void) 
{


    return(0);
}