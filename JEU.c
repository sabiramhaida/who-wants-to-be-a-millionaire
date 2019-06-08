#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "Statistiques.c"
#include "JEU.h"
#include "QUESTION.h"
#include "joueur.h"
#include  "LOGIN.h"
extern int alea;
DonneeJ joueur_courant;
extern GtkWidget *fenetre_accueil;

Question q;
Question** MATRICE_DES_QUESTIONS;
int niveau;
int rep_alea[4];

// les elements de la fenetre menu du jeu
GtkWidget *butt_nouv_jeu,*butt_statistique_joueur,*butt_stat_global,*butt_supprimer,*butt_quitter;
GtkWidget *fenetre_menu_jeu,*cadre_menu_jeu;
GtkWidget * image2=NULL;*image_n25,*image_n50,*image_ns;
//element fenetre jeu
GtkWidget *fenetre_jeu,*cadre_jeu,*image_principale,*butt_rep[4],*label_rep[4],*label_ques,*butt_50,*butt_25,*butt_s,*butt_ab;
GtkWidget *image_50,*image_25,*image_s,*image_ab;
GtkWidget *image_non_50,*image_non_25,*image_non_s,*image_flech;

// les elements de la fenetre des statistiques du joueur ;
GtkWidget *fenetre_stat_j,*cadre_stat_j,*label_m_score,*label_somme_score,*label_nbr_pa;
GtkWidget *butt_ok_sj,*image_st_j;

GtkWidget * fenetre_a_question=NULL,* cadre_a_question=NULL;
GtkWidget *text_question,*text_reponse[3],*text_niveau,*text_reponse_proche,*text_reponse_correcte;
GtkWidget *label_question,*label_reponse,*label_niveau,*label_reponse_proche,*label_reponse_correcte;
GtkWidget *spin_niveau,*spin_reponse_correcte;
// les elements de la fennetre d'administration
GtkWidget * fenetre_admin=NULL;
GtkWidget * cadre_admin=NULL;
GtkWidget * butt_questions=NULL;
GtkWidget * butt_joueurs=NULL;
GtkWidget * butt_exit=NULL;
GtkWidget * supp_sta=NULL,*image3=NULL;

//pour la suppression de l'admin
GtkWidget * fenetre_admin_sup=NULL;
GtkWidget * cadre_admin_sup=NULL;
GtkWidget * label_info_sup,*label_nom_cmp,*text_nom_cmp;
GtkWidget * butt_ok_supprimer=NULL;
//ajout d'une Question:
GtkWidget * text_nom_Q=NULL,*text_reponsea1=NULL,*text_reponsea2=NULL,*text_reponsea3=NULL,*text_reponsea4=NULL;
GtkWidget * label_question,*label_reponses,*label_reponse_corr,*label_NiV;
GtkWidget * fenetre_ajout_ =NULL,*cadre_ajout=NULL,*butt_ok_ajouter=NULL,*text_corr=NULL,*text_Niv=NULL;
int utilise_50,utilise_25,utilise_s;
int prix[16]={0,200,300,500,800,1500,3000,6000,12000,24000,48000,72000,100000,150000,300000,1000000};
const char alp[4]="ABCD";
int nbr_reponse_juste[15];
char text_span_1[100]="<span foreground=\"#FFFFFF\" ><b>",text_span_2[30]="</b></span>";

char text_span_3[100]="<span foreground=\"#000000\" ><b>";
int cpt;
int indice[NOMBRE_NIVEAU];

