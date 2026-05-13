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


    vector<int>temp;
        int x, n;
        cin >> n;
        vector<int>arr(n);
    
        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        }
        int max_len = 0, lastIndex = n - 1;
        vector<int> dp(n , 1), lis;
        map<int,int>prev, ID;
        for(int i = 0; i < n; i++){
            int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            ID[arr[i]] = i;
    
            if(pos >= temp.size() - 1)
                lastIndex = i;
    
            if(pos == temp.size()){
                temp.push_back(arr[i]);
                max_len++;
                
            }else{

                temp[pos] = arr[i];
            }
            
            prev[i] = pos ? ID[temp[pos - 1]] : -1;
    
        }
        int ans1 = temp.size();
        max_len = 0;
        temp.clear();
        reverse(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            ID[arr[i]] = i;
    
            if(pos >= temp.size() - 1)
                lastIndex = i;
    
            if(pos == temp.size()){
                temp.push_back(arr[i]);
                max_len++;
                
            }else{
                temp[pos] = arr[i];
            }
            
            
            prev[i] = pos ? ID[temp[pos - 1]] : -1;
    
        }
        cout << ans1 + temp.size()<< endl;


    return 0 ;

    runtime();

}
