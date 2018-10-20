import copy

def subtree_recurse(parent,start,mappings):
    edges = mappings[start]
    children = edges
    print "\t", parent
    if len(children) == 1:
        return 0
    if len(children) == 3:
        val = 0
        for child in children:
            if child != parent:
                val += subtree_recurse(start,child,mappings)
        return val
    else:
        print parent, start, len(children), subtree_size(parent,start,mappings)
        return subtree_size(parent,start,mappings)-1

def subtree_size(parent,start,mappings):
    count = 1   
    edges = mappings[start]
    children = edges
    #print children
    #print "\t", children
    for child in children:
        if child == parent:
            continue
        count += subtree_size(start,child,mappings)
    return count

print subtree_size(3,4,{1: [2,4],2:[1],3:[5,4],4:[3,1],5:[3]})

def create_mappings(count,in_map):
    mappings = {}
    for i in xrange(1,count+1):
        mappings[i] = []
    for j in in_map:
        a = j[0]
        b = j[1]
        mappings[a].append(b)
        mappings[b].append(a)
    return mappings

def smart_recurse(count,mappings):
    print "NEW CASE"
    min_val = count
    for root in xrange(1,count+1):
        children = mappings[root]
        print "\t\t", root, children
        if len(children) != 2:
            if min_val == count:
                min_val = count-1
        else:
            val = subtree_recurse(root,children[0],mappings) + subtree_recurse(root,children[1],mappings)
            if val < min_val:
                min_val = val
    return str(min_val)

def parse_case(lines):
    in_map = []
    count = int(lines[0])
    for i in xrange(1,len(lines)):
        line = lines[i]
        split_line = line.split(' ')
        a = int(split_line[0])
        b = int(split_line[1])
        in_map.append( (a,b) )
    return (count,in_map)

f = file('small.in','r')

lines = f.readlines()

cases = int(lines[0].strip())
print "Number of cases", cases


case_len = -1
start = 1
end = start+case_len

out = file('small.out','w')

for case in xrange(0,cases):
    case_len = int(lines[start])
    end = start+case_len
    parsed = parse_case(lines[start:end])
    mappings = create_mappings(parsed[0],parsed[1])
    print mappings
    output = smart_recurse(parsed[0],mappings)
    start = end
    end = end+case_len
    out.write("Case #" + str(case+1) + ": " + output + "\n")

f.close()
out.close()
