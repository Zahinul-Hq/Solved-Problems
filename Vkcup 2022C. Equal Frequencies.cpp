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
        int n, mx = 0;
        string s, c = "";
        cin >> n >> s;

        map<char,int>mp;
        vector<pair<int,char>>cp;

        for(int i = 0; i < n; i++){
            mx = max(mx, ++mp[s[i]]);
        }
        int d = n;
        for(char ch = 'a'; ch <= 'z'; ch++){
            cp.push_back({mp[ch], ch});
        }
        sort(cp.rbegin(), cp.rend());

        int total_changes = n;

        for(int i = 1; i <= n; i++){
        	if(n % i != 0 || (n / i) > 26)
        		continue;
        	int changes = 0, extra = 0;
            for(int j = 0; j < 26 && j < (n / i); j++){
                changes += abs(cp[j].first - i);
                if(cp[j].first > i)
                    extra += (cp[j].first - i); 
            }
            changes -= extra;
            if(total_changes > changes){
                total_changes = changes;
                d = i;
            }
        }
        cout << total_changes << endl;

        int pos = 0 ;
        set<char>st;

        for(int j = 0; j < (n / d); j++){
            st.insert(cp[j].second);
        }
        for(int j = 0; j < (n / d); j++){
            for(int i = 0; i < n; i++){
                if(mp[cp[j].second] >= d)
                    continue;
                if(st.find(s[i]) == st.end() ||(mp[cp[j].second] < d && mp[s[i]] > d )){
                    mp[s[i]]--;
                    s[i] = cp[j].second;
                    mp[s[i]]++;
                }
            }
        }
        cout << s << endl;

    }
    return 0 ;
}
