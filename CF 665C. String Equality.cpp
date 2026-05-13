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
        int n, k;
        string a, b;
        
        cin >> n >> k >> a >> b;

        map<char,int>have, need;
        for(int i = 0; i < n; i++){
        	have[a[i]]++;
        	need[b[i]]++;
        }
        bool ok = 0;

        for(char ch = 'a'; ch <= 'z'; ch++){
        	if(have[ch] < need[ch] || ((have[ch] -= need[ch]) % k)){
        		ok = 1;
        		break;
        	}
        	have[ch + 1] += have[ch];
        }
        if(!ok){
        	cout << "YES" << endl;
        }else{
        	cout << "NO" << endl;
        }
    }
    return 0 ;
}
