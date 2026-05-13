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

    unordered_map<ll,int>s_mp;
    unordered_map<ll,ll>q_mp;

    s_mp[0] = 1;
    
    while (t--)
    {
        char ch ; ll q;

        cin >> ch >> q;

        if(ch == '+'){
        	s_mp[q]++;
        	continue;
        }

        ll k = q_mp[q];

        while(s_mp[k] > 0){
        	k += q;
        }
        q_mp[q] = k;

        cout << k << endl;


    }
    return 0 ;
}
