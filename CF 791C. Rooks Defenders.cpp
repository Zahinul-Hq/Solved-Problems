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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n , q  ;

    cin>>n>>q ;
    vector<int>rows(n+1,0) , col(n+1,0);
    set<int>emprow , empcol ;

    for(int i=0; i<=n+1 ; i++){
    	emprow.insert(i);
    	empcol.insert(i);
    }

    while(q--){

    	int t ; cin>>t ;

    	if(t==1){
    		int x , y ;
    		cin>>x>>y;

    		rows[x]++;
    		col[y]++;

    		if(rows[x]==1)emprow.erase(x);
    		if(col[y]==1)empcol.erase(y);
    	}
    	else if(t==2){
    		int x , y ;
    		cin>>x>>y;

    		rows[x]--;
    		col[y]--;

    		if(rows[x]==0)emprow.insert(x);
    		if(col[y]==0)empcol.insert(y);
    	}
    	else if(t==3){
    		int x1,x2,y1,y2;

    		cin>>x1>>y1>>x2>>y2;

    		bool ans=0 ;

    		ans|=(*(emprow.lower_bound(x1)))>x2 ;
    		ans|=(*(empcol.lower_bound(y1)))>y2 ;

    		if (ans) cout << "Yes\n";
			else cout << "No\n";
    	}
    }
    return 0 ;
}
