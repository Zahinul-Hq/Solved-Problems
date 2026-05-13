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

    while(1){


    	int n;
	    cin >> n;

	    if(!n)
	    	break;

	    vector<ll>arr(n + 2, 0);
	    vector<int>left_small(n + 1, 0), right_small(n + 1, 0);

	    stack<pair<int,ll>>st; 
	    st.push({0, -1});

	    for(int i = 1; i <= n; i++){
	    	cin >> arr[i];
	    }

	    for(int i = 1; i <= n ; i++){
	    	while(arr[i] <= st.top().S)
	    		st.pop();

	    	left_small[i] = st.top().F;
	    	st.push({i, arr[i]});
	    }
	    while(!st.empty())
	    	st.pop();
	    st.push({n + 1, -1});

	    for(int i = n; i >= 1; i--){
	    	while(arr[i] <= st.top().S)
	    		st.pop();

	    	right_small[i] = st.top().F;
	    	st.push({i, arr[i]});
	    }

	    ll ans = 0;

	    for(int i = 1; i <= n; i++){
	    	ans = max(ans, (right_small[i] - left_small[i] - 1) * arr[i]);
	    }

	    cout << ans << endl;
    }

    return 0 ;
}
