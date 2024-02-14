
#1.
en passant par le code assembler on remarquera qu'un ordi utilise
un système CISC alors que l'autre utilise un RISC, CISCétant la surement 
meilleur

example:
RISC vs CISC
x86 vs ARM
donc on ne peut pas tout simplement comparé le temps de résolution que sur le 
nombre de MIPS

#2.
1 000 000/40 = 25 000 
CPI=(cycles/instructions)

#3. IPC = intruction par cycle
ou  IPC = 35 000 / 17 000 =  2.059

#4.  time = nCrorale*10-6sec = 1.04 sec
    
    nCyclefp = 200 000 * 10 *0.6 = 800000
    nCycleautre = 200 000 *40 =  240 000
    nCycletotal== 1 040 000

#5.  a. 100/x = 1/( 0.1 + 0.9/10 ) => x=19sec
speed up = ancien temps / nouveau temps = 1/( FS+ FP/s) [cf p.41 du pdf]
    FS = 1-FP

s = nombre de coeur, s est quelque chose qui a été amélioré
par example

    90+10 = 100sec 
    9+10 = 19

    b. S= 100/19=5.26 (pas d'unité on divise un temps par un temps,
    il s'agit d'une amélioration)

    c. la fraction que prend le temps amélioré sur dans le système est de 
        9/19=0.47 => elle prend donc maintenant 47% du temps
        alors qu'avanat elle prenais 90% du temps

#6.  20/100 * 2 = 0.4
    70/100 * 1.3 = 0.91
on prefère donc utilise une amélioration de performance de 1.3 qui est utilisé 70% du temps
S= 1 /(1/(fs+fp/s))
 a. s=2 fp=0.2      S = 1 / (0.8+0.2/2) = 1/tnew = 0.9 <--- il s'agit de tnew
 b. s=1.3 fp=0.7    S = 1 / (0.3+0.7/1.3) = 1/tnew = 0.84 <-- meilleur temps 


#7.  S = 1 / (1/ (fs+ fp/s)) 
    ==> 1.2 = 1 / (0.6+0.4/s) ==> s = 1.71  pour une amélioration de 20%
    ==> 1.6 = 1 / (0.6+0.4/s) ==> s = 16 c'est énorme et c'est que pour une amélioration du système global de 60% 
il vaut mieux améliorer toutes les sous-système que d'améliorer un seul

#8.  S = 1/(1/ (fs + fp/s))
    ==> told/tnew = 1/0.2+0.8/4 =2.5

#9.  S = 1/(0.1+0.9/4) = 3.08

#10. S = 1/(0.52+48/4) = 1.56
    //!\ autre méthode
    S = 1/( (0.2+0.8/4) *0.6 +0.4 )

#11. S = 1 / ( (0.2+0.8/4) *0.6 + (0.1 + 0.9/4)*0.4 ) = 2.70
    E= S/P = 2.70/4 = 0.67 ==> efficacité de 67%


#12. //pour 12
    S = 1/(0.2+0.8/12)= 3.75
    S = 1/(0.1+0.9/12) = 5.71
    S = 1/( (0.2+0.8/12) *0.6 +0.4 ) = 1.79
    S = 1 / ( (0.2+0.8/12) *0.6 + (0.1 + 0.9/12)*0.4 ) = 4.35
    E= S/P = 4.35/12 = 0.36 ==> efficacité de 36%

    //pour 24
    S = 1/(0.2+0.8/24)= 4.29
    S = 1/(0.1+0.9/24) = 7.27
    S = 1/( (0.2+0.8/24) *0.6 +0.4 ) = 1.85
    S = 1 / ( (0.2+0.8/24) *0.6 + (0.1 + 0.9/24)*0.4 ) = 5.13
    E= S/P = 5.13/24 = 0.21 ==> efficacité de 21%

#13. 4 cores  -> 1000/2.70 = 370.3€ par "amélioration"
    12 cores -> 2500/4.35 = 574.7€ par "amélioration"
    24 cores -> 6000/5.13 = 1169.6€ par "amélioration"

#14. 
    Smax = told/tnew = 1000/0.3*1000 = 1/0.3 = 3.33

    S= 1/(0.3+0.7/p)
    smax lim p->+infini = 1/(0.3+0.7/p) ==> 1/0.3 = 3.33

#15. 
    S = told/tnew = tseq/tp = 1000 / ( 300 + 700/p +5*(p-1) )
    Tnew = 5p²+295p+700

#16. 
    graph

#17. 

