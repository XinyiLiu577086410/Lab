#include <cstdio> 
#include <cstring>
#include <stack>
char ss[100+10];
bool var[5]; // p/q/r/s/t
int varId(char c) {return c - 'p';}
bool op(char op, char l, char r) {
	int id1 = 0x7f7f7f7f, id2 = 0x7f7f7f7f;

	switch (op)
	{
	case 'K':
		return var[id1] && var[id2];
		break;
	case 'A':
		return var[id1] || var[id2];
		break;
	case 'N':
		return !var[id2];
		break;
	case 'C':
		return !var[id1] || var[id2];
		break;
	case 'E':
		return var[id1] == var[id2];
		break;
	default:
		break;
	}
}
bool isVar(char c) {
	return c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't';
}
bool isOp(char c) {
	return c == 'K' || c == 'A' || c == 'N' || c == 'C' || c == 'E';
}
bool calc(int assign, std::stack<char> op,  std::stack<char> var) {
	while (! op.empty()) {
		char opp = op.top();
		char l, r;
		op.pop();
		if(opp == 'N') {
			r = var.top();
			var.pop();
			var.push(op(opp,,r));
		}
		else {

		}
	}
	
}
bool judge(char ss[]) {
	// printf("%s",ss);
	std::stack<char> ops, vars;
	int len = strlen(ss);
	for(int i=0; i<len; ++i) {
		if(isVar(ss[i])) vars.push(ss[i]);
		else if(isOp(ss[i])) ops.push(ss[i]);
	}
	for(int i = 0; i < 0b11111; ++i) {
		if(!calc(i, ops, vars))
			return false;
	}
	return true;
}

int main(void) {
	scanf("%s", ss);
	while(strcmp("0", ss)) {
		printf("%s\n", judge(ss)?"tautology":"not");
		scanf("%s", ss);
	}
	return 0;
}