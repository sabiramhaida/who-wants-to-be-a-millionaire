#include <string.h>
#include <stdio.h>
#include "Admin.h"
int VerifierAdmin(char* noma,char* MDP,char* nomFichier){
	{
FILE*f=fopen(nomFichier,"rb");
   if(f!=NULL){
        Administrateur Admin;
      while(fread(&Admin,sizeof(Administrateur),1,f)!=0){
         if(strcmp(Admin.Nom,noma)==0 && (strcmp(Admin.MotDePasse,MDP)==0))
            { return VALIDE;fclose(f); }
      }
      return INVALIDE;
   }
}
}
Administrateur ConnexionAdmin(char *nomdc, char* MDP,char* nomFichier){
FILE*f=fopen(nomFichier,"rb");
Administrateur Admin;
   if(f!=NULL)
   {
      while(fread(&Admin,sizeof(Administrateur),1,f)!=0)
      {
      	if((strcmp(Admin.Nom,nomdc)==0 ) && (strcmp(Admin.MotDePasse,MDP)==0))
      		{ fclose(f); return Admin ;}
      }
      fclose(f); 
      return Admin;
   }
}