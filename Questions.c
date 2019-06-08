#include "Questions.h"
#include <stdio.h>
#include "constantes.h"
#include<stdlib.h>
ListeDesQuestions *liste;

DonneeQ *saisirD(){
    DonneeQ *d= (DonneeQ*)malloc(sizeof(DonneeQ));
    printf("Donner le Texte : ");
    scanf("%s",d->Texte);
    getchar();
    printf("Donner les Reponses: ");
    for (int i=0;i<4;i++)
    {
    	printf("reponse %c",(i+65));
    	scanf("%s",d->Reponses[i]);
    	getchar();
    }
    printf("Donner l'indice de la Reponse Correcte: \n");
    scanf("%d",&d->Correcte);
    getchar();
    printf("donner le Niveau de la Qstn\n");
    scanf("%d",&d->Niveau);
    getchar();
    return d;
}
Question *creerQuestion(DonneeQ *d) {
    Question *nouveau = (Question*)malloc(sizeof(Question));
    nouveau->UnQuestion = d;
    nouveau->suivant = NULL;
    return nouveau;
}

ListeDesQuestions* insererQuestion(DonneeQ *d, ListeDesQuestions *liste){
    //insere un nouveau Qstn en tete de liste
    Question *nouveau =creerQuestion(d);
    nouveau->suivant = liste;
    liste=nouveau;
    return liste;
}
ListeDesQuestions  *chargerQuestion(ListeDesQuestions *liste,char* nomFichier)
{
FILE*f=fopen(nomFichier,"rb");
DonneeQ *d;
   if(f!=NULL){
      d=(DonneeQ*)malloc(sizeof(DonneeQ));
      while(fread(d,sizeof(DonneeQ),1,f)!=0){
        liste=insererQuestion(d,liste);
        d=(DonneeQ*)malloc(sizeof(DonneeQ));
      }
      fclose(f);
   }
   
   else
      printf("erreur ou fichier inexistant");
  return liste;
}




void Sauvegarder(ListeDesQuestions *liste ,char *nomFichier)
{	ListeDesQuestions *p = liste;
	FILE*f=fopen(nomFichier,"wb");       //ouvrir un fichier binaire en écriture
   // si liste non vide
   if(p!=NULL)
   { 
 
      	if((f)!=NULL)
      	{
		// parcourir la liste jusque fin 
        	while(p!=NULL)
         	{ 
   		// copier 
            	fwrite(p->UnQuestion,sizeof(DonneeQ),1,f);
            	// passer au maillon suivant
  				p=p->suivant; 
        	}

         fclose(f);
		// fermer le fichier
    	}
      else
         printf("erreur création fichier\n");
   }
   else
      printf("pas de sauvegarde pour une liste vide\n");
}

void afficherQuestion(ListeDesQuestions *liste){
    ListeDesQuestions *aux;
    if (liste==NULL){
        printf("\nIl n'existe aucun Question !!\n");
        return;
    }
    aux=liste; // on se place au debut
    printf("\n\t || Affichage ............ ||\n\n");
    while(aux!=NULL){
        printf("%s\n",aux->UnQuestion->Texte);
        for (int i = 0; i < 4; ++i)
        {
        	printf("%d-%s\n",i,aux->UnQuestion->Reponses[i]);
        }
        printf("la reponse corr : %d\n",aux->UnQuestion->Correcte);
        printf("Niveau : %d\n",aux->UnQuestion->Niveau);
        aux=aux->suivant;
    }
    return;
}

int main(int argc, char const *argv[])
{   liste=NULL;
    int reponse=0,continuer=1;
    DonneeQ *d;
    char chaine[20];
    char* nf=FICHIER_QUESTION;
    do{
        printf("\n\t\t\t~~~~~~~~~~~~~ MENU DES ADHERENT ~~~~~~~~~~~~\n\n");
        printf("\t\t\t\t[1] Ajouter un Question\n");
        printf("\t\t\t\t[2] chargerQuestion \n");
        printf("\t\t\t\t[3] Affichage \n");
        printf("\t\t\t\t[4] Sauvegarder \n");
        printf("\t\t\t\t[5] Quiter\n\n");
        printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("\t\t\tDonner votre choix: ");

        scanf("%d",&reponse);
        switch(reponse){
            case 1:
                d=saisirD();
                liste=insererQuestion(d,liste);
                break;
            case 2:
                liste = chargerQuestion(liste,nf);
                break;
            case 3:
                afficherQuestion(liste);
                break;
            case 4:
            	Sauvegarder(liste ,nf);
            	break;
            case 5:
                exit(1);
            default:
                continuer=0;
                break;
        }
    }while(continuer==1);
//*/
	return 0;
}

