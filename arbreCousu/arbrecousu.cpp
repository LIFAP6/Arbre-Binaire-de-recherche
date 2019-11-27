#include "arbrecousu.h"
#include <iostream>
using namespace std;

ArbreCousu::ArbreCousu(){
    cout << "Création d'une instance d'un arbre cousu vide!" << endl;
}

ArbreCousu::ArbreCousu(const ArbreCousu& arbre){
    cout << "Création d'une instance d'un arbre cousu à partir d'une référence d'un arbre binaire de recherche" << endl;
}

int ArbreCousu::ajoutElement(int nouvelElement, NoeudCousu* &noeudActuel, NoeudCousu* &dernierNoeudAGauche){
    //Aucun élément dans la table
    if (noeudActuel == nullptr)
    {
        printf("L'arbre binaire de recherche est vide : ajout du 1er élément.\n");
        NoeudCousu *noeud = new NoeudCousu(nouvelElement,dernierNoeudAGauche);
        noeudActuel = noeud;
        if(elementLePlusPetit == nullptr){
            elementLePlusPetit = noeud;
        }
    }
    //L'élément à ajouter est plus petit que celui du noeud actuel -> à ajouter dans le sous-élément de gauche
    else if(noeudActuel->getElementGauche() == nullptr && noeudActuel->getElement() > nouvelElement){
        NoeudCousu* noeud = new NoeudCousu(nouvelElement,dernierNoeudAGauche);
        noeudActuel->setElementGauche(noeud);
        printf("Ajout de l'élément à gauche du noeud %d.\n", noeudActuel->getElement());
        if(elementLePlusPetit->getElement()>noeud->getElement() && elementLePlusPetit != nullptr){
            elementLePlusPetit = noeud;
        }
    }
    //L'élément à ajouter est plus grand que celui du noeud actuel -> à ajouter dans le sous-élément de droite
    else if(noeudActuel->getElementDroite() == nullptr && noeudActuel->getElement()<nouvelElement){
        NoeudCousu* noeud = new NoeudCousu(nouvelElement,dernierNoeudAGauche);
        noeudActuel->setElementDroite(noeud);
        printf("Ajout de l'élément à droite du noeud %d.\n", noeudActuel->getElement());
    }
    else{
        //On passe au sous-arbre de gauche : l'élément est inférieur à celui du noeud
        if(noeudActuel->getElement()<nouvelElement){
            printf("On passe à gauche.\n");
            ajoutElement(nouvelElement, noeudActuel->getElementGauche(), noeudActuel->getElementGauche());
        }
        else if(noeudActuel->getElement()>nouvelElement)
        //On passe au sous-arbre de droite : l'élément est supérieur à celui du noeud
        {
            printf("On passe à droite.\n");
            ajoutElement(nouvelElement, noeudActuel->getElementDroite(),dernierNoeudAGauche);
        }
    }
    printf("Fin de l'ajout de l'élément %d.\n\n", nouvelElement);
}

ArbreCousu::~ArbreCousu(){
    cout << "Suppression de l'arbre cousu" << endl;
}

NoeudCousu* &ArbreCousu::getRacine(){
    return racine;
}