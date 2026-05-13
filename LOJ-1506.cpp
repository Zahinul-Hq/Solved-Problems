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
const int N = 2e6 + 7 ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inout() ;

    int test_cases,  cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, x, mx_val = 0;
        cin >> n;
        vector<ll>arr(N + 1, 0),f(N + 1, 0), a(n + 1, 0);
        for(int i = 0; i < n; i++){
            cin >> x;
            arr[x] += ( x * x);
            a[i] = x;
            f[x]++;
            mx_val = max(mx_val, x);
        }
        vector<bool>marked(N + N, true);

        vector<ll>prefix_sum(N + N, 0), freq_cnt(N +N, 0);
        for(int i = 1; i < N; i++){
            prefix_sum[i] = prefix_sum[i - 1] + (arr[i]);
            freq_cnt[i] = freq_cnt[i - 1] + f[i];
        }
        ll max_cost = inf, gcd = 0;

        for(ll g = 2;  g <= mx_val; g++){
            ll cost = 0;
                for(ll X = g; X <= mx_val + mx_val; X += g){
                  int r = X - 1, l = X - g + 1;
                  cost +=   ((X * X * (freq_cnt[r] - freq_cnt[l - 1])) - (prefix_sum[r] - prefix_sum[l - 1])) ;
               //cout << X << " " << prefix_sum[r - 1] - prefix_sum[l - 1]<< " " << freq_cnt[r] - freq_cnt[l - 1] << endl;
                  if(cost > max_cost)
                    break;
                }
            
            //cout << cost << endl;
            if(cost <= max_cost){
                gcd = g;
                max_cost = cost;
            }
        }
            
        cout << "Case " << cs++ << ": " << max_cost << " " << gcd << endl;
    }
    
}
