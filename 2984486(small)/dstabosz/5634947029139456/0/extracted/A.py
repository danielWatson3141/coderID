# -*- coding: utf-8 -*-

import sys


gDbgLvl = 0
maxLvl = 0
     
def main():   
  
  T = int(sys.stdin.readline())
      
  
  logMsg("T = " + str(T))
  
  for t in range(1, T+1):
      
      line = (sys.stdin.readline())
    
      testCase = line.split();  
      N = int(testCase[0])
      L = int(testCase[1])
      line1 = (sys.stdin.readline())
      line2 = (sys.stdin.readline())
      
      outlets = line1.split();
      devices = line2.split();      
      
      logMsg("N " + str(N) + " L " + str(L))
      logMsg("outlets " + str(outlets))
      logMsg("devices " + str(devices))
      
      out = list()
      dev = list()
      
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
  
#  logMsg("maxLvl " + str(maxLvl), 1)

def countOnes(x):
    count = 0
    while (x != 0):
        if (x % 2 == 1):
            count = count + 1
        x = x // 2
    return count
    

def solve2(farmCost, farmRate, goal, elapsed, cookiesPerSecond):
    done = 0
    level = 0
    elapsed = 0
    global maxLvl

    logMsg("Elapsed " + str(elapsed))
    logMsg("FarmRate " + str(farmRate))
    logMsg("Goal " + str(goal))

 
    while (done == 0):
        timeToWin = goal / cookiesPerSecond
        timeToBuyFarm = farmCost / cookiesPerSecond
        totalTimeToWin = elapsed + timeToWin
        if (level == 0):
            best = totalTimeToWin
        if (totalTimeToWin < best):
            best = totalTimeToWin
        if (best < elapsed + timeToBuyFarm):
            done = 1;
        elapsed = elapsed + timeToBuyFarm
        cookiesPerSecond = cookiesPerSecond + farmRate
        level = level + 1

    logMsg( "level " + str(level), 3)

    if (level > maxLvl):
        maxLvl = level
        
    return best

def logMsg(str, lvl = 1):
    if (gDbgLvl >= lvl):
      print(str);


main()