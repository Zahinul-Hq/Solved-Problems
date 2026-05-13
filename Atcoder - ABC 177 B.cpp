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

 
        string s, t;

        cin >> s >> t;

        int ans = INT_MAX;

        for(int i = 0; i <= s.size() - t.size(); i++){
        	string temp = s.substr(i, t.size());
        	int mismatch = 0;

        	for(int i = 0; i < temp.size(); i++){
        		if(temp[i] != t[i])
        			mismatch++;
        	}
        	ans = min(ans, mismatch);
        }

        cout << ans << endl;


    return 0 ;
}
