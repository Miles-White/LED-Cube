from tkinter import *
maFenetre = Tk()


boutonsEtage1 = [ Checkbutton (maFenetre, text= 'Led '+str(i+1), onvalue=1, offvalue=0) for i in range (16)]    #Définitions des boutons de l'étage 1
boutonsEtage2 = [ Checkbutton (maFenetre, text= 'Led '+str(i+17), onvalue=1, offvalue=0) for i in range (32)]   #Définitions des boutons de l'étage 2
boutonsEtage3 = [ Checkbutton (maFenetre, text= 'Led '+str(i+33), onvalue=1, offvalue=0) for i in range (48)]   #Définitions des boutons de l'étage 3
boutonsEtage4 = [ Checkbutton (maFenetre, text= 'Led '+str(i+49), onvalue=1, offvalue=0) for i in range (64)]   #Définitions des boutons de l'étage 4



for i in range(4):
     for j in range(4):
         boutonsEtage1 [4*i+j].grid(row=i,column=j)

for i in range(4):
     for j in range(4):
         boutonsEtage2 [4*i+j].grid(row=i,column=j+4)
           
for i in range(4):
    for j in range(4):
         boutonsEtage3 [4*i+j].grid(row=i,column=j+8)
           
for i in range(4):
     for j in range(4):
         boutonsEtage4 [4*i+j].grid(row=i,column=j+12)

