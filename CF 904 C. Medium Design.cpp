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
bool cmp(pair<int,int> l, pair<int,int> r){
	if(l.first == r.first){
		return l.second > r.second;
	}
	return l.first < r.first;
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
    	int  n, m;
    	cin >> n >> m;

    	vector<int>l(n , 0), r(n , 0);
    	vector<pair<int,int>> p, q;

    	for(int i = 0; i < n; i++){
    		cin >> l[i] >> r[i];

    		if(l[i] != 1){
    			p.push_back({l[i], 1});
	    		p.push_back({r[i], -1});
    		}
    		if(r[i] != m){
    			q.push_back({l[i], 1});
	    		q.push_back({r[i], -1});
    		}	
    	}
    	sort(p.begin(), p.end(), cmp);
    	sort(q.begin(), q.end(), cmp);

    	debug(p, q);
    	int ans = 0, curr = 0;
    	for(auto [x, y] : p){
    		curr += y;
    		ans = max(ans, curr);
    	}
    	curr = 0;
    	for(auto [x, y] : q){
    		curr += y;
    		ans = max(ans, curr);
    	}

    	cout << ans << endl;
    }
    return 0 ;

    runtime();

}
