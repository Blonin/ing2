import csv
import json
from typing import Union

# Classe pour transformer les données
class Tranform():

    # Enregistre chaque ligne d'un CSV dans une case de la liste "listeQuestion" au format JSON
    def csvToJson(self,input: str,output: str) :
        # Liste pour stocker les données du CSV
        donnees: list[dict[str, str | int | list[str]]] = []
        # Ouvre le fichier CSV en lecture
        with open(input,"r") as f :
            reader = csv.reader(f,dialect='excel',)
            for i,row in enumerate(reader,start=0):
                # Nettoyage des phrases récupérées dans le CSV
                self.nettoyageList(row)
                # Ajoute les données nettoyées à la liste
                donnees.append({
                    "id":i,
                    "questions":row,
                    "function":"",
                    "link":"",
                    "reponse":""
                })
        # Écrit les données dans un fichier JSON
        with open(output,"w") as f:
            json.dump(donnees,f,ensure_ascii=False, indent=2)

    # Fonction pour nettoyer les différents caractères non désirables suite à la lecture du CSV
    @staticmethod
    def nettoyageList(self, p: list ) -> None :
        for i, phrase in enumerate(p):
            l: str = str(phrase).replace("[", "").replace("]", "").replace("}", "").replace("{", "")
            l = l.replace('"', '').replace("\n", "")
            p[i] = l

    @staticmethod
    def nettoyagePhrase(p: str ) -> str :
        l: str = p.replace("[", "").replace("]", "").replace("}", "").replace("{", "")
        l = l.replace("(", " ").replace(")", " ").replace('"', "")
        l = l.replace("'", " ").replace(",", "").replace(".", " ").replace("/", " ")
        l = l.replace(":", "").replace("-", " ").replace("_", " ")
        return l
    
    #utilisation unique sauf si d'autre fichier json arrive
    @staticmethod
    def reFormJson(fichier : str) -> None :
        # Listes pour stocker les différents éléments du JSON
        question: list[str] = []
        function: list[str] = []
        link: list[str] = []
        role: list[str] = []
        type_: list[str] = []
        content: list[Union[str, dict[str, str]]] = []
        reponse: list[dict[str, str, str]] = []
        donnees: list[dict[str, str| int| dict[str, str| dict[str, str]]]] = []

        # Ouvre le fichier JSON en lecture
        with open(fichier,'r',encoding='utf-8') as f :
            data = json.load(f)


        for i,donnee in enumerate(data):
            question.append(donnee['question'])
            function.append(donnee['function'])
            link.append(donnee['link'])
            if donnee['link'] != '' :
                role.append('knowledge')
                type_.append('link')
            else :
                role.append('assistant')
                type_.append('text')

            # Vérifie si 'reponse' est un dictionnaire
            if isinstance(donnee['reponse'],dict) :
                if "documentation_page" in donnee['reponse'] :
                    content.append({
                        'doc':donnee['reponse']['documentation_page'],
                        'content':donnee['reponse']['message']
                        })
                elif "message" in donnee['reponse']:
                    content.append(donnee['reponse']['message'])
                else :
                    content.append(donnee['reponse']['content'])
            else :
                # Si 'text_content' est une chaîne de caractères
                content.append(donnee['reponse'])
            
            reponse.append({
                'content':content[i],
                'role':role[i],
                'type':type_[i]
            })
            


        print(f"{type(reponse)}")
        for j, quest in enumerate(question,start=0):
            donnees.append( {
                'id':j,
                'question':quest,
                'function':function[j],
                'link':link[j],
                'reponse':reponse[j],
            })

        # Écrit les données reformées dans un fichier JSON
        with open(fichier, 'w', encoding='utf-8') as f:
            json.dump(donnees, f, ensure_ascii=False, indent=2)

if __name__ == "__main__" : 
    f= "/opt/amic/ami_bot/testing_chatbot/csv/processed_docs.json"

    transform= Tranform()
    transform.reFormJson(f)

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