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
        int n , x ;

        cin>>n>>x ;

        vector<int>a(n+1,0), b(n+1 ,0) ;



        for(int i=1 ; i<=n ; i++){
        	cin>>a[i];
        	b[i]=a[i] ;
        }

        sort(b.begin() , b.end()) ;

        bool flag=0 ;

        if(is_sorted(a.begin() , a.end()) ||  n>=(2*x)){
        	cout<<"Yes"<<endl;
        	continue ;
        }


        for(int i=n-x+1 ; i<=x ; i++){

        	if(a[i]!=b[i])
        		flag=1 ;
        }

        if(flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;
    }
    return 0 ;
}
