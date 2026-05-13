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
        int n, x ;

        cin>>n>>x; 

        vector<int>vec(n , 0 ) ;

        int s= 0 ;

        for(int i=0 ; i<3 ; i++){

        	for(int j=0 ;j<n ; j++)
        		cin>>vec[j];
        	for(int j=0 ; j<n ; j++){
        		if((x|vec[j])!=x)
        			break ;
        		s|=vec[j] ;

        	}
        }

        if(s==x)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0 ;
}
