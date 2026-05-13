#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	ll x1, y1, z1, x2, y2, z2, mxx = 1005, mxy = 1500, mxz = 1500, mnx = 0, mny = 0, mnz = 0;

    	while(n--){
    		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    		mxx = min(x2, mxx);
    		mxy = min(y2, mxy);
    		mxz = min(z2, mxz);
    		mnx = max(x1, mnx);
    		mny = max(y1, mny);
    		mnz = max(z1, mnz);
    	}

    	debug(mxx, mxy, mxz, mnx, mny, mnz);

    	cout << "Case " << cs++ << ": " ;
    	if((mxx - mnx) > 0 && (mxy - mny) > 0 && (mxz - mnz) > 0){
    		cout << (mxx - mnx) * (mxy - mny) * (mxz - mnz) << endl;
    	}else{
    		cout << 0 << endl;
    	}
    }
    return 0 ;

    runtime();

}
