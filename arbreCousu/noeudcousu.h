#include "../arbre.h"
#ifndef NOEUDCOUSU
#define NOEUDCOUSU
    class NoeudCousu:public Noeud{
        private:
            NoeudCousu *gauche;
            NoeudCousu *droite;
            bool vraiSousArbreDroit;
        public:
            //Constructeur
            NoeudCousu();
            NoeudCousu(int element);
            NoeudCousu(const Noeud *&node);
            NoeudCousu(const NoeudCousu *&node);
            NoeudCousu(int element, NoeudCousu *&dernierNoeudAGauche);

            //Destructeur
            ~NoeudCousu();

            //Surcharge d'opérateur
            NoeudCousu *&operator=(const NoeudCousu &node);
            NoeudCousu *&operator=(const Noeud &node);

            //Getter
            NoeudCousu *&getElementGauche();
            NoeudCousu *&getElementDroite();

            //Setter
            void setElementGauche(NoeudCousu *&enfantGauche);
            void setElementDroite(NoeudCousu *&enfantDroite);
    };
#endif