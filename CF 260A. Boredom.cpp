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

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1e5 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n , x;
    cin >> n;
    vector<ll>cnt(N, 0), arr , dp(N, 0);

    for(int i = 0; i < n; i++){
    	cin >> x;
    	cnt[x]++;
    }
    dp[1] = cnt[1] ;

    for(ll i = 1; i < N; i++){
    	if(i - 2 >= 0){
    		dp[i] = max(dp[i - 1], dp[i - 2] + (cnt[i] * i));
    	}

    }

    cout << dp[N -  1] << endl;
    return 0 ;
}
