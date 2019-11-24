#include "avl.h"

int AVL::ajoutElement(int nouvelElement, Noeud* &noeudActuel, int hauteur){
    arbre.ajoutElement(nouvelElement, arbre.racineTable(), hauteur);
}

int AVL::besoinOperation(Noeud*& noeudActuel){
    //L'arbre est vide
    if(noeudActuel==nullptr){
        throw std::invalid_argument("L'AVL n'a pas de noeud dans son arbre!");
        return 0;
    }else{
        int hauteurSousArbreDroit = noeudActuel->getElementDroite()->getHauteur();
        int hauteurSousArbreGauche = noeudActuel->getElementGauche()->getHauteur();
        return hauteurSousArbreGauche - hauteurSousArbreDroit;
    }
}

void AVL::equilibrer(Noeud* &noeudActuel){
    int difference = besoinOperation(noeudActuel);
    if(difference == 2){
        int differenceGauche = besoinOperation(noeudActuel->getElementGauche());
        if(differenceGauche == 1){
            AVL_Rotation_Droite(noeudActuel);
        }
        else
        {
            AVL_Rotation_Double_Droite(noeudActuel);
        }
    }else{
        int differenceDroite = besoinOperation(noeudActuel->getElementDroite());
        if(differenceDroite == -1){
            AVL_Rotation_Gauche(noeudActuel);
        }
        else
        {
            AVL_Rotation_Double_Gauche(noeudActuel);
        }
    }
}

void AVL::AVL_Rotation_Gauche(Noeud* &noeudActuel){
    Noeud *&sousArbreDroite = noeudActuel->getElementDroite();
    noeudActuel->setElementDroite(sousArbreDroite->getElementGauche());
    sousArbreDroite->setElementGauche(noeudActuel);
    noeudActuel = sousArbreDroite;
}

void AVL::AVL_Rotation_Double_Gauche(Noeud* &noeudActuel){
    Noeud *&sousArbreDroite = noeudActuel->getElementDroite();
    Noeud *&sousArbreDroiteGauche = sousArbreDroite->getElementDroite();
    sousArbreDroite->setElementGauche(sousArbreDroiteGauche->getElementDroite());
    noeudActuel->setElementDroite(sousArbreDroiteGauche->getElementGauche());
    sousArbreDroiteGauche->setElementGauche(noeudActuel);
    sousArbreDroiteGauche->setElementDroite(sousArbreDroite);
    noeudActuel = sousArbreDroiteGauche;
}

/**
 * Réalise une opération simple à droite
 * @param noeudActuel [Noeud] le noeud nécessitant la réalisation de l'opération
 */
void AVL::AVL_Rotation_Droite(Noeud* &noeudActuel){
    cout << "Appel de la rotation à droite."<<endl;
    Noeud *&tmpNoeud = noeudActuel->getElementGauche();
    noeudActuel->setElementGauche(noeudActuel->getElementDroite());
    noeudActuel->setElementDroite(tmpNoeud);
}

/**
 * Réalise une opération double droite
 * @param noeudActuel [Noeud] le noeud nécessitant la réalisation de lopération
 */
void AVL::AVL_Rotation_Double_Droite(Noeud* &noeudActuel){
    cout << "Appel de la double rotation à droite." << endl;
    Noeud *&tmpNoeudGauche = noeudActuel->getElementGauche();
    Noeud *&tmpNoeudSousArbreGaucheDroite = noeudActuel->getElementGauche()->getElementDroite();
    tmpNoeudGauche->setElementDroite(tmpNoeudSousArbreGaucheDroite->getElementGauche());
    tmpNoeudGauche->setElementGauche(tmpNoeudGauche);
    noeudActuel->setElementGauche(tmpNoeudSousArbreGaucheDroite->getElementDroite());
    tmpNoeudSousArbreGaucheDroite->setElementDroite(noeudActuel);
    noeudActuel = tmpNoeudSousArbreGaucheDroite;
}

AVL::AVL(){
    cout << "Création d'une instance d'un arbre Adelson-Velskij et Landis vide!" << endl;
}

AVL::AVL(const AVL &rawAVL){
    cout << "Création d'une instance d'un arbre Adelson-Velskij et Landis par copie d'une référence." << endl;
    arbre = rawAVL.arbre;
}