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
const int N = 2e5 + 7;
vector<int>graph[N];
vector<int>par(N, -1);
ll dis = 0;
void dfs(int v, int p = - 1){
    par[v] = p;
    for(auto u : graph[v]){
        if(u != p){
            dfs(u, v);
            
        }
        dis++;
    }
}
vector<int>path(int v){
    vector<int> ans;

    while(v != -1){
        ans.push_back(v);
        v = par[v];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, x, y;

        cin >> n >> x >> y;
        
        for(int i = 0 ; i < n; i++){
            graph[i].clear();
        }

        for(int i =  0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        par.assign(n,-1);


        dfs(1);


        vector<int>pathx = path(x);
        vector<int>pathy = path(y);

        int root = 1, l = 0;

        for(int i = 0; i < pathx.size() ; i++){
            if(pathx[i] != pathy[i]){
                root = pathx[i - 1];
                l = i;
                break;
            }
        }
        dis = 0;
        dfs(root);

        dis += (pathy.size() - l);

        cout << dis << endl;



    }
    return 0 ;
}
