#include "constantes.h"
typedef struct {
     char Texte[MAX_TEXTE_QUESTION];
     char Reponses[4][MAX_TEXT_REPONSE];
     int Correcte;
     int Niveau;
 }Question;

Question **chargerQuestion(char* nomFichier,Question **MATRICE);
Question QuestionAleatoire();
void AjouterQuestion(Question q,char *nomFichier);
