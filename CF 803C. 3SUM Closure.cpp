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
        int n , zero=0 , pos=0 ,neg=0,x; 

        cin>>n ;

        map<int,int>mp ;
        vector<int>a ;
        for(int i= 0 ; i<n ; i++){

        	cin>>x ;

        	mp[x]=1;

        	if(x<0){
        		neg++ ;
        		a.pb(x) ;
        	}
        	if(x>0){
        		pos++ ;
        		a.pb(x) ;
        	}
        	if(x==0)
        		zero++;

        	
        }


        if(neg>2 || pos>2){
        	cout<<"No"<<endl;
        	continue ;
        }

        zero=min(zero , 5);

        while(zero--)
        	a.pb(0) ;

        int flag=0 ;

        for(int i=0 ; i<a.size() ;i++){
        	for(int j=0; j<a.size() ;j++){
        		for(int k=0 ; k<a.size() ;k++){

        			int x = a[i]+a[j]+a[k] ;

        			if(i!=j && j!=k && i!=k && mp[x]==0)
        				flag=1 ;

        		}
        	}
        }

        if(flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;


    }
    return 0 ;
}
