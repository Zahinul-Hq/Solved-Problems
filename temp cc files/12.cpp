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




string query(string s){
	cout << s << endl;

	string ans;
	cin >> ans;

	return ans;
}

void solve(){




    	int n ;

    	cin >> n;


    	string pref = "", suff = "";

    	while(1){
    		string ans = query(suff + '1');
    		if(ans == "Yes")
    			suff = suff + '1';
    		else if(ans == "Correct"){
    			return;
    		}else{
    			break;
    		}
    	}
    	while(1){
    		string ans = query(pref + '0' + suff);
    		if(ans == "Yes")
    			pref = pref + '0';
    		else if(ans == "Correct"){
    			return;

    		}else{
    			pref = pref + '1';
    			if(suff.size() >= 2)
    				suff = suff.substr(1);
				else{
					suff ="";

				}
    		}
    	}







}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	solve();



    return 0 ;
}
