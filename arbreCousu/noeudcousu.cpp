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

NoeudCousu*& NoeudCousu::operator=(const NoeudCousu &node){
    Noeud::setElement(node.getElement());
}
NoeudCousu*& NoeudCousu::operator=(const Noeud &node){

}