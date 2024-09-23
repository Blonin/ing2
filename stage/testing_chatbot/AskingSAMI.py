# @Gustave Richter
# @file : testing.py
# @date : 19/06/24
# *description : fichier envoyant toutes les question du fichier csv puis 
# *enregistre dans un autre fichier les réponses, il fonctionne avec 
# *le fichier score.py 
# *Fichier qui envoie les questions a SAMI
#? utilisation du module "better comments" pour mettre en surbriance certain com

import time
from ami_bot.Conversation import Conversation
from enum import Enum
import json
from typing import List, Dict, Union

#enum des différentes variables facile a changer si des tests spécifiques sont voulus


class AskingSAMI :

    class Var(Enum):
        COMPANY_ID = 1
        USER_ID =2
        COMPANY_TYPE_ID =  4
        FOLDER_ID = 1
        USER_ROLE_ID =  2
        ASSISANT_NAME = "SAMI"

    def __init__(self) -> None: 
        self.listeQuestion: List[str] = []
        self.reponse: List[str] = []
        self.temps: List[float] = []
        self.rep: List[Dict[str, Union[str, float, int]]] = []
        self.id: List[int] = []
        self.assistant : str = self.Var.ASSISANT_NAME.value

    
    # sauvegarde la liste de question le liste de réponse et de temps dans le fichier outputhPath
    def sauvegarde(self, ouSauvegarder : str, listeDeQuestion: List[str]) -> None:
        
        for i,question in enumerate(listeDeQuestion, start=0) :
            self.rep.append({
                "question":question,
                "reponse": self.reponse[i],
                "temps de réponse": self.temps[i],
                "id":i
            })

        with open(ouSauvegarder,"w") as f:
            json.dump(self.rep,f,ensure_ascii=False, indent=4,sort_keys=True) # sort_keys=True pour qu'il format les dicts automatiquement
        

    #enregistre les données du "path" qui doit être un fichier json
    def enregistrementDesQuestion(self, path:str) :
        
        with open (path,'r',encoding='utf-8') as fichier:
            data = json.load(fichier)
    
        for donnee in data :
            self.listeQuestion.append(donnee['question'])


    # Envoi la liste de "question" à SAMI
    def question(self,question:list):
        current_conv = Conversation(
            company_id = self.Var.COMPANY_ID.value,
            user_id = self.Var.USER_ID.value, 
            company_type_id = self.Var.COMPANY_TYPE_ID.value, 
            folder_id = self.Var.FOLDER_ID.value, 
            user_role_id = self.Var.USER_ROLE_ID.value, 
            assistant_name = self.assistant
            )
        
        for question in question :
            start_time = time.time()
            response: List[Dict[str, str]]=( current_conv.single_conversation_step(
                user_input = str(question),
                user_message_id = 0,
                user_recording_path = None,
                test_mode=True)
                )
            self.reponse.append(response)
            
            #4 digit pour avoir un minimum de précision
            self.temps.append(round(time.time()-start_time,ndigits=4))
            # un sleep une seconde pour ralentir et éviter d'envoyer 400 question en un minimum de temps
            time.sleep(0.2)
            current_conv.history.reset()
        
        
        

if __name__ == "__main__" :
    question ="/opt/amic/ami_bot/testing_chatbot/csv/questionMiniList.json"
    rep = "/opt/amic/ami_bot/testing_chatbot/csv/reponseMiniList.json"
    ask =AskingSAMI()
    ask.enregistrementDesQuestion(question)
    ask.question(ask.listeQuestion)
    ask.sauvegarde(rep,ask.listeQuestion)

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