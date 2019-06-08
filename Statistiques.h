#include <stdio.h>
#include "constantes.h"
typedef struct {
	char MeilleurJoueurs[3][MAX_NOM];
	int BonneReponsesParNV[NOMBRE_NIVEAU];
	int Meilleurscors[3];
}StatistiquesGlobale;


StatistiquesGlobale Top3Joueur(char *nomFichier);