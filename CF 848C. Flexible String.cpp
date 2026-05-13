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

string str;
vector<string>substrings;
int k;
void rec(int i, string temp){
	if(i >= str.size() || temp.size() > k){
		if( temp.size() == k)
			substrings.push_back(temp);
		return;
	}
	if( temp.size() == k ){
		substrings.push_back(temp);
	}
	rec(i + 1, temp + str[i]);
	rec(i + 1, temp);
	
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
        int n;
        string a, b;
        cin >> n >> k;
        cin >> a >> b;
        vector<char>ch_diff(150, 0);

        str = "";
        substrings.clear();

        for(int i = 0; i < n; i++){
        	if(a[i] != b[i] && ch_diff[a[i]] == 0 ){
        		ch_diff[a[i]]++;
        		str += a[i];
        	}
        }
        k = min(k , (int)str.size());
        if(k == 0 || a == b){
        	ll sum = 0, tot = 0;
        	for(int j = 0; j < n; j++){
        		if(a[j] == b[j])
        			sum++;
        		else
        			sum = 0;
        		tot += sum;
        	}
        	cout << tot << endl;
        	continue;
        }
        rec(0, "");
        
        ll ans = 0;

        for(int i = 0; i < substrings.size(); i++){

        	if(substrings[i].size() > k)
        		continue;
        	vector<int>chars(150, 0);
        	for(char ch : substrings[i])
        		chars[ch]++;
        	ll sum = 0, tot = 0;
        	for(int j = 0; j < n; j++){
        		if(a[j] == b[j])
        			sum++;
        		else if(chars[a[j]] && a[j] != b[j])
        			sum++;
        		else
        			sum = 0;
        		tot += sum;
        	}
        	ans = max(tot, ans);

        }
       cout << ans << endl;
    }
    return 0 ;
}
