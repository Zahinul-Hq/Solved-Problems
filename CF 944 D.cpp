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
      	 string s;

      	 cin >> s;

       	if(is_sorted(s.begin(), s.end())){
       		cout << 1 << endl;
       		continue;
       	}

       	bool z1 = 0;

       	bool  tg = s[0] - '0';

       	int seg0 = 0, seg1 = 0, sg = 1; 

       	for(int i = 0; i < s.size(); i++){

       		if(tg != s[i] - '0'){
       			tg ^= 1;
       			sg++;
       		}
       		if(s[i] == '0' && s[i + 1] == '1')
       			z1 =1;
       	}

       	cout << sg - z1 << endl;
    }
    return 0 ;
}
