#include "avl.h"

int AVL::ajoutElement(int nouvelElement, Noeud* &noeudActuel, int hauteur){
    super();
    equilibrer(noeudActuel);
}

int AVL::besoinOperation(Noeud*& noeudActuel){
    //L'arbre est vide
    if(noeudActuel==nullptr){
        cout << "L'AVL n'a pas de noeud dans son arbre!" << endl;
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

}

void AVL::AVL_Rotation_Double_Gauche(Noeud* &noeudActuel){

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