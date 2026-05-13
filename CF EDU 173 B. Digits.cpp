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

bool check(ll val){
    map<ll,int>mp;

    while(val){
        mp[val % 10]++;
        val /= 10;

    }

    return mp.size() == 1;
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
    	int n, d;

        cin >> n >> d;

        cout << 1 << " ";
        if(d % 3 == 0 || n >= 3)
            cout << 3 << " ";
        if(d == 5)
            cout << 5 << " ";
        if(d == 7 || n >= 3)
            cout << 7 << " ";
        if(n >= 6 || (d % 3 == 0 && n >= 3) || d == 9)
            cout << 9 << " ";

        cout << endl;
    }
  

    runtime();
    return 0 ;

}
