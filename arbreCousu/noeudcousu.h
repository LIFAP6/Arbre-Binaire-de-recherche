#include "../arbre.h"
#ifndef NOEUDCOUSU
#define NOEUDCOUSU
#define PASENCOREPARCOURU 0
#define DECOUVERT 1
#define AUCUNEAUTREACTIONAFAIRE 2
    class NoeudCousu:public Noeud{
        private:
            NoeudCousu *gauche;
            NoeudCousu *droite;
            bool vraiSousArbreDroit;
            int status;

            void affectation(NoeudCousu *&noeudActuel, NoeudCousu *&dernierNoeudAGauche, int element);

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
            int getStatus();
            bool estVraiSousArbreDroit();

            //Setter
            void setElementGauche(NoeudCousu *&enfantGauche);
            void setElementDroite(NoeudCousu *&enfantDroite);
            void updateStatus(int newStatus);
    };
#endif