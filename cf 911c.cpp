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
const int N = 3e5 +7 ;
vector<int>adj[N] ;
vector<int> p(N);
void bfs(int s){


	queue<int> q;
	vector<bool> used(N);

	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
	    int v = q.front();
	    q.pop();
	    for (int u : adj[v]) {
	        if (!used[u]) {
	            used[u] = true;
	            q.push(u);
	            p[u] = v;
	        }
	    }
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        int n ;

        string s ;

        vector<int>leaf ;

        vector<int>r(N,0) ,l(N,0) ;

        cin>>n>>s ;

        for(int i=1 ; i<=n ;i++){

        	int x , y ;

        	cin>>x>>y ;

        	if(x==0 && y==0){
        		leaf.pb(i);
        		continue ;
        	}
        	if(x!=0)
        		adj[i].pb(x);
        	if(y!=0)
        		adj[i].pb(y);

        	l[x]=1 ;
        	r[y]=1 ;
        }

        bfs(1) ;

        int ans = 0  , mn= INT_MAX ;

        for(int i=0 ; i<leaf.size() ; i++){
        	vector<int> path;
	    	for (int v = leaf[i]; v != -1; v = p[v]){
		        path.push_back(v);
		    }
		    	reverse(path.begin(), path.end());

		    for (int i=0 ; i<path.size()-1 ; i++){

		    	cout<<path[i+1]<<" ";

		    	if(s[i]=='U'){
		    		ans++ ;
		    		continue;
		    	}
		    	int v= path[i+1] ;

		    	if(s[v]=='R'){
		    		if(r[v]!=1)
		    			ans++ ;
		    	}
		    	if(s[v]=='L'){
		    		if(l[v]!=1)
		    			ans++ ;
		    	}
        	}

        	mn = min(ans , mn);

        	ans=0;
		 }

		 for(int i=1 ; i<=n ; i++){
		 	adj[i].clear() ;
		 	p[i]=0 ;
		 }

		 cout<<mn<<endl;
    }
    return 0 ;
}
