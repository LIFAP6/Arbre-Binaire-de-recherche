// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

//Table de hashage / Contenu de la cellule
#include "arbre/arbre.h"

int main()
{
    ArbreBinaireRecherche* arbre = new ArbreBinaireRecherche();
    arbre->ajoutElement(3, arbre->racineTable());
    arbre->ajoutElement(4, arbre->racineTable());
    arbre->ajoutElement(1, arbre->racineTable());
    arbre->ajoutElement(2, arbre->racineTable());
    arbre->ajoutElement(12, arbre->racineTable());
    arbre->ajoutElement(19, arbre->racineTable());
    arbre->affichageTable(0, arbre->racineTable());
    cout << "Taille de l'arbre : " << arbre->size() << "." << endl;
    Noeud *&noeud = arbre->rechercheElement(3, arbre->racineTable());
    cout << "Élement du noeud : " << noeud->getElement() << endl;
    ArbreBinaireRecherche *arbre2 = new ArbreBinaireRecherche(*arbre);
    ArbreBinaireRecherche *arbre3 = new ArbreBinaireRecherche();
    *arbre3 = *arbre;
    delete arbre;
    arbre2->affichageTable(0,arbre2->racineTable());
    cout << "Taille de l'arbre : " << arbre2->size() << "." << endl;
    delete arbre2;
    arbre3->affichageTable(0, arbre3->racineTable());
    cout << "Taille de l'arbre : " << arbre3->size() << "." << endl;
    delete arbre3;
}
