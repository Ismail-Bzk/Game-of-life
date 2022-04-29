/*
 * @author: Vincent GranetVincent.Granet@univ−cotedazur.fr
 * Creation @date: 29−Apr−2020 21:05
 * Last file update: 28−May−2020 10:24
 */
#pragma once
#include <libsx.h>
#define ml 50
#define mc 50
#define dead 0
#define alive 1
#define ligne 5
#define colonne 5
/*
 * Définition du type data qui représente la matrice affiché dans la grille,
 * la matice utilisée pour calculer le nombre de voisins, la matrice qui lit
 * le fichier, et finalement la mode du jeu
 *
 */
typedef struct {
	int  m[ml][mc];
	int  bis[ml][mc]  ;
	int  s[ligne][colonne];
	int Etatmode;
} data;


extern void set_matrix(data *);
extern int update_cell1(int *, const int ,const int ,const int ,const int );
extern int update_cell2(int *, const int ,const int ,const int ,const int );
extern void updateV1(data *, const int , const int );
extern void updateV2(data *, const int , const int );
extern void initialiser(data *);

extern void affectermode1(data *);
extern void affectermode2(data *);
extern int testermode(data *);
extern void lirefichier(data *,FILE *);