void MenuAdministration()
{
    fenetre_admin=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    cadre_admin=gtk_fixed_new();
    gtk_window_set_resizable(GTK_WINDOW(fenetre_admin), FALSE);
    gtk_window_set_modal(GTK_WINDOW(fenetre_admin),TRUE);
    gtk_container_add(GTK_CONTAINER(fenetre_admin),cadre_admin);
    image3=gtk_image_new_from_file("MenuAdmin.png");
    butt_questions=gtk_button_new_with_label("AJouter une Question");
    butt_joueurs=gtk_button_new_with_label("Supprimer Un joueur ");
    butt_exit=gtk_button_new_with_label("Quitter ");
    gtk_fixed_put(GTK_FIXED(cadre_admin),image3,0,0);
    gtk_container_add(GTK_CONTAINER(fenetre_menu_jeu),cadre_menu_jeu);
    

    gtk_fixed_put(GTK_FIXED(cadre_admin),butt_questions,60,160);
    gtk_fixed_put(GTK_FIXED(cadre_admin),butt_joueurs,60,220);
    gtk_fixed_put(GTK_FIXED(cadre_admin),butt_exit,60,400);
    gtk_widget_set_usize(butt_questions,350,50);
    gtk_widget_set_usize(butt_joueurs,350,50);
    gtk_widget_set_usize(supp_sta,350,50);
    gtk_widget_set_usize(butt_exit,350,50);
    gtk_window_set_title(GTK_WINDOW(fenetre_admin),"Menu de Gestion ");
    gtk_window_set_position(GTK_WINDOW(fenetre_admin),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(fenetre_admin),50,50);
    g_signal_connect(G_OBJECT(butt_joueurs),"clicked", G_CALLBACK(EcranSuppression),NULL);
    g_signal_connect(G_OBJECT(butt_questions),"clicked", G_CALLBACK(EcranAjoutQuestion),NULL);
    
    g_signal_connect(G_OBJECT(butt_exit),"clicked", G_CALLBACK(QuitterAdmin),NULL);
    gtk_widget_show_all(fenetre_admin);
}

void EcranSuppression()
{
     label_info_sup=gtk_label_new("Entrer le nom du\n compte a supprimer  ");
     label_nom_cmp=gtk_label_new(" Nom du compte :");
     text_nom_cmp=gtk_entry_new();
     fenetre_admin_sup=gtk_window_new(GTK_WINDOW_TOPLEVEL);
     cadre_admin_sup=gtk_fixed_new();
     butt_ok_supprimer=gtk_button_new_with_label("supprimer");
     gtk_container_add(GTK_CONTAINER(fenetre_admin_sup),cadre_admin_sup);
     gtk_fixed_put(GTK_FIXED(cadre_admin_sup),label_info_sup,0,0);
     gtk_fixed_put(GTK_FIXED(cadre_admin_sup),label_nom_cmp,15,45);
     gtk_fixed_put(GTK_FIXED(cadre_admin_sup),text_nom_cmp,90,42);
     gtk_fixed_put(GTK_FIXED(cadre_admin_sup),butt_ok_supprimer,130,150);
     gtk_entry_set_max_length (GTK_ENTRY(text_nom_cmp),15);
     gtk_window_set_title(GTK_WINDOW(fenetre_admin_sup),"suppression d'un compte ");
     gtk_window_set_position(GTK_WINDOW(fenetre_admin_sup),GTK_WIN_POS_CENTER);
     gtk_window_set_default_size(GTK_WINDOW(fenetre_admin_sup),300,200);
     gtk_window_set_modal(GTK_WINDOW(fenetre_admin_sup),TRUE);
     gtk_window_set_modal(GTK_WINDOW(fenetre_admin),FALSE);
     g_signal_connect(G_OBJECT(butt_ok_supprimer),"clicked", G_CALLBACK(suppressionjoueur),NULL);
     gtk_widget_show_all(fenetre_admin_sup);

}
void EcranAjoutQuestion()
{
    label_question=gtk_label_new("Entrer La Question ");
    label_reponses=gtk_label_new("Entrer Les Reponses");
    label_reponse_corr= gtk_label_new("correcte ? (0-3)");
    label_NiV=gtk_label_new("Niveau?(1-15)");

    fenetre_ajout_=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fenetre_ajout_),"L'Ajout d'un Question");
    cadre_ajout=gtk_fixed_new();
    butt_ok_ajouter=gtk_button_new_with_label("AJouter");

    text_nom_Q=gtk_entry_new();
    text_reponsea1=gtk_entry_new();
    text_reponsea2=gtk_entry_new();
    text_reponsea3=gtk_entry_new();
    text_reponsea4=gtk_entry_new();
    text_corr=gtk_entry_new();
    text_Niv=gtk_entry_new();

    gtk_container_add(GTK_CONTAINER(fenetre_ajout_),cadre_ajout);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),butt_ok_ajouter,250,495);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),label_question,15,0);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),label_reponses,15,100);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),label_reponse_corr,15,300);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),label_NiV,15,400);    
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_nom_Q,15,50);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_reponsea1,15,120);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_reponsea2,15,160);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_reponsea3,15,200);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_reponsea4,15,240);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_corr,0,360);
    gtk_fixed_put(GTK_FIXED(cadre_ajout),text_Niv,0,480);
    gtk_window_set_position(GTK_WINDOW(fenetre_ajout_),GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(fenetre_ajout_),300,500);
    gtk_widget_set_usize(text_nom_Q,400,30);
    gtk_widget_set_usize(text_reponsea1,100,30);
    gtk_widget_set_usize(text_reponsea2,100,30);
    gtk_widget_set_usize(text_reponsea3,100,30);
    gtk_widget_set_usize(text_reponsea4,100,30);
    gtk_widget_set_usize(text_corr,50,30);
    gtk_widget_set_usize(text_Niv,50,30);

    gtk_widget_set_usize(text_nom_Q,350,20);
    gtk_window_set_modal(GTK_WINDOW(fenetre_ajout_),TRUE);
    gtk_window_set_modal(GTK_WINDOW(fenetre_admin),FALSE);
    g_signal_connect(G_OBJECT(butt_ok_ajouter),"clicked", G_CALLBACK(AjouterQuestionE),NULL);
    gtk_widget_show_all(fenetre_ajout_);
}


