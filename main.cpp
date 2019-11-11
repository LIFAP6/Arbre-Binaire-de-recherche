// LIFAP6 - Automne 2017 - R. Chaine

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "arbre.h"

int main()
{
    ArbreBinaireRecherche arbre = ArbreBinaireRecherche();
    arbre.ajoutElement(3, arbre.racineTable());
    arbre.ajoutElement(4, arbre.racineTable());
    arbre.ajoutElement(1, arbre.racineTable());
    arbre.ajoutElement(2, arbre.racineTable());
    arbre.ajoutElement(12, arbre.racineTable());
    arbre.affichageTable(0, arbre.racineTable());
    arbre.ajoutElement(12, arbre.racineTable());
}
