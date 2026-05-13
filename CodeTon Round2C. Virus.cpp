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
        int n , m ;

        cin>>n>>m ;

        vector<int>vec(m,0) ,diff;

        for(int i=0 ; i<m ; i++){
        	cin>>vec[i] ;
        }

        sort(vec.begin() ,vec.end());

        for(int i=0 ; i<m-1 ; i++){
        	diff.pb(vec[i+1]-vec[i]-1) ;
        }

        diff.pb(vec[0]+n-vec[m-1]-1) ;

        sort(diff.rbegin() ,diff.rend()) ;

        ll safe=0 , spread=0;

        for(int i=0 ; i<diff.size(); i++){

        	int curr = diff[i];

        	curr-= (spread*2);

        	if(curr<=0)
        		break ;

        	safe+=(curr-1) ;

        	if(curr==1)
        		safe++ ;

        	spread+=2 ;
        	
        } 

        cout<<n-safe<<endl;
    }
    return 0 ;
}
