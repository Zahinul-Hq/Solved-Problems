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
    	ll a, b;

    	cin >> a >> b;


    	ll ta = a, tb = b;

    	ll cnt1 = 0, cnt2 = 0;
    	bool f = 0;


    	for(int i = 0; ; i++){

    		if(f){

    			if(ta >= (1 << i)){
    				ta -= (1 << i);
    				cnt1++;
    			}else{
    				break;
    			}
    		}else{
    			if(tb >= (1 << i)){
    				tb -= (1 << i);
    				cnt1++;
    			}else{
    				break;
    			}

    		}

    		f ^= 1;





    	}

    	ta = a, tb = b;
    	f = 1;


    	for(int i = 0; ; i++){

    		if(f){

    			if(ta >= (1 << i)){
    				ta -= (1 << i);
    				cnt2++;
    			}else{
    				break;
    			}
    		}else{
    			if(tb >= (1 << i)){
    				tb -= (1 << i);
    				cnt2++;
    			}else{
    				break;
    			}

    		}

    		f ^= 1;
    	}

    	cout << max(cnt1, cnt2) <<endl;
    }
    return 0 ;

    runtime();

}
