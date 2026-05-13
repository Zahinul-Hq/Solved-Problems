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
bool Is_Sorted(int l, int r, vector<int>&pref_sum){
	int one_count = pref_sum[r] - pref_sum[l - 1];

	if(one_count == (r - l + 1))
		return true;
	if(one_count == 0)
		return true;
	if(one_count == pref_sum[r] - pref_sum[r - one_count])
		return true;

	return false;
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
        int n, q,l, r;
        string s;
        cin >> n >> q >> s;

        s = "#" + s;

        vector<int> pref(n + 2, 0), prev1(n + 2, 0), next0(n + 2, 0);

       	set<pair<int, int>>res;

        for(int i = 1; i <= n; i++){
        	pref[i] = pref[i - 1] + (s[i] == '1');
        }
        int z = -1, o = -1;
        for(int i = 1; i <= n; i++){
        	prev1[i] = o;
        	if(s[i] == '1')
        		o = i;
        }
        for(int i = n; i > 0; i--){
        	next0[i] = z;
        	if(s[i] == '0')
        		z = i;
        }

        while(q--){
        	cin >> l >> r;
        	int x , y;
        	if(Is_Sorted(l, r, pref)){
        		res.insert({-1, -1});
        		continue;
        	}
        		
        	
        		if(prev1[l] == -1)
        			x = 1;
        		else
        			x = prev1[l] + 1;

        		if(next0[r] == -1)
        			y = n;
        		else
        			y = next0[r] - 1;

        		res.insert({x, y});
        	
        }

        cout << res.size() << endl;

    }
    return 0 ;
}
