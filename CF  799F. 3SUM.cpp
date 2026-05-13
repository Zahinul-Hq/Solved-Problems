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
        int n , x;

        cin>>n ;

        vector<int>a ;

        map<int,int>mp ;

        for(int i=0 ; i<n ; i++){

        	cin>>x ;

        	mp[x%10]++ ;

        	if(mp[x%10]<4)
        		a.pb(x%10) ;
        }

        bool flag=0 ;


        for(int i=0 ; i<a.size() ; i++){
        	for(int j=0 ; j<a.size() ; j++ ){
        		for(int l=0 ; l<a.size() ;l++){

        			int res = a[i]+a[j]+a[l] ;

        			if(((res==3)||(res==13)||(res==23))&& i!=j && i!=l && j!=l)
        				flag=1;
        		}
        	}
        }

        if(flag)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0 ;
}
