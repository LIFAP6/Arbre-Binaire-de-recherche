#ifndef NOEUD
#define NOEUD
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
#endif