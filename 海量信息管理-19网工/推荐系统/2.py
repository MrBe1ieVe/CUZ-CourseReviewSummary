import numpy as np
from scipy.spatial import distance
def cos_sim(u, v):
    return np.sum(u * v) / float(np.sqrt(np.sum(u*u)) * np.sqrt(np.sum(v*v)))
a=np.array([1,0,0,-1])
b=np.array([0,0,1,-1])
c=np.array([0,0,1,-1])
print('b-a=%.2f'%cos_sim(a,b))
print('b-c=%.2f'%cos_sim(c,b))
print(' 估计其对物品b的打分:%.2f'%((cos_sim(a,b)*5+cos_sim(c,b)*2)/(cos_sim(a,b)+cos_sim(c,b))))