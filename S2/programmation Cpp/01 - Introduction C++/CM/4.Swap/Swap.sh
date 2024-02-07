#!/bin/sh

##########################################################################
## Programme : Swap.sh                                                  ##
## Acces     : SE                                                       ##
## But       : Edition, Compilation, Exécution d'un programme           ##
##             Edition   : vi Swap.c                                    ##
##             Compil.   : gcc Swap.cpp -o Swap                         ##
##             Exécution : ./start                                      ##
##                                                                      ##
## Arguments                                                            ##
## - IN      : neant                                                    ##
## - IN#OUT  : neant                                                    ##
## - OUT     : neant                                                    ##
## Retour    : neant                                                    ##
##                                                                      ##
## Historique                       Date        Version  par            ##
## Création de Swap.sh              30/08/2022  1.0.00   Alain          ##
## #!/usr/bin/sh -> #!/bin/sh       19/09/2022  1.0.00   Alain          ##
##########################################################################

clear
echo "0.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Swap.0.c
cat Swap.0.c
echo "\r\n0.2 : Compilation du source (gcc Swap.c -o Swap)"
gcc Swap.0.c -o Swap
echo "\r\n0.3 : Execution (./Swap)"
./Swap
rm Swap
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear
echo "\r\n1.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Swap.1.cpp
cat Swap.1.cpp
echo "\r\n1.2 : Compilation du source (g++ Swap.1.cpp -o Swap)\r\n"
g++ Swap.1.cpp -o Swap
echo "1.3 : Execution (./Swap)"
./Swap
rm Swap
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear
echo "\r\n2.1 : Programmation du source (avec vi, gedit, code ...)"
#vi Swap.2.cpp
cat Swap.2.cpp
echo "\r\n2.2 : Compilation du source (g++ Swap.2.cpp -o Swap)\r\n"
g++ Swap.2.cpp -o Swap
echo "2.3 : Execution (./Swap)"
./Swap
rm Swap
printf "\r\n%s " "Appuyez sur n'importe quelle touche pour continuer..."
read ans

clear