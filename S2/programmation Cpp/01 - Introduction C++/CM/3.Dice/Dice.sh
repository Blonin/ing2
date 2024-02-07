#!/bin/sh

##########################################################################
## Programme : Dice.sh                                                  ##
## Acces     : SE                                                       ##
## But       : Edition, Compilation, Exécution d'un programme           ##
##             Edition   : vi Dice.cpp                                  ##
##             Compil.   : gcc Dice.cpp -o Dice                         ##
##             Exécution : ./start                                      ##
##                                                                      ##
## Arguments                                                            ##
## - IN      : neant                                                    ##
## - IN#OUT  : neant                                                    ##
## - OUT     : neant                                                    ##
## Retour    : neant                                                    ##
##                                                                      ##
## Historique                       Date        Version  par            ##
## Création de Dice.sh              30/08/2022  1.0.00   Alain          ##
## #!/usr/bin/sh -> #!/bin/sh       19/09/2022  1.0.00   Alain          ##
##########################################################################

clear
echo "1.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Dice.c
cat Dice.c
echo "\r\n1.2 : Compilation du source (gcc Dice.c -o Dice)\r\n"
gcc Dice.c -o Dice
echo "1.3 : Execution (./Dice)"
./Dice
rm Dice
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear
echo "2.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Dice.cpp
cat Dice.cpp
echo "\r\n2.2 : Compilation du source (g++ Dice.cpp -o Dice)\r\n"
g++ Dice.cpp -o Dice
echo "2.3 : Execution (./Dice)"
./Dice
rm Dice
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear