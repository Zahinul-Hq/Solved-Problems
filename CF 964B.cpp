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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        vector<int>a(2, 0), b(2, 0);
        cin >> a[0] >> a[1] >> b[0] >> b[1];

        int win = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int w1 = 0, w2 = 0;
                if(a[i] > b[j]) 
                	w1++;
                else if(a[i] < b[j]) 
                	w2++;

                bool x = (i != 1), y = (j != 1);

                if(a[x] > b[y]) 
                	w1++;
                else if(a[x] < b[y]) 
                	w2++;

                if (w1 > w2) win++;
            }
        }
        cout << win << endl;

        
    }
    return 0 ;
}
