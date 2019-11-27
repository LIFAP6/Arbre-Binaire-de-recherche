// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

//Table de hashage / Contenu de la cellule
#include "index.h"

int main()
{
    ArbreCousu* cousu = new ArbreCousu();
    cousu->ajoutElement(3, cousu->getRacine(),cousu->getRacine());
    cout << "Element le plus petit " << cousu->getElementLePlusPetit()->getElement() << endl;
    cousu->ajoutElement(4, cousu->getRacine(),cousu->getRacine());
    cout << "Element le plus petit " << cousu->getElementLePlusPetit()->getElement() << endl;
    cousu->ajoutElement(2, cousu->getRacine(),cousu->getRacine());
    cout << "Element le plus petit " << cousu->getElementLePlusPetit()->getElement() << endl;
    cousu->ajoutElement(12, cousu->getRacine(),cousu->getRacine());
    cout << "Element le plus petit " << cousu->getElementLePlusPetit()->getElement() << endl;
    cousu->ajoutElement(19, cousu->getRacine(),cousu->getRacine());
    cout << "Element le plus petit " << cousu->getElementLePlusPetit()->getElement() << endl;
    cousu->ajoutElement(1, cousu->getRacine(),cousu->getRacine());
    cout << "Element le plus petit " << cousu->getElementLePlusPetit()->getElement() << endl;
    cousu->affichageTable();
    delete cousu;
    /*ArbreBinaireRecherche* arbre = new ArbreBinaireRecherche();
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
    delete arbre3;*/
}
