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

        vector<int>a(n,0) ,b ,c ;

        for(int i=0 ; i<n ;  i++){
        	cin>>a[i] ;
        }


        for(int i = (n&1) ; i<n ; i+=2){

        	if(a[i+1]<a[i])
        		swap(a[i+1] , a[i]) ;


        }

        if (is_sorted(a.begin() , a.end())){
        	cout<<"Yes"<<endl;
        }else
        	cout<<"No"<<endl;
    }
    return 0 ;
}
