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

        ll sum=0 , ans = 0 , d=0 ;
        cin >> n;

        vector<ll>a(n, 0);

        for(int i = 0; i < n; i++){
        	cin >> a[i];

        	sum+=a[i] ;
        }

        bool flag=0 ;



        d = sum/n ;

        for(int i=0 ; i<n ; i++){

        	if(a[i]>=d){
        		ans+=(a[i]-d) ;
        	}else{
        		ans= ans - (d-a[i]) ;

        		if(ans<0){

        			flag=1 ;
        			break ;

        		}
        	}

        }

        if(flag){
        	cout<<"No"<<endl;
        }else{
        	cout<<"Yes"<<endl;
        }




    }
    return 0 ;
}
