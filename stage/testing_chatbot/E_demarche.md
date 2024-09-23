# explication des tests
Objectif : Faire une série de question pour tester SAMI sur plusieurs point, et d'attribuer un score afin d'avoir un visuel
Objectif des test : 
* Évaluation des performances et tests en profondeur : 
    * Teneur du langage  
        1.    L'assistant doit répondre en français formel lorsqu'invoqué en français formel 
        1.    L'assistant doit répondre en français formel lorsque la requête emploie un langage inadéquat 
        1.    Aucune erreur permise sur la qualité du langage, ensemble de questions test à définir 
    * Véracité (Hallucination) 
        1. Hallucinations à réduire sous les 10% d'un ensemble de questions test à définir 
        1. Hallucinations non-permises sur un second ensemble à définir 
    * Complicité (Jailbreaking) 
        1. L'assistant doit refuser de répondre à des questions inadéquates (e.g. sur la concurrence, hors-sujet, avis personnel, illégalité, confidentialité) 
        1. Aucune erreur permise 
    * Fonctionnalités 
        1. L'assistant doit utiliser les fonctions à bon escient, et leurs retours ou effets de bord doivent correspondre à l'attendu humain 
        1. Pas d'ensemble de test spécifique, mais chaque fonctionnalité doit être incluse dans un autre ensemble de test, principalement l'ensemble sur les hallucinations 

## Détails
température = 0 du coup réponse toujours pareil? du coup analyse par exactitude?
Le changement du model entrain surement des changements de réponse
 
## <span style="color: #ff8000">TODO

- tester si l'on récuprère bien les réponses avec le fichier testing.py
- commencer le fichier score.py
  1. récupération du fichier output
  1. notation celon la réponse(content) et le temps 
    1. autre notation? les type de retour?
    1. changer l'accés de SAMI pour les graphique
  1. fichier testing.py
    1. amélioration de la récupération des messages
    1. erreur sur l'enregistrement du csv?
  1. Faire le fichier réponse attendu base de donnée 
    1. 

### <span style="color: #33ccff">Variables a possiblement tester

```
"import_source_name" : "UI",
          "import_source" : 1,
          "counterpart_and_journal_prediction_source" : null,
          "validated_journal" : "ACHATS",
          "invoice_details" : {
            "proposed_values" : [
              {
                "account" : "6010000000",
                "label" : "achats stockes mat pre & fourn",
                "prediction_source" : "Exercice",
                "prediction_reference_invoice_id" : null
              }
            ],
            "validated_values" : [
              {
                "account" : "6010000000",
                "label" : "ACHATS STOCKES MAT PRE & FOURN",
                "is_group_items_by_user" : false,
                "is_article" : true
              }
            ]
          },
          "is_cancelled" : false,
          "proposed_counterpart" : "4010000000 - FOURNISSEURS",
          "validated_counterpart" : "401T2 - 401T2",
          "validated_siret" : "83309251300200",
          "validated_siren" : "833092513",
          "validated_tva_number" : "fr92833092513",
          "ape" : "5829C",
          "company_id" : 1,
          "date" : "2023-07-26T12:44:19",
          "document_type" : null,
          "folder_details_id" : 1,
          "folder_type" : 1,
          "folder_number" : "010222",
          "folder_name" : "Dossier Démo 2",
          "group" : null,
          "ic" : 30.0,
          "invoice_pages_count" : 1.0,
          "validated_entity_id_counterpart" : 11076,
          "validated_total_ttc" : 300.0,
          "invoice_number" : "CVN1901",
          "is_autovalidated" : false,
          "edition_date" : "2023-07-06T11:51:39",
          "invoice_type" : 1,
          "invoice_type_name" : "invoice",
          "journal_type" : 1.0,
          "journal_type_name" : "Achat",
          "validated_by_user_code" : "SRI",
          "validated_by_user_email" : "admin_sri@ami-compta.fr",
          "validated_by_user_name" : "Rezzougui Sarah_adm",
          "exercice_date" : "Du 01/01/2019 au 31/12/2022",
          "modified_counterpart" : 1,
          "modified_entry_label" : 1,
          "modified_number" : 0,
          "modified_journal_type" : 0,
          "modified_journal_code" : 0,
          "modified_document_type" : 0,
          "modified_date" : 0,
          "modified_due_date" : 0,
          "modified_total_ttc" : 0,
          "modified_total_ht" : 1,
          "modified_total_tva" : 1,
          "modified_item_ht_account" : 0,
          "modified_item_ht_value" : 1,
          "modified_item_ht_mvt_label" : 1,
          "modified_item_tva_account" : 1,
          "modified_item_tva_value" : 1,
          "modified_item_tva_mvt_label" : 1,
          "modified_item_tva_code" : 0,
          "modified_item_rate" : 0,
          "modified_item_is_credit" : 0,
          "modified_first_item_ht_account" : 0.0,
          "modified_first_item_tva_code" : 0.0,
          "modified_first_item_rate" : 0.0,
          "modified_first_item_is_credit" : 0.0,
          "item_details_count" : 1,
          "receipt_pages_count" : 0.0,
          "handwriting_pages_count" : 0.0,
          "cgv_pages_count" : 0.0,
          "import_date" : "2022-01-11T15:42:39",
          "picto" : "RED",
          "user_id" : 2499,
          "pages_count" : 1.0,
          "prediction_reference_invoice_id" : null,
          "automation_rate" : 75.0,
          "folder_type_name" : "General",
          "exercice" : 1,
          "sector" : null,
          "site" : null,
          "invoice_id" : 1,
          "invoice_id_numeric" : 1
```