void QuitterAdmin()
{
  gtk_widget_destroy(fenetre_admin);
}


void QuitterMenuJeu()
{
   if(msgbox2(fenetre_menu_jeu,"Voulez vous vraiment quitter le menu du jeu ?")==1)
   {
       gtk_widget_destroy(fenetre_menu_jeu);
   }
}


void MenuJeu()
{
fenetre_menu_jeu=gtk_window_new(GTK_WINDOW_TOPLEVEL);
cadre_menu_jeu=gtk_fixed_new();
gtk_window_set_title(GTK_WINDOW(fenetre_menu_jeu),"Menu du jeu");
gtk_window_set_modal(GTK_WINDOW(fenetre_menu_jeu),TRUE);
gtk_window_set_resizable(GTK_WINDOW(fenetre_menu_jeu), FALSE);
gtk_container_add(GTK_CONTAINER(fenetre_menu_jeu),cadre_menu_jeu);
image2=gtk_image_new_from_file("MenuJeu.png");
butt_nouv_jeu=gtk_button_new_with_label("jouer ");
butt_statistique_joueur=gtk_button_new_with_label("Mes statistiques");
butt_stat_global=gtk_button_new_with_label("Statistique globale");
butt_supprimer=gtk_button_new_with_label("Supprimer mon compte");
butt_quitter=gtk_button_new_with_label("Quitter");
gtk_fixed_put(GTK_FIXED(cadre_menu_jeu),image2,0,0);
gtk_fixed_put(GTK_FIXED(cadre_menu_jeu),butt_nouv_jeu,60,160);
gtk_fixed_put(GTK_FIXED(cadre_menu_jeu),butt_statistique_joueur,60,220);
gtk_fixed_put(GTK_FIXED(cadre_menu_jeu),butt_stat_global,60,280);
gtk_fixed_put(GTK_FIXED(cadre_menu_jeu),butt_supprimer,60,340);
gtk_fixed_put(GTK_FIXED(cadre_menu_jeu),butt_quitter,60,400);
gtk_window_set_position(GTK_WINDOW(fenetre_menu_jeu),GTK_WIN_POS_CENTER);
gtk_widget_set_usize(butt_nouv_jeu,350,50);
gtk_widget_set_usize(butt_statistique_joueur,350,50);
gtk_widget_set_usize(butt_stat_global,350,50);
gtk_widget_set_usize(butt_supprimer,350,50);
gtk_widget_set_usize(butt_quitter,350,50);

g_signal_connect(G_OBJECT(butt_nouv_jeu),"clicked", G_CALLBACK(EcranJeu),NULL);
g_signal_connect(G_OBJECT(butt_statistique_joueur),"clicked", G_CALLBACK(EcranMesStatistiques),NULL);
g_signal_connect(G_OBJECT(butt_quitter),"clicked", G_CALLBACK(QuitterMenuJeu),NULL);

//g_signal_connect(G_OBJECT(butt_stat_global),"clicked", G_CALLBACK(EcranStatistiquesGlobale),NULL);

g_signal_connect(G_OBJECT(butt_supprimer),"clicked", G_CALLBACK(SuppressionduCompte),NULL);
gtk_widget_show_all(fenetre_menu_jeu);
}

