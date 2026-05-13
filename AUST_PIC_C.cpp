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

    
    map<char, int>mx_cnt;

    for(char ch = 'a'; ch <= 'z'; ch++){
        mx_cnt[ch] = INT_MAX;
    }

    while (t--)
    {
        string s;

        cin >> s;

        map<char, int>mp;

        for(int i = 0; i < s.size(); i++){
        	mp[s[i]]++;
        }

        for(char ch = 'a'; ch <= 'z'; ch++){
        	mx_cnt[ch] = min(mx_cnt[ch], mp[ch]);
        }
    }

    string ans = "";

    for(char ch = 'a'; ch <= 'z'; ch++){
        for(int i = 1; i <= mx_cnt[ch]; i++){

        	ans += ch;

        }

    }


    cout << ans << endl;

    return 0 ;
}
