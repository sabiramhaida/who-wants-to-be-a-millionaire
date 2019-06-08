#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "QUESTION.h"
#include "constantes.h"
#include <time.h>
 extern int niveau;
 extern int rep_alea[4];
int alea;
Question **chargerQuestion(char* nomFichier,Question **MATRICE)
{
FILE* f= fopen(nomFichier,"rb");
Question *q;
int indice[NOMBRE_NIVEAU];
for(int i=0;i<NOMBRE_NIVEAU;i++)
   {
	indice[i]=0;
   }
if(f!=NULL){
      q=(Question*)malloc(sizeof(Question));
      while(fread(q,sizeof(Question),1,f)!=0){
      	MATRICE[q->Niveau-1][indice[q->Niveau-1]]= *q;
      	indice[q->Niveau-1]++;
         q=(Question*)malloc(sizeof(Question));
      }
      fclose(f);
   }
   return MATRICE;
}

void AjouterQuestion(Question q,char *nomFichier){
   FILE *f=fopen(nomFichier,"rb+");
   Question Q;
   while (fread (&Q, sizeof(Question),1,f) != 0)
   {

   }
   fwrite(&q,sizeof(Question),1,f);
   fclose(f);
}

Question QuestionAleatoire(Question** MATRICE){
	srand(time(NULL));
	alea =(int)rand()%(NOMBRE_QUESTIONS_PAR_NIVEAU-1);
   printf("%s\n","haaaaaaaaaaaaa" );
	Question q= MATRICE[niveau-1][alea];
   return q;
}
