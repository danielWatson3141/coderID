from math import floor
import sys

def main():
   if len(sys.argv) != 2:
      print("Error")
      return
      
   file = open(sys.argv[1], 'r')
   
   line_num = 0
   for line in file:
      if line_num == 0:
         line_num += 1
         continue
      elif line_num%3 == 1:
         vars = line.split()
         N = int(vars[0])
         L = int(vars[1])
         line_num += 1
   
      elif line_num%3 == 2:
         start_str = line.split()
         start = [0]*N
         for i in range(0, N):
            start[i] = int(start_str[i], 2)
         line_num += 1
      
      elif line_num%3 == 0:
         desired_str = line.split()
         desired = [0]*N
         for i in range(0, N):
            desired[i] = int(desired_str[i], 2)

         diff_matrix = [[0]*N for i in range(N)]
         for row in range(0, N):
            for col in range(0, N):
               diff_matrix[row][col] = desired[row] ^ start[col] #bitwise xor
         
         correct = []
         #Go through the top row, checking each column
         for index in range(0, N):
            failed = False
            cur_vec = diff_matrix[0][index]
            
            #In each column, find a row with the matching vector
            for col in range(0, N):
               if col == index:
                  continue #skip own column
                  
               #See if the matching vector is in this row
               found = False
               for row in range(1, N):
                  if diff_matrix[row][col] == cur_vec:
                     found = True
                     break
                  
               if not found:
                  failed = True
                  break
            
            if not failed:
               correct.append(cur_vec)
         
         if len(correct) == 0:
            print("Case #" + str(line_num//3) +  ": NOT POSSIBLE")
            
         else:
            correct_mag = [0]*len(correct)
            for i in range(0, len(correct)):
               correct_mag[i] = bin(correct[i]).count("1")
            
            print("Case #" + str(line_num//3) +  ": " + str(min(correct_mag)))

         
         line_num += 1
   
main()
   