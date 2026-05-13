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
        string s;
		cin >> s;
		ll n = s.size();

		ll cnt = 0, ans = 0;

		bool ok = 0;

		map<char, ll>m;

		for (ll i = 0; i < n; i++)
		{
			if (i < n / 2) {
				if (s[i] != s[n - i - 1]) {
					cnt++;
				}
			}
			else
				m[s[i]] = i;

		}



		ans = cnt;
		ll cnt2 = 0, lagbe = 0;

		for (ll i = 0; i < n / 2; i++)
		{
			if (s[i] != s[n - i - 1] and !ok) {

				if (m.count(s[i])) {
					cnt2 += min(lagbe, i);
					ok = 1;
					lagbe = 0;
				}
				else
					lagbe++;
			}
			else
				cnt2++;
		}

		if (cnt2 != 0)
			ans = min(cnt, cnt2);

		cout << ans;



    }
    return 0 ;
}
