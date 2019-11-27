// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

//Table de hashage / Contenu de la cellule
#include "arbre.h"
#include "avl.h"
#include <stdlib.h>

int main()
{
    AVL avl = AVL();
    for (int i = 0; i < 20;i++){
        avl.ajoutElement(rand() / 100, avl.racineTable(), 0);
        cout << "Taille actuelle : " << avl.size() << "." << endl;
    }
    AVL avl2 = AVL(avl);
    avl.affichageTable(0,avl.racineTable());
    avl2.ajoutElement(55, avl.racineTable(), 0);
    avl2.affichageTable(0, avl2.racineTable());
}
