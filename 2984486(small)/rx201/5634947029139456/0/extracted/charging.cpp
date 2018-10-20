#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
/*
struct node {
    bool value;
	int count;
	struct node  * left, *right;
}

struct node *add(struct node* t, char* path, int L) {
	for(int i=0; i<L; i++) {
		if (path[i] == '0') {
		    if (t->left == NULL) {
				t->left = (struct node*)malloc(sizeof(struct node));
				memset(t->left, 0, sizeof(struct node));
			}
			t = t->left;
		} else {
		    if (t->right == NULL) {
				t->right = (struct node*)malloc(sizeof(struct node));
				memset(t->right, 0, sizeof(struct node));
			}
			t = t->right;
		}
	}
}

int count(struct node* t) {
	if (t == NULL)
		return 0;
	if (t->left == NULL && t->right == NULL)
		return 1;
		
	t->count = count(t->left) + count(t->right);
	return t->count;
}

int compute(struct node* t0, struct node* t1) {
	if (t0 ==
}
*/
int N, L;
int X[2][20];

int solve() {
	int r = L + 1;
	bool set[2048];
	for(int s = 0; s < (1<<L); s++) {
				
		memset(set, 0, sizeof(set));
		for(int i=0; i<N; i++) {
		
			set[X[0][i]] = true;
		}
		bool mismatch = false;
		for(int i=0; i<N; i++) {
			if (!set[X[1][i] ^ s]) {
				mismatch = true;
				break;
			}
		}
		
		if (mismatch) continue;
		
		int s_bits = 0;
		for(int i=0; i<L; i++)
		    if (s & (1<<i))
				s_bits ++;
		if (s_bits < r)
			r = s_bits;
	}
	
	return r;
}

int main(int argc, char* argv[]) {
	int T;
	
	setbuf(stdout, NULL);
		

	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
		char buf[100], c;
		int value;
		//struct node tree[2];
		//memset(tree, 0, sizeof(tree));
		
		scanf("%d %d\n", &N, &L);
		for (int x = 0; x<2; x++ ) {
			int i = 0;
			int j = 0;
			value = 0;
			while (j < N) {
				scanf("%c", &c);
				if (c != '0' && c != '1')
					continue;
				buf[i++] = c;
				value <<= 1;
				if (c == '1') value += 1;
				//printf("%c", c);
				if (i == L) {
					i = 0;
					//add(&tree[x], buf, L);
					X[x][j++] = value;
					value = 0;
				}
			}
			//count(&tree[x]);
		}
		//int r = compute(&tree[0], &tree[1]);
		int r = solve();
		if (r >= 0 && r <= L)
			printf("Case #%d: %d\n", t+1, r);
		else
			printf("Case #%d: NOT POSSIBLE\n", t+1);
	}
	
	return 0;
}