### <span style="color: #ff0000">ERREUR</span>

- problème sur l'écriture en enregistrement des fichier au format utf-8 csv
- chiant l'enregistrement au format csv a voir si un autre format ne serait pas meilleur

# <span style="color: #009933">Scoring data

## Balise dans Reponse
* role
* type
* content
* id

## Notation

La notation d'IA en ce moment se fait 5 grand critères :
+ Pertinence : La réponse est-elle pertinente par rapport à la question posée ?
+ Clarté : La réponse est-elle claire et compréhensible ?
+ Complétude : La réponse couvre-t-elle tous les aspects de la question ?
+ Exactitude : La réponse est-elle factuellement correcte ?
+ Style et Forme : La réponse est-elle bien formulée et exempte de fautes d'orthographe ou de grammaire ?

## Solution

Pour noter le style et la forme utilisation de grammarly? ou autre app ext a run en local? https://pypi.org/project/language-tool-python/
utilisation d'un word2vec pour faire l'analyse question réponse? https://www.datarobot.com/wiki/scoring/

discuter avec Mathias? cémantique

## Comparaison des réponses,
Quelle méthode serait la meilleur?



## FICHIER QUESTION REPONSE

### Que faire

- On veut un fichier avec la liste de question utile a tester et les réponses attendu

### Solution/questionnement
- plusieurs fichier? afin de tester en particulier certaine chose
- fichier json? csv?
- tester les appels de fonction => sorti exacte facile a vérifier


## <span style="color: #afffaa"> Source/Piste

+ Scoring
  - https://huggingface.co/openbmb/UltraRM-13b
  - https://objectiveit.com/blog/understanding-ai-scoring/
  - https://dpi.wi.gov/sites/default/files/imce/assessment/pdf/Forward%20AI%20Brief.pdf
  - https://www.datarobot.com/wiki/scoring/
  - https://scholar.google.fr/scholar?q=latest+research+about+scoring+an+AI&hl=fr&as_sdt=0&as_vis=1&oi=scholart
  - https://www.sciencedirect.com/science/article/pii/S2772766123000101
  - https://www.datarobot.com/wiki/scoring/
  - https://www.micropole.com/en/scoring-ai/
+ verification texte
  - <span style="color: #ff5599"> possiblement inutile :/ puisqu'il parle trop bien SAMI
  - [different spellchecking python](https://www.geeksforgeeks.org/spelling-checker-in-python/)
  - https://pypi.org/project/pyspellchecker/
  - [languagetool](https://languagetool.org/dev?_gl=1*1ooj9bg*_up*MQ..*_ga*ODg5NjQyNTE0LjE3MTk0NzMzNTg.*_ga_ME7QE3CGWG*MTcxOTQ3MzM1NS4xLjAuMTcxOTQ3MzM1NS4wLjAuMA..) </link>
  - https://textblob.readthedocs.io/en/dev/quickstart.html#create-a-textblob
+ Articles 
  - https://www.nature.com/
  - https://arxiv.org/
+ Vids
  - https://www.youtube.com/watch?v=fNxaJsNG3-s

### <span style="color: #afffaa"> Données utiles 

+ https://groupeisagri.sharepoint.com/sites/BSD/_layouts/15/Doc.aspx?sourcedoc={53b53329-f785-4ac2-9b5e-0c64063ad706}&action=edit&wd=target%28Documentation%2FIA%2FAMI%20Chatbot%20%28SAMI%5C%29.one%7C20fbb59e-15ea-48f7-b99f-ad3b3e4e08eb%2FFormat%20de%20donn%C3%A9es%7C4aa61b10-2e30-4928-b2f7-e084d6d22856%2F%29&wdorigin=NavigationUrl

### bibliothèque 
- https://spacy.io/
- TextBlob
- Genism
- Pattern
- Polyglot
- PyNLPI
- Pineapple
  ## source
  - https://datascientest.com/nltk
  - https://pypi.org/project/pyspellchecker/

# 01/07

+ Changement de méthode, le dossier processed_docs.json contient les question ainsi que les réponses attendu
+ je vais utiliser une llm pour verifier s'il n'y a pas de pollution
et dans un seconde temps je vais utiliser une llm pour verifier si les "mots clé" sont dans la réponse et si la réponse a du sens
_________

# 03/07

+ méthode pour faire des comparaisons trouver est implémanté, manque plus qu'a tester
+ liaison a faire entre le fichier testing.py avec sami pour lui envoyer les questions
- a finir la connection SAmi question  into comparaison ave'c la réponse a ttendu puis un scoring
+ Nomalisation (a voir si bon): https://mrmint.fr/data-preprocessing-feature-scaling-python
_________

# 04/07

+ je commence par essayer de faire le lien entre les deux fichiers similaroty.py et testing.py


# 08/07

+ je pense que le ce que je fais dans similarity ne sers a pas grand chose puisque cela est déjà fais avec une meilleur précision je devrais me concentrer sur les question sans réponse attendu

## TODO

retoucher le json questionprocessed pour bien formater les dict


+ revoir par rapport a la négation
+ méthode d'embbending possiblement pas adapté
+ comparé la rep rép de llm 
+ reformatage du fichier de question
+ et des réponses
+ création "d'addition" de question

+ fin sur similarityattendu sami renvoie bien le dictionnaire attendu juste gere comment enregistrer les données des réponses pour les comparer

# 30/07

