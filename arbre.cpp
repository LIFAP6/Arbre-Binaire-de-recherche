#include "arbre.h"
#include <stdlib.h>
#include <stdio.h>

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
Noeud** ArbreBinaireRecherche::rechercheElement(int element, Noeud *&noeudActuel){
    Noeud **noeud;
    //Tant que l'élément n'a pas été trouvé
    if(noeudActuel->getElement()!=element){
        //Element plus grand-> sous-arbre de droite
        if(noeudActuel->getElement()>element){
            noeud = rechercheElement(element, noeudActuel->getElementDroite());
        }else if(noeudActuel->getElement()<element){
            noeud = rechercheElement(element, noeudActuel->getElementGauche());
        }else{
            noeud = &noeudActuel;
            return noeud;
        }
    }
}

/**
 * Ajout d'un élément dans la table
 * 
 */
int ArbreBinaireRecherche::ajoutElement(int nouvelElement, Noeud* &noeudActuel){
    printf("Élément à ajouter : %d\n", nouvelElement);
    //Aucun élément dans la table
    if (noeudActuel == nullptr)
    {
        printf("L'arbre binaire de recherche est vide : ajout du 1er élément.\n");
        Noeud *noeud = new Noeud(nouvelElement);
        racine = noeud;
    }
    //L'élément à ajouter est plus petit que celui du noeud actuel -> à ajouter dans le sous-élément de gauche
    else if(noeudActuel->getElementGauche() == nullptr && noeudActuel->getElement()>nouvelElement){
        Noeud* noeud = new Noeud(nouvelElement);
        noeudActuel->getElementGauche() = noeud;
        printf("Ajout de l'élément à gauche du noeud %d.\n", noeudActuel->getElement());
    }
    //L'élément à ajouter est plus grand que celui du noeud actuel -> à ajouter dans le sous-élément de droite
    else if(noeudActuel->getElementDroite() == nullptr && noeudActuel->getElement()<=nouvelElement){
        Noeud* noeud = new Noeud(nouvelElement);
        noeudActuel->getElementDroite() = noeud;
        printf("Ajout de l'élément à droite du noeud %d.\n", noeudActuel->getElement());
    }
    else{
        //On passe au sous-arbre de gauche : l'élément est inférieur à celui du noeud
        if(noeudActuel->getElement()<nouvelElement){
            printf("On passe à droite.\n");
            //Le noeud à ajouter est plus petit que le noeud en cours, mais est plus grand que le sous-noeud de gauche et plus petit que celui de droite
            if(noeudActuel->getElementDroite()->getElement()<nouvelElement){
                Noeud *noeud = new Noeud(nouvelElement);
                noeud->setElementGauche(noeudActuel->getElementGauche());
                noeudActuel->setElementGauche(noeud);
            }
            else
            {
                ajoutElement(nouvelElement, noeudActuel->getElementGauche());
            }
        }
        else if(noeudActuel->getElement()>nouvelElement)
        //On passe au sous-arbre de droite : l'élément est supérieur à celui du noeud
        {
            if(noeudActuel->getElementDroite()->getElement()<nouvelElement){
                Noeud *noeud = new Noeud(nouvelElement);
                if(noeudActuel->getElementGauche()==nullptr){
                    printf("Pointeur nul!\n");
                }else{
                    printf("Pointeur non nul!\n");
                }
                noeud->setElementDroite(noeudActuel->getElementGauche());
                noeudActuel->setElementDroite(noeud);
            }else{
                printf("On passe à gauche.\n");
                ajoutElement(nouvelElement, noeudActuel->getElementDroite());
            }
        }else{
            printf("Nous n'ajoutons rien car l'élément est déjà présent.\n");
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
        if(noeudActuel->getElementGauche()!=nullptr){
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
 * Constructeur par paramètre du noeud
 * Précondition : un noeud vide
 * newElement : valeur de l'élément du noeud
 * Postcondition : un noeud instancié avec un élément dedans
 */
Noeud::Noeud(int newElement){
    element = newElement;
}

/**
 * Constructeur par copie du noeud
 * Précondition : un noeud vide, un noeud instancié
 * n : noeud instancié
 * Postcondition : deux noeuds indentiques
 */
Noeud::Noeud(const Noeud& n){
    element = n.element;
    droite = n.droite;
    gauche = n.gauche;
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

void Noeud::setElementGauche(Noeud* &elementGauche){
    gauche = elementGauche;
}

void Noeud::setElementDroite(Noeud* &elementDroite){
    droite = elementDroite;
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