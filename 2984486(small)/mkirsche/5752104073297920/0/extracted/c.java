import java.util.*;
import java.io.*;
public class c {
	static int oo = 987654321;
public static void main(String[] args) throws FileNotFoundException
{
	PrintWriter out = new PrintWriter(new File("c.txt"));
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	int good = 0, good2 = 0;
	for(int t = 0; t<T; t++)
	{
//		int n = 1000;
//		Random r = new Random();
//		int[] perm = new int[n];
//		int type = 0;
//		if((type = r.nextInt(2)) == 0) perm = goodperm(n);
//		else perm = badperm(n);
//		int guess = calc(perm);
//		if(guess == 0) good2++;
//		if(guess == type) good++;
		
		int n = input.nextInt();
		int[] perm = new int[n];
		for(int i = 0; i<n; i++) perm[i] = input.nextInt();
		out.printf("Case #%d: ", t+1);
		int guess = calc(perm);
		if(guess == 0)
		{
			good++;
			out.println("GOOD");
		}
		else out.println("BAD");
		
//		int n = input.nextInt();
//		int[] xs = new int[n];
//		int win = 0;
//		double a1 = 0, a2 = 0;
//		int ITER = 10000;
//		ArrayList<Long> list = new ArrayList<Long>();
//		for(int i = 0; i<ITER; i++)
//		{
//			int[] data1 = goodperm(n), data2 = badperm(n);
//			//long ic1 = invCount(data1), ic2 = invCount(data2);
//			long ic1 = disp(data1), ic2 = disp(data2);
//			a1 += ic1;
//			a2 += ic2;
//			list.add(ic2);
//			if(ic1 > ic2) win++;
//		}
//		a1 /= ITER;
//		a2 /= ITER;
//		Collections.sort(list);
//		System.out.println(list.get((int)(ITER * .92)));
//		System.out.println(a1+" "+a2);
//		System.out.println(win);
	}
//	System.out.println(good+" "+(T-good));
//	System.out.println(good2);
	out.close();
}
static int calc(int[] perm)
{
	long disp = disp(perm);
	long inv = invCount(perm);
	if(disp > 330000) return 0;
	if(disp < 322000) return 1;
	if(inv > 244800) return 0;
	else return 1;
//	if(disp > 329000 || inv > 246000) return 0;
//	else return 1;
//	if(inv > 244650) return 0;
//	else return 1;
}
static long disp(int[] perm)
{
	long res = 0;
	int n = perm.length;
	for(int i = 0; i<n; i++) res += Math.abs(i - perm[i]);
	return res;
}
static int[] goodperm(int n)
{
	Random r = new Random();
	int[] res = new int[n];
	for(int i = 0; i<n; i++) res[i] = i;
	for(int k = 0; k<n; k++)
	{
		  int p = r.nextInt(n-k) + k;
		  int temp = res[k];
		  res[k] = res[p];
		  res[p] = temp;
	}
	return res;
}
static int[] badperm(int n)
{
	Random r = new Random();
	int[] res = new int[n];
	for(int i = 0; i<n; i++) res[i] = i;
	for(int k = 0; k<n; k++)
	{
		  int p = r.nextInt(n);
		  int temp = res[k];
		  res[k] = res[p];
		  res[p] = temp;
	}
	return res;
}
public static long merge(int[] arr, int[] left, int[] right) {
    int i = 0, j = 0;
    long count = 0;
    while (i < left.length || j < right.length) {
        if (i == left.length) {
            arr[i+j] = right[j];
            j++;
        } else if (j == right.length) {
            arr[i+j] = left[i];
            i++;
        } else if (left[i] <= right[j]) {
            arr[i+j] = left[i];
            i++;                
        } else {
            arr[i+j] = right[j];
            count += left.length-i;
            j++;
        }
    }
    return count;
}

public static long invCount(int[] arr) {
    if (arr.length < 2) return 0;
    int m = (arr.length + 1) / 2;
    int left[] = Arrays.copyOfRange(arr, 0, m);
    int right[] = Arrays.copyOfRange(arr, m, arr.length);
    return invCount(left) + invCount(right) + merge(arr, left, right);
} 
}
