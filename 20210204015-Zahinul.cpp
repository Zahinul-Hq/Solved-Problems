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
vector<bool> visited;
vector<int>graph[100007] ;
bool balancedparanthesis(string s ){

	stack<char>st ;

	for(int i=0 ; i<s.size();i++){

		if(s[i]=='('){
			st.push(s[i]) ;
			continue ;
		}
		if(!st.empty())
			st.pop() ;
		else
			return false ;
	}
	return st.empty() ;

}


void dfs(int par) {
    visited[par] = true;
    for (int child : graph[par]) {
        if (!visited[child])
            dfs(child);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    string s ;

    cin>>s ;

    if(balancedparanthesis(s))
    	cout<<"Balanced"<<endl;
    else
    	cout<<"Not Balanced"<<endl;


    int n ,x ,y;

    cin>>n ;

    for(int i=0 ; i<n-1 ; i++){

    	cin>>x>>y ;

    	graph[x].push_back(y);
    	graph[y].push_back(x);
    }

    dfs(1) ;

    int node ;

    cin>>node ;

    int ans= ceil(log2(node)) ;

    cout<<"Height of binary Tree is :"<<ans<<endl ;


    return 0 ;
}
