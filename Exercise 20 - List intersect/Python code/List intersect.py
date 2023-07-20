# -*- coding: utf-8 -*-
"""
Created on Thu Jul 20 19:50:42 2023

@author: moureaux pierre
"""

import numpy as np

#version with multiple intersect and storage
def listIntersectMultiple(l1 : list, l2 : list) -> np.array:
    res = np.empty(0)
    for it in l1:
        if it in l2:
            res = np.append(res, it)
    return res;

#version with first touch intersect
def listIntersect(l1 : list, l2 : list):
    for it in l1:
        if it in l2:
            return it
    return -1;


l1 = [ 3, 7 , 8 , 99 ]
l2 = [ 99, 1 , 8 , 10 ]
res = listIntersectMultiple(l1, l2)
for i in res:
    print(i)
print(listIntersect(l1, l2))
