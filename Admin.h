#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
typedef struct 
{
    char Nom[MAX_NOM];
    char MotDePasse[MAX_MOT_DE_PASSE];
} Administrateur;

int VerifierAdmin(char* noma,char* MDP,char* nomFichier);
Administrateur ConnexionAdmin(char *nomdc, char* MDP,char* nomFichier);