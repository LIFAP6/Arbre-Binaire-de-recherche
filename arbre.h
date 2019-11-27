#include <iostream>
using namespace std;
#ifndef table
#define table
    class Noeud
    {
        private:
            int element;
            Noeud *droite;
            Noeud *gauche;

        public:
            Noeud(int element);
            Noeud(const Noeud &n);
            Noeud();
            void setElement(int element);
            int getElement();
            int getElement() const;
            int nombreElements(Noeud *&noeudActuel, int nbElements);
            int nombreElements(Noeud *&noeudActuel, int nbElements)const;

            //Getters
            //pas const
            Noeud *&getElementDroite();
            Noeud *&getElementGauche();

            //const
            Noeud *&getElementDroite()const;
            Noeud *&getElementGauche()const;

            void setElementGauche(Noeud *&nouveauNoeudGauche);
            void setElementDroite(Noeud *&nouveauNoeudDroite);

            ~Noeud();

            Noeud &operator=(const Noeud &autreNoeud);
            bool operator<(const Noeud &autreNoeud);
    };

    class ArbreBinaireRecherche{
        private:
            Noeud *racine;

        protected:
            int sizeRec(int currentSize, Noeud* &noeudActuel);

        public:
            //Constructeur par défaut
            ArbreBinaireRecherche();
            ArbreBinaireRecherche(const ArbreBinaireRecherche &autreArbre);

            //Recherche d'un élément
            Noeud*& rechercheElement(int element, Noeud *&noeudActuel);

            //Ajout d'un élément
            int ajoutElement(int nouvelElement, Noeud* &noeudActuel);
            void affichageTable(int quandAfficher, Noeud* &noeudActuel);

            Noeud* &racineTable();
            Noeud *racineTable() const;

            ~ArbreBinaireRecherche();

            ArbreBinaireRecherche operator=(const ArbreBinaireRecherche &autreArbre);
            int size();
            int size()const;
    };
#endif