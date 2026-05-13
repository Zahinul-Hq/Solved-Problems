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

int digsum(int x){

	int sum = 0;

	while(x>0){

		sum+=(x%10) ;

		x=x/10 ;
	}

	return sum ;
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
        int n , val;

        cin>>n ;

        vector<int>a[92] , ar(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>ar[i] ;
        }

        sort(ar.begin() ,ar.end()) ;

        for(int i=0 ; i<n ; i++){

        	int j = digsum(ar[i]) ;

        	a[j].pb(ar[i]) ;
        }



        int mx= -1 ;

        for(int i=1 ; i<=92 ; i++){

        	if(a[i].size()<2){
        		continue ;
        	}

        		int val = a[i][a[i].size()-1]+a[i][a[i].size()-2];

        		cout<<val<<endl;

        		mx=max(mx,val) ;
        	
        }

        cout<<mx<<endl;




    }
    return 0 ;
}
