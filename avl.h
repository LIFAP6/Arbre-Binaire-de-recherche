#include "arbre.h"
#include <iostream>
#ifndef ADELSONVELSKYANDLANDIS
#define ADELSONVELSKYANDLANDIS
    class AVL : public ArbreBinaireRecherche{
        private:
            ArbreBinaireRecherche arbre;
            int besoinOperation(Noeud* &noeudActuel);
            void equilibrer(Noeud* &noeudActuel);
            void AVL_Rotation_Double_Droite(Noeud *&pN);
            void AVL_Rotation_Double_Gauche(Noeud *& pN);
            void AVL_Rotation_Droite(Noeud *& pN);
            void AVL_Rotation_Gauche(Noeud *& pN);
        public:
            int ajoutElement(int nouvelElement, Noeud* &noeudActuel, int hauteur);
            AVL(const AVL &rawAvl);
            AVL();
    };
#endif