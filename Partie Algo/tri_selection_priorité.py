from random import *
from numpy import * 
import gen_tab


petit1 = gen_tab.gen_tab(10)
petit2= gen_tab.gen_tab(10)
petit3 = gen_tab.gen_tab(10)
petit4 = gen_tab.gen_tab(10)
petit5 = gen_tab.gen_tab(10)
petit6 = gen_tab.gen_tab(10)
petit7 = gen_tab.gen_tab(10)
petit8 = gen_tab.gen_tab(10)
petit9 = gen_tab.gen_tab(10)
petit10 = gen_tab.gen_tab(10)

moyen1 = gen_tab.gen_tab(100)
moyen2 = gen_tab.gen_tab(100)
moyen3 = gen_tab.gen_tab(100)
moyen4 = gen_tab.gen_tab(100)
moyen5 = gen_tab.gen_tab(100)
moyen6 = gen_tab.gen_tab(100)
moyen7 = gen_tab.gen_tab(100)
moyen8 = gen_tab.gen_tab(100)
moyen9 = gen_tab.gen_tab(100)
moyen10 = gen_tab.gen_tab(100)

grand1 = gen_tab.gen_tab(1000)
grand2 = gen_tab.gen_tab(1000)
grand3 = gen_tab.gen_tab(1000)
grand4 = gen_tab.gen_tab(1000)
grand5 = gen_tab.gen_tab(1000)
grand6 = gen_tab.gen_tab(1000)
grand7 = gen_tab.gen_tab(1000)
grand8 = gen_tab.gen_tab(1000)
grand9 = gen_tab.gen_tab(1000)
grand10 = gen_tab.gen_tab(1000)



def tri_age(tab):
    i = 0
    pdouze = len(tab) - 1
    while i < pdouze:
        if tab[i] >= 2011:
            i = i + 1
        else:
            temp=tab[i]
            tab[i] = tab[pdouze]
            tab[pdouze] = temp
            pdouze = pdouze - 1
    return tab
                    
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
            j -= 1
        i += 1
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
            j -= 1
        i += 1
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
            j = j +1
        i = i-1  
    return tab      

print(tri_selection(grand1))
