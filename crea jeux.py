print("pendue by wakend225")
score = 0
# next

c = True

while c==True:
    from getpass import getpass
    print("----------- start the game-------------")
    mot = getpass("entrer votre mot:")
    #next


    'creation de 2 listes vides  '


    liste=[]
    votre_liste=[]
    #next


    for x in mot:
        liste.append(x)
        votre_liste.append('*')
    print("".join(votre_liste))
    #next
    nb_erreur = 0
    while nb_erreur < 9 :
        lettre = input("entrez votre lettre: ")
        if lettre ==mot:
            print("vous avez trouvé: ")
            score = score +1
            print("votre score est :",score)
            print("**********************************")
            break
        if lettre in liste:
            for (index,x) in enumerate(liste):
                if x==lettre:
                    votre_liste[index] = x
            v = "",join(votre_liste)
            print ("bonne lettre: ",v)
        if liste==votre_liste:
            print ("vous avez trouvé: ")
            score = score +1
            print ("*******************")
            break
        else:
            nb_erreur +=1
            print (' désolé il vous reste: %s essai'%(9-nb_erreur))
        if nb_error ==9:
            print ('vous avez perdu le mot était: ')
            print(mot)
            print(score)
            print("************************")


        #the last

        home = input("voulez vous continuer ? oui/non ")
        if home == 'oui' :
           print("********************nouvelle partie")
           c=True
        elif home == 'non' :
            print("fin")
            c=false

        


    
    
