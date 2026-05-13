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
bool cmp(pair<int,int>x, pair<int,int>y){
	if(x.S > y.S)
		return false;
	if(x.S == y.S){
		if(x.F <= y.F)
			return false;
	}

	return true;
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
    	int n, x, b;
    	cin >> n >> x;
    	vector<pair<ll,ll>>arr;
    	vector<ll>a(n);


    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    	}
    	for(int i = 0; i < n; i++){
    		cin >> b;
    		arr.push_back({a[i], b});
    	}

    	sort(arr.begin(), arr.end(),cmp);

    	ll cost = x, cnt = n - 1;

    	int i = 0;

    	while(cnt > 0 && i < n){
    		if(arr[i].S <= x){
    			cost += (min(arr[i].F, cnt) * arr[i].S);
    			cnt -= arr[i].F;
    			i++;
    		}else{
    			cost += x;
    			cnt--;
    		}
    	}

    	cout << cost << endl;
    	debug(arr);
    }
    return 0 ;

    runtime();

}