void finJeu()
{
GtkWidget *pQuestion;
if(prix[niveau-1]<200)
{

    msgbox1(fenetre_jeu,"vous avez gagné 0 DH");
    

}
else if(prix[niveau-1]<1500)
{

    msgbox1(fenetre_jeu," vous avez gagné 200DH");
    if(joueur_courant.MeilleurScoreJoueur<200){ joueur_courant.MeilleurScoreJoueur=200;  Sauvegarder(FICHIER_JOUEUR);}
   
}
else if(prix[niveau-1]<48000)
{
    msgbox1(fenetre_jeu," vous avez gagné 1500DH");
    if(joueur_courant.MeilleurScoreJoueur<1500){ joueur_courant.MeilleurScoreJoueur=1500;Sauvegarder(FICHIER_JOUEUR);}
    

}
else if((prix[niveau-1])<1000000)
{
    msgbox1(fenetre_jeu," vous avez gagné 48000DH");
    if(joueur_courant.MeilleurScoreJoueur<48000){ joueur_courant.MeilleurScoreJoueur=48000;Sauvegarder(FICHIER_JOUEUR);}
    
}
else
{ 
   msgbox1(fenetre_jeu,"felicitations,vous avez gagner Un MILLION ") ;
    joueur_courant.MeilleurScoreJoueur=1000000;
    Sauvegarder(FICHIER_JOUEUR);
}
gtk_widget_destroy(fenetre_jeu);
//supprimer_sauvegarde();
}


