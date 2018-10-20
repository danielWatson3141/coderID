#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef long long lint;

// 最多聚类数目
const int MAX_K = 1 << 10;
// 设定的极大值
const double INF = 1e200;
// 所相差的最小值
const double EPS = 1.0e-1;

// 元素的集合，用"点"这个概念形象理解表示
class Point: public vector<double> {
	public:
		// 每个元素的维度，所有元素的维度相同
		static int dimSize;
		int id;
		Point(): vector<double>(dimSize, 0), id(0) {
		}
		Point(int id): vector<double>(dimSize, 0), id(id) {
		}
		Point(const Point & o) {
			this->clear();
			for (int i = 0; i < dimSize; i++) {
				this->push_back(o[i]);
			}
			this->id = o.id;
		}
		double dis2(const Point & o) const {
			double res = 0.0;
			for (int i = 0; i < dimSize; i++) {
				double tmp = (*this)[i] - o[i];
				res += tmp * tmp;
			}
			return res;
		}
		// 距离函数，欧式距离
		double dis(const Point & o) const {
			return sqrt(this->dis2(o));
		}
		Point operator + (const Point & o) {
			Point res = Point();
			for (int i = 0; i < dimSize; i++) {
				res[i] = (*this)[i] + o[i];
			}
			return res;
		}
		Point operator / (double x) {
			Point res = Point();
			for (int i = 0; i < dimSize; i++) {
				res[i] = (*this)[i] / x;
			}
			return res;
		}
		Point &operator = (const Point & o) {
			this->clear();
			for (int i = 0; i < dimSize; i++) {
				this->push_back(o[i]);
			}
			this->id = id;
			return *this;
		}
};
// 元素的格式，聚类的个数
int numSize, kSize;
int Point::dimSize = 1;
vector<Point> points;

// 获取point元素最近的一个中心下标
int getLable(vector<Point> &means, Point &point) {
	double minDis = INF;
	int res = -1;
	for (int i = 0; i < kSize; i++) {
		double tmp = means[i].dis(point);
		if (minDis > tmp) {
			minDis = tmp, res = i;
		}
	}
	return res;
}

// 得到当前的标准差之和E
double getVal(vector<Point> &means, vector<Point> cluster[]) {
	double res = 0.0;
	for (int i = 0; i < kSize; i++) {
		for (int j = 0; j < (int)cluster[i].size(); j++) {
			res += means[i].dis(cluster[i][j]);
		}
	}
	return res;
}

// 各个集合得到新的质心，迭代的过程
void getMeans(vector<Point>& means, vector<Point> cluster[]) {
	means.clear();
	for (int i = 0; i < kSize; i++) {
		Point tmp = Point();
		for (int j = 0; j < (int)cluster[i].size(); j++) {
			tmp = tmp + cluster[i][j];
		}
		means.push_back(tmp / (double)cluster[i].size());
	}
}

// 执行K-means算法核心
void K_Means(FILE *output) {
	static set<int> vis;
	static vector<Point> cluster[MAX_K];
	static vector<Point> means;
	vis.clear(), means.clear();
	srand(time(NULL));
	for (int i = 0; i < kSize; i++) {
		// 随机选取起始点
		int choose = (lint)rand() * numSize / RAND_MAX;
		if (vis.find(choose) != vis.end()) {
			i--;
			continue;
		}
		vis.insert(choose);
		means.push_back(points[choose]);
	}

	fill(cluster, cluster + kSize, vector<Point>());
	for (int i = 0; i < numSize; i++) {
		cluster[getLable(means, points[i])].push_back(points[i]);
	}

	double oldVal = -1, newVal = getVal(means, cluster);
	fprintf(stderr, "The orignal E = %.12lf.\n", newVal);

	int tim = 0;
	// 迭代加深，直到前后两次相差在EPS以内
	while (fabs(oldVal - newVal) > EPS) {
		getMeans(means, cluster);
		fill(cluster, cluster + kSize, vector<Point>());
		for (int i = 0; i < numSize; i++) {
			cluster[getLable(means, points[i])].push_back(points[i]);
		}

		oldVal = newVal, newVal = getVal(means, cluster);
		fprintf(stderr, "The No.%d E = %.12lf.\n", ++tim, newVal);
	}

	for (int i = 0; i < kSize; i++) {
		fprintf(output, "%d\n", cluster[i].size());
		for (int j = 0; j < (int)cluster[i].size(); j++) {
			fprintf(output, "%d%c", cluster[i][j].id, " \n"[j == cluster[i].size() - 1]);
		//	for (int k = 0; k < Point::dimSize; k++) {
		//		fprintf(output, " %.3lf%c", cluster[i][j][k], ",\n"[k == Point::dimSize - 1]);
		//	}
		}
		fprintf(output, "\n");
	}
}

int main(int argc, char *argv[]) {
	FILE *output, *input;

	if (argc == 1) {
		input = fopen("in.txt", "r"), output = fopen("out.txt", "w");
	} else {
		input = fopen(argv[1], "r"), output = fopen("out.txt", "w");
	}

	fscanf(input, "%d%d%d", &numSize, &Point::dimSize, &kSize);
	points.clear();
	for (int i = 1; i <= numSize; i++) {
		Point read = Point(i);
		for (int j = 0; j < Point::dimSize; j++) {
			fscanf(input, "%lf", &read[j]);
		}
		points.push_back(read);
	}

	K_Means(output);
	fclose(input), fclose(output);
	//system("notepad out.txt");
	return 0;
}
