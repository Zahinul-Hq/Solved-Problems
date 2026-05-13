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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n;
        cin >> n;

        ll p = log2(n);

        ll val = 1 << p ;

        vector<int>arr(n + 1, 0);

        if(val + 1 <= n){


        	if(n % 2 == 0){
        		arr[n] = val - 1;
	        	arr[n - 1] = val + 1;
	        	arr[n - 2] = val;

	        	for(int i  = 1; i <= val - 2; i++){
	        		arr[i] = i;
	        	}
	        	int j = val - 2 + 1;

	        	val++;

	        	for(;j <= n - 3; j++){
	        		arr[j] = ++val;
	        	}
        	}else{
        		arr[n] = n;
	        	arr[n - 1] = n - 1;
	        	arr[n - 2] = 3;
	        	arr[n - 3] = 1;
	        	arr[1] = 2;
	        	int j = 2;
        		for(int i = 4 ; i <= n - 2; i++){
        			arr[j++] = i;        		
        		}
        	}


        	
        }else if(val + 1 > n){
        	arr[n] = val;
        	arr[n - 1] = val - 1;
        	arr[n - 2] = val - 2;
        	arr[n - 3] = 3;
        	arr[n - 4] = 1;
        	arr[1] = 2;
        	int j = 2;
        	for(int i  = 4; i < val - 2; i++){
        		arr[j++] = i;
        	}
        	
        }
        ll k = 0;
        for(int i = 1; i <= n; i++){
        	if(i % 2 == 0){
        		k |= arr[i];
        	}else{
        		k &= arr[i];
        	}
        }

        cout << k << endl;

        for(int i = 1; i <= n; i++){
        	cout << arr[i] << " ";
        }
        cout << endl;

        
    }
    return 0 ;
}
