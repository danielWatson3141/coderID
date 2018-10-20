### Set the input and output file names
import time
import datetime
filename = 'A-small-attempt1'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'


### Open input file for reading
with open(input_filename) as f:
    lines = f.read().splitlines()

    ### Open output file for writing
    with open(output_filename, 'w') as output:

        ######################################################
        ### Initialise variables from first line of the file
        ######################################################   
        vars = lines[0].split(' ')
        cases = int(vars[0])                    # number of cases
        print(str(cases) + ' cases detected.')  # [soft validation]
        lineNum = 1                             # first case starts here
        caseNum = 0                             # for counting the num of cases
        caseSize_r = 1                          # number of rows in each case; default = 1
        caseSize_c = 1                          # number of columns in each case; default = 1
        
        infoLines = True                        # Toggle according to question
        #infoLines = False                       # Toggle according to question
        
        ### i.e. infoLines == True
        if infoLines:
            while lineNum < len(lines):
                ### A new case! Initialize some variables
                caseNum += 1                                    # case number count
                
                num_switches = int(lines[lineNum].split(' ')[0])  # case size (rows)
                digits = int(lines[lineNum].split(' ')[1])  # case size (columns)
   
                
                ### Case data saved into myA and myB
                myA = lines[lineNum + 1].split(' ')
                myB = lines[lineNum + 2].split(' ')
                for x in range(0, num_switches):
                    myA[x] = int(myA[x],2)
                    myB[x] = int(myB[x],2)
                
                
                
                ### Do the Work!
                matchFound = False
                switchFlicks = 0

                while switchFlicks < 2**digits and not(matchFound):
                    myFlickedA = lines[lineNum + 1].split(' ')
                    for x in range(0, num_switches):
                        myFlickedA[x] = int(myFlickedA[x],2)
                        
                    ### flick switches
                    for x in range(0, num_switches):
                        myFlickedA[x] = myFlickedA[x] ^ switchFlicks

                    ### test if it works
                    if set(myFlickedA).intersection(myB) == set(myB):
                        matchFound = True
                    else:
                        switchFlicks += 1
                    
                
                ### Output myArr
                if matchFound:
                    print('Case #%d: %d' % (caseNum, int(bin(switchFlicks).count("1"))))
                    output.write('Case #%d: %d\n' % (caseNum, int(bin(switchFlicks).count("1"))))
                else:
                    print('Case #%d: NOT POSSIBLE' % (caseNum))
                    output.write('Case #%d: NOT POSSIBLE\n' % (caseNum))
              
                
                ### Step
                lineNum += 3
                
                
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                
                ### Do the Work!
                ### TODO! 
                myAns = len(lines[lineNum])
                lineNum += 1
                
                ### Output myAns
                print('Case #%d: %d\n' % (caseNum, myAns))
                output.write('Case #%d: %d\n' % (caseNum, myAns))

                

### END
