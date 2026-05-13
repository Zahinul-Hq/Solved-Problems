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
        ll n ;

        cin>>n ;

        vector<ll>a(n+1,0) , df(1,0) ;

        for(int i=1 ;i<n ; i++){

        	cin>>a[i];
        }

        a[n]=(n*(n+1)/2) ;

        map<ll , int>mp ;

        ll flag=0 ,sum=0 , c=0;

        for(int i=1; i<=n ; i++){

        	ll diff = a[i]-a[i-1] ;

        	if(diff<0){
        		flag=1 ;
        		break;
        	}

        	if(diff==0)
        		continue;

        	if(mp[diff]==0 && diff<=n )
        		mp[diff]++ ;
        	else{
        		df[0]=diff ;

        		c++ ;

        		if(c>1){
        			flag=1;
        			break;
        		}

        	}
        }

        c=0 ;

        for(int i=1 ; i<=n ;i++){

        	if(!mp[i]){
        		sum+=i ;
        		c++;
        		if(c>=3)
        			flag=1;
        	}
        }

        if(flag ||( df[0]!=sum&& df.size()==1))
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;

    }
    return 0 ;
}
