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
g++ -c light.cpp
g++ -c main.cpp
g++ -o LIGHT light.o main.o  
rm light.o
rm main.o

echo "3 : Execution (./LIGHT)\r\n"
./LIGHT
rm LIGHT

