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
        cin >> n;

        string s;

        cin >> s;
        vector<int>dig;
        vector<char> let;

        bool ok = true;

        for(int i = 0; i < s.size() - 1; i++){
        	if(s[i] >= 'a' && s[i] <= 'z'){
        		if(s[i + 1] >= '0' && s[i + 1] <= '9')
        			ok = false;
        	}
        }
        if(!ok){
        	cout << "NO" << endl;
        	continue;
        }

         for(int i = 0; i < s.size() ; i++){
         	if(s[i] >= '0' && s[i] <= '9'){
         		dig.push_back(s[i] - '0');
         	}else{
         		let.push_back(s[i]);
         	}
        	
        }

        if(is_sorted(dig.begin(), dig.end()) && is_sorted(let.begin(), let.end()) ){
        	cout << "YES" << endl;
        }else{
        	cout << "NO" << endl;
        }


    }
    return 0 ;
}
