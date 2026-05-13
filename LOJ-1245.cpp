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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll n, ans  = 1;

    	cin >> n;

    	ll prev_d = n;


    	cout << "Case " << cs++ << ": " ;

    	if(n < 16){
    		ans = 0;
    		for(int i = 1; i <= n; i++){
    			ans += (n / i);

    			debug(n, i, n / i);
    		}
    		cout << ans << endl;
    		//continue;
    	}
    	ans = 1;

    	ll i = 2;
    	for( i = 2; i * i <= (n ); i++){

    		int d = n / i;

    		ans += d;

    		if(d != i) ans += i;

    		ans += (((prev_d - d) - 1) * (i - 1));

    		debug(d, prev_d, i, (((prev_d - d) - 1) * (i - 1)) );

    		prev_d = d;

    	}

    	debug(i);


    	for( ; i < prev_d; i++){
    		ans += (n / i);
    	}

    	cout << ans + n << endl;



    }
    return 0 ;

    runtime();

}
