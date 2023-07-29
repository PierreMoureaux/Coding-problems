# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 19:01:09 2023

@author: moureaux pierre
"""

import numpy as np

def PiMonteCarlo(NbSimul):
    c = 0
    x = np.random.uniform(0,1,NbSimul)
    y = np.random.uniform(0,1,NbSimul)
    d = [np.linalg.norm(np.sqrt(u**2 + v**2)) for u, v in zip(x, y)]
    for k in d:
        if (k <= 1):
            c = c+1
    return 4*c / NbSimul;

NbSimul = 1000000
print(format(PiMonteCarlo(NbSimul),'.3f'))