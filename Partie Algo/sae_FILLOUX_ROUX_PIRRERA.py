from numpy import *
from random import randint



# Algorithme de tri selection
def tri_selection(tab: [int]):
    """
    :entrée/sortie tab: [int]
    :pré-cond: len(tab) >= 2  
    :post-cond: Cherche le minimum de la liste et qui le met au début du tableau puis recommence encore et encore jusquà ce que le tableau soit trié
    """
    i = 0
    while i < len(tab) - 1:
        j = i + 1
        i_mini = i
        while j < len(tab):
            if tab[j] < tab[i_mini]:
                i_mini = j
            j = j + 1   
        temp = tab[i]
        tab[i] = tab[i_mini]
        tab[i_mini] = temp
        i = i + 1 

# Algorithme de tri selection avec compteur d'opérations élémentaires
def tri_selection_cpt(tab: [int]):
    i = 0
    cpt = 1
    while i < len(tab) - 1:
        j = i + 1
        i_mini = i
        cpt = cpt + 6
        while j < len(tab):
            if tab[j] < tab[i_mini]:
                i_mini = j
                cpt = cpt + 4
            j = j + 1
            cpt = cpt + 5
        cpt = cpt + 2    
        temp = tab[i]
        tab[i] = tab[i_mini]
        tab[i_mini] = temp
        i = i + 1
        cpt = cpt + 5
    cpt = cpt + 2    
    return cpt        

# Algorithme de tri insertion 
def tri_insertion(tab : [int]):
    """
    :entrée/sortie tab: [int]
    :pré-cond: len(tab) >= 2  
    :post-cond: Insère successivement chaque élément dans le début du tableau déjà trié
    """
    n = len(tab)
    i = 1
    while i < n:
        j = i
        while j > 0 and tab[j-1] > tab[j]:
            temp = tab[j-1]
            tab[j-1] = tab[j]
            tab[j] = temp
            j = j - 1
        i = i + 1 

# Algorithme de tri insertion avec compteur d'opérations élémentaires
def tri_insertion_cpt(tab: [int]):
    n = len(tab)
    i = 1
    cpt = 3
    while i < n:
        j = i
        cpt = cpt + 2
        while j > 0 and tab[j-1] > tab[j]:
            temp = tab[j-1]
            tab[j-1] = tab[j]
            tab[j] = temp
            j = j - 1
            cpt = cpt + 10
        i = i + 1
        cpt = cpt + 6
    cpt = cpt + 1    
    return cpt

# Algorithme de tri à bulle
def tri_a_bulles(tab: [int]):
    """
    :entrée/sortie tab: [int]
    :pré-cond: len(tab) >= 2  
    :post-cond: remonte le maximum à droite du tableau grâce à des permutations

    """
    i = len(tab)-1
    while i > 0:
        j = 0
        while j < i :
            if tab[j] > tab[j + 1]:
                temp = tab[j]
                tab[j] = tab[j+1]
                tab[j+1] = temp
            j = j +1
        i = i - 1

# Algorithme de tri à bulle avec compteur d'opérations élémentaires
def tri_a_bulle_cpt(tab: [int]):
    i = len(tab)-1
    cpt = 3
    while i > 0:
        j=0
        cpt = cpt + 2
        while j < i :
            if tab[j] > tab[j + 1]:
                temp = tab[j]
                tab[j] = tab[j+1]
                tab[j+1] = temp
                cpt = cpt + 8
            j = j + 1
            cpt = cpt + 3
        i = i-1
        cpt = cpt + 4  
    return cpt

# Algorithme de tri rapide
def tri_rapide(tab : [int], i_debut : int, i_fin : int): 
    """
    :entrée i_début, i_fin: int
    :entrée/sortie tab: [int]
    :pré-cond: len(tab) > 2, i_debut = 0, i_fin = len(tab)-1 
    :post-cond: Choisit un pivot, divise le tableau en deux parties, trie ces parties, et répète jusqu'à obtenir un tableau trié.

    """
    if i_debut < i_fin: 
        pivot = tab[i_debut]
        i = i_debut + 1 
        j = i_fin 
        while i <= j: 
            if tab[i] > pivot and tab[j] <= pivot: 
                temp = tab[i]
                tab[i] = tab[j]                                      
                tab[j] = temp
                i = i + 1 
                j = j - 1 
            if tab[i] <= pivot: 
                i = i + 1 
            if tab[j] > pivot: 
                j = j - 1 
        temp = tab[i_debut]
        tab[i_debut] = tab[j] 
        tab[j] = temp
        tri_rapide(tab, i_debut, j - 1)
        tri_rapide(tab, j + 1, i_fin)

# Algorithme de tri rapide avec compteur d'opérations élémentaires
def tri_rapide_cpt(tab, i_debut, i_fin, cpt): 
    if i_debut < i_fin: 
        pivot = tab[i_debut]
        i = i_debut + 1 
        j = i_fin
        cpt = cpt + 5 
        while i <= j: 
            if tab[i] > pivot and tab[j] <= pivot: 
                temp = tab[i]
                tab[i] = tab[j] 
                tab[j] = temp
                i = i + 1 
                j = j - 1
                cpt = cpt + 10 
            if tab[i] <= pivot: 
                i = i + 1
                cpt = cpt + 6 
            if tab[j] > pivot: 
                j = j - 1
                cpt = cpt + 7
        cpt = cpt + 1         
        temp = tab[i_debut]
        tab[i_debut] = tab[j] 
        tab[j] = temp
        cpt = cpt + 3
        cpt = tri_rapide_cpt(tab, i_debut, j - 1, cpt) 
        cpt = tri_rapide_cpt(tab, j + 1, i_fin, cpt)
    return cpt

