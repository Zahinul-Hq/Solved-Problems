#include<bits/stdc++.h>
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

    int n ;

    cin >> n;



    vector<int>arr(n + 1), ans(n + 1);

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }

    ll mx = 0, mx_indx = 0;


    for(int i = 1; i <= n; i++){
    	ll hi = arr[i], sum = arr[i], lo = arr[i];

    	for(int l = i - 1; l >= 1; l--){

    		if(lo > arr[l]){
    			sum += arr[l];
    			lo = arr[l]; 
    		}else{
    			sum += lo;
    		}
    	}
    	for(int r = i + 1; r <= n; r++){

    		if(hi > arr[r]){
    			sum += arr[r];
    			hi = arr[r]; 
    		}else{
    			sum += hi;
    		}
    	}

    	if(mx <= sum){
    		mx = sum;
    		mx_indx = i;
    	}
    }
    ans[mx_indx] = arr[mx_indx];

    ll loo = arr[mx_indx], hii = arr[mx_indx];

    for(int l = mx_indx - 1; l >= 1; l--){

    	if(loo > arr[l]){
    		ans[l] = arr[l];
    		loo = arr[l]; 
    	}else{
    		ans[l] = loo;
    	}
    }
    for(int r = mx_indx + 1; r <= n; r++){

    	if(hii > arr[r]){
    		ans[r] = arr[r];
    		hii = arr[r]; 
    	}else{
    		ans[r] = hii;
    	}
    }

    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
    }
    cout << endl;

    return 0 ;
}
