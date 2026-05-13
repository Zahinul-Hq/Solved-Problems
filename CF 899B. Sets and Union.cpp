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

    int t ;
    cin>>t ;
    
    while (t--)
    {
        int n ,x ,z;

        cin>>n ;

        vector<int>a[n] ;

        for(int i=0 ; i<n ; i++){
        	cin>>x;

        	while(x--){
        		cin>>z ;
        		a[i].pb(z) ;
        	}

        }

        set<int>st  , temp ;

        for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<a[i].size();  j++){
	        	temp.insert(a[i][j]);
	        }
	    }

        

        int mx = 0;

        for(int k=1 ; k<=50 ; k++){
        	for(int i=0 ; i<n ; i++){

        		bool ok =1 ;
	        	for(int j=0 ; j<a[i].size();  j++){
	        		if(a[i][j]==k)
	        			ok=0 ;
	        	}
	        	if(ok)
	        		for(int  j : a[i])
	        			st.insert(j);
	        }

        	int sz = st.size();

        	if(temp.size()!=st.size())
        		mx=max(mx , sz);
        	
        	st.clear() ;
        }

        cout<<mx<<endl;

        

        /*set<int>st ;

        for(int i=0 ; i<n ; i++){
        	cin>>x ;
        	st.insert(x);
        }

        cin>>n ;

        st.erase(n);

        for(auto i : st){
        	cout<<i<<endl;
        }
        */
    }
    return 0 ;
}
