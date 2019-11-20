# LIFAP6 - Automne 2017 - R. Chaine
main.ex : main.o arbre.o
# L'executable main.ex doit être remis à jour si certains des fichiers 
# main.o liste.o et element.o sont plus rêcents
	g++ -g main.o arbre.o

main.o : main.cpp arbre.h
# Le fichier objet main.o doit être remis à jour si certains des fichiers
# main.cpp liste.h et element.h sont plus rêcents
	g++ -Wall -ansi -pedantic -c main.cpp

arbre.o : arbre.cpp arbre.h
	g++ -Wall -c arbre.cpp $(CFLAGS)

clean :
	-rm *.o *~

delete : clean
	- rm *.ex
	- rm *.out