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


    	int n;
    	cin >> n;
    	vector<int>arr(n, 0);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	sort(arr.begin(), arr.end());
    	int mid = n / 2;
    	if(n % 2 != 0){
    		
    		cout << arr[mid] << endl;
    	}else{
    		int sum[2] = {arr[mid - 1], arr[mid]};
    		ll tot[2] ={0, 0};
    		for(int i = 0; i < 2; i++){
    			for(int j = 0; j < n; j++){
    				tot[i] += abs( sum[i] - arr[j]);
    			}
    		}
    		if(tot[0] <= tot[1]){
    			cout << sum[0] << endl;
    		}else{
    			cout << sum[1] << endl;
    		}
    	}
        
    
    return 0 ;
}
