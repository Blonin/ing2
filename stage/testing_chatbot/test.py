# @file : testing.py
# @date : 19/06/24
#from AskingSAMI import AskingSAMI
#from ami_bot.testing_chatbot.SimilarityAttendu import SimAttendu
import json
import datetime
import os

#from ami_bot.Conversation import Conversation

def sauvegarde(dist : list, temps : list, moy_tps : float, moy_dist : float, fichier : str, model : str, name : str) -> None:
    print('saving')

    val: dict[list[int, str, str ]] = []
    donnees: dict [dict[list[int, str, float ]]] = []

    for i in range(len(dist)) :
         val.append({
                    "id":i,
                    "temps":temps[i],
                    "distance":float(dist[i])
                })
    donnees.append({
         'model' : model,
         'distance moyenne' : moy_dist,
         'temps moyen' : moy_tps,
         'valeur' : val

    })

    fichier  += name + '-' + model + datetime.datetime.today().strftime('_%d-%m-%Y_%H:%M:%S') + '.json'
    print(fichier)
    with open(fichier,"x") as f:
       json.dump(donnees,f,ensure_ascii=False, indent=2)
    
    
def choixDoc(repertoire : str) -> str :
    """
    Permet à l'utilisateur de choisir un fichier JSON dans un répertoire.

    :param repertoire: Chemin du répertoire contenant les fichiers
    :return: Nom du fichier choisi
    """

    fichiers = [f for f in os.listdir(repertoire) if f.endswith('.json')]
    print("\nVeuillez choisir un fichier parmi la liste suivante:")
    for i, fichier in enumerate(fichiers, start=1):
        print(f"{i}. {fichier}")
    
    choix = int(input("\nEntrez le numéro du fichier que vous souhaitez utiliser: "))
    return fichiers[choix - 1]


def changerDoc():
    """
    Change les fichiers de base pour les tests.

    :return: Tuple contenant les chemins des fichiers de question, réponse et le type de fichier
    """

    print("\n \nVeullez choisir les 3 fichier de base pour les tests :")
    fQuest : str = '/opt/amic/ami_bot/testing_chatbot/fichier/question/' + choixDoc('/opt/amic/ami_bot/testing_chatbot/fichier/question')
    fRep : str = '/opt/amic/ami_bot/testing_chatbot/fichier/reponse/' + choixDoc('/opt/amic/ami_bot/testing_chatbot/fichier/reponse')
    
    print('''\nDe quel type de fichier s'agit'il?
                            1                              2                                   3
                         Globale                         Texte                               Liens
                            4                              5  
                         Function                        Autre ''')
    
    #? possibilité de faire juste taper une chaine de cara a l'utilisateur et de l'utiliser comme tel
    typechoix = input()
    fichierScore : str = '/opt/amic/ami_bot/testing_chatbot/fichier/score/'
    if typechoix == '1' :
        fichierScore += 'Globale'
    elif typechoix == '2' :
        fichierScore += 'Texte'
    elif typechoix == '3' :
        fichierScore += 'Liens'
    elif typechoix == '4' :
        fichierScore += 'Function'
    else :
        fichierScore += 'Autre'

    return (fQuest,fRep,fichierScore)

def menu() -> None:
    """
    Menu principal pour l'interaction avec l'utilisateur.
    """
    is_chat_active : bool = True
    

    fQuest : str = ''
    fRep : str = ''
    fichierScore : str = ''
