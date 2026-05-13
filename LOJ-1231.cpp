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

const int mod = 100000007;
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int case_no = 1; case_no <= t; case_no++){
        int n, K;
        cin >> n >> K;
        
        vector<int> A(n + 1), C(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> C[i];
        }
        
        vector<vector<int>> dp(n + 1,vector<int> (K + 1, 0) );

        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= K; j++){
                for(int l = 0; l <= C[i]; l++){
                    if(A[i] * l <= j){
                       dp[i][j] += dp[i - 1][j - (A[i] * l)];
                       dp[i][j] %= mod;
                    }
                }
               debug(dp, i, j);
            }  
        }

        cout << "Case " << case_no << ": " << dp[n][K] << "\n";
    }
    
    return 0;
}

