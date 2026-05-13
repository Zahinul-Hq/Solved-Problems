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

    int t , c = 1 ;
    cin>>t ;
    
    while (t--)
    {
        string s ;

        cin >> s; 


        int ans = INT_MAX; 

        map<char, int>mp ;

        bool f = 0 ;

       /* for(int i = 0; i < s.size(); i++){


        	if(mp[s[i]] == 0)
        		mp[s[i]] = i;
        	else{

        		f = 1; 
        		ans = min(ans , abs(mp[s[i]] - i));
        		mp[s[i]] = i;

        	}
        }

        */


        if(f)
        	cout << "Case " << c++ << ": " << ans << endl;
        else
        	cout << "Case " << c++ << ": " << s.size() << endl;
    }
    return 0 ;
}
