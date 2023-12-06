from random import *
from numpy import * 

def gen_tab(n : int):
    i = 0
    s = zeros(n)
    while i < n:
        s[i] = random.randint(600,2200)
        i = i + 1
    return s
petit = gen_tab(10)
