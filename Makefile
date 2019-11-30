# LIFAP6 - Automne 2017 - R. Chaine
main.ex : main.o arbre.o arbrecousu.o noeudcousu.o
# L'executable main.ex doit être remis à jour si certains des fichiers 
# main.o liste.o et element.o sont plus rêcents
	g++ -g main.o arbre.o arbrecousu.o noeudcousu.o
main.o : main.cpp arbre.h arbreCousu/arbrecousu.h arbreCousu/noeudcousu.h
# Le fichier objet main.o doit être remis à jour si certains des fichiers
# main.cpp liste.h et element.h sont plus rêcents
	g++ -Wall -ansi -pedantic -c main.cpp

noeudcousu.o : arbreCousu/noeudcousu.cpp arbreCousu/noeudcousu.h
	g++ -Wall -c arbreCousu/noeudcousu.cpp

arbrecousu.o : arbreCousu/arbrecousu.cpp arbreCousu/arbrecousu.h
	g++ -Wall -c arbreCousu/arbrecousu.cpp

arbre.o : arbre.cpp arbre.h
	g++ -Wall -c arbre.cpp $(CFLAGS)

clean :
	-rm *.o *~

delete : clean
	- rm *.ex
	- rm *.out