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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll n, m;

    	cin >> n >> m;

    	vector<pair<ll,ll>>vp(n);

    	for(int i = 0; i < n; i++){
    		cin >> vp[i].first;
    	}
    	for(int i = 0; i < n; i++){
    		cin >> vp[i].second;
    	}

    	sort(vp.begin(), vp.end());

    	ll val = 0;

        debug(vp);


    	for(int i = 0; i < n - 1; i++){
    		if(vp[i].first + 1 == vp[i + 1].first){
    			ll x = vp[i].first, x_cnt = vp[i].second + vp[i + 1].second, y_cnt = vp[i + 1].second;
                ll d = m / x, r ;



                d = min(d, x_cnt), r = min(m - (x * d), y_cnt);

                debug(d, r,i, x);

                val = max(val, x * d + min(d, r));
    		}

    	}



        cout << val << endl;

    }
    return 0 ;

    runtime();

}
