#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
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

   	/*int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, m ;

        cin >> n >> m;

        if(m == 0){
        	cout << n << endl;
        	continue;
        }


        ll pos = n + m, last = 0;

        ll val = 1;


        for(ll i = 1 ; i < 32; i++){

        	if(val > pos){
        		last = i;
        		break;
        	}

        	val = val * 2;
        } 
        val = 1;

        for(ll i = 1 ; i < last; i++){
        	val = val * 2;
        } 


       cout << ((n - 1) | n | (n + 1)) << endl; 
    }*/


    int m ;

    cin >> m;


    vector<int> arr(1155, 0);

    for(int i = 1; i <= 1155; i++){
    	arr[i] = i;
    }

    for(int j = 0; j <= m; j++){
    	cout <<"new" <<j << "   ";
    	for(int i = 1; i <= 1150; i++){
    		
    			arr[i] = (arr[i - 1] | arr[i] | arr[i + 1]);
    			cout << arr[i] << " ";
    		
    		
    	}

    	


    	cout << endl;

    }
    
    return 0 ;
}
