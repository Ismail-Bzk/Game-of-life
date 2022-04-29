/*
 * cette vue fabrique l’interface graphique à l’aide
 * de la bibliothèque libsx
 *
 * @author: Vincent GranetVincent.Granet@univ−cotedazur.fr
 * Creation @date: 29−Apr−2020 21:05
 * Last file update: 28−May−2020 11:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "modele.h"
#include "callbacks.h"





/* Rôle: création et assemblage des widgets */
void init_display(int argc, char *argv[], void *d)
{
	  Widget BQuit, BMode2, BMode1, grille,BStart,Bfichier,Bfichier2,Bfichier3,Bfichier4,Breinitialiser;
// créer les composants graphiques
 	BQuit = MakeButton(" Quitter ", quit, NULL);
 	BMode1= MakeButton(" Normal mode ", mode1, d);
 	BMode2= MakeButton(" Day and night mode ", mode2, d);
 	BStart= MakeButton(" Start ", start, d);
 	Bfichier= MakeButton(" Stable ", fichier, d);
 	Bfichier2= MakeButton(" Periodique ", fichier2, d);
 	Bfichier3= MakeButton(" Vaisseaux ", fichier3, d);
 	Bfichier4= MakeButton(" Mathusalem ", fichier4, d);
 	Breinitialiser= MakeButton(" Reinitialiser ", reinitialiser, d);
 	
 	grille=MakeDrawArea(200, 300, NULL, NULL);
 	//ZoneSaisie = MakeStringEntry(NULL, TAILLEZONESAISIE, NULL, NULL);
 	
// assembler les composants graphiques
 		
 	
 	SetWidgetPos(BMode1, PLACE_RIGHT, grille, NO_CARE, NULL);
	SetWidgetPos(BMode2, PLACE_RIGHT, BMode1, NO_CARE, NULL);
	SetWidgetPos(Bfichier, PLACE_UNDER, BMode1,PLACE_RIGHT, grille);
	SetWidgetPos(Bfichier2, PLACE_UNDER, BMode2, PLACE_RIGHT, Bfichier);
	SetWidgetPos(Bfichier3, PLACE_UNDER, Bfichier, PLACE_RIGHT, grille);
	SetWidgetPos(Bfichier4, PLACE_UNDER, Bfichier2, PLACE_RIGHT, Bfichier3);
	
	SetWidgetPos(BQuit, PLACE_UNDER, grille, NO_CARE, NULL);
	SetWidgetPos(BStart, PLACE_UNDER, grille, PLACE_RIGHT, BQuit);
	SetWidgetPos(Breinitialiser, PLACE_UNDER, grille, PLACE_RIGHT, BStart);
	
// pour gérer les couleurs
 	GetStandardColors();
// pour afficher l’interface
 	ShowDisplay();
}

