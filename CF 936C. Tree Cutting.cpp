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
const int N = 1e5 + 7;
vector<int>graph[N];
int res;
int dfs(int v, int p, int x){

	int ans = 1;
	for(int u : graph[v]){
		if(u != p){
			ans += dfs(u, v, x);
		}
	}
	if(ans >= x){
		res++;
		return 0;
	}
	return ans;
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
        int n, k, u , v;
        cin >> n >> k;

        for(int i = 0; i <= n; i++){
        	graph[i].clear();
        }

        for(int i = 0; i < n - 1; i++){
        	cin >> u >> v;
  
        	graph[u].push_back(v);
        	graph[v].push_back(u);
        }


        int hi = n, lo = 1, ans = 0;
        while(hi >= lo){
        	int mid = (hi + lo ) / 2;
        	res = 0 ;
        	int d = dfs(1, -1, mid);

        	if(res > k){
        		ans = mid;
        		lo = mid + 1;
        	}else{
        		hi = mid - 1;
        	}

        }

        cout << ans << endl;
    }
    return 0 ;
}
