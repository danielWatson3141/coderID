# -*- coding: utf-8 -*-

import sys


gDbgLvl = 0
maxLvl = 0


cannedInput = 0

def main():   
  
  
  if (cannedInput):
      T = 100
  else:
      T = int(sys.stdin.readline())        

  logMsg("T = " + str(T))
  
  for t in range(1, T+1):
      

      if (cannedInput):
          N = 150
          L = 40
      else:
          line = (sys.stdin.readline())    
          testCase = line.split();  
          N = int(testCase[0])
          L = int(testCase[1])
          line1 = (sys.stdin.readline())
          line2 = (sys.stdin.readline())
          outlets = line1.split();
          devices = line2.split();            
          logMsg("outlets " + str(outlets))
          logMsg("devices " + str(devices))

      logMsg("N " + str(N) + " L " + str(L))
      
      out = list()
      dev = list()
      
      if (cannedInput):
          for i in range(0, N):
            out.append(long(i))
            dev.append(long(i))
      else:
          for i in range(0, N):
              out.append(long(outlets[i], 2))
              dev.append(long(devices[i], 2))
              logMsg("out[" + str(i) + "] " + str(out[i]))
              logMsg("dev[" + str(i) + "] " + str(dev[i]))
          
      switchStates = list()

      # 22500
      
      for i in range(0, N):
          states = list()
          for j in range(0, N):
              states.append(dev[i] ^ out[j])
              logMsg("states[" + str(i) + "][" + str(j) + "] " + str(bin(states[j]))[2:].zfill(L))
          switchStates.append(set(states))

          
    
      logMsg("switchStates " + str(switchStates))

      validStates = list()

      validStates = switchStates[0]
      
      for i in range(1, N):
          validStates.intersection_update(switchStates[i])

      logMsg("validStates " + str(validStates))
      
      if (len(validStates) == 0):
          minFlip = "NOT POSSIBLE"
      else:          
          minFlip = 1000
          for oneState in validStates:
              count = countOnes(oneState)
              minFlip = min(minFlip, count)
                       
      print("Case #" + str(t) + ": " + str(minFlip))

def countOnes(x):
    count = 0
    while (x != 0):
        if (x % 2 == 1):
            count = count + 1
        x = x // 2
    return count
    

def logMsg(str, lvl = 1):
    if (gDbgLvl >= lvl):
      print(str);


main()