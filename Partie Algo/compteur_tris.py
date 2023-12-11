from random import *
from numpy import * 
import gen_tab

def tri_age_cpt(tab):
    i = 0
    pdouze = len(tab) - 1
    cpt = 2
    while i < pdouze:
        if tab[i] >= 2011:
            i = i + 1
            cpt += 4
        else:
            temp=tab[i]
            tab[i] = tab[pdouze]
            tab[pdouze] = temp
            pdouze = pdouze - 1
            cpt += 7
    cpt += 1    
    return cpt

def tri_selection_dec_cpt(tab):
    i = 0
    cpt = 1
    while i < len(tab) - 1:
        j = i + 1
        i_maxi = i
        cpt += 4
        while j < len(tab):
            if tab[j] > tab[i_maxi]:
                i_maxi = j
                cpt += 2
            j = j + 1
            cpt += 3
        cpt += 1    
        temp = tab[i]
        tab[i] = tab[i_maxi]
        tab[i_maxi] = temp
        i = i + 1
        cpt += 5
    cpt += 1    
    return cpt

def indice_du_mini_a_partir_de_cpt(tab, i):
    i_mini = i
    while i < len(tab):
        if tab[i] < tab[i_mini]:
            i_mini = i
        i = i + 1
    return i_mini

def tri_selection_cpt(tab):
    i = 0
    cpt = 1
    while i < len(tab) - 1:
        j = i + 1
        i_mini = i
        cpt += 4
        while j < len(tab):
            if tab[j] < tab[i_mini]:
                i_mini = j
                cpt += 2
            j = j + 1
            cpt += 3
        cpt += 1    
        temp = tab[i]
        tab[i] = tab[i_mini]
        tab[i_mini] = temp
        i = i + 1
        cpt += 5
    cpt += 1    
    return cpt

def tri_insertion_dec_cpt(tab):
    n = len(tab)
    i = 1
    cpt = 2
    while i < n:
        j = i
        cpt += 2
        while j > 0 and tab[j-1] < tab[j]:
            temp = tab[j-1]
            tab[j-1] = tab[j]
            tab[j] = temp
            j -= 1
            cpt += 7
        i += 1
        cpt += 3
    cpt += 1    
    return cpt

def tri_insertion_cpt(tab):
    n = len(tab)
    i = 1
    cpt = 2
    while i < n:
        j = i
        cpt += 2
        while j > 0 and tab[j-1] > tab[j]:
            temp = tab[j-1]
            tab[j-1] = tab[j]
            tab[j] = temp
            j -= 1
            cpt += 7
        i += 1
        cpt += 3
    cpt += 1    
    return cpt

def tri_a_bulle_cpt(tab):
    i = len(tab)-1
    cpt = 1
    while i > 0:
        j=0
        cpt += 2
        while j < i :
            if tab[j] > tab[j + 1]:
                temp = tab[j]
                tab[j] = tab[j+1]
                tab[j+1] = temp
                cpt += 5
            j = j +1
            cpt += 3
        i = i-1
        cpt += 3  
    return cpt

print((tri_age_cpt(gen_tab.petit1)+tri_age_cpt(gen_tab.petit2)+tri_age_cpt(gen_tab.petit3)+
       tri_age_cpt(gen_tab.petit4)+tri_age_cpt(gen_tab.petit5)+tri_age_cpt(gen_tab.petit6)+
       tri_age_cpt(gen_tab.petit7)+tri_age_cpt(gen_tab.petit8)+tri_age_cpt(gen_tab.petit9)+tri_age_cpt(gen_tab.petit10))/10)