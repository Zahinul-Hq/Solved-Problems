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
        string s;
        cin >> s;

        if(s.size() <= 2){
        	cout << "NO" << endl;
        	continue;
        }


        if(s[0] == '1' && s[1] == '0'){
        	bool ok = 0;
        	string n = "";
        	for(int i = 2; i < s.size(); i++){
        		n += s[i];
        	}
        	int val = stoi(n);
        	if(val >= 2 && s[2] != '0'){
        		cout << "YES" << endl;
        	}else{
        		cout << "NO" << endl;
        	}
        }else{
        	cout << "NO" << endl;
        }
    }
    return 0 ;
}
