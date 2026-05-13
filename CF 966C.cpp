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
    	vector<int>arr(n, 0);
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	int m;
    	cin >> m;
    	while(m--){
    		string s;
    		cin >> s;
    		if(s.size() != n){
    			cout << "NO" << endl;
    			continue;
    		}

    		map<char,int>mp;
    		map<int, char>chk;
    		bool ok = 1;

    		for(int i = 0; i < n; i++){
    			if(mp.count(s[i]) == 0 && chk.count(arr[i]) == 0){
    				mp[s[i]] = arr[i];
    				chk[arr[i]] = s[i];
    			}else{
    				if((mp[s[i]] != arr[i]) || (chk[arr[i]] != s[i])){
    					ok = 0;
    					break;
    				}
    			}
    		}
    		if(ok){
    				cout << "YES" << endl;
    			}else{
    				cout << "NO" << endl;
    			}
    	}
        
    }
    return 0 ;
}
