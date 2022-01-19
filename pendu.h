#ifndef _screen_
#define _screen_

#define image_x 16
#define image_y 12
#define gagne 2
#define perd 1
#define suite 0

void strmaj(char *chaine); /* transforme en majuscule la chaine */
void clrscr(void); /* efface l'ecran */
void image_clear(void); /* initialise l'image (rempli d'espace) */
void image_affiche(void); /* affiche l'image */
void image_sol(void); /* place le sol dans l'image */
void image_potence_verticale(void); /* place la potence verticale dans l'image*/
void image_potence_oblique(void); /*place la potence oblique dans l'image */
void image_potence_horizontale(void);
void image_jambe_gauche(void);
void image_jambe_droite(void);
void image_corps(void);
void image_bras_gauche(void);
void image_bras_droit(void);
void image_tete(void);
void image_corde(void); /* place la corde */
void image_nbessai(int nbessai);
int test_lettre(char lettre);
int validation_chaine(char *motinconnu);
void init_mot_cache(void);

#endif