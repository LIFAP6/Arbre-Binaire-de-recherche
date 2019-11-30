#include "noeud.h"
#include "arbre.h"


/**
 * Constructeur par paramètre du noeud
 * Précondition : un noeud vide
 * newElement : valeur de l'élément du noeud
 * Postcondition : un noeud instancié avec un élément dedans
 */
Noeud::Noeud(int newElement){
    element = newElement;
}

Noeud::Noeud(){
    element = -1;
    gauche = nullptr;
    droite = nullptr;
}

void Noeud::setElementDroite(Noeud* &nouveauSousArbreDroite){
    droite = nouveauSousArbreDroite;
}

void Noeud::setElementGauche(Noeud* &nouveauSousArbreGauche){
    gauche = nouveauSousArbreGauche;
}

/**
 * Constructeur par copie du noeud
 * Précondition : un noeud vide, un noeud instancié
 * n : noeud instancié
 * Postcondition : deux noeuds indentiques
 */
Noeud::Noeud(const Noeud& n){
    printf("Constructeur par copie de %d.\n", n.element);
    element = n.element;
    if(n.gauche !=nullptr){
        gauche = new Noeud(*n.gauche);
    }
    if(n.droite !=nullptr){
        droite = new Noeud(*n.droite);
    }
}

/**
 * Retourne le sous-arbre de droite d'un noeud
 * Précondition : un noeud
 * Postcondition : le sous élément à droite
 */
Noeud*& Noeud::getElementGauche(){
    return gauche;
}

/**
 * Retourne le sous-arbre de droite d'un noeud
 * Précondition : un noeud
 * Postcondition : le sous élément à droite
 */
Noeud*& Noeud::getElementDroite(){
    return droite;
}

/**
 * Retourne l'élément du noeud
 * Postcondition : élement (entier) retourné
 */
int Noeud::getElement(){
    return element;
}

/**
 * Compte le nombre d'éléments
 * Post condition : le nombre d'élements de l'arbre binaire de recherche
 */
int Noeud::nombreElements(Noeud* &noeudActuel, int nbElements){
    if(noeudActuel->getElementDroite() == nullptr && noeudActuel->getElementGauche() == nullptr){
        return nbElements;
    }else{
        if(noeudActuel->getElementDroite() == nullptr){
            nbElements = nbElements + 1 + nombreElements(noeudActuel->getElementGauche(), nbElements);
        }else if(noeudActuel->getElementGauche() == nullptr){
            nbElements = nbElements + 1 + nombreElements(noeudActuel->getElementGauche(), nbElements);
        }else{
            nbElements = nbElements + 1 + nombreElements(noeudActuel->getElementGauche(), nbElements);
            nbElements = nbElements + 1 + nombreElements(noeudActuel->getElementDroite(), nbElements);
        }
    }
}

Noeud::~Noeud(){
    printf("Suppression du noeud %d.\n", element);
    if (getElementGauche() != nullptr)
    {
        printf("Suppression de sa partie gauche.\n");
        delete getElementGauche();
    }
    if(getElementDroite() != nullptr){
        printf("Suppression de sa partie droite.\n");
        delete getElementDroite();
    }
    gauche = nullptr;
    droite = nullptr;
    element = -1;
    printf("Élement supprimé.\n\n");
}

Noeud& Noeud::operator=(const Noeud &autreNoeud){
    printf("Opérateur d'affectation pour le noeud %d.\n", autreNoeud.element);
    if(this != &autreNoeud){
        element = autreNoeud.element;
        if(autreNoeud.gauche != nullptr){
            gauche = new Noeud(*autreNoeud.gauche);
        }
        if(autreNoeud.droite != nullptr){
            droite = new Noeud(*autreNoeud.droite);
        }
    }
    return *this;
}

bool Noeud::operator<(const Noeud& autreNoeud){
    return element < autreNoeud.element;
}