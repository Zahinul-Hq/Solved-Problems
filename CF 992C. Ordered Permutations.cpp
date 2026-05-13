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
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
        long long k;
        cin >> n >> k;
        vector <int> a, b;
        
        if (n <= 60 && (1ll << (n - 1)) < k) {
            cout << -1 << endl;
            continue;
        }
        k--;
        vector <int> d;
        while (k) {
            d.push_back(k % 2);
            k /= 2;
        }
        while (d.size() < n - 1) d.push_back(0);
        
        for (int i = n - 2, j = 1; i >= 0; i--, j++) {
            if (d[i] == 0) a.push_back(j);
            else b.push_back(j);
        }
        
        reverse(b.begin(), b.end());
        for (int i : a) cout << i << ' ';
        cout << n << ' ';
        for (int i : b) cout << i << ' ';
        cout << endl; 



    }
		
    return 0 ;

    runtime();

}
