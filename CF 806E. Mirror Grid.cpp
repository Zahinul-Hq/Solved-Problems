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
        int n , sum=0  ;

        cin>>n ;

        int in[n+1][n+1];

        for(int i=0; i<n ; i++){
        	for(int j=0; j<n ; j++){

        		char c ;

        		cin>>c ;

        		in[i][j]= c-'0';
        	}
        }


        for(int i=0; i<(n+1)/2 ; i++){
        	for(int j=0 ; j<(n/2) ; j++){

        		int i1=i,j1=j, jj =j ,sum2=0  ;

        		sum2+=in[i1][j1] ;

        		j1= n-i1-1 , i1=jj , jj = j1 ;

        		sum2+=in[i1][j1];

        		j1= n-i1-1 , i1=jj , jj = j1 ;

        		sum2+=in[i1][j1];

        		j1= n-i1-1 , i1=jj , jj = j1 ;

        		sum2+=in[i1][j1];

        		sum+=min(sum2 , 4-sum2);
        		
        	}
        }

        cout<<sum<<endl;
    }
    return 0 ;
}
