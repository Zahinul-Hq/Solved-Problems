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
const int N = 2e5+7 ;
vector<int>graph[N] ;
vector<bool> visited(N,0);

void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u])
            dfs(u);
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

        cin>>n>>s ;

        n=n*2 ;

        stack<pair<char,int>>st ;

        st.push({'(' , 0}) ;

        for(int i=1 ; i<n ; i++){

        	if(s[i]=='(')
        		st.push({'(' , i}) ;
        	else{


        		pair<int,int> p = st.top();

        		int x = p.S ;
        		st.pop() ;

        		graph[x].pb(i) ;
        		graph[i].pb(x) ;
        	}
        }

        for(int i=0 ; i<n-1 ; i++){

        	if((s[i]==')') && (s[i+1]=='(')){

        		graph[i].pb(i+1) ;
        		graph[i+1].pb(i) ;
        	}

        }

        int ans = 0 ;

        for(int i=0 ; i<n ; i++){

        	if(!visited[i]){
        		ans++ ;
        		dfs(i);
        	}

        }


        cout<<ans<<endl;

        for(int i=0 ; i<n ; i++){

        	visited[i]=0 ;

        	graph[i].clear() ;

        }



    }
    return 0 ;
}
