import random
for i in xrange(120):
    if random.randint(0,100)%2==1:
        print 'Case #'+str(i+1)+': BAD'
    else:
        print 'Case #'+str(i+1)+': GOOD'