from tkinter import *
import tkinter as tk
def envoie_trame():
    if (var1.get() == 0) & (var2.get() == 0) & (var3.get() == 0) & (var4.get() == 0):
        trame1= "0000000000000000000000000000000000000000000000000000000000000000"
       
    elif (var1.get() == 0) & (var2.get() == 0) & (var3.get() == 0) & (var4.get() == 1):
        trame1= "0000000000000000000000000000000000000000000000001111111111111111"
    
    elif (var1.get() == 0) & (var2.get() == 0) & (var3.get() == 1) & (var4.get() == 1):
        trame1= "0000000000000000000000000000000011111111111111111111111111111111"
    
    elif (var1.get() == 0) & (var2.get() == 0) & (var3.get() == 1) & (var4.get() == 0):
        trame1= "0000000000000000000000000000000011111111111111110000000000000000"
    
    elif (var1.get() == 0) & (var2.get() == 1) & (var3.get() == 1) & (var4.get() == 0):
        trame1= "0000000000000000111111111111111111111111111111110000000000000000"
    
    elif (var1.get() == 0) & (var2.get() == 1) & (var3.get() == 1) & (var4.get() == 1):
        trame1= "0000000000000000111111111111111111111111111111111111111111111111"
    
    elif (var1.get() == 0) & (var2.get() == 1) & (var3.get() == 0) & (var4.get() == 1):
        trame1= "0000000000000000111111111111111100000000000000001111111111111111"
    
    elif (var1.get() == 0) & (var2.get() == 1) & (var3.get() == 0) & (var4.get() == 0):
        trame1= "0000000000000000111111111111111100000000000000000000000000000000"
    
    elif (var1.get() == 1) & (var2.get() == 1) & (var3.get() == 0) & (var4.get() == 0):
        trame1= "1111111111111111111111111111111100000000000000000000000000000000"
    
    elif (var1.get() == 1) & (var2.get() == 1) & (var3.get() == 0) & (var4.get() == 1):
        trame1= "1111111111111111111111111111111100000000000000001111111111111111"
    
    elif (var1.get() == 1) & (var2.get() == 1) & (var3.get() == 1) & (var4.get() == 1):
        trame1= "1111111111111111111111111111111111111111111111111111111111111111"
    
    elif (var1.get() == 1) & (var2.get() == 1) & (var3.get() == 1) & (var4.get() == 0):
        trame1= "1111111111111111111111111111111111111111111111110000000000000000"
    
    elif (var1.get() == 1) & (var2.get() == 0) & (var3.get() == 1) & (var4.get() == 0):
        trame1= "1111111111111111000000000000000011111111111111110000000000000000"
    
    elif (var1.get() == 1) & (var2.get() == 0) & (var3.get() == 1) & (var4.get() == 1):
        trame1= "1111111111111111000000000000000011111111111111111111111111111111"
    
    elif (var1.get() == 1) & (var2.get() == 0) & (var3.get() == 0) & (var4.get() == 1):
        trame1= "1111111111111111000000000000000000000000000000001111111111111111"
    
    elif (var1.get() == 1) & (var2.get() == 0) & (var3.get() == 0) & (var4.get() == 0):
        trame1= "1111111111111111000000000000000000000000000000000000000000000000"

    
    message= trame1 +'\r'
    port.write(message.encode())
    
    reception=port.read()
    print('message envoye : ',message,'\tmessage reçu : ',reception)
    
var1 = tk.IntVar()
var2 = tk.IntVar()
var3 = tk.IntVar()
var4 = tk.IntVar()

boutonsEtage1 =  Checkbutton (maFenetre, text= 'Etage 1',variable=var1, onvalue=1, offvalue=0,command=envoie_trame)    #Définitions des boutons de l'étage 1
boutonsEtage2 =  Checkbutton (maFenetre, text= 'Etage 2',variable=var2, onvalue=1, offvalue=0,command=envoie_trame)    #Définitions des boutons de l'étage 2
boutonsEtage3 =  Checkbutton (maFenetre, text= 'Etage 3',variable=var3, onvalue=1, offvalue=0,command=envoie_trame)    #Définitions des boutons de l'étage 3
boutonsEtage4 =  Checkbutton (maFenetre, text= 'Etage 4',variable=var4, onvalue=1, offvalue=0,command=envoie_trame)    #Définitions des boutons de l'étage 4

l = tk.Label(maFenetre, width=25, text="Allumez les étages du cube led.")
l.pack()
boutonsEtage1.pack()
boutonsEtage2.pack()
boutonsEtage3.pack()
boutonsEtage4.pack()
maFenetre.mainloop()


port.close()             # Ferme le port
print('port ferme')    