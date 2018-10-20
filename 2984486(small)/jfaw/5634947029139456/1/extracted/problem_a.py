import sys
import math

case_nums=0
num_of_lines=1;

def print_ans(case_num,solution):
	print("Case #"+str(case_num)+":"),
	print_solution(solution)


def print_solution(solution):
	"""TO DO"""
	print solution

def input_processor(filename):
	f=open(filename)
	data=f.read().split("\n")
	case_nums=int(data[0])

	"""Insert number of lines per test case here"""
	num_of_lines=3
	data_length=len(data)

	"""Edit start_index here"""
	start_index=1
	case_num=1
	for i in xrange(0,case_nums):
		start=(i*num_of_lines)+start_index
		problem=data[start:start+num_of_lines]
		process_input_case(case_num,problem)
		case_num+=1

def process_input_case(case_num,problem):
	"""Process raw input into apropriate type"""
	
	problem_variable=[]
	for i in xrange(0,len(problem)):
		problem_variable.append(problem[i].split(" "))

	for i in xrange(len(problem_variable[0])):
		problem_variable[0][i]=int(problem_variable[0][i])

	solve(case_num,problem_variable)

def solve(case_num,problem_variable):
	"Solve each problem"
	n=problem_variable[0][0]
	l=problem_variable[0][1]

	a_list=problem_variable[1][:]
	b_list=problem_variable[2][:]

	solution=0
	match=0
	for i in xrange(l+1):
		if match>=n:
				break
		solution=i
		match_list=find_match(a_list[0],b_list,i)
		#print a_list[0],match_list
		for j in xrange( len(match_list)):
			match=1
			for k in xrange (1,n):
				candidates=find_match(a_list[k],b_list,i)
				this_match=0
				for item in candidates:
					if (item==match_list[j]):
						#print item
						match+=1
						this_match+=1
				if this_match>=2:
					print "error"
					print candidates
				if (this_match==0):
					match=0
					break;
			if match>=n:
				break

	if match<n:
		solution="NOT POSSIBLE"


	print_ans(case_num,	 solution)

def find_match(item, list, dis):
	result=[]
	for i in xrange(len(list)):
		dist,mat=distance(item, list[i])
		if (dist==dis):
			#print dis,item,list[i]
			result.append(mat)
	return result



def distance(a,b):
	dis=0
	mat=[]
	for i in xrange (len(a)):
		if (a[i]!=b[i]):
			dis+=1
			mat.append(i)
	return dis,mat

def main():
	input_file=sys.argv[1]
	input_processor(input_file)


if __name__=="__main__":
	main()




	


