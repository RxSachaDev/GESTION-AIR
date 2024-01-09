from random import *
from numpy import * 
import gen_tab


def tri_selection_cpt(tab):
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


def tri_insertion_cpt(tab):
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

def tri_a_bulle_cpt(tab):
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
        tri_rapide_cpt(tab, i_debut, j - 1, cpt) 
        tri_rapide_cpt(tab, j + 1, i_fin, cpt)
    return cpt


print((tri_a_bulle_cpt(gen_tab.grand1)+tri_a_bulle_cpt(gen_tab.grand2)+tri_a_bulle_cpt(gen_tab.grand3)+
       tri_a_bulle_cpt(gen_tab.grand4)+tri_a_bulle_cpt(gen_tab.grand5)+tri_a_bulle_cpt(gen_tab.grand6)+
       tri_a_bulle_cpt(gen_tab.grand7)+tri_a_bulle_cpt(gen_tab.grand8)+tri_a_bulle_cpt(gen_tab.grand9)+tri_a_bulle_cpt(gen_tab.grand10))/10)