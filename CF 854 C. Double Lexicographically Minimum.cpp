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

    	string s;
    	cin >> s;
        int n = s.size();

    	map<char,int>mp;

    	for(auto i : s){
            mp[i]++;
        }
        vector<pair<char,int>>vp;
        for(auto i : mp){
            vp.push_back({i.first, i.second});
        }
        string ans(n, '#');
        int l = 0, r = n - 1;
        for(int i = 0; i < vp.size(); i++){
            while(vp[i].second > 1){
                ans[l++] = ans[r--] = vp[i].first;
                vp[i].second -= 2;
            }
            if(vp[i].second % 2 != 0){
                if(i == vp.size() - 2){
                    while( vp[i + 1].second > 1){
                        ans[l++] = ans[r--] = vp[i + 1].first;
                        vp[i + 1].second -= 2;
                    }
                    if(vp[i + 1].second != 0){
                        ans[l++] = vp[i + 1].first;
                    }
                    ans[l] = vp[i].first;
                }else{
                    for(int j = i + 1; j < vp.size(); j++){
                        while(vp[j].second > 0){
                            ans[l++] = vp[j].first;
                            vp[j].second--;
                        }
                    }
                    ans[l] = vp[i].first;
                }
                break;

            }
             
        }

        cout << ans << endl;
    }
    return 0 ;
    runtime();

}
