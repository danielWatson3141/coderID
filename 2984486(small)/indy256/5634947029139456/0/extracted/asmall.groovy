name = "A-small-attempt1"
path = ""

sc = new Scanner(new File(path + name + ".in"))
pw = new PrintWriter(path + name + ".out")

testCases = sc.nextInt()

for (testCase in 1..testCases) {

	n = sc.nextInt()
	sc.nextInt()
	a = new long[n]
	for (i in 0..n - 1) {
		a[i] = Long.valueOf(sc.next(), 2)
	}
	b = new long[n]
	for (i in 0..n - 1) {
		b[i] = Long.valueOf(sc.next(), 2)
	}
	Arrays.sort(b)
	int res = Integer.MAX_VALUE
	for (i in 0..n - 1) {
		long x = a[i] ^ b[0]
		a1 = a.clone()
		for (j in 0..n - 1) {
			a1[j] ^= x
		}
		Arrays.sort(a1)
		if (Arrays.equals(a1, b)) {
			res = Math.min(res, Long.bitCount(x))
		}
	}
	pw.println("Case #" + testCase + ": " + (res == Integer.MAX_VALUE ? "NOT POSSIBLE" : res))
}

pw.close()
sc.close()
