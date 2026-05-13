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
    	ll n, xx = 0;
    	cin >> n;

    	for(ll i = 1;; i++){
    		if((i * (i - 1)) / 2 > n)
    			break;
    		xx = i;
    	}

    	ll ex = n - ((xx * (xx - 1)) / 2);

    	vector<pair<int,int>>ans;

    	debug(xx);

    	int x = 0, y =0; 
    	while(xx--){
    		ans.push_back({x++, y});
    	}
    	y++;

    	while(ex--){
    		ans.push_back({x++, y});
    		ans.push_back({x++, y++});
    	}

    	cout << ans.size() << endl;

    	for(auto i : ans){
    		cout << i.F << " " << i.S << endl;
    	}




    }
    return 0 ;

    runtime();

}
