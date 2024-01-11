# **GESTIONAIR**

Bienvenue sur GestionAir, l'application en console qui permet la gestion de vols de l'aéroport Grenoble Alpes Isère.

Cette application a été développée en langage C en réponse aux besoins du Directeur de l'aéroport Grenoble Alpes Isère, tel que spécifié dans le cahier des charges du projet GESTION'AIR, SAE.S01.S02.2023.

Client : Directeur de l'aéroport Grenoble Alpes Isère


## **Ajouter les fichiers au git bash**
```
cd existing_repo ou git init
git remote add origin https://forge.univ-lyon1.fr/p2203403/gestionair.git
git branch -M main
git add .
git commit -m "Votre commit"
git push -f origin main
```

### **Comment installer et executer le projet**

Pour ce projet nous avons utilisé CodeBlocks commme IDE pour la programmation et la compilation. 

Pour télécharger mon projet:

**1.** ```bash git clone https://forge.univ-lyon1.fr/p2203403/gestionair.git```

**2.** Dans CodeBlocks ou dans le dossier, ouvrez le
fichier .cbp  pour ouvrir directement le projet.



# **Infos sur l'application**

### **Structure du Projet**
Le projet est organisé de manière à faciliter la compréhension et la maintenance :
- **Sources :** Contient les fichiers C où se trouve les programmes. 
- **Header :** Contient les fichiers d'en-tête.
- **data_vols.csv :** Le fichier de données.


### **Format des Données de la BD**
Les informations nécessaires à l'application sont fournies dans un fichier CSV avec un format spécifique, comprenant les détails de chaque vol, y compris les passagers associés.

### **Tableau de structures**
Pour simplifier la manipulation des éléments contenu dans le csv, nous avons créé un tableau de struct qui regroupe les données du vol et de la liste des passagers du vols. 

### **Fonctionnalités Principales**
L'application offre plusieurs fonctionnalités essentielles pour la gestion efficace des vols commerciaux au départ de l'aéroport. Ces fonctionnalités incluent :

**Affichage des Informations sur les Vols** : Présentation des détails des vols triés par ordre croissant sur l'heure de décollage. Les informations comprennent l'heure de décollage, le numéro de vol, le nom de la compagnie, la destination, le comptoir d'enregistrement, l'heure de debut d'enregistrement et celle de fin, la salle d'embarquement, l'heure de debut d'embarquement et celle de fin, l'état du vol, etc.

**Recherche de Vol** : Possibilité de rechercher un vol en utilisant le nom de la compagnie, la destination ou l'heure de décollage. ces fonctions possèdent une gestion d'erreur de l'utilisateur.

**Affichage des Passagers** dans les Salles d'Embarquement : Présentation de la liste des passagers dans les salles d'embarquement, triée sur l'ordre d'embarquement basé sur l'âge du passager, le prix du billet, et en cas d'égalité, l'ordre alphabétique basé sur le nom.

**Gestion des Retards et des Annulations** : Traitement des retards en tentant de reprogrammer un vol retardé au plus tôt tout en respectant les contraintes de sécurité telles que le délai de 5 minutes minimum entre deux décollages et le couvre-feu de 6h à 22h. Possibilité d'annulation de vols qui ne peuvent pas décoller avant 22h.

**Maximisation de l'Utilisation de la Piste (Bonus)** : Fonctionnalité qui vise à maximiser l'utilisation de la piste en reprogrammant les vols retardés pour maximiser le nombre de décollages sur la journée.
