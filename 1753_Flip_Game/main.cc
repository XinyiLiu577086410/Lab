#include <cstdio>
#define MIN(a,b) ((a)<(b)?(a):(b))

bool a[4][4];
int ans = 0x7f7f7f7f;
void flip(int cur) {
	int x = cur / 4, y = cur % 4;
	a[x][y] = !a[x][y];
	if(x>0) a[x-1][y] = !a[x-1][y];
	if(x<3) a[x+1][y] = !a[x+1][y];
	if(y>0) a[x][y-1] = !a[x][y-1];
	if(y<3) a[x][y+1] = !a[x][y+1];
}

bool check() {
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			if(a[i][j] != a[0][0])
				return false;
	return true;
}

void dfs(int cur, int stp) {
	if(check()) {
		ans = MIN(ans, stp);
		return;
	}
	if(cur == 16) return ;
	if(stp == ans) return ;
	dfs(cur+1, stp);
	flip(cur);// let operation[cur] = 1
	dfs(cur+1, stp+1);
	flip(cur);// or let operation[cur] = 0
}

int main(void) {
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
	dfs(0, 0);
	if(ans == 0x7f7f7f7f)
		printf("Impossible");
	else
		printf("%d", ans);
	return 0;
}

/*
WA1:
bwbw
bwww
wwwb
wwwb
2139062143
修改：
check()函数检查的是调用者的结果，放到最前面，仍然WA
如果不可能就输出“Impossible”
*/ 
