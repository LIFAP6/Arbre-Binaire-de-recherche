# LIFAP6 - Automne 2017 - R. Chaine
main.ex : main.o arbre.o noeud.o
# L'executable main.ex doit être remis à jour si certains des fichiers 
# main.o liste.o et element.o sont plus rêcents
	g++ -g main.o arbre.o

main.o : main.cpp arbre/arbre.h arbre/noeud.h
# Le fichier objet main.o doit être remis à jour si certains des fichiers
# main.cpp liste.h et element.h sont plus rêcents
	g++ -Wall -ansi -pedantic -c main.cpp

arbre.o : arbre/arbre.cpp arbre/arbre.h
	g++ -Wall -c arbre/arbre.cpp

noeud.o : arbre/noeud.h arbre/noeud.cpp
	g++ -Wall -c arbre/noeud.cpp

clean :
	-rm *.o *~

delete : clean
	- rm *.ex
	- rm *.out