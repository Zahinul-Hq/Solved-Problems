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


    int test_cases = 1 ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	vector<int>arr(n);
        stack<int>st;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];

            st.push(arr[i]);
    	}

        arr.clear();


        for(int i = 0; i < n; i++){
            arr.push_back(st.top());
            st.pop();
            int sz = arr.size();

            if(sz >= 4){
                bool ok = 1;
                for(int j = sz - 1; j >= sz - 4; j--){
                    if(arr[sz - 1] != arr[j]){
                        ok = 0;
                        break;
                    }
                }
                if(ok){
                    for(int j = 1;j <= 4; j++){
                        arr.pop_back();
                    }
                }
            }
        }

        cout << arr.size() << endl;


    	
    }
    return 0 ;

    runtime();

}
