#include<cstdio>
#include<cstring>
char s[110];
bool var[5]; // p,q,r,s,t
bool ans;
int rbound[110]; 
int cur = 0;
void build(int l, int r) {
	nd[cur++] = s[l];
}


void test() {

}


int main(void) {
	scanf("%s", s+1);
	build(1, strlen(s));
	for(int i=0; i<=0b11111; ++i){
		int msk = 1;
		for(int j=0; j<5; ++j){
			var[j] = msk & i;
			msk <<= 1;
		}
		test();
	}
	return 0;
}
