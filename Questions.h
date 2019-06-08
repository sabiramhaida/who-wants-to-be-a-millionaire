#include <stdio.h> 
#include "constantes.h"
typedef struct {
     char Texte[MAX_TEXTE_QUESTION];
     char Reponses[4][MAX_TEXT_REPONSE];
     int Correcte;
     int Niveau;
 }DonneeQ;

typedef struct Question{
    DonneeQ *UnQuestion ;
    struct Question *suivant;
} Question;

typedef Question ListeDesQuestions; //nomination..

Question *CreerQuestion(DonneeQ *d);
ListeDesQuestions InsererQuestion(DonneeQ *d, ListeDesQuestions *liste);
void Sauvegarder(ListeDesQuestions *liste ,char *nomFichier);
ListeDesQuestions * chargerQuestion( ListeDesQuestions *liste, char *nomFichier);