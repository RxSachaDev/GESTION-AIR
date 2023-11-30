from random import *
from numpy import * 



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

def prix_décroissant(tab):
    i = 0
    while i < len(tab)-1:
        i_maxi = indice_du_maxi_a_partir_de(tab, i)
        temp = tab[i]
        tab[i] = tab[i_maxi]
        tab[i_maxi] = temp
        i = i + 1
    return tab



def tri_nom(tab):
    n = len(tab)
    i = 1
    while i < n:
        j = i
        while j > 0 and tab[j-1][2] > tab[j][2]:
            tab[j-1], tab[j] = tab[j], tab[j-1]
            j -= 1
        i += 1
    return tab
       
def decortiquer(nom):
    i = 0
    nom_traduit = zeros(len(nom))
    while i < len(nom):
        nom_traduit[i] = ord(nom[i])
        i += 1
    return nom_traduit





