

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
const int N = 5e4 + 7, mod = 1e9+7;
vector<ll>pref(N, 0), spf(N, INT_MAX);
vector<bool>is_prime(N, true);
void pre(){

    for(ll i = 2; i < N; i++){
        if(spf[i] == INT_MAX){
            for(ll j = i; j < N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }

    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int test_cases, cs = 1 ;
    cin >> test_cases ;

    while (test_cases--)
    {
        int n;
        cin >> n;
        ll nod = 1;
        vector<int>cnt(n + 1, 0);
        for(int i = 2; i <= n; i++){
        int val = i;

        
            while(val > 1){
                cnt[spf[val]]++;
                val /= spf[val];
            }
        }

        for(int i = 2; i <= n; i++){
            nod *= (cnt[i] + 1);
            nod %= mod;
        }

        cout << nod << endl;
       
    }
    return 0 ;

    runtime();

}
