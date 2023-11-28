#include <cstdio>
#include <cmath>
int n;
int radius[100];
int main(void) {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int year;
		double x, y;
		scanf("%lf%lf", &x, &y);
	    double area = 3.1415926 * (x * x + y * y) / 2;
		year = area / 50 + 1;
		printf("Property %d: This property will begin eroding in year %d.\n", i, year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}