void EcranJeu(GtkButton *button,gpointer data)
{
char exp[300];
int rep=0;
int i;
joueur_courant.NombreDeParties++;
for(i=0;i<15;i++)
{
nbr_reponse_juste[i]=0;
}
MATRICE_DES_QUESTIONS=(Question**)malloc(15*sizeof(Question*));
for(int i=0 ; i<NOMBRE_NIVEAU;i++)
      {
         MATRICE_DES_QUESTIONS[i]=(Question*)malloc(NOMBRE_QUESTIONS_PAR_NIVEAU*sizeof(Question));
      }

int fuck=0;

   char line[400];

   for(int i=0;i<NOMBRE_NIVEAU;i++)
   {
   indice[i]=0;
   }
   static const char filename[] = "LQuestions.txt";
   FILE *file = fopen ( filename, "r" );
   Question *Q;
   if ( file != NULL )
   { 
      while ( feof(file)==0 && fuck!=45)
      {
        Q=(Question*)malloc(sizeof(Question));
      for(int k=0;k<7;k++)

      {
        fgets ( line, sizeof line, file );
      switch(k){
        case 0:
          strcpy((char*)Q->Texte,line);
          //printf("%s\n", Q->Texte);
          break;
        case 1:
          strcpy((char*)Q->Reponses[0],line);
          //printf("%s\n",Q->Reponses[0]);
          break;
        case 2:
          strcpy((char*)Q->Reponses[1],line);
          //printf("%s\n",Q->Reponses[1]);
          break;
        case 3:
          strcpy((char*)Q->Reponses[2],line);

          //printf("%s\n",Q->Reponses[2]);
          break;
        case 4:
          strcpy((char*)Q->Reponses[3],line);
          //printf("%s\n",Q->Reponses[3]);
          break;
        case 5:
          Q->Correcte=atoi(line);
          break;
      case 6:
          Q->Niveau=atoi(line);
          break;
      
      }
      if(k==6)
      {fuck++;
       MATRICE_DES_QUESTIONS[Q->Niveau-1][indice[Q->Niveau-1]]= *Q;
      }
      }
      indice[Q->Niveau-1]++;
      
      }
      fclose ( file );
   }
   else
   {
      perror ( filename ); 
   }

fenetre_jeu=gtk_window_new(GTK_WINDOW_TOPLEVEL);
cadre_jeu=gtk_fixed_new();
gtk_window_set_title(fenetre_jeu,"Course Au Million");
gtk_window_set_modal(GTK_WINDOW(fenetre_jeu),TRUE);
gtk_window_set_modal(GTK_WINDOW(fenetre_menu_jeu),FALSE);
gtk_window_set_decorated(GTK_WINDOW(fenetre_jeu),TRUE);
gtk_window_set_position(GTK_WINDOW(fenetre_jeu),GTK_WIN_POS_CENTER);
gtk_container_add(GTK_CONTAINER(fenetre_jeu),cadre_jeu);
image_principale=gtk_image_new_from_file("imageprincipale.png");
image_50=gtk_image_new_from_file("Joker50.png");
image_25=gtk_image_new_from_file("Joker25.png");
image_s=gtk_image_new_from_file("Jokerswitch.png");
image_ab=gtk_image_new_from_file("Abandonner.png");
image_n50=gtk_image_new_from_file("nJoker50.png");
image_n25=gtk_image_new_from_file("nJoker25.png");
image_ns=gtk_image_new_from_file("nJokerswitch.png");

image_non_50=gtk_image_new_from_file("ok.png");
image_flech=gtk_image_new_from_file("banner.png");



butt_50=gtk_button_new();
butt_25=gtk_button_new();
butt_s=gtk_button_new();
butt_ab=gtk_button_new();
gtk_fixed_put(GTK_FIXED(cadre_jeu),image_principale,0,0);

for(i=0;i<4;i++)
{

label_rep[i]=gtk_label_new(NULL);
butt_rep[i]=gtk_button_new();
}
label_ques=gtk_label_new(NULL);
gtk_fixed_put(GTK_FIXED(cadre_jeu),image_principale,0,0);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_50,150,17);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_25,250,17);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_s,350,17);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_ab,19,7);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_rep[0],60,430);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_rep[1],430,430);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_rep[2],60,490);
gtk_fixed_put(GTK_FIXED(cadre_jeu),butt_rep[3],430,490);
gtk_fixed_put(GTK_FIXED(cadre_jeu),label_rep[0],62,440);
gtk_fixed_put(GTK_FIXED(cadre_jeu),label_rep[1],432,440);
gtk_fixed_put(GTK_FIXED(cadre_jeu),label_rep[2],62,500);
gtk_fixed_put(GTK_FIXED(cadre_jeu),label_rep[3],432,500);
gtk_fixed_put(GTK_FIXED(cadre_jeu),label_ques,80,370);

gtk_fixed_put(GTK_FIXED(cadre_jeu),image_50,148,7);
gtk_fixed_put(GTK_FIXED(cadre_jeu),image_25,248,7);
gtk_fixed_put(GTK_FIXED(cadre_jeu),image_s,350,7);

gtk_fixed_put(GTK_FIXED(cadre_jeu),image_ab,19,7);

gtk_widget_hide(image_flech);
gtk_widget_hide(image_n25);
gtk_widget_hide(image_n50);
gtk_widget_hide(image_ns);
for(i=0;i<4;i++)
{
gtk_widget_set_usize(butt_rep[i],232,38);
gtk_label_set_use_markup(GTK_LABEL(label_rep[i]), TRUE);
}
gtk_widget_set_usize(butt_50,57,20);
gtk_widget_set_usize(butt_25,57,20);
gtk_widget_set_usize(butt_s,57,20);
gtk_widget_set_usize(butt_ab,100,40);
gtk_window_set_modal(GTK_WINDOW(fenetre_menu_jeu),FALSE);

gtk_window_set_position(GTK_WINDOW(fenetre_jeu),GTK_WIN_POS_CENTER);
niveau=1;

g_signal_connect(G_OBJECT(butt_rep[0]),"pressed", G_CALLBACK(button_a_clique),NULL);
g_signal_connect(G_OBJECT(butt_rep[1]),"pressed", G_CALLBACK(button_b_clique),NULL);
g_signal_connect(G_OBJECT(butt_rep[2]),"pressed", G_CALLBACK(button_c_clique),NULL);
g_signal_connect(G_OBJECT(butt_rep[3]),"pressed", G_CALLBACK(button_d_clique),NULL);
g_signal_connect(G_OBJECT(butt_s),"pressed", G_CALLBACK(switch_clique),NULL);

