#include "../arbre.h"
#include "noeudcousu.h"
#ifndef ARBRECOUSUTP
#define ARBRECOUSUTP
    class ArbreCousu : public ArbreBinaireRecherche{
        private:
            NoeudCousu *racine;
            NoeudCousu *elementLePlusPetit;
            int sizeRec(int currentSize, NoeudCousu *&noeudActuel);

        public:
            //Constructeur
            ArbreCousu();
            ArbreCousu(const ArbreCousu &arbreCousu);
            ArbreCousu(const ArbreBinaireRecherche &arbre);
            ArbreCousu(const Noeud *&noeudRacine);

            //Destructeur
            ~ArbreCousu();

            //Surcharge d'opérateur
            ArbreCousu operator=(const ArbreBinaireRecherche &arbreBinaireRecherche);

            //Getter
            NoeudCousu *&getRacine();
            NoeudCousu *&getElementLePlusPetit();

            //Setter
            void setRacine(NoeudCousu *&nouvelleRacine);
            void setFond(NoeudCousu *&nouvelElementLePlusPetit);

            //Ajouter élement
            int ajoutElement(int nouvelElement, NoeudCousu* &noeudActuel, NoeudCousu* &dernierNoeudAGauche);
    };
#endif