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
        int n  ,flag=0,prev,cnt ; 

        cin>>n ;

        vector<int>vec(n);

        for(int i= 0; i<n ; i++){
        	cin>>vec[i] ;
        }

        sort(vec.begin() , vec.end()) ;

        int ans=0  ;

        for(int k=0 ; k<=n ; k++){

            if(k==0 || vec[k-1]<k )
                if(k==n || vec[k]>k)
                    ans++ ;
        	
        }

        cout<<ans<<endl;


    }
    return 0 ;
}
