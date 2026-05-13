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
    	int n,x ;
        cin>>n;

        vector<int>cnt(n+1 ,0) , mx(n+1,0); 
        for(int i=1 ; i<=n ;i++){
        	cin>>x ;

        	if(x<=n)
        		cnt[x]++ ;
        }

        for(int i=1 ; i<=n ; i++){
        	for(int j=i ; j<=n ; j+=i)
        		mx[j]+=cnt[i] ;
        }

        int mm = *max_element(mx.begin() ,mx.end()) ;


        cout<<mm<<endl;

    }

        
    return 0 ;
}
