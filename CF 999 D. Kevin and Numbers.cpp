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
    	int n, m, x;
        cin >> n >> m;
        vector<int> a(n);
        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < m; i++){
            cin >> x;
            pq.push(x);
        }

        for(int i = 0; i < n - m; i++){
            while(!pq.empty() && a.size() > 0 && a.back() == pq.top()){
                pq.pop();
                a.pop_back();
            }

            if(pq.empty() || a.size() == 0){
                break;
            }


            int val = pq.top();
            pq.pop();

            pq.push((val + 1) / 2);
            pq.push((val) / 2);
            debug(pq);
        }


        while(!pq.empty() && a.size() > 0 && a.back() == pq.top()){
            pq.pop();
            a.pop_back();
        }

        debug(pq, a);

        if (pq.empty() && a.size() == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0 ;

    runtime();

}