g_signal_connect(G_OBJECT(butt_50),"pressed", G_CALLBACK(butt_50_clique),NULL);
g_signal_connect(G_OBJECT(butt_25),"pressed", G_CALLBACK(butt_25_clique),NULL);

g_signal_connect(G_OBJECT(butt_ab),"pressed", G_CALLBACK(AbandonnerLaPartie),NULL);
init_question();
gtk_widget_show_all(fenetre_jeu);

}

void AbandonnerLaPartie()
{
    char str[100];
    joueur_courant.MeilleurScoreJoueur=prix[niveau-1];
    Sauvegarder(FICHIER_JOUEUR);
    sprintf(str,"Vous avez abandonné, vous avez gagné %d DH . Bsse7a ",prix[niveau-1]);
    msgbox1(fenetre_jeu,str);
    gtk_widget_destroy(fenetre_jeu);
}


void init_question()
{
char str[400],exp[450];
int i;
utilise_50=VALIDE;
utilise_25=VALIDE;
utilise_s=VALIDE;
q=QuestionAleatoire(MATRICE_DES_QUESTIONS);


char UTF8[500];
strcpy(UTF8,(char*)g_locale_to_utf8(q.Texte, -1, NULL, NULL, NULL));
sprintf(exp,"%s%s%s",text_span_1,UTF8,text_span_2);
gtk_label_set_text(GTK_LABEL(label_ques),exp);
gtk_label_set_use_markup(GTK_LABEL(label_ques), TRUE);
int rep_alea[4]={0,1,2,3};

for(i=0;i<4;i++)
{
printf("%s\n",q.Reponses[i] );
strcpy(UTF8,(char*)g_locale_to_utf8(q.Reponses[i], -1, NULL, NULL, NULL));
sprintf(exp,"%s%s%s",text_span_3,UTF8,text_span_2);
gtk_label_set_text(GTK_LABEL(label_rep[i]),exp);
gtk_label_set_use_markup(GTK_LABEL(label_rep[i]), TRUE);
}
for(i=0;i<4;i++)
{
gtk_widget_show(butt_rep[i]);
gtk_widget_show(label_rep[i]);
gtk_fixed_put(GTK_FIXED(cadre_jeu),image_flech,485,344);
	gtk_fixed_move(GTK_FIXED(cadre_jeu),image_flech,485,(344-21.2*niveau));
	gtk_widget_show(image_flech);

}

}


void EcranMesStatistiques()
{
    char exp[300];
    _Bool ok= FALSE;
    fenetre_stat_j=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    cadre_stat_j=gtk_fixed_new();
    butt_ok_sj=gtk_button_new_with_label("  fermer  ");
    image_st_j=gtk_image_new_from_file("votre-statistiques.jpg");
    gtk_window_set_modal(GTK_WINDOW(fenetre_stat_j),TRUE);
    gtk_window_set_modal(GTK_WINDOW(fenetre_menu_jeu),FALSE);
    gtk_window_set_position(GTK_WINDOW(fenetre_stat_j),GTK_WIN_POS_CENTER);
    gtk_window_set_decorated(GTK_WINDOW(fenetre_stat_j),FALSE);
    gtk_container_add(GTK_CONTAINER(fenetre_stat_j),cadre_stat_j);
    label_m_score=gtk_label_new("");
    label_nbr_pa=gtk_label_new("");
    label_somme_score=gtk_label_new("");
    sprintf(exp,"<span foreground=\"white\" font=\"Times New Roman italic 12\" size=\"xx-large\" > %d </span>",joueur_courant.NombreDeParties);
    gtk_label_set_text(GTK_LABEL(label_nbr_pa),exp);
    gtk_label_set_use_markup(GTK_LABEL(label_nbr_pa), TRUE);
    sprintf(exp,"<span foreground=\"white\" font=\"Times New Roman italic 12\"size=\"xx-large\" > %d DH </span>",joueur_courant.MeilleurScoreJoueur);
    gtk_label_set_text(GTK_LABEL(label_m_score),exp);
    gtk_label_set_use_markup(GTK_LABEL(label_m_score), TRUE);
    gtk_fixed_put(GTK_FIXED(cadre_stat_j),image_st_j,0,0);
    gtk_fixed_put(GTK_FIXED(cadre_stat_j),label_nbr_pa,420,120);
    gtk_fixed_put(GTK_FIXED(cadre_stat_j),label_m_score,420,270);
    gtk_fixed_put(GTK_FIXED(cadre_stat_j),butt_ok_sj,525,0);
    g_signal_connect(G_OBJECT(butt_ok_sj),"clicked", G_CALLBACK(QuitterMesStatistiques),NULL);
    gtk_widget_show_all(fenetre_stat_j);

}
void QuitterMesStatistiques()
{
    gtk_window_set_modal(GTK_WINDOW(fenetre_menu_jeu),TRUE);
    gtk_widget_destroy(fenetre_stat_j);
}

