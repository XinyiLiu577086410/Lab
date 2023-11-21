#include <map>
#include <string>
#include <cstdio>
char s3[100+10];
char s1[100+10], s2[100+10];
int main(void) {
	std::map<std::string, std::string> mmap;
	while (1) {
		scanf("%s%s", s1, s2);
		mmap[s2] = s1;
		char t;	
		getchar();
		if( (t=getchar()) == '\n' ) break; else ungetc(t, stdin);
	}
	while (1) {
		char t;
		if(scanf("%s", s3) == 0) break;
		if(mmap.find(s3) != mmap.end()) 
			printf("%s\n", mmap[s3].c_str());
		else printf("eh\n");
		getchar();
		if((t=getchar()) == EOF || t == '\n') break; else ungetc(t, stdin);
	}
	return 0;
}