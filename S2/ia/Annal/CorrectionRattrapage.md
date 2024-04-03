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

