#include <stdio.h>
#include <stdlib.h>
//Debut Question 2.1
//int main()
//{
//    typedef struct Coureur Coureur;
//    struct Coureur{
//        int NCoureur;
//        int Chrono;
//        Coureur *suivant;
//    };
//    return 0;
//}
//Fin Question 2.1
//###################
//Debut Question 2.2
typedef struct Coureur Coureur;
struct Coureur{
    int NCoureur;
    int Chrono;
    Coureur *suivant;
};
//Prototype des fonction
Coureur* Insere(Coureur *,int);
//Question 2.3
int Somme(Coureur *);

void Affiche (Coureur *);

int main()
{
    Coureur *maListe = malloc(sizeof(*maListe));
    int n;

    n=4;

    maListe = Insere(maListe, n);
    Affiche(maListe);
    printf("la moyenne de chrone est : %d\n",Somme(maListe));
    return 0;
}

Coureur * Insere(Coureur *liste, int Nb){
    Coureur *element = malloc(sizeof(*element));
    element->suivant = NULL;
    if (Nb == 0) {
            return liste;
    }
    if(liste == NULL){
        printf("entrer le numero d'un coureur : ");
        scanf("%d",&element->NCoureur);
        printf("son chrono : ");
        scanf("%d",&element->Chrono);
        element->suivant = NULL;
        liste = element;
        liste = Insere (liste,--Nb);
        return liste;
    }
    else{
        printf("entrer le numero d'un coureur : ");
        scanf("%d",&element->NCoureur);
        printf("son chrono : ");
        scanf("%d",&element->Chrono);
        element->suivant = liste;
        liste = element;
        liste = Insere (liste,--Nb);
        return liste;
    }
}
//Fin Question 2.2
//###################
//Debut Question 2.3
int Somme(Coureur *liste){
    if (liste == NULL){
            printf(" somme des chrono NULL");
            exit(EXIT_FAILURE);
    }
    else{
            return (liste->Chrono+Somme(liste->suivant));

    }
}

void Affiche(Coureur *liste){
    if (liste == NULL){
            printf("NULL ->");
    }
    else {
            printf("%d -> ", liste->NCoureur);
            printf("%d -> ", liste->Chrono);
            Affiche(liste->suivant);
            return;
    }
}
