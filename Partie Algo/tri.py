from random import *
from numpy import * 
import gen_tab

                    
def indice_du_maxi_a_partir_de(tab, i):
    i_maxi = i
    while i < len(tab):
        if tab[i] > tab[i_maxi]:
            i_maxi = i
        i = i + 1
    return i_maxi

def tri_selection_dec(tab):
    i = 0
    while i < len(tab)-1:
        i_maxi = indice_du_maxi_a_partir_de(tab, i)
        temp = tab[i]
        tab[i] = tab[i_maxi]
        tab[i_maxi] = temp
        i = i + 1
    return tab

def indice_du_mini_a_partir_de(tab, i):
    i_mini = i
    while i < len(tab):
        if tab[i] < tab[i_mini]:
            i_mini = i
        i = i + 1
    return i_mini

def tri_selection(tab):
    i = 0
    while i < len(tab)-1:
        i_mini = indice_du_mini_a_partir_de(tab, i)
        temp = tab[i]
        tab[i] = tab[i_mini]
        tab[i_mini] = temp
        i = i + 1
    return tab

def tri_insertion_dec(tab):
    n = len(tab)
    i = 1
    while i < n:
        j = i
        while j > 0 and tab[j-1] < tab[j]:
            temp = tab[j-1]
            tab[j-1] = tab[j]
            tab[j] = temp
            j = j - 1
        i = i + 1
    return tab

def tri_insertion(tab):
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
    return tab

def tri_a_bulle(tab):
    i = len(tab)-1
    while i > 0:
        j=0
        while j < i :
            if tab[j] > tab[j + 1]:
                temp = tab[j]
                tab[j] = tab[j+1]
                tab[j+1] = temp
            j = j + 1
        i = i - 1  
    return tab      



def echange(tab, i, j):
    temp = tab[i]
    tab[i] = tab[j] 
    tab[j] = temp 

def repartition(tab, i_debut, i_fin): 
    pivot = tab[i_debut]
    i = i_debut + 1 
    j = i_fin 
    while i <= j: 
        if tab[i] > pivot and tab[j] <= pivot: 
            echange(tab, i, j) 
            i = i + 1 
            j = j - 1 
        if tab[i] <= pivot: 
            i = i + 1 
        if tab[j] > pivot: 
            j = j - 1 
    echange(tab, i_debut, j) 
    return j
 
def tri_rapide(tab, i_debut, i_fin): 
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
    return tab

print(tri_rapide(gen_tab.petit1,0,9))