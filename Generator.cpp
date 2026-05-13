#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   1e12
//#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll rnd(ll low, ll high) {
    
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    uniform_int_distribution<ll> dist(low, high);

    return dist(rng);
}
ll  l = 1e18, r = 20;
int main(){


    //int t = 200;
    
    srand(chrono::steady_clock::now().time_since_epoch().count());
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


    int N = 100000;
    long long MOD = 1e9 + 7; // large prime within constraint
    
    // Method: Linear congruential spread — all distinct, pseudorandom spread
    // a[i] = (i * MAGIC) % MOD + 1
    // MAGIC = large prime coprime with MOD → gives full permutation-like spread
    
    long long MAGIC = 998244353LL; // large prime

    set<ll>st;
    
    cout << N << "\n";
    for (int i = 1; i <= N / 2; i++) {
        
        ll val = (107897 * i);

        cout << val % MOD;
        if (i < N) cout << " ";

    }
    for (int i = 1; i <= N / 2; i++) {
        
        ll val = 126271 * i ;

        cout << val % MOD;
        if (i < N) cout << " ";

    }




    
    cout << "\n";


    cout << N << endl;

    for (int i = 1; i <= N; i++) {
        
        ll val = 126271 * i ;

        cout << l <<endl;

    }



    
    return 0;
}


