# -*- coding: utf-8 -*-
"""
Created on Sat Jul 22 21:04:52 2023

@author: moureaux pierre
"""

def NumberOfRooms(t:[]) -> int:
    if (len(t) != 0):
        c = 1
        minRange = min(t, key = lambda tu: tu[0])
        UpperTime = minRange[1]
        t.remove(minRange)
        while (len(t) != 0):
            minRange = min(t, key = lambda tu: tu[0])
            lowerTimeLoop = minRange[0]
            UpperTimeLoop = minRange[1];
            if lowerTimeLoop <= UpperTime:
                c = c+1
            if UpperTimeLoop >= UpperTime:
                UpperTime = UpperTimeLoop
            t.remove(minRange)
        return c;
    else:
        return -1;

a1 = (0, 50)
a2 = (30, 42)
a3 = (45, 160)
t = [a1,a2,a3]
print(NumberOfRooms(t))

a4 = (0, 50)
a5 = (30, 42)
a6 = (60, 160)
t2 = [a4,a5,a6]
print(NumberOfRooms(t2))



