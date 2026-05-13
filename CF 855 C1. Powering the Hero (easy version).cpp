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
        int n ,x ,mx=-1 ; 
        ll sum= 0 ;

        cin>>n ;

        priority_queue<int>pq ;

        for(int i=0 ; i<n  ; i++){

        	cin>>x ;

        	if(x==0 && !pq.empty()){
        		sum+=pq.top() ;
        		pq.pop() ;
        	}

        	pq.push(x) ;

        }

        cout<<sum<<endl;
    }
    return 0 ;
}
