#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
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
const int N = 2e5 + 7;
string s;
int n, k, m;
ll dp[N];

ll solve(int i){
    if(i >= n)
        return 0;
    if(s[i] == 'C')
        return inf;
    if(dp[i] != -1)
        return dp[i];
    int cnt = 0;
    ll ans = inf;
    if(s[i] == 'W'){
        while(s[i + cnt] == 'W'){
            cnt++;
        }
        if(cnt > 0)
            ans = solve(i + cnt) + cnt;
    }
    if(s[i] == 'L'){
        for(int x = 1; x <= m; x++){
            ans = min(ans, solve(i + x));
        }
    }
    return dp[i] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

        cin >> n >> m >> k >> s;

        for(int i = 0 ;i <= n + 2; i++){
            dp[i] = -1;
        }



        bool ok = 1;

        ll ans = inf;

        for(int i = 0; i < m; i++){
            ans = min(ans, solve(i));
        }
        

        if(ans <= k){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    return 0 ;
}