void SuppressionduCompte()
{
  if(msgbox2(fenetre_menu_jeu,"Vous Confirmer la suppression ?")==1)
  {
	
  SupprimerCompte(FICHIER_JOUEUR,joueur_courant.Nom);
  gtk_window_set_modal(GTK_WINDOW(fenetre_menu_jeu),FALSE);
  gtk_widget_destroy(fenetre_menu_jeu);
  }
}

void suppressionjoueur()
{
  if(msgbox2(fenetre_admin_sup,"Vous Confirmer la suppression ?")==1)
  {
	strcpy(joueur_courant.Nom,text_nom_cmp);
  SupprimerCompte(FICHIER_JOUEUR,joueur_courant.Nom);
  gtk_window_set_modal(GTK_WINDOW(fenetre_admin_sup),FALSE);
  gtk_widget_destroy(fenetre_admin_sup);
  }
}

void AjouterQuestionE(){
    Question q;
    strcpy(q.Texte,(char *)gtk_entry_get_text(GTK_ENTRY(text_nom_Q)));
    strcpy(q.Reponses[0],(char *)gtk_entry_get_text(GTK_ENTRY(text_reponsea1)));
    strcpy(q.Reponses[0],(char *)gtk_entry_get_text(GTK_ENTRY(text_reponsea2)));
    strcpy(q.Reponses[0],(char *)gtk_entry_get_text(GTK_ENTRY(text_reponsea3)));
    strcpy(q.Reponses[0],(char *)gtk_entry_get_text(GTK_ENTRY(text_reponsea4)));
    strcpy(q.Correcte,(int)gtk_entry_get_text(GTK_ENTRY(text_corr)));    
    strcpy(q.Niveau,(int)gtk_entry_get_text(GTK_ENTRY(text_Niv)));
  if(msgbox2(fenetre_ajout_,"Vous Confirmer l'ajout ?")==1)
  {
  AjouterQuestion(q,FICHIER_QUESTION);
  gtk_window_set_modal(GTK_WINDOW(fenetre_ajout_),FALSE);
  gtk_widget_destroy(fenetre_ajout_);

  }
}

void button_a_clique()
{
    GtkWidget *pQuestion;
    char exp[300];
    int i,ind_rech;
    if(q.Correcte==0)
    {
     msgbox1(fenetre_jeu,"Bravo! C'est correcte");
     niveau++;
     nbr_reponse_juste[niveau-1]++;
    if(niveau==16)
    {
        finJeu();   
    }
    else
    {

      init_question();

    }

    }
    else
    {
        sprintf(exp,"Reponse fausse,la reponse correcte est :%s",q.Reponses[q.Correcte]);
        msgbox(fenetre_jeu,exp);
        finJeu();
    }



}

void button_b_clique()
{
    GtkWidget *pQuestion;
    char exp[300];
    int i,ind_rech;
    if(q.Correcte==1)
    {
     msgbox1(fenetre_jeu,"Bravo! C'est correcte");
     nbr_reponse_juste[niveau-1]++;
     niveau++;
    if(niveau==16)
    {
        
        finJeu();
    }
    else
    {

      init_question();

    }

    }
    else
    {
        sprintf(exp,"Reponse fausse,la reponse correcte est :%s",q.Reponses[q.Correcte]);
        msgbox(fenetre_jeu,exp);
        finJeu();
    }



}

