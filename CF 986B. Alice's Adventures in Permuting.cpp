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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll n, i, b, c;
    	cin >> n >> b >> c;


    	if(b == 0 && c == 0){

    		if(n == 1 ){
    			cout << 0 << endl;
    		}else if(n == 2){
    			cout << 1 << endl;

    		}else{
                cout << -1 << endl;
            }
    		
    		continue;
    	}

    	if(b == 0){
    		if(c < n - 2){
    			cout << -1 << endl;
    		}else if(c >= n){
    			cout << n << endl;
    		}else{
                cout << n - 1 << endl;
            }
    		continue;
    	}
    	if(n - c <= 0){
    		cout << n << endl;
    		continue;

    	}


    	i = ((n - c) / b)  + ((n - c) % b  > 0);
    	//i++;
    	//debug(i);
    	

    	cout << n - i << endl;



    }
    return 0 ;
}
