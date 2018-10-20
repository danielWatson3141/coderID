#v2.0
import os
#Reads file whose name is specified by the argument "infilename" in the current working directory, and returns a value T, the first line in the file, and a two dimensional array, where X is the line number and Y is the values on that line, seperated by spaces.
def read_infile(infilename,splitSpaces):
	f=open(os.getcwd()+"/"+infilename)
	file_data=f.read()
	first_split = file_data.split("\n")
	first_value=first_split.pop(0)
	second_split=[]
	if splitSpaces==True:
		for i in first_split:
			if True!=("".join(i.split())==""):
				second_split.append(i.split(" "))
	else:
	
		for i in first_split:
			if i!="":
				second_split.append(i)
	
	

	return first_value,second_split

#Takes a list of strings and a filename, and writes an outfile in the current directory with the specified name and each string in the list after a "Case #N: "
def write_outfile(answerlist,name):
	i=1
	outData=""
	for a in answerlist:
		outData=outData+"Case #"+str(i)+": "+str(a)+"\n"
		i+=1
	f=open(os.getcwd()+"/"+name,"w")
	f.write(outData)

#Groups a list into a list of lists of size N
def grouplist(inlist,n):
	if len(inlist)%n==0:
		i=0
		outlist=[]
		while i/n<(len(inlist)/n):
			newlist=inlist[i:n+i]		
			outlist.append(newlist)
			i+=n
		return outlist
	else:
		print "List not dividable."	