#Algorithme de génération de tableau (Aucune nécessité de rajouter un compteur d'opération élémentaire car ce n'est pas un tri)
def gen_tab(n : int):
    """
    :entrée n: int
    :sortie s: [int]
    :pré-cond: n > 0  
    :post-cond: Génère un tableau s d'entier aléatoire de n élément 

    """
    i = 0
    s = zeros(n)
    while i < n:
        s[i] = random.randint(600,2200)
        i = i + 1
    return s


#Algorithme qui enlève les valeur des heures avec un format incorrect (par exemple 1289 sera enlevé)
def tri_tab_heure(tab : [int],n : int):
    """
    :entrée tab: [int]
    :entrée n: int 
    sortie new_tab: [int]
    :pré-cond: len(tab) > 0 , n > 0 
    :post-cond: Remplie un nouveau tableau sans les valeurs avec un format incorrect (par exemple 1289 sera enlevé)

    """
    i = 0 
    j = 0
    k = 0
    m = n 
    while i < n:
        if (tab[i] % 100) >= 60: 
            # On utilise le while en cas de test d'opération élémentaire pour avoir bien un tableau de 10,100 ou 1000 éléments
            # Il faudra changer le return new_tab par return tab et le new_tab[k] = tab[j] par tab[k] = tab[j]
            """
            while (tab[i] % 100) >= 60:         
                tab[i] = random.randint(600,2200)
            """
            m = m-1
        i = i + 1
    new_tab = zeros(m)
    while j < n and k < m:
        if(tab[j] % 100) < 60: 
            new_tab[k] = tab[j]
            k = k + 1
        j = j + 1
    return new_tab

#Algorithme compteur de tri_tab_heure
def tri_tab_heure_cpt(tab : [int],n : int):
    i = 0 
    j = 0
    k = 0
    m = n 
    cpt = 7
    while i < n:
        cpt = cpt + 2
        if (tab[i] % 100) >= 60:
            """
            while (tab[i] % 100) >= 60:
                tab[i] = random.randint(600,2200)
            """
            m = m-1
            cpt = cpt + 2
        i = i + 1
        cpt = cpt + 2
    new_tab = zeros(m)
    cpt = cpt + 1
    while j < n and k < m:
        cpt = cpt + 2
        if(tab[j] % 100) < 60: 
            new_tab[k] = tab[j]
            k = k + 1
            cpt = cpt + 3
        j = j + 1
        cpt = cpt + 2
    return cpt


#Affichage opération élémentaire tri sélection 
print("Petit tableau tri sélection")
print((tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10))+
       tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10))+
       tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10))+tri_selection_cpt(gen_tab(10)))/10)

print("Moyen tableau tri sélection")
print((tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100))+
       tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100))+
       tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100))+tri_selection_cpt(gen_tab(100)))/10)

print("Grand tableau tri sélection")
print((tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000))+
       tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000))+
       tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000))+tri_selection_cpt(gen_tab(1000)))/10)

#Affichage opération élémentaire tri insertion
print("Petit tableau tri insertion")
print((tri_selection_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10))+
       tri_insertion_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10))+
       tri_insertion_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10))+tri_insertion_cpt(gen_tab(10)))/10)

print("Moyen tableau tri insertion")
print((tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100))+
       tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100))+
       tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100))+tri_insertion_cpt(gen_tab(100)))/10)

print("Grand tableau tri insertion")
print((tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000))+
       tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000))+
       tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000))+tri_insertion_cpt(gen_tab(1000)))/10)

#Affichage opération élémentaire tri à bulle
print("Petit tableau tri à bulle")
print((tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10))+
       tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10))+
       tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10))+tri_a_bulle_cpt(gen_tab(10)))/10)

print("Moyen tableau tri à bulle")
print((tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100))+
       tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100))+
       tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100))+tri_a_bulle_cpt(gen_tab(100)))/10)

print("Grand tableau tri à bulle")
print((tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000))+
       tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000))+
       tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000))+tri_a_bulle_cpt(gen_tab(1000)))/10)

#Affichage opération élémentaire tri rapide
print("Petit tableau tri rapide")
print((tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0)+
       tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0)+
       tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0)+tri_rapide_cpt(gen_tab(10), 0, 9, 0))/10)

print("Moyen tableau tri rapide")
print((tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0)+
       tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0)+
       tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0)+tri_rapide_cpt(gen_tab(100), 0, 99, 0))/10)

print("Grand tableau tri rapide")
print((tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+
       tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+
       tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0)+tri_rapide_cpt(gen_tab(1000), 0, 999, 0))/10)

#Affichage opération élémentaire tri tab heure
print("Petit tableau tri tab heure")
print((tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10)+
       tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10)+
       tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10)+tri_tab_heure_cpt(gen_tab(10),10))/10)

print("Moyen tableau tri tab heure")
print((tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100)+
       tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100)+
       tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100)+tri_tab_heure_cpt(gen_tab(100),100))/10)

print("Grand tableau tri tab heure")
print((tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000)+
       tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000)+
       tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000)+tri_tab_heure_cpt(gen_tab(1000),1000))/10)