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
ll lcm(ll a, ll b){
    return a/__gcd(a,b) * b;
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
    	ll N, m;
    	cin >> N >> m;
    	vector<ll>arr(m, 0);

    	for(int i = 0; i < m; i++){
    		cin >> arr[i];
    	}

    	ll ans = 0;

    	for(int i = 1; i < (1 << m); i++){
    		bool f = 0;
    		ll mul = 1;
    		int cnt = 0;

    		for(int j = 0; j < m; j++){
    			if(i & (1 << j)){
    				mul = lcm(mul,arr[j]);
    				cnt++;
    				if(mul > N){
	    				f = 1;
	    				break;
    				}
    			}

    			
    		}

    		if(!f){
    			if(cnt % 2 == 1){
    				ans += (N / mul);
    			}else{
    				ans -= (N / mul);
    			}
    		}
    	}

    	cout << "Case " << cs++ << ": " << N - ans << endl;
    }
    return 0 ;

    runtime();

}
