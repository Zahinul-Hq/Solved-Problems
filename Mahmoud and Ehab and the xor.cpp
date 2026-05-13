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

	int n, x;
	cin >> n >> x;
    if(n == 1){
    	cout << "YES" << endl << x << endl;
    	return 0;
    }

    if(n == 2 ){
        if(x == 0)
    	   cout << "NO" << endl;
        else
            cout << "YES" << endl << 0 << " " << x << endl;
    	return 0;
    }

    int hi = (1 << 19);

    if(n == 3 && x == 0){
    	cout << "YES" << endl << 1 << " " << hi + 1 << " " << hi << endl;
    	return 0;

    }
    if(n == 3){
    	cout << "YES" << endl << 0 << " " << (hi | x) << " " << hi << endl;
    	return 0;
    }

    int r = 0;

    cout << "YES" << endl;
    int cnt = 0, xr = 0;
    for(int i = 1; cnt < n - 3; i++){
    	if(i != x){
            if(cnt == n - 4 && (r ^ i) == 0 )
                continue;

    		r ^= i;
	    	cout << i << ' ' ;
	    	cnt++;
    	}
	    	
    }





    cout << hi << " " << (hi | r) << " " << x << endl;


    return 0 ;

    runtime();

}
