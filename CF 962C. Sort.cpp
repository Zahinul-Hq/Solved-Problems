#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
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
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, q;

        cin >> n >> q;
        string s1, s2;
        cin >> s1 >> s2;

        s1 = "#" + s1;
        s2 = "#" + s2;

        int pref1[150][n + 2], pref2[150][n + 2];

        for(char ch = 'a'; ch <= 'z'; ch++){
        	pref1[ch][0] = pref2[ch][0] = 0;
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
        	for(int i = 1; i <= n; i++){
        		pref1[ch][i] = pref1[ch][i - 1] + (s1[i] == ch);
        		pref2[ch][i] = pref2[ch][i - 1] + (s2[i] == ch);
        	}
        }

        while(q--){
        	int l, r;
        	cin >> l >> r;
        	ll cnt = 0;
        	for(char ch = 'a'; ch <= 'z'; ch++){
        		int x = pref1[ch][r] - pref1[ch][l - 1];
        		int y = pref2[ch][r] - pref2[ch][l - 1];
        		cnt += abs(x - y);
        	}

        	cout << cnt / 2 << endl;
        }
    }
    return 0 ;
}
