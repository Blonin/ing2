#!/bin/sh

##########################################################################
## Programme : Bonjour.sh                                               ##
## Acces     : SE                                                       ##
## But       : Edition, Compilation, Exécution d'un programme           ##
##             Edition   : vi Bonjour.c                                 ##
##             Compil.   : gcc Bonjour.cpp -o Bonjour                   ##
##             Exécution : ./start                                      ##
##                                                                      ##
## Arguments                                                            ##
## - IN      : neant                                                    ##
## - IN#OUT  : neant                                                    ##
## - OUT     : neant                                                    ##
## Retour    : neant                                                    ##
##                                                                      ##
## Historique                       Date        Version  par            ##
## Création de Bonjour.sh           30/08/2022  1.0.00   Alain          ##
## #!/usr/bin/sh -> #!/bin/sh       19/09/2022  1.0.00   Alain          ##
##########################################################################

clear
echo "0.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Bonjour.0.c
cat Bonjour.0.c
echo "\r\n0.2 : Compilation du source (gcc Bonjour.c -o Bonjour)"
gcc Bonjour.0.c -o Bonjour
echo "\r\n0.3 : Execution (./Bonjour)"
./Bonjour
rm Bonjour
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear
echo "\r\n1.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Bonjour.1.cpp
cat Bonjour.1.cpp
echo "\r\n1.2 : Compilation du source (g++ Bonjour.1.cpp -o Bonjour)\r\n"
g++ Bonjour.1.cpp -o Bonjour
echo "1.3 : Execution (./Bonjour)"
./Bonjour
rm Bonjour
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear
echo "\r\n2.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Bonjour.2.cpp
cat Bonjour.2.cpp
echo "\r\n2.2 : Compilation du source (g++ Bonjour.2.cpp -o Bonjour)\r\n"
g++ Bonjour.2.cpp -o Bonjour
echo "2.3 : Execution (./Bonjour)"
./Bonjour
rm Bonjour
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear