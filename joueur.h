#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
typedef struct {
     char Nom[MAX_NOM];
     char MotDePasse[MAX_MOT_DE_PASSE];
     int MeilleurScoreJoueur;
     int NombreDeParties;
 } DonneeJ;

typedef struct _Joueur {
     DonneeJ *UnJoueur ;
    struct _Joueur *suivant;
}Joueur;

typedef Joueur ListeDesJoueurs ;


int ChercherJoueur(char *Nomdc,char *nomFichier);
DonneeJ SaisirJoueur(char *Nomdc,char*MDP);
DonneeJ ConnexionJoueur(char *nomdc, char* MDP,char* nomFichier);
void Sauvegarder(char *nomFichier);
int VerifierJoueur(char *Nomdc,char *MDP,char *nomFichier);
void  SupprimerCompte(char *nomFichier,char *nom);

