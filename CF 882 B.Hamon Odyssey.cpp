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

        vector<int>v(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>v[i] ;
        }

        int sum=v[0] , cnt=1;

        for(int i=0 ; i<n ; i++){

        	sum&=v[i] ;

        	if(sum==0){
        		if(i==n-1)
        			break ;
        		sum=v[i+1] ;
        		cnt++ ;

        	}

        }

        if(sum!=0)
        	cnt-- ;

        cout<<max(cnt ,1)<<endl;
    }
    return 0 ;
}
