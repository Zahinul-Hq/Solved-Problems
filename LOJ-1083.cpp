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

    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n;
        cin >> n;
        vector<ll>arr(n + 1, 0), left(n + 1, 0), right(n + 1, n);
        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }
        stack<int>st;
        for(int i = 1; i <= n; i++){
        	if(st.empty()){
        		left[i] = 1;
        		
        	}else{
        		while(!st.empty() && arr[st.top()] >= arr[i]){
        			st.pop();
        		}
        		left[i] = st.empty() ? 1 : st.top() + 1;
        	}
        	st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n; i >= 1; i--){
        	if(st.empty()){
        		right[i] = n;
        	}else{
        		while(!st.empty() && arr[st.top()] >= arr[i]){
        			st.pop();
        		}
        		right[i] = st.empty() ? n : st.top() - 1;
        	}
        	st.push(i);
        }

        ll ans = 0;
        for(int i = 1; i <= n; i++){ 
        	ans = max(ans,  (right[i] - left[i] + 1) * arr[i]);
        }

        cout << "Case " << cs++ << ": " << ans << endl;
    }
    return 0 ;
}
