Ce si est mon projet de cube LED 3D en taille 9 x 9 x 9
Dans ce dossier vous trouverer les differentes version de programme que j'ai realisé.

Descriptif du projet : Ce projet a pour objectif de créer un cube led avec différentes animations lumineuse personnalisable. Ce cube sera doté d’une interfaces utilisateur pour créer ses propres animations.

V1: Trois boutons permettent à l’utilisateur de changer d’animations parmis celle préinstallé sur l’arduino. Un potentiomètre permet de faire varier la vitesse de l’animations sélectionner.
 
V2: Une interface graphique permet à l’utilisateur de pouvoir changer d'animations.

V3: Une Interface graphique permet à l’utilisateur de créer une animation simple qui générera un code qui devra ensuite être téléverser sur l’arduino.

V4: Une Interface graphique permet à l’utilisateur de créer une animation simple qui générera un code et le téléverser automatiquement sur l’arduino. 


V1	Création d’animations avec un code simple et compatible avec l’arduino nano	Programmation du code permettent un changement d’animations suite à l’activation d’un boutons.
V2	Création d’une interface simple et agréable à utiliser par l’utilisateur	Programmation du code mettent en oeuvre les animations.
V3	Création d’une interfaces interactive permettent la personnalisation des animations	Programmation d’un code capable de générer le programme de l'animations qui pourra par la suite être téléverser
V4	Recherche d’une solution pour faire un téléversement 
automatique puis création de ce code


Bilan du projet

Le projet en est au stade ou nous essayons de faire communiquer l’interface sur ordinateur et le cube. Pour le moment l’information est bien envoyé lorsque l’utilisateur coche les étages qu’il souhaite allumer et la carte arduino reçoit la trame envoyé et la déchiffre. Le cube fonctionne également avec des fonctions que l’on peut choisir avec les 3 boutons et la vitesse de chaque animations peut être modifié à l’aide d’un potentiomètre. Le plus gros problème que nous avons rencontrés et le fait les broches 0 et 1 ne peuvent pas être utiliser en même temp que l’utilisation du moniteur série ce qui se manifeste par deux rangées qui ne s’allument pas.

Le fonctionnement du cube:

                                                             
Le cube peut paraître complexe en raison de son grand nombre de led mais peut facilement être simplifié avec un schéma. Le principe est de créer un circuit réversible permettant dans un sens d’allumer la led et de l'éteindre dans l’autre. Le but de cela est de pouvoir ainsi allumer certaine led et pas d’autre dans une même rangée.
	





               




Comment allumer une led du cube:

Pour allumer une led du cube il faut donner la valeur 1 à l’anode et 0 à la cathode. Ensuite si on veut éteindre cette led il faut les inverser, donner la valeur 0 à l’anode et 1 a la cathode.

Si on veut allumer toutes les leds du cube il faut utiliser ce même système sur le reste des led. Le langage c++ permet de faire cela d’une façon raccourci en utilisant le programme ci-contre ce qui permet d’envoyer la même valeur à toutes les sortie sans répétition.


Le fonctionnement des boutons
	Pour permettre de faire varier les animations nous avons pensé à ajouter des boutons. Malheureusement nous n’avions que deux broche restant sur l’arduino donc nous avons utiliser une pour le potentiomètre qui fait varier la tension et nous avons mis les trois autre bouton sur l’autre branche avec des résistance différente pour ainsi distinguer les bouton selon la tension obtenu. Pour la programmation nous lison tout d’abord la tension obtenu. Avec cette tension nous la comparons avec celle attendue et si celle ci correspond alors une animations est lancer. Pour développer ce programme nous avons tout d’abord commencer avec un simple code affichant ‘1’ si le bouton etait activer.

Les animations
Le grand nombre de led contrôlable individuellement permettent la créations d’un grand nombre d’animations de toutes formes différente.

Le programme ci-contre permet d’allumer une colonne sur le cube différente a une intervalle régulière definit par la variable ‘t’.

L’interface et la communication

Pour créer l’interface nous avons utilisé tkinter en python. L’interface est composé de  4 cases à cocher qui correspondent aux 4 étages du cube. Lorsque l’utilisateur coche l’une des cases la trame qui correspond aux cases cocher et directement envoyé sur la carte arduino qui déchiffre cette trame.



La trame envoyé est une chaîne de caractère composé de 64 nombre binaire. Pour allumer un étage la trame est composé de 16 chiffre 1 et pour l'éteindre 16 chiffre 0 .

Le déchiffreur
	Le déchiffreur est un programme qui permet de lire une trame envoyer par l'ordinateur. Il y a 64 nombre binaire qui sont envoyés à l’arduino chaque caractère contrôle l'état d’une led.

Cette petit partie de programme lit un caractère et contrôle la 1ere led en fonction. Ce programme est ensuite répéter à toutes les led du cube.

