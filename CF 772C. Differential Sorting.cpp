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

        vector<int>a(n,0) ;


        for(int i= 0; i<n ; i++){
        	cin>>a[i] ;
        }

        if(a[n-2]>a[n-1]){
        	cout<<-1<<endl;
        	continue ;
        }

        if(a[n-1]<0){
        	
        	if(is_sorted(a.begin() , a.end()))
        		cout<<0<<endl;
        	else
        		cout<<-1<<endl;

        	continue ;
        }

        cout<<n-2<<endl;


        for(int i=1 ; i<=n-2 ; i++){

        	cout<<i<<" "<<n-1<<" "<<n<<endl;

        }


    }
    return 0 ;
}
