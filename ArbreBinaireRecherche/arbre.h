#include <iostream>
#include "noeud.h"
using namespace std;
#ifndef table
#define table
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
            int ajoutElement(int nouvelElement, Noeud* &noeudActuel);
            void affichageTable(int quandAfficher, Noeud* &noeudActuel);

            Noeud* &racineTable();

            ~ArbreBinaireRecherche();

            ArbreBinaireRecherche operator=(const ArbreBinaireRecherche &autreArbre);
            int size();
            int size()const;
    };
#endif