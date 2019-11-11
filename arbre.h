#ifndef table
#define table
    class Noeud{
        private:
            int element;
            Noeud *droite;
            Noeud *gauche;
        public:
            Noeud(int element);
            Noeud(const Noeud& n);
            void setElement(int element);
            int getElement();
            int nombreElements(Noeud* &noeudActuel, int nbElements);

            Noeud*& getElementDroite();
            Noeud*& getElementGauche();

            void setElementGauche(Noeud *&nouveauNoeudGauche);
            void setElementDroite(Noeud *&nouveauNoeudDroite);
    };

    class ArbreBinaireRecherche{
        private:
            Noeud *racine;

        public:
            //Constructeur par défaut
            ArbreBinaireRecherche();

            //Recherche d'un élément
            Noeud** rechercheElement(int element, Noeud *&noeudActuel);

            //Ajout d'un élément
            int ajoutElement(int nouvelElement, Noeud* &noeudActuel);
            void affichageTable(int quandAfficher, Noeud* &noeudActuel);

            Noeud* &racineTable();
    };
#endif