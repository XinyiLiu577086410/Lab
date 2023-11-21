#include <cstdio>
#include <cstring>
#include <algorithm>
// #define print(x) do{\
// 	for (int i = 0; i < 4; i++) \
// 	{\
// 		for (int j = 0; j < 4; j++)\
// 		{\
// 			printf("%d ", **(x + i*4 + j));\
// 		}\
// 		printf("\n");\
// 	}\
// }while(0);\

int maxdp = 5;
bool check(bool a[4][4]) {
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			if(a[i][j] != a[0][0]) {
				return false;
			}
	return true;
}

int dfs(bool a[4][4], int dp) {
	if(check(a)) return 0;
	if(dp > maxdp) return 0x7f7f7f7f;
	bool tmp[4][4];
	int m = 0x7f7f7f7f;
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j){
			memcpy(tmp, a, sizeof(tmp));
			if(i>0) 
				tmp[i-1][j] = !tmp[i-1][j];
			if(i<3) 
				tmp[i+1][j] = !tmp[i+1][j];
			if(j>0) 
				tmp[i][j-1] = !tmp[i][j-1];
			if(j<3) 
				tmp[i][j+1] = !tmp[i][j+1];
			tmp[i][j] = !tmp[i][j];
			m = std::min(m, dfs(tmp, dp+1));
		}
	return m+1;
}

int main(void) {
	bool a[4][4];
	char c;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++) {
			scanf("%c", &c);
			if(c == 'w') 
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
		getchar();
	}
	printf("%d", dfs(a, 0));
	return 0;
}