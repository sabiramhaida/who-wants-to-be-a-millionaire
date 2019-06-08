#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "MSGBOX.h"
#include "LOGIN.h"
#include "QUESTION.h"
#include "joueur.h"
#include "Admin.h"
#include "JEU.h"
extern GtkWidget *fenetre_accueil;
Administrateur Admin;
DonneeJ joueur_courant;
GtkWidget * fenetre_login=NULL;
GtkWidget * cadre_login=NULL;
GtkWidget * label_nom=NULL,*label_mot_passe=NULL,*label_info;
GtkWidget * text_nom=NULL,*text_mot_passe=NULL;
GtkWidget * butt_ok=NULL;
GtkWidget * fenetre_creation=NULL;
GtkWidget * cadre_creation=NULL,*text_mot_passe_2=NULL,*label_mot_passe_2=NULL;
GtkWidget * fenetre_logina=NULL;
GtkWidget * cadre_logina=NULL;


void VerificationAdmin(){

    char nom[MAX_NOM],mot_passe_tapee[MAX_MOT_DE_PASSE],exp[500];
    GtkWidget *pQuestion;
    strcpy(nom,(char *)gtk_entry_get_text(GTK_ENTRY(text_nom)));
    strcpy(mot_passe_tapee,(char *)gtk_entry_get_text(GTK_ENTRY(text_mot_passe)));
    if(VerifierAdmin(nom,mot_passe_tapee,FICHIER_ADMIN)==INVALIDE)
          {
        pQuestion = gtk_message_dialog_new (GTK_WINDOW(fenetre_logina),GTK_DIALOG_MODAL,GTK_MESSAGE_OTHER, GTK_BUTTONS_YES_NO,
        "Le Nom De Compte ou Le Mot de Passe est erroné.Ressayez à Nouveau !!");
                                            /* Affichage et attente d une reponse */
        switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
            {
            case GTK_RESPONSE_YES:  gtk_widget_destroy(pQuestion);
                gtk_entry_set_text(GTK_ENTRY(text_nom),"");
                gtk_entry_set_text(GTK_ENTRY(text_mot_passe),"");break;
            case GTK_RESPONSE_NO:   gtk_widget_destroy(pQuestion);
                gtk_widget_destroy(fenetre_logina);break;
              }
          }
    else
    
    {
        Admin=ConnexionAdmin(nom,mot_passe_tapee,FICHIER_ADMIN);
        sprintf(exp,"Bienvenue %s",Admin.Nom);
        msgbox1(fenetre_logina,exp);
        gtk_widget_destroy(fenetre_logina);
        MenuAdministration();
    }
}

void Verification(){

	char nom[MAX_NOM],mot_passe_tapee[MAX_MOT_DE_PASSE],exp[500];
	GtkWidget *pQuestion;
	strcpy(nom,(char *)gtk_entry_get_text(GTK_ENTRY(text_nom)));
	strcpy(mot_passe_tapee,(char *)gtk_entry_get_text(GTK_ENTRY(text_mot_passe)));
	if(VerifierJoueur(nom,mot_passe_tapee,FICHIER_JOUEUR)==INVALIDE)
          {
        pQuestion = gtk_message_dialog_new (GTK_WINDOW(fenetre_login),GTK_DIALOG_MODAL,GTK_MESSAGE_OTHER, GTK_BUTTONS_YES_NO,
        "Le Nom De Compte ou Le Mot de Passe est erroné.Ressayez à Nouveau !!");
											/* Affichage et attente d une reponse */
        switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
            {
            case GTK_RESPONSE_YES:  gtk_widget_destroy(pQuestion);
                gtk_entry_set_text(GTK_ENTRY(text_nom),"");
                gtk_entry_set_text(GTK_ENTRY(text_mot_passe),"");break;
            case GTK_RESPONSE_NO:   gtk_widget_destroy(pQuestion);
                gtk_widget_destroy(fenetre_login);break;
              }
          }
    else
    
    {
    	joueur_courant=ConnexionJoueur(nom,mot_passe_tapee,FICHIER_JOUEUR);
    	sprintf(exp,"Bienvenue %s",joueur_courant.Nom);
        msgbox1(fenetre_login,exp);
        gtk_widget_destroy(fenetre_login);
        MenuJeu();
    }
}


