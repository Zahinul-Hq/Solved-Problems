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
        int n;
        cin >> n;
        bool ok = 1;
        vector<int>a(n), b(n);
        vector<pair<int,int>>neq;
        for(int i = 0; i < n; i++){
        	cin >> a[i];
        }
        for(int i = 0; i < n; i++){
        	cin >> b[i];
        	if(a[i] > b[i])
        		ok = 0;
        	if(a[i] != b[i])
        		neq.push_back({a[i], i});
        }
        if(!ok){
        	cout << "NO" << endl;
        	continue;
        }

        while(neq.size()){
        	
        	int indx = neq.back().second;
        	ok = 0;

        	for(int i = indx; i < n; i++){
        		if(a[i] == b[indx]){
        			ok = 1;
        			break;
        		} 
        	}
        	for(int i = indx; i < n; i++){
        		if(a[i] == b[indx]){
        			break;
        		}
        		ok &= a[i] < b[indx];
        		ok &= b[indx] <= b[i];
        	}

        	if(!ok ){
        		for(int i = indx; i >= 0; i--){
	        		if(a[i] == b[indx]){
	        			//cout << i << endl;
	        			ok = 1;
	        			break;
	        		} 
	        	}
	        	for(int i = indx; i >= 0; i--){
	        		if(a[i] == b[indx]){
	        			break;
	        		}

	        		ok &= a[i] < b[indx];
	        		ok &= b[indx] <= b[i]; 
	        	}
        	}
        	if(!ok)
        		break;
        	neq.pop_back();

        }
        if(ok){
        	cout << "YES" << endl;
        }else{
        	cout << "NO" << endl;
        }



    }
    return 0 ;
}
