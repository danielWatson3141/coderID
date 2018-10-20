fout = open('./out.txt', 'w+')
with open('in.txt') as f:
  T = int(f.readline())
  for x in range(T):
    temp, lengthBinary = f.readline().split(' ')
    lengthBinary = int(lengthBinary)
    maxSwitch = 2**lengthBinary

    outlets = f.readline().split(' ')
    required = f.readline().split(' ')
    i = 0
    while i < len(outlets):
      outlets[i] = int(outlets[i], 2);
      required[i] = int(required[i], 2);
      i += 1

    #print outlets
    #print required

    switches = 0;
    bestScore = 9999999999999
    while switches < maxSwitch:
      tempOutlets = list(outlets)
      i = 0
      while i < len(outlets):
        tempOutlets[i] = tempOutlets[i] ^ switches
        i += 1

      #print "Switch " + str(switches)
      #print tempOutlets
      #print required

      if set(tempOutlets) == set(required):
        bestScore = min(bestScore, bin(switches).count("1"))

      switches += 1


    if bestScore == 9999999999999:
      print "Case #" + str(x+1) + ": NOT POSSIBLE"
      fout.write("Case #" + str(x+1) + ": NOT POSSIBLE\n")
    else:
      print "Case #" + str(x+1) + ": " + str(bestScore)
      fout.write("Case #" + str(x+1) + ": " + str(bestScore) + "\n")
