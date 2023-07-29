# -*- coding: utf-8 -*-
"""
Created on Wed Jul 19 10:11:13 2023

@author: pmoureaux
"""

import numpy as np

#version with storing results
def MaxArrayK(vec:np.array, k:int):
    res = [np.max(vec[i:i+k]) for i in range(0,vec.size-2)]
    return res;

#version with print
def MaxArrayK2(vec:np.array, k:int):
    print([np.max(vec[i:i+k]) for i in range(0,vec.size-2)])

vec = np.array([10, 5, 2, 7, 8, 7])
res = MaxArrayK(vec,3)
for  i in res:
    print(i)
MaxArrayK2(vec,3)