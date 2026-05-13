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
        ll sum = 0, madsum = 0;
        cin >> n;
        vector<int>arr(n), mad(n);

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	sum += arr[i];
        }

        map<int,int> cnt;
        int t = 2, val = 0;
        while(t--){
        	cnt.clear(), val = 0, madsum = 0;
        	for(int i = 0; i < n; i++){
	        	if(++cnt[arr[i]] >= 2){
	        		val = max(val, arr[i]);
	        	}
	        	mad[i] = val;
	        	madsum += mad[i];
	        }
	        sum = sum + madsum;
	        
	        arr = mad;
        }
        

        for(int i = n - 1; i >= 0; i--){
        	madsum -= mad[i];
        	sum += madsum;
        }
        cout << sum << endl;

    }
    return 0 ;
}
