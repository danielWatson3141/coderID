import itertools

def Search(pos, left, olds, news, N, L):
	if(left < 0):
		return False

	if pos == -1:
		olds2 = olds
		olds2.sort()
		news.sort()
		if olds2 == news:
			# print
			# print olds
			# print news
			# print left
			# print
			return True
		else:
			return False
	else:

		if Search(pos - 1, left, olds, news, N, L):
			return True;

		for i in range(N):
			new_s = olds[i][:pos] + str(1 - int(olds[i][pos])) + olds[i][pos + 1:]
			olds[i] = new_s

		if Search(pos - 1, left - 1, olds, news, N, L):
			return True;

		for i in range(N):
			new_s = olds[i][:pos] + str(1 - int(olds[i][pos])) + olds[i][pos + 1:]
			olds[i] = new_s

		return False


T = int (raw_input())

for t in range(T):
	N, L = map(int, raw_input().split())

	olds = raw_input().split()
	news = raw_input().split()

	res = 1000
	for i in range(L):
		if Search(L - 1, i, olds, news, N, L):
			res = i
			break


	if res == 1000:
		print 'Case #{0}: NOT POSSIBLE'.format(t + 1)
	else:
		print 'Case #{0}: {1}'.format(t + 1, res)


