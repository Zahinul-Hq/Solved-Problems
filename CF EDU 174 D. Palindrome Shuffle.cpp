#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
bool check( string &s, int m){

	int n = (int)s.size();

	for(int i = m; i < (n / 2); i++){
		if(s[i] != s[n - 1 - i])
			return false;
	}



	map<char,int>mp;

	for(int i = 0; i < m; i++){
		mp[s[i]]++;
	}

	for(int i = n - 1; i >= m && i >= n - m; i--){
		if(mp[s[i]] >= 1){
			mp[s[i]]--;
		}else{
			return false;
		}
	}
	debug(s, m);

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

    	string s;

    	cin >> s;

    	int i = 0, j = (int)s.size() - 1;

    	while(s[i] == s[j] && i < j){
    		i++;
    		j--;
    	}

    	string  t = "";

    	for(int l = i; l <= j; l++){
    		t += s[l];
    	}

    	string r = t;

    	reverse(r.begin(), r.end());

    	int hi = (int)t.size(), lo = 0, ans = hi;

    	while(hi >= lo){

    		int mid = (hi + lo) / 2;

    		if(check(t, mid) || check(r, mid)){
    			ans = mid;
    			hi = mid - 1;
    		}else{
    			lo = mid + 1;
    		}
    	}


    	cout << ans << endl;
    }
    return 0 ;

    runtime();

}
