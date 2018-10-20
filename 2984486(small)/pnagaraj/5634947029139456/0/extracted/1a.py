import copy

def check(vals,need):
    need_map = {}
    for n in need:
        need_map[n] = 0
    for v in vals:
        if v not in need_map:
            return False
        need_map[v] += 1
    for c in need_map:
        if need_map[c] != 1:
            return False
    return True

# print check(['01','10'],['10','01'])    
# print check(['01','11','10'],['11','00','10'])

def recurse(in_vals,in_need,index,flips):
    min_count = len(in_vals[0])+1
    min_count_1 = len(in_vals[0])+1
    min_count_2 = len(in_vals[0])+1

    if  index >= len(in_vals[0]):
        return min_count

    if check(in_vals,in_need) == True:
        return flips

    ## Flip
    vals = copy.deepcopy(in_vals)
    for i in xrange(0,len(vals)):
        v = vals[i] 
        vals[i] = v[:index] + str ((int(v[index])+1)%2) + v[min(len(in_vals[0]),index+1):]
    if check(vals,in_need) == True:
        min_count_1 = flips+1
    else:
        min_count_1 = recurse(vals,in_need,index+1,flips+1)

    ## No Flip
    min_count_2 = recurse(in_vals,in_need,index+1,flips)

    return min(min_count_1,min_count_2)

def handler(vals,need):
    result = recurse(vals,need,0,0)
    if result > len(vals[0]):
        return "NOT POSSIBLE"
    return str(result)

def parse_case(lines):
    need_clean = lines[2].strip()
    vals_clean = lines[1].strip()
    need = need_clean.split(' ')
    vals = vals_clean.split(' ')
    return (vals,need)

#print handler(['01','10'],['10','01'])
#print handler(['101','111'],['010','001'])
#print handler(['01','11','10'],['11','00','10'])

f = file('small.in','r')

lines = f.readlines()

cases = int(lines[0].strip())
print "Number of cases", cases

case_len = 3
start = 1
end = start+case_len

out = file('small.out','w')

for case in xrange(0,cases):
    parsed = parse_case(lines[start:end])
    output = handler(parsed[0],parsed[1])
    start = end
    end = end+case_len
    out.write("Case #" + str(case+1) + ": " + output + "\n")

f.close()
out.close()
