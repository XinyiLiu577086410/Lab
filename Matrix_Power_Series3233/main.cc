#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n, k, m;
struct mat;
#define DBG
#undef DBG
#define PRINT(m) do{  \
	for(int i=0; i<n; ++i) {\
		for(int j=0; j<n; ++j) {\
			printf("%d ", m.a[i][j]); \
		}\
		printf("\n");\
	}\
}while(0);

struct mat
{
	int a[30][30];
	int size; 
	mat(){}
	mat(int n): size(n) { memset(a, 0, sizeof a); }
	void mkunit() { for(int i=0; i<n; ++i)a[i][i] = 1; }
	mat operator* (mat b) {
		mat res(size);
		for(int i=0; i<size; ++i) 
			for(int j=0; j<size; ++j)
				for(int k=0; k<size; ++k)
				{
					res.a[i][j] += (a[i][k] * b.a[k][j]) % m;	
					res.a[i][j] %= m;
				}
		return res;
	}
	mat operator+ (mat b) {
		mat res(size);
		for (int i=0; i<size; ++i)
			for(int j=0; j<size; ++j) 
				res.a[i][j] = (a[i][j] + b.a[i][j]) % m;
		return res;
	}
};


mat s_memo[32], base_memo[32];
int cur; // data in [1, cur]
mat series(int k) {
	int floor = (int) pow(2, (int) log2(k));
	int remain = k-floor;
	if(remain == 0)
		return s_memo[(int)log2(k)];
	else 
		floor = (int)log2(floor);
		return s_memo[floor] + base_memo[floor] * series(remain);
}


int main(void) {
	/*init*/
	scanf("%d%d%d", &n, &k, &m);
	mat I(n); I.mkunit();
	for(int i=0; i<32; ++i){
		s_memo[i].size=n; base_memo[i].size = n;
	}
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) 
			scanf("%d", &base_memo[0].a[i][j]);
	/*end init*/
	/*calculate*/
	int ppow = 1, i = 0;
	s_memo[0] = base_memo[0];
	while(ppow<k) {
		++i;
		s_memo[i] = s_memo[i-1]*(base_memo[i-1]+I);
		base_memo[i] = base_memo[i-1]*base_memo[i-1];
		ppow <<= 1;
	}
	mat res=series(k);
	/*end calculate*/
	PRINT(res);
	return 0;
}