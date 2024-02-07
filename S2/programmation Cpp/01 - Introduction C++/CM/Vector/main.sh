#!/bin/sh
clear

##########################################################################
## Programme : main.sh                                                  ##
## Acces     : SE                                                       ##
## But       : Edition, Compilation, Exécution d'un programme           ##
##             Edition   : vi main.cpp                                  ##
##             Compil.   : g++ main.cpp -o main                         ##
##             Exécution : ./start                                      ##
##                                                                      ##
## Arguments                                                            ##
## - IN      : neant                                                    ##
## - IN#OUT  : neant                                                    ##
## - OUT     : neant                                                    ##
## Retour    : neant                                                    ##
##                                                                      ##
## Historique                       Date        Version  par            ##
## Création de main.sh              30/08/2022  1.0.00   Alain          ##
## #!/usr/bin/sh -> #!/bin/sh       19/09/2022  1.0.00   Alain          ##
##########################################################################

echo "1 : Programmation du source (avec vi, gedit, code ...)"
#vi main.cpp
cat main.cpp

echo "\r\n2 : Compilation du source (g++ light.cpp main.cpp -o LIGHT)\r\n"
g++ -c Vector.cpp
g++ -c main.cpp
g++ -o VECTOR Vector.o main.o  
rm Vector.o
rm main.o

echo "3 : Execution (./VECTOR)\r\n"
./VECTOR
rm VECTOR

