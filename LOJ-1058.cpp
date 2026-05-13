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

    	vector<int>x(n, 0), y(n, 0);

    	vector<pair<int,int>>cnt;

    	for(int i = 0; i < n; i++){
    		cin >> x[i] >> y[i];
    	}


    	for(int i = 0; i < n; i++){
    		for(int j = i + 1; j < n; j++){
    			int cx = (x[i] + x[j]) ;
    			int cy = (y[i] + y[j]) ;

    			cnt.push_back({cx, cy});
    		}
    	}

    	ll ans = 0;

    	sort(cnt.begin(), cnt.end());
    	int c = 1;
    	for(int i = 1; i < cnt.size(); i++){
    		if((cnt[i].first == cnt[i - 1].first) && (cnt[i].second == cnt[i - 1].second)){
    			c++;
    		}else{
    			ans += ((1LL * c * (c - 1)) / 2);
    			c = 1;
    		}
    	}

    	debug(cnt);

    	ans += ((1LL * c * (c - 1)) / 2);


    	cout << "Case " << cs++ << ": " << ans << endl;
    }
    return 0 ;

    runtime();

}
