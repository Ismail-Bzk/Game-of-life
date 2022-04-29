#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "modele.h"
#include "vue.h"
#include "callbacks.h"
/*
 * Role : End the execution of the game
 */
void quit(Widget w, void *d) {
 exit(EXIT_SUCCESS);
}



/*
 * Role: reinitialiser la grille (toutes les cellules sont mortes)
   Role: reset grid (all cells are dead)
 */
void reinitialiser(Widget w, void *d) {
	initialiser(d);
	
	afficher(d);
	
}
/*
 * Rôle : Affiche la matrice dans la grille
   Role: Displays the matrix in the grid
 */
void afficher(data *d){
	ClearDrawArea();
	
	
	
	int *v = d-> m[0];
	
	for(int i=0;i<ml ;i++){
		for(int j=0;j <mc ;j++){
			if(*(v + j*mc +i)){
				DrawFilledBox(i*25, j*25,25,25);
			}
			else{
				DrawBox(i*25, j*25,25,25);
			}
		}
	}
}

/*
 * Rôle : callback Mode1's button ( affecting normal mode to the game)
 * Affecte le mode normal au jeu 
 * 
 */



void mode1(Widget w, void *d) {
	affectermode1(d);		
}
/*
 * Rôle : callback du bouton Mode2.
 * Affecte le mode "Day and night" au jeu 
  Role : callback Mode2's button ( affecting "Day and night" mode to the game )
 * 
 */
void mode2(Widget w, void *d) {
	affectermode2(d);
}



/*
 * Rôle : Laisser le jeu en boucle infinie
   Role: Leave the game in an infinite loop

 */
 void loop(void *d, XtIntervalId *id){
 	
 	int h;
	h=testermode(d);
	if (h==1){
		updateV1(d, ml, mc);
		}
	else if (h==2){
		updateV2(d, ml, mc);
		}
	
	afficher(d);
 	
 	AddTimeOut(1500,  (GeneralCB)loop, d);
	
}
/*
 * Rôle : callback du bouton Start.
 * Commencer la partie après avoir définir le mode du jeu et le fichier à lire
 * Cette fonction à la particularité de s'exécuter en boucle grace à l'appel de
 * la fonction AddTimeOut
 
 * Role: callback of the Start button.
  * Start the game after setting the game mode and file to play
  * This function has the particularity of being executed in a loop thanks to the call to
  * the AddTimeOut function
 */
void start(Widget w, void *d) {
	int h;
	h=testermode(d);
	if (h==1){
		updateV1(d, ml, mc);
		printf("mm\n");
		}
	else if (h==2){
		updateV2(d, ml, mc);
		}
	
	afficher(d);
	
	
	
	AddTimeOut(1500,  (GeneralCB)loop, d);
	 
}
/*
 * Rôle : callback du bouton Stable.
 * Lire la matrice se trouvant dans le fichier Stable  et l'affecter à la 
 * matrice qui represente la grille et enfin l'afficher sur la grille
 
 Role: callback Stable button .
  * Read the array from the Stable file and assign it to the
  * matrix that represents the grid and finally display it on the grid
  * 
 */

void fichier(Widget w, void *d) {
	
	FILE *fic;
	if((fic=fopen("Stable","r"))==NULL)	
		fprintf(stderr,"Fichier introuvable\n");
	else{
		lirefichier(d,fic);
	}
	
	fclose(fic);
	
	set_matrix(d);
	
	afficher(d);
	
}
/*
 * Rôle : callback du bouton Periodique.
 * Lire la matrice se trouvant dans le fichier Periodique  et l'affecter à la 
 * matrice qui represente la grille et enfin l'afficher sur la grille
 
  * Role: callback Periodic button .
  * Read the matrix found in the Periodic file and assign it to the
  * matrix that represents the grid and finally display it on the grid 
 * 
 */
void fichier2(Widget w, void *d) {
	
	FILE *fic;
	if((fic=fopen("Periodique","r"))==NULL)	
		fprintf(stderr,"Fichier introuvable\n");
	else{
		lirefichier(d,fic);
	}
	
	fclose(fic);
	
	set_matrix(d);
	
	afficher(d);
	
}
/*
 * Rôle : callback du bouton Vaisseaux.
 * Lire la matrice se trouvant dans le fichier Vaisseaux  et l'affecter à la 
 * matrice qui represente la grille et enfin l'afficher sur la grille
 			
 	Same thing to applied to Vaisseaux file
 * 
 */
void fichier3(Widget w, void *d) {
	
	FILE *fic;
	if((fic=fopen("Vaisseaux","r"))==NULL)	
		fprintf(stderr,"Fichier introuvable\n");
	else{
		lirefichier(d,fic);
	}
	
	fclose(fic);
	
	set_matrix(d);
	
	afficher(d);
	
}
/*
 * Rôle : callback du bouton Mathusalem.
 * Lire la matrice se trouvant dans le fichier Mathusalem  et l'affecter à la 
 * matrice qui represente la grille et enfin l'afficher sur la grille
 
 	Same thing to applied to Mathusalem file
 * 
 */
void fichier4(Widget w, void *d) {
	
	FILE *fic;
	if((fic=fopen("Mathusalem","r"))==NULL)	
		fprintf(stderr,"Fichier introuvable\n");
	else{
		lirefichier(d,fic);
	}
	
	fclose(fic);
	
	set_matrix(d);
	
	afficher(d);
	
}





