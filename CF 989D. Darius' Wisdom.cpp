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
    	cin >> n;
    	vector<int>arr(n), sorted_arr(n);
        vector<set<int>>vs(3);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
            vs[arr[i]].insert(i);
    	}

    	sorted_arr = arr;

    	int last0 = n - 1 , first2 = 0, last1 = n - 1;

        vector<pair<int,int>>ans;


        auto handle = [&](int i, int x, int y){

            auto idx = vs[]

        }


    	sort(sorted_arr.begin(), sorted_arr.end());

    	for(int i = 0; i < n; i++){
    		if(arr[i] == sorted_arr[i])
    			continue;

    		if(sorted_arr[i] == 0 && arr[i] == 1){
                

                
    		}else if(sorted_arr[i] == 0 && arr[i] == 2){
                


            }else if(sorted_arr[i] == 1 && arr[i] == 2){

               

            }
    	}

        cout << ans.size() << endl;

        for(auto i : ans){
            cout << i.F << " " << i.S << endl;

        }
    }
    cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    runtime();
    return 0 ;
}
