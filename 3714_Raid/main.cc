#include <cstdio>
#include <vector>
#include <cmath>
#define MIN(x, y) ((x)<(y)?(x):(y))
#define MAX(x, y) ((x)>(y)?(x):(y))
using namespace std;
typedef long long ll;
typedef vector<pair<ll,ll>> coord;
				//  ^x ^y
ll t, n, x, y;
coord sttn, agt, sttn_x, sttn_y, agt_x, agt_y;
// 升序
struct CMPX
{
	bool operator() (pair<ll,ll> a, pair<ll,ll> b) 
	{
		return a.first > b.first;
	}
} cmpx;

struct CMPY
{
	bool operator() (pair<ll,ll> a, pair<ll,ll> b) 
	{
		return a.second > b.second;
	}
} cmpy;

// divide and conque on x
ll mindis2(ll xl, ll xr) { 
	ll mid = (xl+xr)/2;
	ll lres = mindis2(xl, mid);
	ll rres = mindis2(mid, xr);

}


int main(void) {
	scanf("%lld", &t);
	for(ll i=0; i<t; ++i)
	{
		/* begin one testcase */
		sttn.clear();
		agt.clear();
		sttn.reserve(100000+10);
		agt.reserve(100000+10);
		scanf("%lld", &n);
		for(ll j=0; j<n; ++n)
		{
			scanf("%lld%lld", &x, &y);
			sttn.push_back({x,y});
		}
		for(ll j=0; j<n; ++n)
		{
			scanf("%lld%lld", &x, &y);
			agt.push_back({x,y});
		}
		sttn_x = sttn;
		sttn_y = sttn;
		agt_x = agt;
		agt_y = agt;
		sort(sttn_x.begin(), sttn_x.end(), cmpx);
		sort(sttn_y.begin(), sttn_y.end(), cmpy);
		sort(agt_x.begin(), agt_x.end(), cmpx);
		sort(agt_y.begin(), agt_y.end(), cmpy);
		ll lbound = MIN(sttn_x.begin()->first, agt_x.begin()->first);
		ll rbound = MAX(sttn_x.end()->first, agt_x.end()->first);
		ll dis2 = mindis2(lbound, rbound);
		printf("%.3lf", sqrt(dis2));
		/* end one testcase */
	}
	return 0;
}
