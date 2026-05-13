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
        int s1 ,s2 ;

        cin>>n>>s1>>s2 ;

        vector<pair<int,int>>a(n) ;


        for(int i=0 ; i<n ; i++){
 
        	int x ;
        	cin>>x ;
        	a.pb({x , i+1}) ;
        }

        sort(a.begin() ,a.end());
        reverse(a.begin() , a.end()) ;

        vector<vector<int>>list(2) ;

        for(int i = 0 ; i<n ; i++){

        	int cost1 = s1*(list[0].size()+1);
        	int cost2 = s2*(list[1].size()+1) ;

        	if(cost1<cost2)
        		list[0].pb(a[i].second);
        	else
        		list[1].pb(a[i].second) ;

        }

        for(int j = 0; j < 2; j++)
		{
		    cout << list[j].size();
		    for(auto x : list[j]){    
		    	cout << " " << x;
		    }
		    cout << endl;
		}
    }
    return 0 ;
}