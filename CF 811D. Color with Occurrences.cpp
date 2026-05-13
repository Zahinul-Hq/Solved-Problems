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
string text, s;
vector<string>strs;
bool check(int i, int j){

	int sz = strs[j].size() - 1;

	while(sz >= 0){
		if(text[i] != strs[j][sz])
			return false;
		i--;
		sz--;
	}

	return true;
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
        strs.clear();
        cin >> text;
        int n; cin >> n;

        text = "#" + text;
        int l = text.size() - 1;

        strs.push_back("#");

        for(int i = 0; i < n; i++){
        	cin >> s;
        	strs.push_back(s);
        }
        vector<ll>dp(l + 2, INT_MAX),from(l + 2, -1), use(l +2, -1);

        dp[0] = use[0] = from[0] = 0;
        for(int i = 1; i <= l; i++){
        	int id = -1;
        	for(int j = 1; j <= n; j++){
        		
        		if(strs[j].size() > i)
        			continue;

        		if(check(i, j) && dp[i - strs[j].size()] + 1 < dp[i]){
        			dp[i] = dp[i - strs[j].size()] + 1;
        			id = j;
        			use[i] = id  ;

        			from[i] = i;
        		}
        	}
        	if(id == -1)
        		continue;

        	for(int k = i; k > (i - strs[id].size()); k--){
        		if(dp[i] < dp[k]){
        			dp[k] = dp[i];
        			use[k] = id;
        			from[k] = i;
        		}
        	}

        }

        if(dp[l] == INT_MAX){
        	cout << -1 << endl;
        	continue;
        }
        cout << dp[l] << endl;
        
        int sid = use[l];
        int p = l - strs[sid].size() + 1;

        while(sid != 0){
        	cout << sid << " " << p << endl;
        	int id = from[p - 1];
        	sid = use[id];
        	p = id - strs[sid].size() + 1;
        }
    }
    return 0 ;
}
