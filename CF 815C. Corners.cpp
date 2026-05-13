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
        int n ,m , tot=0 ,cnt =0 ;

        string s ;

        cin>>n>>m ;

        int a[n+1][m+1] ;

        for(int i=0 ; i<n; i++){
        	cin>>s;
        	for(int j=0 ; j<m ; j++){
        		a[i][j]=s[j]-'0';

        		tot+=a[i][j] ;
        	}
        }

        if(tot==0){
        	cout<<0<<endl;
        	continue;
        }

        int mn = INT_MAX ;


        for(int i=0 ; i<n-1; i++){
        	for(int j=0 ; j<m-1 ; j++){
        		

        		cnt = a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1] ;

        		//cout<<a[i][j]<<" "<<a[i][j+1]<<" "<<a[i+1][j+1]<<" "<<a[i+1][j]<<endl;
        		//cout<<cnt<<endl;


        		if(cnt==0)
        			continue;


        		mn= min(mn , max(1,cnt-1));




        		cnt=0 ;



        	}
        }

        cout<<1+tot-mn<<endl;
    }
    return 0 ;
}
