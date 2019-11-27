#include <iostream>
using namespace std;
#ifndef table
#define table
    class Noeud
    {
        private:
            int element;
            int hauteur;
            Noeud *droite;
            Noeud *gauche;

        public:
            Noeud(int element);
            Noeud(int element, int hauteur);
            Noeud(const Noeud &n);
            Noeud();
            void setElement(int element);
            void setHauteur(int nouvelleHauteur);
            int getHauteur();
            int getElement();
            int nombreElements(Noeud *&noeudActuel, int nbElements);

            //Getters
            Noeud *&getElementDroite();
            Noeud *&getElementGauche();

            void setElementGauche(Noeud *&nouveauNoeudGauche);
            void setElementDroite(Noeud *&nouveauNoeudDroite);

            ~Noeud();

            Noeud &operator=(const Noeud &autreNoeud);
            bool operator<(const Noeud &autreNoeud);
            bool operator==(const Noeud &autreNoeud);
    };

    class ArbreBinaireRecherche{
        private:
            Noeud *racine;
            int sizeRec(int currentSize, Noeud* &noeudActuel);

        public:
            //Constructeur par défaut
            ArbreBinaireRecherche();
            ArbreBinaireRecherche(const ArbreBinaireRecherche &autreArbre);

            //Recherche d'un élément
            Noeud*& rechercheElement(int element, Noeud *&noeudActuel);

            //Ajout d'un élément
            virtual int ajoutElement(int nouvelElement, Noeud* &noeudActuel, int hauteur);
            void affichageTable(int quandAfficher, Noeud* &noeudActuel);

            Noeud* &racineTable();

            ~ArbreBinaireRecherche();

            ArbreBinaireRecherche operator=(const ArbreBinaireRecherche &autreArbre);
            bool operator==(const ArbreBinaireRecherche &premierArbre);
            int size();
    };
#endif