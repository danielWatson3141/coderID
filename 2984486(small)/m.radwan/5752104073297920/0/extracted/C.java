import java.io.File;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Scanner;

public class C {
	static Random r = new Random(System.nanoTime());

	public static int[] bad(int n) {
		// for k in 0 .. N-1:
		// a[k] = k
		// for k in 0 .. N-1:
		// p = randint(0 .. N-1)
		// swap(a[k], a[p])
		int[] arr = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int nxt = r.nextInt(n);
			int t = arr[nxt];
			arr[nxt] = arr[i];
			arr[i] = t;
		}
		return arr;
	}

	public static int[] good(int n) {
		// for k in 0 .. N-1:
		// a[k] = k
		// for k in 0 .. N-1:
		// p = randint(0 .. N-1)
		// swap(a[k], a[p])
		int[] arr = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int nxt = r.nextInt(i + 1);
			int t = arr[nxt];
			arr[nxt] = arr[i];
			arr[i] = t;
		}
		return arr;
	}

	public static void swap(int i, int j, int[] a) {
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	static int[] bias = { -82, 3562, 4064, 3597, 3350, 3806, 3624, 3512, 3672,
			3718, 3570, 3528, 3224, 3541, 3570, 3433, 3685, 3842, 3793, 3477,
			3574, 3531, 3635, 3529, 3177, 3589, 3527, 3282, 3487, 3342, 3055,
			3414, 3284, 3395, 3279, 3311, 3254, 3373, 3161, 3411, 3255, 3273,
			3458, 3248, 3302, 3377, 3210, 3367, 3229, 3310, 3259, 3443, 3332,
			2946, 3252, 3083, 3067, 3181, 3264, 3152, 2954, 2922, 3221, 3035,
			3326, 2974, 3354, 2916, 3012, 3153, 3207, 3075, 2916, 3011, 2968,
			2934, 2915, 3186, 2719, 2853, 2934, 2921, 2701, 2621, 2951, 2636,
			2784, 2860, 2951, 2624, 2765, 2855, 2813, 2806, 2745, 2663, 2543,
			2678, 2657, 2742, 2709, 2895, 2616, 2500, 2862, 2620, 2673, 2611,
			2643, 2679, 2578, 2481, 2690, 2877, 2774, 2489, 2628, 2501, 2550,
			2454, 2614, 2446, 2543, 2587, 2375, 2468, 2374, 2327, 2528, 2426,
			2214, 2567, 2485, 2368, 2527, 2083, 2453, 2345, 2609, 2542, 2615,
			2198, 2479, 2382, 2546, 2177, 2466, 2201, 2038, 2026, 2241, 2317,
			2399, 2038, 2136, 2063, 2058, 2045, 2182, 2043, 2183, 2096, 2397,
			2277, 2336, 2375, 2082, 2002, 2104, 2184, 1946, 1968, 1968, 1935,
			1988, 2160, 2108, 2053, 2123, 2254, 1945, 1945, 2105, 2191, 2133,
			1864, 2051, 1978, 2001, 2160, 2183, 1947, 1898, 1965, 1885, 2065,
			2182, 1985, 1927, 1830, 1849, 1993, 1842, 1866, 1759, 1762, 1813,
			1784, 1795, 1621, 1757, 1806, 1763, 1790, 1613, 1755, 1611, 1801,
			1787, 1754, 1592, 1528, 1751, 1995, 1557, 1830, 1655, 1729, 1687,
			1646, 1643, 1505, 1639, 1765, 1655, 1759, 1428, 1502, 1543, 1491,
			1398, 1378, 1556, 1484, 1632, 1764, 1660, 1383, 1384, 1158, 1651,
			1490, 1560, 1421, 1676, 1232, 1441, 1462, 1242, 1483, 1377, 1230,
			1261, 1286, 1617, 1524, 1180, 1143, 1297, 1653, 1368, 1283, 1196,
			1363, 1243, 1259, 1419, 1458, 1275, 1195, 1191, 1371, 1449, 1562,
			1189, 1203, 960, 1103, 931, 1198, 1086, 1078, 1234, 713, 1343,
			1194, 1034, 1032, 1234, 1227, 1008, 1418, 1188, 1206, 1188, 980,
			1103, 1032, 801, 1059, 1183, 1077, 849, 1113, 1108, 985, 674, 967,
			682, 725, 983, 1218, 958, 878, 1222, 650, 723, 988, 986, 801, 903,
			852, 831, 826, 972, 984, 835, 742, 1069, 836, 687, 918, 637, 736,
			830, 682, 681, 885, 374, 642, 627, 728, 450, 833, 694, 658, 656,
			501, 586, 579, 844, 894, 427, 704, 913, 440, 784, 725, 494, 629,
			686, 402, 826, 811, 489, 547, 602, 798, 270, 461, 431, 619, 703,
			554, 467, 433, 324, 322, 592, 302, 502, 537, 393, 399, 454, 430,
			333, 488, 403, 586, 424, 258, 169, 110, 234, 373, -101, 262, 328,
			121, 208, 372, 239, 327, 310, 116, 69, 297, 376, 406, 280, 260,
			226, 318, 244, 278, 252, 101, -100, 34, 68, 9, 292, 224, 255, 330,
			292, 253, 132, 257, 129, 19, 17, 100, 263, -71, 74, -15, 99, -45,
			-60, 81, -233, 98, 225, -76, 77, -145, -181, -57, -40, 102, -136,
			-37, -43, 2, 39, -110, -97, 36, 165, -406, 187, 43, -15, -1, -322,
			-7, -149, -328, 94, -27, 8, -213, -304, 98, -285, -379, -379, -345,
			-292, -113, -6, -226, -41, -372, -433, -359, -309, -263, -477,
			-226, -389, -232, -128, -161, -307, -180, -304, -353, -200, -547,
			-386, -265, -256, -354, -264, -495, -346, -280, -402, -491, -472,
			-648, -193, -379, -348, -375, -577, -280, -400, -418, -560, -329,
			-443, -320, -368, -519, -729, -478, -604, -289, -360, -409, -532,
			-455, -440, -445, -624, -444, -547, -430, -412, -714, -505, -433,
			-577, -482, -559, -582, -721, -502, -1029, -487, -909, -530, -508,
			-579, -1048, -639, -753, -929, -847, -352, -679, -651, -812, -843,
			-740, -534, -793, -844, -729, -663, -869, -864, -1077, -698, -1063,
			-589, -751, -728, -916, -708, -709, -1001, -653, -1017, -611, -793,
			-829, -814, -937, -898, -1212, -922, -858, -786, -852, -696, -851,
			-835, -1011, -946, -496, -558, -776, -812, -941, -992, -920, -1346,
			-856, -717, -840, -1325, -1107, -1246, -1097, -1074, -843, -974,
			-809, -884, -1096, -1102, -848, -1055, -1256, -818, -1272, -1049,
			-1138, -1271, -1169, -822, -1285, -1058, -988, -1165, -1153, -1139,
			-1024, -1311, -1394, -1175, -1342, -1121, -838, -1078, -1295,
			-1044, -1209, -1161, -1386, -1096, -1063, -1093, -1125, -982,
			-1137, -1013, -1108, -1054, -1475, -1011, -1298, -1228, -1339,
			-1249, -1122, -1249, -1292, -1207, -1455, -1320, -1289, -1224,
			-1378, -1354, -1207, -1403, -1468, -1415, -1451, -1281, -1338,
			-1467, -1459, -1287, -1449, -1222, -1309, -1403, -1459, -1318,
			-1688, -1381, -1464, -1321, -1342, -1618, -1258, -1298, -1451,
			-1562, -1624, -1483, -1414, -1317, -1699, -1464, -1392, -1478,
			-1622, -1221, -1537, -1466, -1364, -1591, -1588, -1579, -1615,
			-1703, -1409, -1440, -1938, -1368, -1592, -1445, -1398, -1372,
			-1658, -1465, -1595, -1701, -1358, -1602, -1735, -1728, -1452,
			-1477, -1461, -1354, -1561, -1656, -1834, -1488, -1418, -1906,
			-1553, -1525, -1722, -1734, -1539, -1651, -1812, -1898, -1432,
			-1667, -1397, -1676, -1826, -1671, -1833, -1855, -1741, -1812,
			-2031, -1581, -1695, -1682, -1566, -1546, -1762, -1900, -1908,
			-1867, -1729, -1892, -1798, -1689, -1804, -1760, -1670, -1986,
			-1767, -1807, -1962, -1675, -1866, -1936, -1733, -1522, -1938,
			-1764, -1778, -1923, -1775, -1684, -1970, -1674, -2010, -1788,
			-2034, -1917, -1861, -1594, -1924, -1815, -1930, -1782, -2176,
			-1821, -1855, -2115, -1957, -1825, -1884, -2031, -2117, -2147,
			-2166, -2049, -2009, -1895, -1950, -1717, -1827, -2030, -2337,
			-1895, -1900, -2045, -2024, -2077, -1991, -1784, -1969, -2080,
			-1960, -2049, -2042, -1970, -2193, -2221, -1912, -2208, -2077,
			-2080, -2116, -2289, -2007, -2252, -1907, -2068, -2141, -2007,
			-2282, -2288, -2144, -2028, -2140, -2319, -1835, -1987, -2086,
			-2094, -2179, -2192, -2167, -2143, -2089, -1903, -2018, -2070,
			-2080, -2201, -2485, -2126, -2274, -2279, -2161, -2245, -2318,
			-2394, -2020, -2105, -2395, -2274, -2174, -2034, -1964, -2228,
			-2060, -2426, -2298, -2146, -2596, -2292, -2266, -2297, -2335,
			-2532, -2236, -2675, -2280, -2371, -2337, -2273, -2269, -2311,
			-2312, -2344, -2497, -2200, -2505, -2516, -2233, -2755, -2265,
			-2490, -2439, -2346, -2315, -2550, -2204, -2251, -2453, -2402,
			-2357, -2369, -2416, -2219, -2487, -2116, -2352, -2497, -2471,
			-2393, -2431, -2631, -2331, -2498, -2609, -2514, -2602, -2413,
			-2449, -2311, -2433, -2621, -2456, -2531, -2647, -2471, -2377,
			-2628, -2254, -2604, -2681, -2562, -2588, -2468, -2656, -2755,
			-2528, -2397, -2680, -2647, -2565, -2607, -2464, -2767, -2672,
			-2627, -2502, -2493, -2356, -2551, -2662, -2418, -2635, -2796,
			-2480, -2572, -2971, -2529, -2655, -2483 };

	public static void main(String[] args) throws Exception {
		// int[] cnt = new int[1000];
		// int max = 10000000;
		// for (int i = 0; i < 10000000; i++) {
		// int[] a = bad(1000);
		// cnt[a[0]]++;
		// int[] b = good(1000);
		// cnt[b[0]]--;
		// if (i % 1000000 == 0) {
		// System.out.println(i * 1.00 / max);
		// }
		// }
		// System.out.println(Arrays.toString(cnt));
		String fileName = "C-small-attempt7";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(fileName + ".out");
		int tc = in.nextInt();
		int cc = 1;
		while (tc-- > 0) {
			Random r = new Random(System.nanoTime());
			int n = in.nextInt();
			int[] input = new int[n];
			for (int i = 0; i < input.length; i++)
				input[i] = in.nextInt();
			String outp = r.nextBoolean() ? "GOOD" : "BAD";
			if (bias[input[0]] > 0) {
				if (r.nextInt(1000) < bias[input[0]]) {
					outp = "BAD";
				}
			} else {
				if (r.nextInt(1000) < -bias[input[0]]) {
					outp = "GOOD";
				}
			}
			System.out.printf("Case #%d: %s\n", cc, outp);
			out.printf("Case #%d: %s\n", cc, outp);
			cc++;
		}
		out.close();
	}
}