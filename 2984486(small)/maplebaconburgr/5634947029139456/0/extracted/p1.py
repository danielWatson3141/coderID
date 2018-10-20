'''
Created on Apr 25, 2014

@author: Dino Baron
'''
def main():
   f = open('A-small-attempt0.in', 'r')
   g = open('output.txt', 'w')
   T = int(readLine(f))
   for testCase in range(1, T+1):
      a = readIntArray( f )
      N = a[ 0 ]
      L = a[ 1 ]
      outlets = readStringArray( f )
      devices = readStringArray( f )
      x = operate( [ ( outlets, devices ) ], L )
      if x is None:
         x = "NOT POSSIBLE"
      else:
         x = str( x )
      g.write( "Case #%d: %s\n" % (testCase, x))
      print "Case #%d: %s" % (testCase, x)

def operate( inputSets, length ):
   if length == 0:
      return 0
   possibilities = []
   for sets in inputSets:
      outlets = sets[0]
      devices = sets[1]
      l = len( outlets )
      numOutlets = sum( [ 1 for x in outlets if x[0] == '1' ] )
      numDevices = sum( [ 1 for x in devices if x[0] == '1' ] )
      if numOutlets == numDevices and float(numOutlets) == l/2.0:
         possibilities.append('e') # either
      elif numOutlets == numDevices:
         possibilities.append('n') # don't flip
      elif abs( l - numOutlets ) == abs( numDevices ):
         possibilities.append('y') # flip
      else:
         possibilities.append('f') # fail
         break
   flip = all( x == 'e' or x == 'y' for x in possibilities )
   dontflip = all( x == 'e' or x == 'n' for x in possibilities )
   bestResult = None
   
   flipInput = []
   noflipInput = []
   for sets in inputSets:
      outlets = sets[0]
      devices = sets[1]
      outlets1 = [ outlet[1:] for outlet in outlets if outlet[0] == '1' ]
      outlets0 = [ outlet[1:] for outlet in outlets if outlet[0] == '0' ]
      devices1 = [ device[1:] for device in devices if device[0] == '1' ]
      devices0 = [ device[1:] for device in devices if device[0] == '0' ]
      flipInput.append( ( outlets1, devices0 ) )
      flipInput.append( ( outlets0, devices1 ) )
      noflipInput.append( ( outlets1, devices1 ) )
      noflipInput.append( ( outlets0, devices0 ) )
      
   if flip:
      result = operate( flipInput, length - 1 )
      if result is not None:
         bestResult = result + 1
   if dontflip:
      result = operate( noflipInput, length - 1 )
      if bestResult is None or ( result is not None and result < bestResult ):
         bestResult = result
   return bestResult

def readFloatArray( f ):
   return map( float, readLine(f).split() )

def readIntArray( f ):
   return [ int( x ) for x in f.readline().split() ]

def readStringArray( f ):
   return f.readline().split()

def readLine( f ):
   return f.readline().rstrip('\n')

if __name__ == '__main__':
    main()