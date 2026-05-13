#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e10
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
const int N = 1e3 + 7;
vector<bool>is_prime(N, true);
vector<int>factors[N];
void seive(){
    for(int i=2;i< N;i++){
        int n = i;
        for(int j=2;j*j<=n;j++){
            if(n%j==0){
                factors[i].pb(j);
                while(n%j==0){
                    n/=j;
                }
            }
        }
        if(n>1 and n!=i)factors[i].pb(n);//as 1 and nije not allowed
    }
}
int s, t;

ll dp[N] ;

ll f(int n){
	if(n >= t || factors[n].size() == 0){
		if(n == t){
			return 0;
		}
		return inf;
	}

	if(dp[n] != -1)
		return dp[n];

	ll ans = inf;
	for(int i = 0; i < factors[n].size(); i++){
		ans = min(ans, f(n + factors[n][i]) + 1);
	}
	return dp[n] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int test_cases,cs = 1 ;
    cin >> test_cases ;

    seive();
    debug(factors);

    
    while (test_cases--)
    {

    	cin >> s >> t;

    	cout << "Case " << cs++ << ": " ;

    	for(int i = 1; i < N; i++){
    		dp[i] = -1;
    	}

    	ll ans = f(s);

    	if(ans == inf)
    		cout << -1 << endl;
    	else
    		cout << ans << endl;
    }
    return 0 ;

}