void EcranLogin()
{
     label_info=gtk_label_new("Entrer le nom et le mot de passe ");
     label_nom=gtk_label_new("Nom :");
     label_mot_passe=gtk_label_new("Mot de passe :");
     text_nom=gtk_entry_new();
     text_mot_passe=gtk_entry_new();
     fenetre_login=gtk_window_new(GTK_WINDOW_TOPLEVEL);
     cadre_login=gtk_fixed_new();
     butt_ok=gtk_button_new_with_label("Se Connecter");
     gtk_container_add(GTK_CONTAINER(fenetre_login),cadre_login);
     gtk_fixed_put(GTK_FIXED(cadre_login),label_info,0,0);
     gtk_fixed_put(GTK_FIXED(cadre_login),label_nom,5,45);
     gtk_fixed_put(GTK_FIXED(cadre_login),text_mot_passe,90,102);
     gtk_fixed_put(GTK_FIXED(cadre_login),text_nom,90,42);
     gtk_fixed_put(GTK_FIXED(cadre_login),label_mot_passe,5,105);
     gtk_fixed_put(GTK_FIXED(cadre_login),butt_ok,130,150);
     gtk_entry_set_max_length (GTK_ENTRY(text_nom),15);
     gtk_entry_set_max_length (GTK_ENTRY(text_mot_passe),14);
     gtk_window_set_title(GTK_WINDOW(fenetre_login),"Connexion ");
     gtk_window_set_position(GTK_WINDOW(fenetre_login),GTK_WIN_POS_CENTER);
     gtk_window_set_default_size(GTK_WINDOW(fenetre_login),300,200);
     gtk_entry_set_visibility(GTK_ENTRY(text_mot_passe),FALSE);
     gtk_window_set_modal(GTK_WINDOW(fenetre_login),TRUE);
     g_signal_connect(G_OBJECT(butt_ok),"clicked", G_CALLBACK(Verification),NULL);
     gtk_widget_show_all(fenetre_login);

}

void EcranLoginAdmin()
{

     label_info=gtk_label_new("Entrer Le Nom et Le Mot de Passe");
     label_nom=gtk_label_new("Nom :");
     label_mot_passe=gtk_label_new("Mot de passe :");
     text_nom=gtk_entry_new();
     text_mot_passe=gtk_entry_new();
     fenetre_logina=gtk_window_new(GTK_WINDOW_TOPLEVEL);
     cadre_logina=gtk_fixed_new();
     butt_ok=gtk_button_new_with_label("Se Connecter en tant q'un Admin ");
     gtk_container_add(GTK_CONTAINER(fenetre_logina),cadre_logina);
     gtk_fixed_put(GTK_FIXED(cadre_logina),label_info,0,0);
     gtk_fixed_put(GTK_FIXED(cadre_logina),label_nom,5,45);
     gtk_fixed_put(GTK_FIXED(cadre_logina),text_mot_passe,90,102);
     gtk_fixed_put(GTK_FIXED(cadre_logina),text_nom,90,42);
     gtk_fixed_put(GTK_FIXED(cadre_logina),label_mot_passe,5,105);
     gtk_fixed_put(GTK_FIXED(cadre_logina),butt_ok,130,150);
     gtk_entry_set_max_length (GTK_ENTRY(text_nom),15);
     gtk_entry_set_max_length (GTK_ENTRY(text_mot_passe),14);
     gtk_window_set_title(GTK_WINDOW(fenetre_logina),"Connexion D'administration");
     gtk_window_set_position(GTK_WINDOW(fenetre_logina),GTK_WIN_POS_CENTER);
     gtk_window_set_default_size(GTK_WINDOW(fenetre_logina),300,200);
     gtk_entry_set_visibility(GTK_ENTRY(text_mot_passe),FALSE);
     gtk_window_set_modal(GTK_WINDOW(fenetre_logina),TRUE);
     g_signal_connect(G_OBJECT(butt_ok),"clicked", G_CALLBACK(VerificationAdmin),NULL);
     gtk_widget_show_all(fenetre_logina);

}
void Creation()
{    
     char  nom[MAX_NOM],mot_passe_tapee[MAX_MOT_DE_PASSE],mot_passe_tapee_2[MAX_MOT_DE_PASSE];
     GtkWidget *pMsg;
     strcpy(nom,gtk_entry_get_text(GTK_ENTRY(text_nom)));
     strcpy(mot_passe_tapee,(char *)gtk_entry_get_text(GTK_ENTRY(text_mot_passe)));
     strcpy(mot_passe_tapee_2,(char *)gtk_entry_get_text(GTK_ENTRY(text_mot_passe_2)));
    if(ChercherJoueur(nom,FICHIER_JOUEUR)==VALIDE)
    {
          msgbox1(fenetre_creation,"Ce nom existe déja veuillez choisir un autre nom");
          gtk_entry_set_text(GTK_ENTRY(text_nom),"");
          gtk_entry_set_text(GTK_ENTRY(text_mot_passe),"");
          gtk_entry_set_text(GTK_ENTRY(text_mot_passe_2),"");
          return ;
    }
    if(strcmp(mot_passe_tapee,mot_passe_tapee_2)!=0)
     {
          msgbox1(fenetre_creation,"Les deux mots de passe ne sont pas identiques");
          gtk_entry_set_text(GTK_ENTRY(text_mot_passe),"");
          gtk_entry_set_text(GTK_ENTRY(text_mot_passe_2),"");
          return ;
     }
    strcpy(joueur_courant.Nom,nom); 
    strcpy(joueur_courant.MotDePasse,mot_passe_tapee); 
    joueur_courant.MeilleurScoreJoueur=0;
    joueur_courant.NombreDeParties=0;
    msgbox1(fenetre_creation,"Inscription effectué");
    Sauvegarder(FICHIER_JOUEUR);
    gtk_widget_destroy(fenetre_creation);
    MenuJeu();
    
    }

