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
const int N = 2e5 + 7;
vector<int>divisors[N];
void pre_calculate(){

	for(ll i = 1; i < N; i++){
		for(ll d = 1; d * d <= i ; d++){
			if(i % d == 0){
				divisors[i].push_back(d);
				if(i / d != d){
					divisors[i].push_back(i / d);
				}
			}
		}
		sort(divisors[i].begin(), divisors[i].end());
	}

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
    	int n;
    	cin >> n;

    	vector<int>arr(n + 1, 0), pos[n + 1];
    	int r = sqrt(n);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}


    	ll ans = 0;
    	for(int l = 1; l <= n; l++){
    		for(int d = 1; d * d <= n; d++){
    			if((ll)arr[l] * d > n)break;
    			int val = arr[l] * d;
    			debug(val, d, l);
    			if(l - val > 0 && arr[l - val] == d){
    				debug(l, l - val);
    				ans++;
    			}
    			if(arr[l] > r && l + val <= n && arr[l + val] == d ){
    				ans++;
    			}

    		}
    	}

    	cout << ans << endl;
    }
    runtime();
    return 0 ;

    

}
