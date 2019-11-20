#include "arbre.h"
#include <iostream>
#ifndef ADELSONVELSKYANDLANDIS
#define ADELSONVELSKYANDLANDIS
    class AVL : public ArbreBinaireRecherche{
        private:
            int besoinOperation(int hauteurActuelle);
            typedef ArbreBinaireRecherche super;
        public:
            void AVL_Rotation_Double_Droite(Noeud *&pN);
            void AVL_Rotation_Double_Gauche(Noeud *& pN);
            void AVL_Rotation_Droite(Noeud *& pN);
            void AVL_Rotation_Gauche(Noeud *& pN);
    };
#endif