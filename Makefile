# LIFAP6 - Automne 2017 - R. Chaine
CFLAGS += -std=c++11
main.ex : main.o arbre.o
# L'executable main.ex doit être remis à jour si certains des fichiers 
# main.o liste.o et element.o sont plus rêcents
	g++ main.o arbre.o $(CFLAGS)

main.o : main.cpp arbre.h
# Le fichier objet main.o doit être remis à jour si certains des fichiers
# main.cpp liste.h et element.h sont plus rêcents
	g++ -Wall -ansi -pedantic -c main.cpp $(CFLAGS)

arbre.o : arbre.cpp arbre.h
	g++ -Wall -c arbre.cpp $(CFLAGS)

clean :
	-rm *.o *~

veryclean : clean 
	-rm *.ex

delete : veryclean
	- rm *.out