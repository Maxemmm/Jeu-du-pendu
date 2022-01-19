/* LIBRAIRIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendu.h"

/* INITIALISATIONS */
char mot[200];
char mot_cache[200];
char image[image_x][image_y];
int *lettrestrouvees;
int nbessai = 11;
char lettre[200];

/* MAIN */
int main(int argc, char **argv){

    if (argc == 1 || argc != 2){                                                /* On verifie les arguments */
        printf("Not enough data ! One word is required.\n");
        return EXIT_FAILURE;
    }
    strcpy(mot, argv[1]);                                                       /* Stock les arguments dans une chaine de caracteres */
    char test = validation_chaine(mot);
    size_t taillemot = strlen(mot);

    if (test == 1){
        return EXIT_FAILURE;
    }
    else{                                                                       /* On rentre dans le coeur du programme */
        strmaj(mot);                                                            /* On met en majuscule le mot a trouver */
        lettrestrouvees = malloc(taillemot * sizeof(int));

        if (lettrestrouvees == NULL)
            return EXIT_FAILURE;

        for (int i = 0; i < taillemot; i++){
            mot_cache[i] = '*';
            lettrestrouvees[i] = 0;
        }

        while (nbessai >= 0){                                                   /* On commence le decompte du nombre d'essai */
            image_nbessai(nbessai);

            if (nbessai != 0){
                printf("Mot a trouver : ");
                printf("%s\n", mot_cache);
                printf("Proposez moi une lettre puis entrée: ");
            }
            scanf(" %s", &lettre);                                              /* On recupere la lettre entree par l'utilisateur */

            if ((int)strlen(lettre) > 1){                                       /* On verifie que l'utilisateur rentre un seul caractre en meme temps, si non, on affiche un message d'erreur */
                printf("Only one word at the time !\n");
                return EXIT_FAILURE;
            }
            int i = 0;
            int resultat = test_lettre(lettre[i]);

            if (resultat == perd){                                              /* Si l'utilisateur a entree une mauvaise lettre, le decompte du nombre d'essai est decremente */
                nbessai = nbessai - 1;
            }
            if (resultat == gagne){                                             /* Si tout le mot est trouve, on arrete de jouer et on felicite l'utilisateur */
                clrscr();
                image_nbessai(nbessai);
                printf("Le mot sauveur : ");
                printf("%s\n", mot);
                printf("Vous avez sauve sa vie! Bravo\n");
                printf("Appuyez sur <ENTRÉE> pour fermer cette fenêtre...");
                scanf("%c", &lettre);
                getchar();
                nbessai = -1;
            }
            if (nbessai == suite){                                              /* Si le nombre d'essai tombe a 0, on montre a l'utilisateur qu'il a perdu */
                image_nbessai(nbessai);
                printf("Le mot sauveur : ");
                printf("%s\n", mot);
                printf("Vous avez perdu !\n");
                printf("Appuyez sur <ENTRÉE> pour fermer cette fenêtre...");
                scanf("%c", &lettre);
                getchar();
                nbessai = -1;
            }
        }
    }
    return EXIT_SUCCESS;
}

/* FONCTIONS VERFICATION CHAINE */
void strmaj(char *chaine){                                                      /* On met toutes les lettres du mot a trouver en majuscule */
    int i = 0;
    while (chaine[i] != '\0'){
        if ((chaine[i] > 96) && (chaine[i] <= 122)){
            chaine[i] = chaine[i] - 32;
        }
        else if ((chaine[i] > 64) && (chaine[i] <= 90)){
            chaine[i] = chaine[i];
        }
        i++;
    }
    printf("\n");
}
int validation_chaine(char *chaine){                                            /* On verifie que la chaine de caractères contient seulement des lettres */
    int i = 0;
    char boo = 0;
    while ((chaine[i] != '\0') && (boo == 0)){
        if (((chaine[i] > 64) && (chaine[i] <= 90)) || ((chaine[i] > 96) && (chaine[i] <= 122))){
            i++;
        }
        else{
            printf("Your word must contains only letters !\n");
            boo = 1;
        }
    }
    return boo;
}

