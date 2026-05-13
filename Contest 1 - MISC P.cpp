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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll fib[51] ; 
	fib[0] = fib[1] = 1;

	for(int i = 2; i <= 50; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}

    while (1)
    {
    	int n ;
    	cin >> n;

    	if(n == 0)
    		break;

    	cout << fib[n] <<endl;


    }
    return 0 ;

    //runtime();

}
