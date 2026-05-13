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
    		bool f = 0;

    	if(s.size() == 1){
    		cout << -1 <<endl;
    		continue;
    	}

    	for(int i = 0; i < s.size() - 1; i++){
    			if(s[i] == s[i + 1]){
    				char ch1 = s[i];
    				char ch2 = s[i + 1];


    				cout << ch1 << ch2 << endl;
    				f = 1;
    				break;
    			}
    			//cout << s[i] << endl;
    		}

    	if(f)
    		continue;
    	for(int i = 0; i < s.size() - 2; i++){
    			if(s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]){
    				cout << s[i] << s[i + 1] << s[i + 2] << endl;
    				f = 1;
    				break;
    			}
    		}
    	if(!f){
    		cout << -1 <<endl;
    	}
    		
    	
    }
    return 0 ;
    	
}
