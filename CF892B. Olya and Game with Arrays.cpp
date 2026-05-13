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
        ll n,m , mn=INT_MAX ,x ,sum=0,mn2=INT_MAX;






        cin>>n;

        if(n==1){

        	cin>>m ;

        	for(int i=0 ; i<m ; i++){
        		cin>>x ;
        		mn=min(mn,x);
        	}

        	cout<<mn<<endl;

        	continue ;
        }

        vector<int> var;

        for(int i=0 ; i<n ; i++){

        	cin>>m ;
        	priority_queue<ll, vector<ll> ,greater<ll>>pq ;

        	for(int j=0 ; j<m ; j++){

        		cin>>x; 
        		mn= min(mn,x) ;
        		pq.push(x) ;

        	}
        	
        	pq.pop() ;
        	//var.pb(pq.top()) ;

        	sum+=pq.top();

        	mn2=min(mn2 , pq.top()) ;
        }

       //int mn2 = *min_element(var.begin() ,var.end()) ;

       /*for(int i=0 ; i<var.size() ; i++){
       		sum+=var[i];
       }*/

       cout<<sum-mn2+mn<<endl;

    }
    return 0 ;
}
