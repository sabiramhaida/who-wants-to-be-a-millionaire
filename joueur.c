#include <stdio.h>
#include <string.h>
#include "joueur.h"

extern DonneeJ joueur_courant;

int ChercherJoueur(char *Nomdc,char *nomFichier)	
{
FILE*f=fopen(nomFichier,"rb");
   if(f!=NULL){
   	  DonneeJ J;
      while(fread(&J,sizeof(DonneeJ),1,f)!=0){
      	if(strcmp(J.Nom,Nomdc)==0 )
      		{ return VALIDE;fclose(f); }
      }
   }
   return INVALIDE;
}

int VerifierJoueur(char *Nomdc,char *MDP,char *nomFichier)   
{
FILE*f=fopen(nomFichier,"rb");
   if(f!=NULL){
        DonneeJ J;
      while(fread(&J,sizeof(DonneeJ),1,f)!=0){
        printf("%smot \n",J.MotDePasse);
         if(strcmp(J.Nom,Nomdc)==0 && (strcmp(J.MotDePasse,MDP)==0))
            { return VALIDE;fclose(f); }
      }   
   }
   return INVALIDE;
}


DonneeJ ConnexionJoueur(char *nomdc, char* MDP,char* nomFichier){
FILE*f=fopen(nomFichier,"rb+");
DonneeJ J;
   if(f!=NULL)
   {
      while(fread(&J,sizeof(DonneeJ),1,f)!=0)
      {
      	if((strcmp(J.Nom,nomdc)==0 ) && (strcmp(J.MotDePasse,MDP)==0))
      		{ fclose(f); return J ;}
      }
      fclose(f); 
      return J;
   
   }
}


void Sauvegarder(char *nomFichier)
{DonneeJ J ;
FILE *f=fopen(nomFichier,"wb+");
 while (fread (&J, sizeof(DonneeJ),1,f) != 0)
  { if((strcmp(J.Nom,joueur_courant.Nom)==0 ))
  {
 	fseek(f, sizeof(DonneeJ) * -1,SEEK_CUR); 
 	fwrite(&joueur_courant,sizeof(DonneeJ),1,f);
  return;
 	}
  }
  fclose(f);
  f=fopen(nomFichier,"ab");
  rewind(f);
  fwrite(&joueur_courant,sizeof(DonneeJ),1,f);
  fclose(f);
}

void  SupprimerCompte(char *nomFichier,char *nom){
DonneeJ J ;
FILE *f=fopen(nomFichier,"rb");
FILE *copy=fopen("copy","wb");
while (fread (&J, sizeof(DonneeJ),1,f) != 0)
{
{  if((strcmp(J.Nom,joueur_courant.Nom)==0 ))
   // fseek(f, sizeof(DonneeJ) * 1,SEEK_CUR);
    continue;
    }
fwrite(&J,sizeof(DonneeJ),1,copy);
}
fclose(f);
rewind(copy);
fclose(copy);
remove(nomFichier);
rename("copy",nomFichier);

}
