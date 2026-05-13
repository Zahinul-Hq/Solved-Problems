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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll hc, dc, hm, dm, k, w, a;
    	cin >> hc >> dc >> hm >> dm >> k >> w >> a;

    	ll mn = ((hc + dm - 1) / dm );

    	ll cwn = ((hm + (k* w) + dc - 1)/ (dc + (k* w)));

    	ll man = ((hc + (k * a) + dm - 1) / dm);

    	ll cn = ((hm  + dc - 1) / dc);

    	debug(mn, cwn, man, cn);

    	if(mn >= cwn || man >= cn){
    		cout << "Yes" << endl;
    	}else{
    		bool ok = 0;
    		for(ll i = 0; i <= k; i++){
    			cwn = ((hm + (i* w) + dc - 1)/ (dc + (i* w)));
    			man = ((hc + ((k - i) * a) + dm - 1) / dm);
    			mn = ((hc + dm - 1) / dm );
    			cn = ((hm  + dc - 1) / dc);

    			if(cwn <= man){
    				ok = 1;
    				break;
    			}

    		}

    		if(ok){
    			cout << "Yes" << endl;
    		}else{
    			cout << "No" << endl;
    		}
    	}






    }
    return 0 ;

    runtime();

}
