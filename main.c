#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gtk/gtk.h>
#include "ACCUEIL.h"
#include "joueur.h"
#include "QUESTION.h"
#include "LOGIN.h"
int main(int argc, char **argv)
{   /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);
    EcranAccueil();
    gtk_main();
    return EXIT_SUCCESS;
}
