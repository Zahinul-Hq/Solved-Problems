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

ll ff(string s){

	ll ans =0 ;
	set<char> st;
	for(int i=0 ; i<s.size() ; i++){
		st.insert(s[i]);
		ans+=st. size();
	}

	return ans ;
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
    	int  n;
		cin >> n;
		string s;
		cin >> s;

		ll ans = ff(s);
		
		cout << ans<< endl;

	}
	    
    return 0 ;
}
