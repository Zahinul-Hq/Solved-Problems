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
        int n , k;

        cin>>n>>k ;

        vector<int>vec(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>vec[i] ;
        }

        int i=0 , j=n-1 ;

        int cntf=0 , cntl=0 ;

        for( i= 0 ; i<n ; i++){

        	if(vec[0]==vec[i])
        		cntf++ ;

        	if(cntf==k)
        		break ;

        }

        for( j= n-1 ; j>=0 ; j--){

        	if(vec[n-1]==vec[j])
        		cntl++ ;

        	if(cntl==k)
        		break ;

        }


        if((vec[0]==vec[n-1]) && cntf==k)
        	cout<<"Yes"<<endl;
        else if(cntf==k && cntl==k  && i<=j)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0 ;
}
