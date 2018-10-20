import sys

def distance(a, b):
    dist = 0
    changes = []
    for i in range(len(a)):
        if a[i] != b[i]:
            dist += 1
            changes.append(i)
    return (dist, set(changes))

def matches(dist, cng, i):
    changes = []
    counts = []
    for out in range(len(dist[0])):
        if dist[0][out] == i:
            changes.append(cng[0][out])
            counts.append(0)
    for dev in range(len(dist)):
        for out in range(len(dist[0])):
            if dist[dev][out] == i:
                for n in range(len(changes)):
                    if cng[dev][out] == changes[n]:
                        counts[n] += 1
    for count in counts:
        if count >= len(dist):
            return True
    return False

lines = sys.stdin.readlines()
T = int(lines[0])
for t in range(T):
    N, L = map(lambda x: int(x), lines[t * 3 + 1].split())
    outlets = lines[t * 3 + 2].split()
    devices = lines[t * 3 + 3].split()
    distances = [[None] * N for x in range(N)]
    changes = [[None] * N for x in range(N)]
    for a in range(N):
        for b in range(N):
            distances[a][b], changes[a][b] = distance(devices[a], outlets[b])
    for i in range(L):
        if matches(distances, changes, i):
            print("Case #{}: {}".format(t + 1, i))
            break
    else:
        print("Case #{}: NOT POSSIBLE".format(t + 1))
