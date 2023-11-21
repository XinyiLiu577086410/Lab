#include <cstdio>
int n1, n2;
#define BIAS 32768
bool hshtbl[BIAS*2];
short tmp;
int main(void) {
	scanf("%d", &n1);
	for(int i=1; i<=n1; ++i) {
		scanf("%hd", &tmp);
		hshtbl[tmp + BIAS] = true;
	}
	scanf("%d", &n2);
	for(int i=1; i<=n2; ++i) {
		scanf("%hd", &tmp);
		if(hshtbl[(10000-tmp) + BIAS] == true) {
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}