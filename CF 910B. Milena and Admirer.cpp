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
int mn=-1 ;
ll cnt =0  ; 

void div(int x ){


	if(x<=mn)
		return ;

	int c= 0 ;
	int xmn ;

	while(x>mn){

		xmn  = x/2 ;
		x = ((x+1)/2) ;
		c++ ;

		cnt+=(1<<(c-1)) ;

		if(xmn==0)
			cnt--;
	}


	mn = max(1 , xmn) ;
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

        vector<int>a(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }

        mn= a[n-1] ;

        for(int i=n-2 ; i>=0 ; i--){
        	div(a[i]) ;
        }

        cout<<cnt<<endl ;

        cnt=0 ;
        mn=-1 ;
    }
    return 0 ;
}