#    askSAMI = AskingSAMI()
    
    #fQuest,fRep,fichierScore = changerDoc()

    while is_chat_active :
            print('''\nQue voulez vous faire ?\n
                            1                              2                                   3
                    Lancer les tests          ajouter de nouvelle question         (re)Poser les questions a SAMI
                            4                              5                                   6
                    Afficher résultats                   Bilan                         Changer de dossier
                            7                              8
                    Changer l'assistant                 Quitter
                    ''')

            print("\n Utilisateur : ")
            message=input()
            
            if is_chat_active :
                
                #questiontest=SimAttendu(fQuest)
                #reptest=SimAttendu(fRep)
                
                #!Lancer les tests
                if message == '1' : 
                    questiontest.distance(reptest.data)
                    moy_tps = reptest.scoreTime()
                    moy_dist :float =0
                    moy_tps :float =0

                    for i in questiontest.dist :
                        moy_dist += float(i)
                    for j in reptest.score :
                        moy_tps  += float(j)

                    moy_dist = moy_dist / len(questiontest.dist)
                    moy_tps = moy_tps / len(reptest.score)
                    moy_tps = round(moy_tps,4)
                    moy_dist = round(moy_dist,4)

                    sauvegarde(questiontest.dist, reptest.score, moy_tps, moy_dist, fichierScore, reptest.embedding_model, askSAMI.assistant)
                    

                #! Ajout de nouvelle question
                elif message == '2' :
                    # Charger le fichier JSON
                    with open(fQuest, 'r', encoding='utf-8') as f:
                        data = json.load(f)

                    question : str = ''
                    function : str = ''
                    link : str = ''
                    reponse : dict[str,str,str] = {'','',''}
                    choix: int = -1

                    print('\n Quel est votre question :')
                    question=input()
                    
                    chat_choix : bool = True
                    while(chat_choix):
                        print('''\n Quel type de réponse est attendu \n
                    
                                1                              2                               3
                           Que du texte          Un lien est attendu en retour         tester une fonction
                              
                                4
                             Quitter                ''')
                        choix = input()

                        id :int = len(data)+1

                        if choix == '1' :
                            print('\n Quelle réponse est attendue :')
                            reponse=input()
                            role = 'assistant'
                            type_ = 'text'
                            function = ''
                            link = ''
                            chat_choix = False

                        elif choix == '2' :
                            print('\n Quel lien est attendu :')
                            link=input()
                            reponse = ''
                            role = 'knowledge'
                            type_ = 'link'
                            function = ''
                            chat_choix = False

                        #! 'complexe' a implementer sera plus rapide de juste ajouter dans le json les questions voulu avec les réponses attendu
                        elif choix == '3' :
                            print('\n Demande a l\'équipe IA pour cela !!\n')

                        elif choix == '4' :
                            chat_choix = False

                        else :
                            print("Erreur sur le choix de la réponse attendu")
                    
                    if choix != '4' :

                        print(f' Question :{question} \n Réponse :{reponse}\n Lien :{link}\n Fonction :{function}')

                        new_quest: dict[str, any] = {
                            'id': id,
                            'question': question,
                            'function': function,  
                            'link': link,
                            'reponse': 
                            {
                                'content': reponse,  
                                'role': role,
                                'type': type_
                            }
                        }
                        # Ajouter la nouvelle question aux données existantes
                        data.append(new_quest)

                        # Enregistrer les données mises à jour dans le fichier JSON
                        with open(fQuest, 'w', encoding='utf-8') as f:
                            json.dump(data, f, ensure_ascii=False, indent=2)
                        print("Nouvelle question ajouté, veuillez reposer les questions\n")

                #! (re)poser les questions a Sami
                elif message == '3':
                    dossier = '/opt/amic/ami_bot/testing_chatbot/fichier/score'
                    
                    # A utiliser si le fichier de question est nouveau ou que le modèle est changé
                    askSAMI.enregistrementDesQuestion(fQuest)
                    askSAMI.question(askSAMI.listeQuestion)
                    askSAMI.sauvegarde(fRep,askSAMI.listeQuestion)
                    # recharge le fichier frep pour être sur d'avoir la dernière MAJ du fichier
                
                #! Afficher les résultats
                elif message == '4':
                    dossier = '/opt/amic/ami_bot/testing_chatbot/fichier/score'
                    
                    file = dossier+'/'+choixDoc(dossier)
                    with open(file, 'r', encoding='utf-8') as fichier:
                        data = json.load(fichier)
                    for i in data[0]['valeur'] :
                        print(f" n°{i['id']}  Distance : {i['distance']} - Temps : {i['temps']}")

                #! Bilan faut il l'enregistrer dans un fichier? pourquoi pas a voir
                elif message =='5':
                    dossier = '/opt/amic/ami_bot/testing_chatbot/fichier/score'
                    
                    file = dossier+'/'+choixDoc(dossier)

                    with open(file, 'r', encoding='utf-8') as fichier:
                        data = json.load(fichier)
                    print(f'\n\n\tTemps moyen sur les question : {data[0]["temps moyen"]} seconde \n\tSimilarité moyenne : {data[0]["distance moyenne"]}')

                #! Changer de dossier
                elif message == '6' :
                    fQuest,fRep,fichierScore=changerDoc()

                #! Changé d'assistant
                elif message == '7' : 
                    print(askSAMI.assistant)

                    fichiers = [f for f in os.listdir("/opt/amic/models") if f.find('.')==-1]
                    print("\nVeuillez choisir un fichier parmi la liste suivante:")
                    for i, fichier in enumerate(fichiers, start=1):
                        print(f"{i}. {fichier}")
                    
                    choix = int(input("\nEntrez le numéro du fichier que vous souhaitez utiliser: "))
                    askSAMI.assistant = fichiers[choix - 1]
                    
                    print(askSAMI.assistant)
                    print("\nAssistant changé veuillez reposer les questions puis relancer le test\n")

                #! Quitter
                elif message == '8' :
                    is_chat_active = False
                
                else :
                    print("Erreur sur le choix de la réponse attendu")
                    

if __name__ == "__main__" :
    menu()

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


