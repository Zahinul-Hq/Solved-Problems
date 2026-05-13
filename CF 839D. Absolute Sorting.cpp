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
        int n ,x;

        cin>>n ;
        vector<int>a ;

        for(int i = 0  ;i<n  ; i++){
        	cin>>x;
        	a.pb(x);
        }

        int mx= INT_MAX , mn=0 ;

        for(int i= 0 ; i<n-1 ; i++){

        	int p = a[i] , q= a[i+1] ;

        	if(p<q){
        		mx = min(mx , (p+q)/2);
        	}else if(p>q){
        		mn = max(mn , (p+q+1)/2) ;
        	}

        }

        if(mn<=mx){
        	cout<<mn<<endl;
        }else{
        	cout<<-1<<endl;
        }



    }
    return 0 ;
}