/* FONCTIONS JEU */
void init_mot_cache(void){                                                      /* On initialise le mot cache pour l'utilisateur avec des '*' */
    int i;
    size_t len = strlen(mot);
    for (i = 0; i < len; i++){
        mot_cache[i] = '*';
    }
    mot_cache[i] = '\0';
}
void image_nbessai(int nbessai){                                                /* On decrit chaque cas en fonction du nombre d'essai restant */
    switch (nbessai){
    case 11:
        clrscr();
        printf("Il vous reste 11 tentatives\n\n");
        image_clear();
        image_affiche();
        break;
    case 10:
        clrscr();
        printf("Nombre d'essai : 10\n\n");
        image_sol();
        image_affiche();
        break;
    case 9:
        clrscr();
        printf("Nombre d'essai : 9\n\n");
        image_potence_verticale();
        image_affiche();
        break;
    case 8:
        clrscr();
        printf("Nombre d'essai : 8\n\n");
        image_potence_oblique();
        image_affiche();
        break;
    case 7:
        clrscr();
        printf("Nombre d'essai : 7\n\n");
        image_potence_horizontale();
        image_affiche();
        break;
    case 6:
        clrscr();
        printf("Nombre d'essai : 6\n\n");
        image_corde();
        image_affiche();
        break;
    case 5:
        clrscr();
        printf("Nombre d'essai : 5\n\n");
        image_tete();
        image_affiche();
        break;
    case 4:
        clrscr();
        printf("Nombre d'essai : 4\n\n");
        image_bras_droit();
        image_affiche();
        break;
    case 3:
        clrscr();
        printf("Nombre d'essai : 3\n\n");
        image_bras_gauche();
        image_affiche();
        break;
    case 2:
        clrscr();
        printf("Nombre d'essai : 2\n\n");
        image_corps();
        image_affiche();
        break;
    case 1:
        clrscr();
        printf("Nombre d'essai : 1\n\n");
        image_jambe_droite();
        image_affiche();
        break;
    case 0:
        clrscr();
        printf("Nombre d'essai : 0\n\n");
        image_jambe_gauche();
        image_affiche();
        break;
    default:
        break;
    }
}
int test_lettre(char lettre){                                                   /* On devoile, ou non, les lettres que l'utilisateur rentre au fur et a mesure qu'il joue */
    long i = 0;
    char boo = gagne;
    for (i; mot[i] != '\0'; i++){
        if ((lettre == mot[i] || (lettre - 32) == mot[i]) && lettrestrouvees[i] == 0){
            lettrestrouvees[i] = 1;
            boo = suite;
        }
        if ((lettre != mot[i] || (lettre - 32) != mot[i]) && lettrestrouvees[i] == 0 && boo != 0){
            boo = perd;
        }
        if (lettrestrouvees[i] == 1)
            mot_cache[i] = mot[i];
    }
    if (strcmp(mot, mot_cache) == 0){
        boo = gagne;
    }
    return boo;
}

/* FONCTIONS AFFICHAGE PENDU */
void clrscr(void){
    system("clear");
}
void image_clear(void){
    int x, y;
    for (y = 0; y < image_y; y++){
        for (x = 0; x < image_x; x++){
            image[x][y] = ' ';
        }
    }
}
void image_affiche(void){
    int x, y;
    for (y = 0; y < image_y; y++){
        for (x = 0; x < image_x; x++){
            printf("%c", image[x][y]);
        }
        printf("\n");
    }
}
void image_sol(void){
    int x, y = 11;
    for (x = 0; x < 10; x++){
        image[x][y] = '=';
    }
}
void image_potence_verticale(void){
    int x = 4;
    int y;
    while (x < 6){
        for (y = 1; y < 11; y++){
            image[x][y] = '|';
        }
        x++;
    }
}
void image_potence_oblique(void){
    image[6][3] = '/';
    image[6][2] = '/';
    image[7][2] = '/';
    image[7][1] = '/';
    image[8][1] = '/';
}
void image_potence_horizontale(){
    int x, y = 0;
    for (x = 4; x < image_x; x++){
        image[x][y] = '=';
    }
}
void image_jambe_gauche(void){
    image[12][7] = '/';
}
void image_jambe_droite(void){
    image[14][7] = '\\';
}
void image_corps(void){
    int x = 13, y;
    for (y = 5; y < 7; y++){
        image[x][y] = '|';
    }
}
void image_bras_gauche(void){
    image[12][5] = '/';
}
void image_bras_droit(void){
    image[14][5] = '\\';
}
void image_tete(void){
    image[13][4] = 'O';
}
void image_corde(void){
    int x = 13, y;
    for (y = 1; y < 4; y++){
        image[x][y] = '|';
    }
}
