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
vector<int>graph[N], par(N), col(N);
bool cycle ;
int last_node ;
void dfs(int u){
	col[u] = 1;
	for(auto v : graph[u]){
		if(col[v] == 0){
			par[v] = u;
			dfs(v);
		}else if(col[v] == 1){
			par[v] = u;
			last_node = v;
			cycle = 1;
		}
	}
	col[u] = 2;
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
        int  n, x;
        cin >> n;
        for(int i = 1; i <= n; i++){
        	graph[i].clear();
        	par[i] = -1;
        	col[i] = 0;
        }

        for(int i = 1; i <= n; i++){
        	cin >> x;
        	graph[i].push_back(x);
        }

        int cyc = 0, bamboo = 0;


        for(int i = 1; i <= n; i++){
        	if(col[i] == 0){
        		cycle = 0;
        		dfs(i);

        		//cout << last_node << endl;
        	
	        	if(cycle){
	        		//cyc++;
	        		int cycle_size = 0;
	        		int u = last_node;

	        		while(par[u] != last_node && par[u] != -1){
	        			//cout << u << endl;
	        			u = par[u];
	        			cycle_size++;
	        		}

	        		//cout << cycle_size << endl;
	        		
	        		if(cycle_size == 1)
	        			bamboo++;
	        		else
	        			cyc++;
	        	}
	        }
        }

        cout << cyc + min(bamboo, 1) << " " << cyc + bamboo << endl;
    }
    return 0 ;
}
