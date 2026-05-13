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
    	vector<int>arr(n + 1, 0);
    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}
    	string s;
    	cin >> s;
    	s = "#" + s;

    	vector<int>vis(n + 1 , -1), ans(n + 1, 0);
    	for(int i = 1; i <= n; i++){

    		if(vis[i] ==1)
    			continue;
    		vector<int>temp;
    		int cnt = 0;
    		int val = arr[i];
    		while(vis[val] == -1){
    			cnt += (s[val] == '0');
    			vis[val] = 1;
    			temp.push_back(val);
    			val = arr[val];
    		}
    		for(auto j: temp){
    			ans[j] = cnt;
    		}
    	}

    	for(int i = 1; i <= n; i++){
    		cout << ans[i] << " ";
    	}
    	cout << endl;

    	
        
    }
    return 0 ;
}
