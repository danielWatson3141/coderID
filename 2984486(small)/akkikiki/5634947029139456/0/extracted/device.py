# coding: utf-8


import sys

 

def charge():
  f = open(sys.argv[1], 'r')
  f_out = open(sys.argv[1] + '_out', 'w')
  T = int(f.readline()) # the first line
  case = 1

  for i in xrange(T):  
    N, L = map(int,f.readline().split(" ")) 
    initial_bit = map(lambda x: int(x, 2), f.readline().split(" "))
    target_bit = map(lambda x: int(x, 2), f.readline().split(" "))
    

    # generate all the possible bit patterns
    all_bit_pat = range(2**L)
    print all_bit_pat
    result = 100000 

    for bit_pat in all_bit_pat:
      xored_bit_list = []
      for bit in initial_bit:
        xored_bit_list.append(bit_pat ^ bit)
      print sorted(xored_bit_list)
      print sorted(target_bit)
      print bin(bit_pat)[2:].count("1")
      if sorted(xored_bit_list) == sorted(target_bit):
        result = min(result, bin(bit_pat)[2:].count("1"))

    
    output = 'Case #' + str(case) + ': '
    if result == 100000:
      output += 'NOT POSSIBLE'
    else:
      output += str(result)

    f_out.write(output + '\n') 
    case += 1

if __name__ == "__main__":
  charge()
