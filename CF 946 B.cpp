#include<bits/stdc++.h>
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

    int t ;
    cin >> t ;
    
    while (t--)
    {

    	int n;
    	string s;

    	cin >> n >> s;

    	string dis_char = "";

    	map<char,int>mp;

    	for(int i = 0; i < n; i++){
    		if(mp[s[i]] == 0){
    			dis_char += s[i];
    			mp[s[i]]++;
    		}
    	}

    	sort(dis_char.begin(), dis_char.end());

    	int sz = dis_char.size();

    	for(int i = 0; i < n; i++){
    		int pos = -1;
    		for(int j = 0; j < sz; j++){
    			if(s[i] == dis_char[j]){
    				pos = j;
    				break;
    			}
    		}

    		s[i] = dis_char[sz - pos - 1];
    	}

    	cout << s << endl;

    }
    return 0 ;
}