void button_c_clique()
{
    GtkWidget *pQuestion;
    char exp[300];
    int i,ind_rech;
    if(q.Correcte==2)
    {
     msgbox1(fenetre_jeu,"Bravo! C'est correcte");
    nbr_reponse_juste[niveau-1]++;
    niveau++;
    if(niveau==16)
    {
        finJeu();

    }
    else
    {

      init_question();
    }

    }
    else
    {
        sprintf(exp,"Reponse fausse,la reponse correcte est :%s",q.Reponses[q.Correcte]);
        msgbox(fenetre_jeu,exp);
        finJeu();
    }


}
void button_d_clique()
{
    GtkWidget *pQuestion;
    char exp[300];
    int i,ind_rech;
    if(q.Correcte==3)
    {
     msgbox1(fenetre_jeu,"Bravo! C'est correcte");
     nbr_reponse_juste[niveau-1]++;
     niveau++;
    if(niveau==16)
    {
        finJeu();

    }
    else
    {

      init_question();
    }

    }
    else
    {
        sprintf(exp,"Reponse fausse,la reponse correcte est :%s",q.Reponses[q.Correcte]);
        msgbox(fenetre_jeu,exp);
       finJeu();
    }

}

void switch_clique()
{
char str[400],exp[450];
int q_rand;
int i;
utilise_50=VALIDE;
utilise_25=VALIDE;
utilise_s=INVALIDE;
gtk_widget_hide(image_s);
gtk_widget_hide(butt_s);
gtk_fixed_put(GTK_FIXED(cadre_jeu),image_ns,350,7);
gtk_widget_show(image_ns);
msgbox1(fenetre_jeu,"joker SWITCH");
q=MATRICE_DES_QUESTIONS[q.Niveau-1][(alea+1)%3];
char UTF8[500];
strcpy(UTF8,(char*)g_locale_to_utf8(q.Texte, -1, NULL, NULL, NULL));
sprintf(exp,"%s%s%s",text_span_1,UTF8,text_span_2);
gtk_label_set_text(GTK_LABEL(label_ques),exp);
gtk_label_set_use_markup(GTK_LABEL(label_ques), TRUE);
int rep_alea[4]={0,1,2,3};

for(i=0;i<4;i++)
{
printf("%s\n",q.Reponses[i] );
strcpy(UTF8,(char*)g_locale_to_utf8(q.Reponses[i], -1, NULL, NULL, NULL));
sprintf(exp,"%s%s%s",text_span_3,UTF8,text_span_2);
gtk_label_set_text(GTK_LABEL(label_rep[i]),exp);
gtk_label_set_use_markup(GTK_LABEL(label_rep[i]), TRUE);
}
for(i=0;i<4;i++)
{
gtk_widget_show(butt_rep[i]);
gtk_widget_show(label_rep[i]);
}
}

void butt_50_clique()
{
    utilise_50=INVALIDE;
    GtkWidget *pQuestion;
    int i;
    gtk_widget_hide(image_50);
    gtk_widget_hide(butt_50);
    gtk_fixed_put(GTK_FIXED(cadre_jeu),image_n50,150,7);
    gtk_widget_show(image_n50);
    msgbox1(fenetre_jeu,"le joker 50");
    gtk_widget_hide(label_rep[(q.Correcte+3)%4]);
    gtk_widget_hide(butt_rep[(q.Correcte+3)%4]);
    gtk_widget_hide(label_rep[(q.Correcte+1)%4]);
    gtk_widget_hide(butt_rep[(q.Correcte+1)%4]);
}
void butt_25_clique()
{
    utilise_25=INVALIDE;
    GtkWidget *pQuestion;
    int i;
    gtk_widget_hide(image_25);
    gtk_widget_hide(butt_25);
    gtk_fixed_put(GTK_FIXED(cadre_jeu),image_n25,250,7);
    gtk_widget_show(image_n25);
    msgbox1(fenetre_jeu,"le joker 25");
    gtk_widget_hide(label_rep[(q.Correcte+2)%4]);
    gtk_widget_hide(butt_rep[(q.Correcte+2)%4]);
}
