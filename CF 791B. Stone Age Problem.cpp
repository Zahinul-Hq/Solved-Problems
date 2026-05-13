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

   	int n , q ;
   	ll sum= 0 ;

   	cin>>n>>q;

   	vector<int>arr(n+1,0);
   	map<int,int>mp ;

   	for(int i=1 ; i<=n ; i++){
   		cin>>arr[i] ;

   		sum+=arr[i] ;

   	}



   	int t ,i ,x ,flag=-1;

   	while(q--){

   		cin>>t ;

   		if(t==1){

   			cin>>i>>x ;

   			if(flag==-1 && mp[i]==0)
   				sum=sum-arr[i]+x ;
   			else if(mp[i]!=0){
   				sum=sum-mp[i]+x;
   			}else{
   				sum= sum-flag+x;
   			}

   			mp[i]=x;

   		}else{

   			cin>>x ;

   			sum= (1LL*n*x) ;

   			flag=x;

   			mp.clear() ;

   		}

   		cout<<sum<<endl;

   	}





    return 0 ;
}
