// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

//Table de hashage / Contenu de la cellule
#include "arbre.h"
#include <stdlib.h>

int main()
{
    ArbreBinaireRecherche tree;
    for (int i = 0; i < 20;i++){
        tree.ajoutElement(rand() / 100,tree.racineTable(),0);
        tree.affichageTable(0, tree.racineTable());
    }
}
