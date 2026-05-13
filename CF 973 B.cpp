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
//#define endl  "\n"
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
int query(string sq){
	int ok;
	cout << "? " << sq << endl;
	cin >> ok;
	return ok;
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
    	cin >> n;
        string ans = "";

        bool pref = 0, suff = 1;


        while(ans.size() != n){

        	if(suff){

        		string s0 = ans + '0';
        		string s1 = ans + '1';

        		if(query(s0)){
        			ans = s0;
        		}else if(query(s1)){
        			ans = s1;
        		}else{
        			suff = 0;
        			pref = 1;
        		}
        	}else if(pref){
        		string s0 = '0' + ans ;
        		string s1 = '1' + ans;

        		if(query(s0)){
        			ans = s0;
        		}else{
        			ans = s1;
        		}

        	}
        }

        cout << "! " << ans << endl;
    }
    return 0 ;
}
