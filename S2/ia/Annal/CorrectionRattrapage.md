# Correction Rattrapage IA 
## Apprentissage par renforcement
## Sujet :
Soit le graphe décrivant la mise en production d’un modèle d’IA avec quelques étapes importantes et la probabilité de transition entre celles-ci.
    Les étapes sont : 
{ Récupération des données (R), 
Labélisation des données (L), 
Prétraitement des données (P),
Construction et entraînement d’un modèle (C), 
Test du modèle (T), 
Mise en production (M) } .

Les probabilités de transition sont les suivantes :

+ (a) Récupération des données → Labélisation avec une probabilité de 0.9 ou Récupération des données (0.1)
+ (b) Labélisation des données → Prétraitement des données (0.75) ou Construction d’un modèle (0.2) ou Récupération (0.05),
+ (c) Construction et entraînement d’un modèle → Test du modèle (0.8) ou Mise en production (0.2),
+ (d) Test du modèle → Mise en production (0.5) ou Récupération des données (0.25) ou Labélisation (0.25),
+ (e) Mise en production → Mise en production (1).

Les récompenses associées sont de 10 pour la mise en production, 8 pour une arrivée sur le Test du modèle, 1 pour la Construction du modèle et 4 pour la Récupération des données. Les autres seront à 0.

## Apprentissage par renforcement 1

### 1 Faire un schéma récapitulatif et donner la matrice de transition.

On doit attribuer des valeur de transition a l'état "Prétraitement des données (P) 
+ Prétraitement des donnée → Labélisation des données (0.3) ou Construction et entraînement d’un modèle (0.7)

Schéma:

Graphe représentant la mise en production d'un modèle d'IA avec les étapes et les probabilités de transition ; 
![Schéma](schemaMatrice.jpg "Schéma de la matrice de transition")

Matrice de transition:

|État actuel    | R     | L     | P     | C     | T     | M     |
|---------------|-------|-------|-------|-------|-------|-------|
|R              | 0.1   | 0.9   | 0     | 0     | 0     | 0     |
|L              | 0.05  | 0     | 0.75  | 0.2   | 0     | 0     |
|P              | 0     | 0.3   | 0     | 0.7   | 0     | 0     |
|C              | 0     | 0     | 0     | 0.8   | 0.2   | 0     |
|T              | 0     | 0     | 0     | 0     | 0.5   | 0.5   |
|M              | 0     | 0     | 0     | 0     | 0     | 1     |
|Récompense     | 0.1   | 0.3   | 0.4   | 0.5   | 0.8   | 1     |
### 2 Donner trois exemples de suites d’états possibles.

+ R, L, P, C, T, M
+ R, L, C, T, M
+ R, L, P, C, T, T, M

### 3 En utilisant le système de récompense, expliquer comment calculer la valeur de chaque état

on multiplie la probabilitée de l'état et sa récompense
part on des équation de bellman définissant les valeurs des états :
pour tout états ,
comme on est dans un ensemble d'états fini faire une représentation matricielle:
V = R + gama * P * V 
=> V - gama * P * V = R
=> (Id - gama * P ) * V = R
=> V = (Id - gama * P)-¹ * R

## 2 Apprendtissage par renforcement 2

### 4 Proposer une modélisation (détaillée) de ce problème.

Etats : S = {16 case états désignées par des coord(xi,yi)}; 
Action : Déplacement de l'agent dans l'une des quatres directions A= (haut,bas,droite,gauche)
Transition : T = En tout état s, on peut réaliser n'importe qu'elle action
Récompense :
- -1 : Si l'action nous fait sortir de la grille
- -10 : Si l'action nous amène sur une case noir
- +10 : Si l'action nous amène sur une case verte
- 0 : Sinon

### 5 Donner la définition d’une stratégie et donner un exemple de stratégie non optimale et un autre d’une stratégie optimale.

+ Deterministe
strat: S -->A
+ Probaliste 
strat: S*A -->S

Supposons s1 l'état initiale.

+ Stratégie non optimale :
S1 bas
S5 gauche
S2 haut
S3 droite
S4 gauche

+ Stratégie optimale :
S1 droite
S2 droite
S3 bas

### 6 Donner la différence entre les méthodes model-based et model free. Pour chacune d’elles, donner un algorithme.

## 3 Deep learning 

### 7. Sur la figure 2, commenter les étapes 2 et 3.

l'étape numéro 1 consiste a faire une normalisation des donnée de sorte que toutes les valeurs soient dans [0.1]
l'étape numéro 2 est de la classification traité les variables catégorielles
les labels sont encodées apr des entiers qui représentent des variables catégorielle l'opération permet au modèle de ne faire de régression et prédire un label 

### 8. Sur la figure 3, décrire (sans répétition) les différentes couches.

+ input : couche d'entré du réseaux adaptée a la forme des images (32.32.3)
canva2D: couche de convolution de 32 ou 64 filtres de taille (3.3) avec une fonction d'activation relu
maxpooling2D : sous échantillonne les torseurs en entrée en divisant par 2 la hauteur et la largeur
Flatten : permet de redimensionner un te sous forme de vecteur pour se servier d'entrer a un réseau entierement connecté
Dropout : désactive un neurone avec 50% de chance d'éviter le surentrainement
Dense : c'est le classificateur de la couche finale a 10 neuronne ( car 10 labels) avec une activation softmax pour retrouver un vecteur de proba a 10 composante chaque composant est la proba que l'image appartienne a la classe  représenté sous la forme de vecteurs avec des 0 et 1 sur la composante de la classe associé

### 9. À partir de la figure 3, retrouver les hyperparamètres manquants.
### 10. Sur la figure 5, commenter/décrire/expliquer les hyperparamètres loss, optimizer et metric


## 4 Optimisation
### 4.1 Compréhension
#### 11. Définir la notion de problème à variables discrètes et problème à variables continues. Citer une méthode pour
résoudre chacun d’entre eux.
#### 12. On souhaite utiliser une métaheuristique pour résoudre un problème d’optimisation dont on ne connaît absolument
pas l’optimum. Comment évaluer la pertinence de sa réponse et sa stabilité ?
#### 13. Définir la notion de convergence pour l’algorithme du recuit simulé.
### 4.2 Application
### Sujet :
Nous souhaitons générer de manière automatique l’emploi du temps des ING2 GSI et MI, considérant le fait qu’il n’y a
qu’un seul groupe par parcours.
Générer un emploi du temps consiste à positionner un ensemble de n créneaux de 1h30 dans la semaine (on supposera
qu’il existe au moins une configuration admissible).
Un créneau consiste à affecter une heure de début, un cours, un groupe d’étudiants et une salle (avec une capacité).
Un cours représente un couple prof / séance. Une séance est un CM ou un TD.
Entre deux créneaux, il est nécessaire d’avoir 15 min de pause réglementaire et on ne fait pas cours avant 8h, de 12h30 à
13h30 et après 20h.
#### 14. Proposer une représentation pour décrire une solution candidate.
#### 15. Étudier les contraintes d’admissibilité/faisabilité (explicites et implicites).
#### 16. Quelle métaheuristique pourriez-vous utiliser pour résoudre ce problème ? Justifier