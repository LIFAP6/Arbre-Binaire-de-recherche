#include "arbrecousu.h"
#include <iostream>
using namespace std;
//Constructeurs
/**
 * Constructeur par défaut
 */
ArbreCousu::ArbreCousu(){
    cout << "Création d'une instance d'un arbre cousu vide!" << endl;
}
/**
 * Constructeur par copie
 */
ArbreCousu::ArbreCousu(const ArbreBinaireRecherche& arbre){
        cout << "Création d'une instance d'un arbre cousu à partir d'une référence d'un arbre binaire de recherche" << endl;
        const Noeud *noeudRacine = arbre.racineTable();
        racine = (NoeudCousu*)noeudRacine;
}

ArbreCousu::~ArbreCousu(){
    cout << "Suppression de l'arbre cousu." << endl;
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

NoeudCousu* &ArbreCousu::getRacine(){
    return racine;
}

NoeudCousu* &ArbreCousu::getElementLePlusPetit(){
    return elementLePlusPetit;
}

void ArbreCousu::affichageTable(){
    if(racine != nullptr){
        NoeudCousu *&noeudEncours = racine;
        noeudEncours->updateStatus(DECOUVERT);
        cout << "Arbre cousu." << endl;
        cout << "Liste : " << racine->getElement();
        while (racine->getStatus() != AUCUNEAUTREACTIONAFAIRE)
        {
            //L'élément existe mais n'a pas encore été parcouru
            while(racine->getElementGauche()!= nullptr && racine->getElementGauche()->getStatus()==PASENCOREPARCOURU){
                noeudEncours = noeudEncours->getElementGauche();
                cout << " " << noeudEncours->getElement();
            }
            //Nous n'avons pas de sous-arbre droit ici
            if(racine->getElementDroite() != nullptr && !racine->estVraiSousArbreDroit()){
                while(racine->getElementDroite() != nullptr && racine->estVraiSousArbreDroit() && racine->getElementDroite()->getStatus() != PASENCOREPARCOURU){
                    //On remonte au dernier élément en passant à gauche qui a un sous-arbre droit
                    noeudEncours = noeudEncours->getElementDroite();
                }
            }
            if((racine->getElementGauche() == nullptr || racine->getElementDroite() == nullptr) ||
            (racine->getElementGauche()->getStatus() == AUCUNEAUTREACTIONAFAIRE && racine->getElementDroite()->getStatus()==AUCUNEAUTREACTIONAFAIRE)){
                noeudEncours->updateStatus(AUCUNEAUTREACTIONAFAIRE);
            }
        }
        cout << endl;
    }
    else
    {
        throw std::invalid_argument("Arbre cousu vide!");
    }
}

ArbreCousu ArbreCousu::operator=(const ArbreBinaireRecherche &arbreBinaireRecherche){

}