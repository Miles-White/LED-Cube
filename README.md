---

**Projet de Cube LED 3D (4 x 4 x 4)**

Dans ce dossier, vous trouverez les différentes versions des programmes que j'ai réalisés.

**Description du projet :**

Ce projet vise à créer un cube LED avec des animations lumineuses personnalisables. Le cube sera doté d'une interface utilisateur permettant de créer ses propres animations.

**Versions du projet :**

- **V1 :** Trois boutons permettent à l'utilisateur de changer parmi les animations préinstallées sur l'Arduino. Un potentiomètre permet de varier la vitesse de l'animation sélectionnée.
- **V2 :** Une interface graphique permet à l'utilisateur de changer d'animations.
- **V3 :** Une interface graphique permet à l'utilisateur de créer une animation simple, générant un code à téléverser ensuite sur l'Arduino.
- **V4 :** Une interface graphique permet à l'utilisateur de créer une animation simple, générant et téléversant automatiquement le code sur l'Arduino.

**Détails des versions :**

- **V1 :** Création d'animations avec un code simple compatible avec l'Arduino Nano. Programmation permettant de changer d'animations via des boutons.
- **V2 :** Création d'une interface simple et agréable. Programmation des animations.
- **V3 :** Création d'une interface interactive permettant la personnalisation des animations. Programmation d'un code générant le programme des animations à téléverser.
- **V4 :** Recherche et création d'une solution pour un téléversement automatique du code.

**Bilan du projet :**

Le projet en est à l'étape où nous essayons de faire communiquer l'interface sur ordinateur avec le cube. Actuellement, les informations sont bien transmises lorsque l'utilisateur coche les étages qu'il souhaite allumer, et la carte Arduino reçoit et déchiffre la trame envoyée. Le cube fonctionne aussi avec des fonctions sélectionnables via trois boutons, et la vitesse de chaque animation peut être modifiée à l'aide d'un potentiomètre. Le principal problème rencontré est l'impossibilité d'utiliser les broches 0 et 1 en même temps que le moniteur série, ce qui empêche l'allumage de deux rangées de LEDs.

**Fonctionnement du cube :**

Le cube peut paraître complexe à cause du grand nombre de LEDs, mais il peut être simplifié par un schéma. Le principe est de créer un circuit réversible permettant d'allumer ou d'éteindre une LED en changeant le sens du courant. Cela permet d'allumer certaines LEDs et pas d'autres dans une même rangée.

**Comment allumer une LED du cube :**

Pour allumer une LED, il faut donner la valeur 1 à l'anode et 0 à la cathode. Pour l'éteindre, il faut inverser les valeurs. Pour allumer toutes les LEDs du cube, on utilise ce même système. Le langage C++ permet de le faire de manière concise avec un programme adapté.

**Fonctionnement des boutons :**

Pour varier les animations, nous avons ajouté des boutons. Nous n'avions que deux broches restantes sur l'Arduino : l'une pour le potentiomètre qui fait varier la tension, et l'autre pour trois boutons distincts grâce à des résistances différentes. La programmation consiste à lire la tension obtenue, la comparer à celle attendue et lancer l'animation correspondante. Nous avons commencé par un code simple affichant '1' lorsque le bouton est activé.

**Les animations :**

Le grand nombre de LEDs contrôlables individuellement permet de créer de nombreuses animations variées. Le programme ci-joint allume une colonne du cube à intervalles réguliers définis par la variable 't'.

**Interface et communication :**

Pour créer l'interface, nous avons utilisé Tkinter en Python. L'interface comporte quatre cases à cocher correspondant aux quatre étages du cube. Lorsque l'utilisateur coche une case, la trame correspondante est envoyée directement à la carte Arduino qui la déchiffre.

**La trame envoyée :**

La trame envoyée est une chaîne de caractères composée de 64 nombres binaires. Pour allumer un étage, la trame contient 16 chiffres '1', et pour l'éteindre, 16 chiffres '0'.

**Le déchiffreur :**

Le déchiffreur est un programme permettant de lire une trame envoyée par l'ordinateur. Il y a 64 nombres binaires envoyés à l'Arduino, chaque caractère contrôlant l'état d'une LED. Ce programme lit chaque caractère et contrôle les LEDs en conséquence, répétant l'opération pour toutes les LEDs du cube.

---
