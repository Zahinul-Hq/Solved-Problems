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
const int N = 1e5 + 7;
vector<int>graph[N];
vector<int>used(N, 0);
ll lyk , vam ;
void bfs(int s){

	queue<int>q;
	q.push(s);
	used[s] = 1;
	vam++;

	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : graph[v]) {
	        if (!used[u]) {
	            if(used[v] == 1){
	            	used[u] = 2;
	            	lyk++;
	            }
	            else if(used[v] == 2){
	            	used[u] = 1;
	            	vam++;
	            }
	            q.push(u);
	        }
	    }
	}
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
        int n, u, v, q = 0;
        cin >> n;
        for(int i = 0 ; i < n; i++){
        	cin >> u >> v;
        	graph[u].push_back(v);
        	graph[v].push_back(u);
        	q = max({q, u, v});
        }
        ll total = 0;

        for(int i = 1; i <= q; i++){
        	if(!used[i] && !graph[i].empty()){
        		lyk = 0, vam = 0;
        		bfs(i);
        		total += max(lyk , vam);
        	}
        }
        
        cout << "Case " << cs++ << ": "; 
        cout << total  << endl;

        for(int i = 0; i <= q; i++){
        	graph[i].clear();
        	used[i] = 0;
        }
        lyk = 0, vam = 0;

    }
    return 0 ;
}
