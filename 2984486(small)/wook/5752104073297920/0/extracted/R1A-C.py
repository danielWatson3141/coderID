
# coding: utf-8

# In[20]:

get_ipython().magic(u'pylab inline')

import numpy as np
from random import randrange
import scipy.stats
import pandas as pd
import sklearn

import matplotlib.pyplot as plt


# In[12]:

def good_random(n):
    a = list(xrange(n))
    for k in xrange(n):
        p = randrange(k, n)
        a[k], a[p] = a[p], a[k]
    return a


# In[13]:

good_random(10)


# In[14]:

def bad_random(n):
    a = list(xrange(n))
    for k in xrange(n):
        p = randrange(0, n)
        a[k], a[p] = a[p], a[k]
    return a


# In[15]:

bad_random(10)


# In[17]:

# the identity
n = 1000
I = list(xrange(n))


# In[87]:

def indexof(a):
    return a.index(0)


def inversions(a):
    inv = 0
    for i in xrange(n):
        for j in xrange(i+1, n):
            if a[i] > a[j]:
                inv += 1
    return inv


# In[121]:

def run_test(generator, metric = inversions, iters = 1000):
    stat = []
    samples = []

    for it in xrange(iters):
        sys.stderr.write('.')
        sam = generator(n)
        samples.append( sam )
        stat.append( metric(sam) )
    sys.stderr.flush()
    
    stat = pd.DataFrame(stat)
    return samples, stat


# In[96]:




# In[122]:

n_it = 1000
metric = inversions

sys.stderr.write('G')
Gsamples, G = run_test(good_random, metric, n_it)
G.describe()

sys.stderr.write('B')
Bsamples, B = run_test(bad_random, metric, n_it)
B.describe()


# In[97]:




# In[124]:

bins = np.linspace(min(G.min()[0], B.min()[0]), max(G.max()[0], B.max()[0]), 20)


plt.hist(G.values, bins=bins, normed=True, color="green", alpha=.5)
plt.hist(B.values, bins=bins, normed=True, color="blue", alpha=.5);


# In[117]:

expected_inversions = n*(n-1)/4


# In[118]:

Gv = G.values.T[0]
Bv = B.values.T[0]


# In[125]:

print len(Gv[Gv < expected_inversions]), len(Gv[Gv > expected_inversions])
print len(Bv[Bv < expected_inversions]), len(Bv[Bv > expected_inversions])


# In[137]:

from sklearn.ensemble import RandomForestClassifier
clf = RandomForestClassifier(max_depth=10, n_estimators=10, max_features=100)


# In[142]:

X = Gsamples + Bsamples
Y = [1] * len(Gsamples) + [-1] * len(Gsamples)

clf.fit(X, Y)
Y_predicted = clf.predict(X)
print clf.score(X, Y)


# In[155]:

# solve GCJ

f = open('C-small-attempt0.in','r')
fw = open('C-small-attempt0.out', 'w')
rl = f.readline

def classify(a):
    y = clf.predict(a)
    if y > 0: return 'GOOD'
    return 'BAD'
    
T = int(rl())
for kase in xrange(1, T):
    dummy = int(rl())
    a = map(int, rl().split())

    print >> fw, 'Case #%d: %s' % (kase, classify(a))
    
fw.close()


# In[139]:




# In[ ]:



