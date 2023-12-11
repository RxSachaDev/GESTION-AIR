from random import *
from numpy import * 

def gen_tab(n : int):
    i = 0
    s = zeros(n)
    while i < n:
        s[i] = random.randint(600,2200)
        i = i + 1    
    return s



petit1 = gen_tab(10)
petit2= gen_tab(10)
petit3 = gen_tab(10)
petit4 = gen_tab(10)
petit5 = gen_tab(10)
petit6 = gen_tab(10)
petit7 = gen_tab(10)
petit8 = gen_tab(10)
petit9 = gen_tab(10)
petit10 = gen_tab(10)

moyen1 = gen_tab(100)
moyen2 = gen_tab(100)
moyen3 = gen_tab(100)
moyen4 = gen_tab(100)
moyen5 = gen_tab(100)
moyen6 = gen_tab(100)
moyen7 = gen_tab(100)
moyen8 = gen_tab(100)
moyen9 = gen_tab(100)
moyen10 = gen_tab(100)

grand1 = gen_tab(1000)
grand2 = gen_tab(1000)
grand3 = gen_tab(1000)
grand4 = gen_tab(1000)
grand5 = gen_tab(1000)
grand6 = gen_tab(1000)
grand7 = gen_tab(1000)
grand8 = gen_tab(1000)
grand9 = gen_tab(1000)
grand10 = gen_tab(1000)
