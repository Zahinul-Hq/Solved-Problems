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
void solve(){
        ll l, r, g;

        cin >> l >> r >> g;
        if(((l + g - 1) / g)  >= (r / g) && (l > g || r  < g)){
            cout << -1 << " " << -1 << endl;
            return;
        }

        ll st = ((l + g - 1) / g) * g;
        ll en = (r / g) * g;
        ll max_diff = -1, x = st , y = en;

        int it = 300;


        for(ll i = st; i <= en; i += g){
            int iit = 30;
            for(ll j = en; j >= i; j -= g){
                if(__gcd(i, j) == g){
                    if(max_diff < j - i){
                        max_diff = j - i;
                        x = i, y = j;
                    }
                    break;
                }
            }
            if(!it--)
                break;
        }

        cout << x << " " << y << endl;
        //cout << y - x << endl;
        return ;
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
        solve();
    	


    }
    return 0 ;

    runtime();

}
