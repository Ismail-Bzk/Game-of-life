
#include <stdlib.h>
#include <stdio.h>
#include "modele.h"
/* Rôle :  affecte la matrice lue dans fichier à la matrice qui  représente la grille

	Role: assigns the matrix read from file to the matrix that represents the grid
 */
void set_matrix(data *d){

	int*m=d->m[0];
	int *s = d->s[0];
	
     for(int i=0;i<ligne; i++){
          for(int j=0;j<colonne; j++){
             *(m+ i*mc +j)= *(s+ (i)*colonne +(j));
          }
     }

}
/*
 * Rôle : Calculer le nombre de voisins d'une cellule et appliquer les regles du jeu
 
 Role: Calculate the number of neighbors of a cell and apply the rules of the game
 */
    
int update_cell1(int *m, const int ipos,const int jpos,const int l,const int c){
    int nb=0; // counter
    int i,j;
    //Computes the number of nreighbors
    for(i=ipos-1;i<=ipos+1;i++){
    // on vérife qu'on dépasse pas les bornes
    // Check limits
        if(i>=0 && i<l){
            for(j=jpos-1;j<=jpos+1;j++){
            // on reteste les bornes
                if(j>=0 && j<c){
                	// on exclut la cellule dont on veur calculer le nouvel état
                    if(i!=ipos || j!=jpos){
                    // si la cellule est vivante ,on incrémente le compteur
                    // if the cell is alive , then we increase the couter
                        if(*(m+ i*c +j)==alive){
                            nb++;
                        }
                    }
                }
            }      
        }
    }
    // on applique les conditions du jeu (mode normal)
    // rules od normal mode
    if(*(m+ ipos*c +jpos)==alive){
        if(nb==2|| nb==3){
            return alive;
        }
        else{
            return dead;
        }
    }
    else{
        if(nb==3){
            return alive;
        }
        else{
            return dead;
        }
    }
}    
/*
 * Rôle : Calculer le nombre de voisins d'une cellule et appliquer les regles du jeu (Day an night)
 */
int update_cell2(int *m, const int ipos,const int jpos,const int l,const int c){

    int nb=0; // on  intialise la variable qui joue le role d'un compteur
    int i,j;
    //calcul du nombre de voisins
    for(i=ipos-1;i<=ipos+1;i++){
    // on vérife qu'on dépasse pas les bornes
        if(i>=0 && i<l){
            for(j=jpos-1;j<=jpos+1;j++){
            // on reteste les bornes
                if(j>=0 && j<c){
                	
                	// on exclut la cellule dont on veut calculer le nouvel état
                    if(i!=ipos || j!=jpos){
                    // si la cellule est vivante ,on incrémente le compteur
                        if(*(m+ i*c +j)==alive){
                            nb++;
                        }
                    }
                }
            }      
        }
    }
    // on applique les conditions du jeu (mode Day and night)
    if(*(m+ ipos*c +jpos)==alive){
        if(nb==3|| nb==4 || nb==6|| nb==7|| nb==8) {
            return alive;
        }
        else{
            return dead;
        }
    }
    else{
        if(nb==3 || nb==6|| nb==7|| nb==8){
            return alive;
        }
        else{
            return dead;
        }
    }
}
    
/*
 * 
 * Rôle : Mettre à jour la matrice m qui represente la grille
 */
void updateV1(data *d, const int l, const int c){
	int *m= d->m[0];
	int *bis = d->bis[0];
	
	// parcourir les lignes et les colonnes
     for(int i=0;i<l; i++){
          for(int j=0;j<c; j++){
          	
              //calculer les nombres des voisins et et faire la mise à jour
              // à jour dans la matrice bis
              *(bis + i*c +j)= update_cell1(m,i,j,l,c); //bis[i][j]
          }
     }
     // recopier la matrice bis qui contient la mise à jour dans la matrice m
     for(int i=0;i<l; i++){
          for(int j=0;j<c; j++){
              // m[i][j] = bis[i][j] 
              *(m + i*c +j)= *(bis + i*c +j); 
          }
     }
}    
/*
 * Rôle : Mettre à jour la matrice m qui represente la grille selon les 
 *	  les règle de "Day and night)
 */
void updateV2(data *d, const int l, const int c){
	int *m= d->m[0];
	int *bis = d->bis[0];
	// parcourir les lignes et les colonnes
	for(int i=0;i<l; i++){
          for(int j=0;j<c; j++){
          //calculer les nombres des voisins et et faire la mise à jour
              // à jour dans la matrice bis selon "Day and night"
              
              *(bis + i*c +j)= update_cell2(m,i,j,l,c); 
          }
     }
     
     for(int i=0;i<l; i++){
          for(int j=0;j<c; j++){
              //bis[i][j]
              *(m + i*c +j)= *(bis + i*c +j);
          }
     }
}    



/*
 * 
 * Rôle : Initialiser la matrice m qui represente la grille en mettant toutes  		les cellules à 0 (cellules mortes)
 */
void initialiser(data *d){
	int *x=d->m[0];
	for(int i=0;i<ml ;i++){
			for(int j=0;j <mc ;j++){
				*(x + j*mc +i)=0;
		}
	}
}

/*
 * 
 * Rôle : Affecter le mode de la partie 1 au jeu
 */
void affectermode1(data *d){
	d->Etatmode=1;
}
/*
 * 
 * Rôle : Affecter le mode "Day and night" au jeu
 */
void affectermode2(data *d){
	d->Etatmode=2;
}

/*
 * 
 * Rôle : tester le mode  du jeu en verifiant la valeur de champs Etatmode
 */

int testermode(data *d){
	return d->Etatmode;
}
/*
 * 
 * Rôle : Lire la matrice à partir du fichier
 */
void lirefichier(data *d,FILE *fichier){
	int c;
	int *k = d-> s[0];  
	// parcourir le fichier
	for(int i=0;i<ligne ;i++){
		for(int j=0;j <colonne ;j++){
			c=fgetc(fichier);
			*(k+ i*colonne +j)=c-'0'; // transformer en nombre
			
			
		}
		c=fgetc(fichier);
	}
	// afficher la matrice sur la sortie standard
	for(int i=0;i<ligne ;i++){
		for(int j=0;j <colonne ;j++){
			printf("%d ",*(k+ i*colonne +j));
		}
		printf("\n");
	}
	
}

