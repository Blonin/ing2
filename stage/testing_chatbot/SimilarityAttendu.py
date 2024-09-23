# source : https://platform.openai.com/docs/api-reference/chat/create?lang=python

import openai
from openai.embeddings_utils import get_embedding
from ami_compta.bslib.config import conf_amibot

from typing import Any
config: 'dict[dict]' = conf_amibot

import json
from tqdm import tqdm

from sklearn.metrics.pairwise import cosine_similarity

class SimAttendu:
    
    def __init__(self, path:str, model : str = 'défaut') -> None:

        # initialisation des clé d'api
        openai.api_type      = config['API']['api_type']
        openai.api_key       = config['API']['api_key']
        openai.api_base      = config['API']['api_base']
        openai.api_version   = config['API']['api_version']
        #! model a changé pour tester d'autre model
        self.embedding_model = config['API']['embedding_model']

        if model != 'défaut':
            self.embedding_model = model
        
        self.dist: list[float] = [] # Liste pour stocker les distances
        self.score : list[float] = []

        # Charger les données depuis le fichier JSON
        with open(path, 'r', encoding='utf-8') as fichier:
            self.data: list[dict[str, Any]] = json.load(fichier)
    
    # toujours envoyer en data_2 les réponses obtenus 
    # @data_2 : donnée du fichier avec les réponses obtenus
    def distance(self, data_2:list) -> None:
        
        i: int = 0  # Index pour parcourir les données
        for a in tqdm(self.data) :
            if a['reponse']['type']=='text' :
                #!FONCTIONNE 
                # Obtenir l'embedding de la réponse attendue
                L1 : list[float] = get_embedding(
                        a['reponse']['content'],
                        engine=self.embedding_model)
                # Calculer la distance pour chaque réponse obtenue normalement ici il n'y en a qu'une seule asuf quelle est sous forme de liste donc 
                # j'utilise un "for r" afin de l'avoir en str
                for r in data_2[i]['reponse'][0]['content'] :
                    L2 : list[float] = get_embedding(
                        r,
                        engine=self.embedding_model)
                # Ajouter la similarité cosinus à la liste des distances
                self.dist.append(cosine_similarity([L1], [L2])) 
                
            # comparaison s'il s'agit d'un lien, vérifie si au moins un des liens renvoyer est celui attendu
            elif a['reponse']['type']=='link':
                #! fin ici check le type pour avoir le bon content et comparaison de la liste de content! ET BINGO
                for r in data_2[i]['reponse'] :
                    if r['type']== 'link' :
                        score_dist_link : float = 0 
                        for j in range(len(r['content'])) :

                            L1 : list[float] = get_embedding(
                                a['link'],
                                engine=self.embedding_model
                            )
                            L2 : list[float] = get_embedding(
                                r['content'][j],
                                engine=self.embedding_model
                            )
                            s : float = cosine_similarity([L1], [L2])

                            if score_dist_link<s :
                                score_dist_link=s
                self.dist.append(score_dist_link)

            #! Comparaison si la fonction appelé est la bonne      
            elif a['reponse']['type']=='function':
                #?vérification si la bonne fonction est appellé sinon zéro point
                if a['reponse']['name'] == data_2[i]['reponse'][0]['name'] :
                    r = data_2[i]['reponse'][0]['content']
                    isValide : bool = True
                    for key_,value in a['reponse']['content'].items():
                        if value != r.get(key_,"pasDéfini") :
                            isValide = False    
                    print(isValide)
                    if isValide :
                        self.dist.append(1)
                    else :
                        self.dist.append(0)
                else :
                    self.dist.append(0)
            else :
                # Si le type de réponse n'est pas 'text' ni dans 'link', ajouter 0 à la liste des distances pour le moment cela met en évidence cce qu'il reste a faire
                self.dist.append(0)
            i += 1


    def scoreTime(self) :
        max : float = 0
        min : float = 0
        for temps in self.data :
            if max < temps['temps de réponse'] :
                max = temps['temps de réponse']
            if min > temps['temps de réponse'] :
                min = temps['temps de réponse']
        for time in self.data :
            score : float = (time['temps de réponse'] -min) / (max-min)
            # Inverser la normalisation pour que le temps le plus bas ait la meilleure note
            self.score.append(round(1 - score,4))
        

if __name__ == "__main__" :

    # Chemin du fichier contenant les questions
    Quest='/opt/amic/ami_bot/testing_chatbot/csv/questionMiniList.json'
    questiontest=SimAttendu(Quest)

    # Chemin du fichier contenant les réponses
    Rep='/opt/amic/ami_bot/testing_chatbot/csv/reponseMiniList.json'
    reptest=SimAttendu(Rep)

    # Calculer les distances entre les questions et les réponses
    questiontest.distance(reptest.data)
    reptest.scoreTime()
    for i in questiontest.dist :
       print(i)



#  _________________
# |# :           : #|
# |  :           :  |
# |  : @Richter  :  |
# |  : @Gustave  :  |
# |  :___________:  |
# |     _________   |
# |    | __      |  |
# |    ||  |     |  |
# \____||__|_____|__|