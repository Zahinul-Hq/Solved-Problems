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
	//inout() ;

	ll t, flag = 1;

	vector<int>v;
    
    while (cin >> t)
    {



    	if(t  == 42)
    		flag = 0;
    
    	if(flag)
        	v.pb(t);
    }


    for(int i = 0; i < v.size(); i++){
    	cout << v[i] << endl;
    }
    return 0 ;
}
