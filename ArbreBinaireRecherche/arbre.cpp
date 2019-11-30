#include "arbre.h"
#include "noeud.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <exception>

/**
 * Constructeur par défaut
 * Précondition : instance pas initialisée
 * Postcondition : instance initialisée avec une racine vide
 */
ArbreBinaireRecherche::ArbreBinaireRecherche(){
    racine = nullptr;
}

/**
 * Recherche d'un élément
 * Précondition : un arbre binaire de recherche, un élément à trouver
 * Postcondition : un arbre binaire de recherche, un élément à trouver, un élement trouvé si il est présent dans la table, pointeur nul sinon
 */
Noeud*& ArbreBinaireRecherche::rechercheElement(int element, Noeud *&noeudActuel){
    Noeud *&returnedNoeud = noeudActuel;
    //Tant que l'élément n'a pas été trouvé
    if(noeudActuel->getElement()!=element){
        //Element plus grand-> sous-arbre de droite
        if(noeudActuel->getElement()>element){
            if(noeudActuel->getElementDroite()!=nullptr){
                returnedNoeud = rechercheElement(element, noeudActuel->getElementDroite());
            }
        }else if(noeudActuel->getElement()<element){
            if(noeudActuel->getElementGauche()!=nullptr){
                returnedNoeud = rechercheElement(element, noeudActuel->getElementGauche());
            }
        }else{
            return returnedNoeud;
        }
    }else{
        returnedNoeud = noeudActuel;
        return returnedNoeud;
    }
}

/**
 * Ajout d'un élément dans la table
 * 
 */
int ArbreBinaireRecherche::ajoutElement(int nouvelElement, Noeud* &noeudActuel){
    //Aucun élément dans la table
    if (noeudActuel == nullptr)
    {
        printf("L'arbre binaire de recherche est vide : ajout du 1er élément.\n");
        Noeud *noeud = new Noeud(nouvelElement);
        noeudActuel = noeud;
    }
    //L'élément à ajouter est plus petit que celui du noeud actuel -> à ajouter dans le sous-élément de gauche
    else if(noeudActuel->getElementGauche() == nullptr && noeudActuel->getElement() > nouvelElement){
        Noeud* noeud = new Noeud(nouvelElement);
        noeudActuel->getElementGauche() = noeud;
        printf("Ajout de l'élément à gauche du noeud %d.\n", noeudActuel->getElement());
    }
    //L'élément à ajouter est plus grand que celui du noeud actuel -> à ajouter dans le sous-élément de droite
    else if(noeudActuel->getElementDroite() == nullptr && noeudActuel->getElement()<nouvelElement){
        Noeud* noeud = new Noeud(nouvelElement);
        noeudActuel->getElementDroite() = noeud;
        printf("Ajout de l'élément à droite du noeud %d.\n", noeudActuel->getElement());
    }
    else{
        //On passe au sous-arbre de gauche : l'élément est inférieur à celui du noeud
        if(noeudActuel->getElement()<nouvelElement){
            printf("On passe à gauche.\n");
            ajoutElement(nouvelElement, noeudActuel->getElementGauche());
        }
        else if(noeudActuel->getElement()>nouvelElement)
        //On passe au sous-arbre de droite : l'élément est supérieur à celui du noeud
        {
            printf("On passe à droite.\n");
            ajoutElement(nouvelElement, noeudActuel->getElementDroite());
        }
    }
    printf("Fin de l'ajout de l'élément %d.\n\n", nouvelElement);
}

/**
 * Affichage de l'arbre binaire de recherche
 * quandAfficher -> indique à l'utilisateur quand afficher la table
 * noeudActuel -> référence vers le noeud actuel
 */
void ArbreBinaireRecherche::affichageTable(int quandAfficher, Noeud* &noeudActuel){
    //Tant que le noeud dispose d'enfants
    if(noeudActuel != nullptr){
        //Préfixe
        if(quandAfficher==0){
            printf("Adresse : %d, Noeud actuel : %d.\n",noeudActuel,noeudActuel->getElement());
        }
        if (noeudActuel->getElementGauche() != nullptr)
        {
            affichageTable(quandAfficher, noeudActuel->getElementGauche());
        }
        if(quandAfficher==1){
            printf("Adresse : %d, Noeud actuel : %d.\n",noeudActuel,noeudActuel->getElement());
        }
        if(noeudActuel->getElementDroite()!=nullptr){
            affichageTable(quandAfficher, noeudActuel->getElementDroite());
        }
        if(quandAfficher==2){
            printf("Adresse : %d, Noeud actuel : %d.\n",noeudActuel,noeudActuel->getElement());
        }
    }else{
        printf("Aucun élement dans l'arbre binaire de recherche.\n");
    }
}

/**
 * Retourne une référence vers la racine de l'arbre binaire de recherche
 * PostCondition : retourne le premier élément de l'arbre binaire de recherche
 */
Noeud*& ArbreBinaireRecherche::racineTable(){
    return racine;
}

/**
 * Constructeur par copie
 */
ArbreBinaireRecherche::ArbreBinaireRecherche(const ArbreBinaireRecherche &autreArbre){
    printf("Constructeur par copie.\n");
    racine = new Noeud(*autreArbre.racine);
}

/**
 * Destructeur de l'arbre binaire de recherche
 */
ArbreBinaireRecherche::~ArbreBinaireRecherche(){
    printf("Suppression de l'arbre binaire de recherche.\n");
    delete racine;
}

/**
 * Surcharge de l'opérateur d'affectation
 */
ArbreBinaireRecherche ArbreBinaireRecherche::operator=(const ArbreBinaireRecherche &autreArbre){
    printf("Appel de l'opérateur d'affectation.\n");
    if(autreArbre.racine != nullptr){
        racine = new Noeud(*autreArbre.racine);
    }
    return *this;
}

int ArbreBinaireRecherche::size(){
    int size = 0;
    Noeud *&noeudActuel = racine;
    if (noeudActuel == nullptr){
        return size;
    }else{
        size = size + sizeRec(size, noeudActuel);
        return size;
    }
}

int ArbreBinaireRecherche::sizeRec(int currentSize, Noeud*& noeudActuel){
    if (noeudActuel == nullptr) {
        return 0;
    }else if(noeudActuel->getElementDroite() == nullptr && noeudActuel->getElementGauche() == nullptr){
        return 1;
    }else{
        if(noeudActuel->getElementGauche() != nullptr){
            currentSize = currentSize + sizeRec(currentSize, noeudActuel->getElementGauche());
        }
        if(noeudActuel->getElementDroite() != nullptr){
            currentSize = currentSize + sizeRec(currentSize, noeudActuel->getElementDroite());
        }
    }
}