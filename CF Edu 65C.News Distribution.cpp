#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N= 5e5+7 ;
vector<int>adj[N] ;
vector<bool> used(N);
vector<int> d(N), str;
int cnt=1;
void dfs(int src){

	used[src]=true ;

	str.pb(src) ;

	for(auto ch : adj[src]){

		if(!used[ch]){
			cnt++ ;

			dfs(ch) ;
		}
	}

	d[src]=cnt ;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n,m ,x, p;
    
 
    cin>>n>>m;
 
    for(int i = 0; i < m; i++)
	{
		int k;
		cin>>k;

		if(k){

			cin>>x;

			for(int j = 1; j < k; j++)
			{

				cin>>p ;

				adj[x].push_back(p);
				adj[p].push_back(x);

			}
		}
	}

        for(int i=1 ; i<=n ; i++){

        	if(!used[i]){
        		
        		dfs(i) ;
        		
        		for(int c : str){
        			d[c]=cnt ;
        		}
        		cnt=1;
        		str.clear();
        	}
        }
        for(int i=1 ; i<=n ; i++){

        	cout<<d[i]<<" ";
        }
        cout<<endl;

    
    return 0 ;
}
