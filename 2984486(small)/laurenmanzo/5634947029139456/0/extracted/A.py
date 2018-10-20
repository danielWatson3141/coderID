import sys
import itertools
import copy

def main(argv):
	filename = argv[1]
	output = argv[2]
	with open(filename) as infile:
		num_tests = int(infile.readline())
		with open(output, 'w+') as out:
			for test_num in range(num_tests):
				out.write('Case #{}: '.format(test_num + 1))
				num_strings, string_length = map(int, infile.readline().split())
				initial = sorted(map(str, infile.readline().split()))
				required = sorted(map(str, infile.readline().split()))

				finished = False
				if initial == required:
					out.write('0\n')
					finished = True

				indexes = list(range(string_length))
				
				if not finished:
					for i in range(1, string_length + 1):
						for combination in itertools.combinations(indexes, i):
							if not finished:
								copylist = copy.deepcopy(initial)
								for flip in combination:
									if not finished:
										for j in range(len(copylist)):
											if copylist[j][flip] == '0':
												copylist[j] = copylist[j][:flip] + '1' + copylist[j][(flip + 1):]
											else:
												copylist[j] = copylist[j][:flip] + '0' + copylist[j][(flip + 1):]
								if sorted(copylist) == required:
									out.write('{}\n'.format(len(combination)))
									finished = True
									break
				if not finished:
					out.write('NOT POSSIBLE\n')

main(sys.argv)