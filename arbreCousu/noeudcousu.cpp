#include "noeudcousu.h"
#include <iostream>
using namespace std;

NoeudCousu::NoeudCousu()
{
    cout << "Création d'un noeud cousu vide!" << endl;
}

/**
 * Constructeur pour un noeud cousu avec un pointeur vers le dernier élément à gauche
 */
NoeudCousu::NoeudCousu(int nouvelElement, NoeudCousu*& dernierNoeudAGauche){
    cout << "Création d'un noeud cousu avec une valeur et le dernier élément à gauche" << endl;
    Noeud::setElement(nouvelElement);
    //droite = dernierNoeudAGauche;
    vraiSousArbreDroit = false;
}

NoeudCousu* &NoeudCousu::getElementGauche(){
    return gauche;
}

NoeudCousu* &NoeudCousu::getElementDroite(){
    return droite;
}

NoeudCousu* NoeudCousu::getElementDroite()const{
    return droite;
}

NoeudCousu* NoeudCousu::getElementGauche()const{
    return gauche;
}

int NoeudCousu::getStatus(){
    return status;
}

void NoeudCousu::setElementGauche(NoeudCousu*& nouvelleGauche){
    gauche = nouvelleGauche;
}

void NoeudCousu::setElementDroite(NoeudCousu*& nouvelleDroite){
    droite = nouvelleDroite;
}

void NoeudCousu::updateStatus(int newStatus){
    status = newStatus;
}

bool NoeudCousu::estVraiSousArbreDroit(){
    return vraiSousArbreDroit;
}

/**
 * Vérifie si le noeud a été parcouru entièrement
 */
bool NoeudCousu::estParcouruEntierement(){
    if(getElementGauche()==nullptr && getElementDroite()==nullptr){
        return (getStatus() == DECOUVERT || getStatus()==AUCUNEAUTREACTIONAFAIRE);
    }else if(getElementGauche()==nullptr){
        return ((getStatus() == DECOUVERT || getStatus() == AUCUNEAUTREACTIONAFAIRE)
        && (getElementDroite()->estParcouruEntierement()));
    }else if(!estVraiSousArbreDroit()){
        return ((getStatus() == DECOUVERT || getStatus() == AUCUNEAUTREACTIONAFAIRE)
        && (getElementGauche()->estParcouruEntierement()));
    }else{
        return ((getStatus() == DECOUVERT || getStatus() == AUCUNEAUTREACTIONAFAIRE)
        && (getElementGauche()->estParcouruEntierement())
        && (getElementDroite()->estParcouruEntierement()));
    }
}

NoeudCousu*& NoeudCousu::operator=(const NoeudCousu &node){
    cout << "Constructeur par copie d'un noeud cousu." << endl;
    Noeud::setElement(node.getElement());
    if(this != &node){
        Noeud::setElement(node.getElement());
        if(node.gauche != nullptr){
            gauche = new NoeudCousu(*node.gauche);
        }
        if(node.droite != nullptr){
            droite = new NoeudCousu(*node.droite);
        }
    }
}
NoeudCousu*& NoeudCousu::operator=(const Noeud &node){
    Noeud::setElement(node.getElement());
}

