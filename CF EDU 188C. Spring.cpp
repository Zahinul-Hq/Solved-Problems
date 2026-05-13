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
ll gcd(ll x, ll y){

	if(x < y)
		swap(x, y);
	if(y == 0)
		return x;

	return gcd(x % y, y );
}
ll lcm(ll a, ll b){
	return (a / gcd(a, b)) * b;
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
    	ll a, b, c, m;
    	cin >> a >> b >> c >> m;

    	ll lcm_a = (m / lcm(a, b))  + (m / lcm(c, a)) - (m / lcm(lcm(a, b), lcm(a, c)));
    	ll lcm_b = (m / lcm(a, b))  + (m / lcm(c, b)) - (m / lcm(lcm(a, b), lcm(b, c)));
    	ll lcm_c = (m / lcm(a, c))  + (m / lcm(c, b)) - (m / lcm(lcm(a, c), lcm(b, c)));
    	ll lcm_abc = (m / lcm(lcm(a, b), c));

    	debug(lcm_abc, lcm_a, lcm_b, lcm_c, m / a);

    	ll cnt_a = (((m / a) - lcm_a ) * 6) + ((lcm_a - lcm_abc) * 3) + ((lcm_abc) * 2);
    	ll cnt_b = (((m / b) - lcm_b ) * 6) + ((lcm_b - lcm_abc) * 3) + ((lcm_abc) * 2);
    	ll cnt_c = (((m / c) - lcm_c ) * 6) + ((lcm_c - lcm_abc) * 3) + ((lcm_abc) * 2);

    	cout << cnt_a << " " << cnt_b << " " << cnt_c << endl;




    }
    return 0 ;

    runtime();

}
