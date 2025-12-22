# Projet Programmation Avancée

## Utilisation du Makefile : 	
Le Makefile fonctionne ainsi :  
	'make' : compile le projet en un executable 2048.  
	'make run' : compile et lance le programme.  
	'make clean' : nettoie le projet et supprime les .o  
	'make fclean' : lance clean et supprime les executables.  
	'make re' : lance fclean et recompile l'executable 2048.  

Les sauvegardes du jeu sont enregistrées dans le dossier savefiles/ :  
	La regle 'make resetsavefiles' permet de supprimer les fichiers du dossier.  

### Replay Mode
Le replay_mode est disponible avec la commande 'make replay' :  
	Cela compile et donne un exectutable 'replay_mode' qu'il suffit d'executer avec le chemin vers un fichier de sauvegarde.  
	Exemple : './replay_mode savefiles/Mon_Dec_22_15:31:02_2025.txt'.  
