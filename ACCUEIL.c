#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "LOGIN.h"
#include "ACCUEIL.h"
#include "Admin.h"
// les élements de la fenetre d'acceuik
GtkWidget * fenetre_accueil=NULL, *cadre_accueil=NULL;
GtkWidget * butt_l=NULL,*butt_c=NULL,*butt_q=NULL,*butt_a=NULL;
GtkWidget * image1=NULL;

void EcranAccueil()
{
    cadre_accueil=gtk_fixed_new();
    fenetre_accueil=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    butt_l=gtk_button_new_with_label("Se Connecter");
    butt_c=gtk_button_new_with_label("Creer un nouveau compte ");
    butt_a=gtk_button_new_with_label("Administration");
    butt_q=gtk_button_new_with_label("Quitter");
    image1=gtk_image_new_from_file("bienvenue.png");
    gtk_window_set_resizable(GTK_WINDOW(fenetre_accueil), FALSE);
    gtk_container_add(GTK_CONTAINER(fenetre_accueil),cadre_accueil);
    gtk_fixed_put(GTK_FIXED(cadre_accueil),image1,0,0);
    gtk_fixed_put(GTK_FIXED(cadre_accueil),butt_l,30,33);
    gtk_fixed_put(GTK_FIXED(cadre_accueil),butt_c,30,83);
    gtk_fixed_put(GTK_FIXED(cadre_accueil),butt_a,30,125);
    gtk_fixed_put(GTK_FIXED(cadre_accueil),butt_q,30,180);
    g_signal_connect(G_OBJECT(fenetre_accueil),"destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(butt_l),"clicked", G_CALLBACK(EcranLogin),NULL);
    g_signal_connect(G_OBJECT(butt_c),"clicked", G_CALLBACK(EcranCreation),NULL);
    g_signal_connect(G_OBJECT(butt_q),"clicked", G_CALLBACK(Quitter),NULL);
    g_signal_connect(G_OBJECT(butt_a),"clicked", G_CALLBACK(EcranLoginAdmin),NULL);
    gtk_window_set_title(GTK_WINDOW(fenetre_accueil),"Qui Veut Gagner des millions ? ");
    gtk_window_set_position(GTK_WINDOW(fenetre_accueil),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(fenetre_accueil),600,400);
    gtk_widget_show_all(fenetre_accueil);
}



void Quitter()
{
     GtkWidget * pMsg=NULL;
     pMsg = gtk_message_dialog_new (GTK_WINDOW(fenetre_accueil),GTK_DIALOG_MODAL,GTK_MESSAGE_OTHER, GTK_BUTTONS_YES_NO,
     "Voulez vous vraiment quitter ?");
      switch(gtk_dialog_run(GTK_DIALOG(pMsg)))
              {
              case GTK_RESPONSE_YES:  gtk_main_quit();break;
              case GTK_RESPONSE_NO:   gtk_widget_destroy(pMsg);break;
              }
}

