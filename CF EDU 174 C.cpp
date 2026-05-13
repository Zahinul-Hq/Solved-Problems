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
const int mod = 998244353;

int dp[100005][3];
vector<int> v;

int solve(int i, int state) {
    if (i == 0) return (state == 0 ? 1 : 0);
    if (dp[i][state] != -1) 
        return dp[i][state];


    ll ans  = solve(i - 1, state); 
    
    if (v[i - 1] == 1 && state == 0)
        ans = (ans + 1) % mod;
    else if (v[i - 1] == 2 && state == 1)
        ans = (ans + solve(i - 1, 0)) % mod;
    else if (v[i - 1] == 2 && state == 1)
        ans = (ans + solve(i - 1, 1)) % mod;
    else if (v[i - 1] == 3 && state == 2)
        ans = (ans + solve(i - 1, 1)) % mod;
    
    return dp[i][state] = ans;
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

        for(int i = 1; i <= n; i++){
            cin  >> v[i];
        }

        for(int i = 0; i <= n + 1; i++){
            for(int j = 0; j < 3; j++){
                dp[i][j] = -1;
            }
        }

        cout << solve(n , 2) << endl;
    }
    return 0 ;

    runtime();

}
