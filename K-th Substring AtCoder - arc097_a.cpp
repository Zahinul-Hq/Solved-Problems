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

    string s;
    int k;
    cin >> s >> k;
    set<string>ans;


    	for(int len = 1; len <= k; len++){
    		for(int i = 0; i < s.size() - len + 1; i++){
    			string temp = "";
    			for(int j = i; j <= i + len - 1; j++){
    				temp += s[j];
    			}
    			ans.insert(temp);
    			//cout << temp << endl;
    			
    		}
    	}
    	k--;

    	while(k--){
    		ans.erase(ans.begin());
    	}
    	cout << *ans.begin() << endl;
    
    return 0 ;
}
