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
        int n ;

        cin>>n ;

        vector<int>a[n];

        int l=1 , r=n*n ;

        bool t=1;

        for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<n ;j++){
        		int x = t ? l++ : r-- ; 

        		a[i].pb(x) ;

        		t=t^1 ;
        	}
        	if(i&1)
        		reverse(a[i].begin() , a[i].end()) ;
        }

         for(int i=0 ; i<n ; i++){
        	for(int j=0 ; j<n ;j++){
        		cout<<a[i][j]<<" ";
        	}

        	cout<<endl;
        }
    }
    return 0 ;
}
