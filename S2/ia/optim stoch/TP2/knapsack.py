import random
import matplotlib.pyplot as plt

x = []
v = []
w = []

#enregistrement des données
with open("data/ks_4_0","r") as f:
    i = 0
    for line in f:
        line_list = line.strip().split(" ")
        if(i == 0):
            n = int(line_list[0])
            k = int(line_list[1])
        else:
            x.append(0)
            v.append(int(line_list[0]))
            w.append(int(line_list[1]))
        i+= 1


def reset_x(x, n):
    for i in range(n):
        x[i] = 0
    return(x)

def total_value(x,v):
    res = 0
    for i in range(n):
        res += x[i] *v[i]
    return(res)