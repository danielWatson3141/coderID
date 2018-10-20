### Set the input and output file names
import time
import datetime
filename = 'B-small-attempt4'
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
        
        ### i.e. infoLines == True
        if infoLines:
            while lineNum < len(lines):
                ### A new case! Initialize some variables
                caseNum += 1                                    # case number count
                totalNodes = int(lines[lineNum].split(' ')[0])  # case size (rows)

                ### Case data saved into myArr
                myCount = [0] * totalNodes
                for r in range(1, totalNodes):
                    a = int(lines[lineNum + r].split(' ')[0])
                    b = int(lines[lineNum + r].split(' ')[1])
                    myCount[a-1] += 1
                    myCount[b-1] += 1

                ### Do the Work!
                tracker = 0
                twoNoder = False
                needStartNode = True
                for x in range(0, totalNodes):
                    if myCount[x] > 3:
                        tracker += myCount[x] - 3
                    elif myCount[x] == 2:
                        if twoNoder:
                            tracker += 1
                        else:
                            needStartNode = False
                            twoNoder = True
                    elif myCount[x] == 0:
                        print('ERROR 00')
                    
                if not(twoNoder) and needStartNode:
                    tracker += 1
                    
                print(myCount)
                ### Output myArr
                print('Case #%d: %d\n' % (caseNum, tracker))
                output.write('Case #%d: %d\n' % (caseNum, tracker))

                ### Step
                lineNum += totalNodes
                
        ### i.e. infoLines == False
        else:   
            print('unused')

                

### END