void EcranCreation()
{
     label_info=gtk_label_new("Entrer le nom et le mot de passe ");
     label_nom=gtk_label_new("Nom :");
     label_mot_passe=gtk_label_new("Mot de passe :");
     label_mot_passe_2=gtk_label_new("Mot de passe \n A nouveau :");
     text_nom=gtk_entry_new();
     text_mot_passe=gtk_entry_new();
     text_mot_passe_2=gtk_entry_new();
     fenetre_creation=gtk_window_new(GTK_WINDOW_TOPLEVEL);
     cadre_creation=gtk_fixed_new();
     butt_ok=gtk_button_new_with_label("creer un Compte");
     gtk_container_add(GTK_CONTAINER(fenetre_creation),cadre_creation);
     gtk_fixed_put(GTK_FIXED(cadre_creation),label_info,15,0);
     gtk_fixed_put(GTK_FIXED(cadre_creation),label_nom,5,45);
     gtk_fixed_put(GTK_FIXED(cadre_creation),text_mot_passe,90,102);
     gtk_fixed_put(GTK_FIXED(cadre_creation),text_mot_passe_2,90,168);
     gtk_fixed_put(GTK_FIXED(cadre_creation),text_nom,90,42);
     gtk_fixed_put(GTK_FIXED(cadre_creation),label_mot_passe,5,105);
     gtk_fixed_put(GTK_FIXED(cadre_creation),label_mot_passe_2,15,165);
     gtk_entry_set_max_length (GTK_ENTRY(text_nom),15);
     gtk_entry_set_max_length (GTK_ENTRY(text_mot_passe),14);
     gtk_entry_set_max_length (GTK_ENTRY(text_mot_passe_2),14);
     gtk_fixed_put(GTK_FIXED(cadre_creation),butt_ok,130,210);
     gtk_window_set_title(GTK_WINDOW(fenetre_creation),"Inscription ");
     gtk_window_set_position(GTK_WINDOW(fenetre_creation),GTK_WIN_POS_CENTER);
     gtk_window_set_default_size(GTK_WINDOW(fenetre_creation),300,250);
     gtk_entry_set_visibility(GTK_ENTRY(text_mot_passe),FALSE);
     gtk_entry_set_visibility(GTK_ENTRY(text_mot_passe_2),FALSE);
     gtk_window_set_modal(GTK_WINDOW(fenetre_creation),TRUE);
     g_signal_connect(G_OBJECT(butt_ok),"clicked", G_CALLBACK(Creation),NULL);
     gtk_window_set_modal(GTK_WINDOW(fenetre_creation),TRUE);
     gtk_widget_show_all(fenetre_creation);

}
