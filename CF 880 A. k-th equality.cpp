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
int power(int a, int e) {
    if (e == 0) return 1;
    return e == 1 ? a : a * power(a, e-1);
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
    	ll a , b, c, k;
    	cin >> a >> b >> c >> k;

        cout << pow(10, a) << " " << power(10, a - 1) << endl;
        for (int i = power(10, a-1); i < power(10, a); ++i) {

            int left = max(power(10, b - 1), power(10, c - 1) - i);
            int right = min(power(10, b) - 1, power(10, c) - 1 - i);
            if(left > right)
                continue;

            int have = right - left + 1;
            if(k <= have){
                cout << i << " + "
            }
        }


        if(max(a, b) != c && max(a, b) + 1 != c){
            cout << -1 << endl;
            continue;
        }

        ll mx_val = pow(10, a);

    	ll sum = 0, i, pref = max(pow(10, a), pow(10, c) - (pow(10, b + 1) - 1)), suff = pow(10, c) - pref ;

        ll st = pow(10, c) - suff - 1;


    	for(i = 0; sum <= k && pref + i <= mx_val; i++){
    		sum += st++;
    	}
    	//cout << sum << endl;





    }
    runtime();
    return 0 ;

    

}
