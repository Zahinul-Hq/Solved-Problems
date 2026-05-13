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

const int N =  2e5 + 7;
vector<int>arr[N + 1];
int n, root;


void solve(vector<int> &big, vector<int>&small, int sz){


    for(int i = 0; i < big.size(); i++){
        vector<int>mark(sz + 1, 0);

        for(auto val : arr[big[i]]){
            mark[val]++;
        }
        
        for(int j = i + 1; j < big.size(); j++){
            int cnt = 0;
            for(auto val : arr[big[j]]){
                if(mark[val])cnt++;
                if(cnt >= 2){
                    cout << big[i] << " " << big[j] << endl;
                    return;
                }
            }
        }
        
        for(int j = 0; j < small.size(); j++){
            int cnt = 0;
            for(auto val : arr[small[j]]){
                if(mark[val])cnt++;
                if(cnt >= 2){
                    cout << big[i] << " " << small[j] << endl;
                    return;
                }
            }
        }
    }

    // vector<vector<pair<int,int>>>check(sz + 1);

    // for(int i = 0; i < small.size(); i++){
    //     for(int j = 0; j < arr[small[i]].size(); j++){
    //         for(int k = j + 1; k < arr[small[i]].size(); k++){
    //             check[arr[small[i]][j]].push_back({arr[small[i]][k], small[i]});
    //         }
    //     }
    // }

    // for(int i = 1; i <= sz; i++){
    //     map<int,int>mp;
    //     for(auto val : check[i]){
    //         mp[val.first]++;
    //         if(mp[val.first] == 2){
    //             int pos = val.second;
    //             for(auto v : check[i]){
    //                 if(v.first == val.first){
    //                     cout << v.second << " " << pos << endl;
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    // }

    vector<int>pos[sz + 1], vis(sz + 1, 0), index(sz + 1, 0);

    for(int i = 1; i <= n; i++){
        for(auto val : arr[i]){
            pos[val].push_back(i);
        }
    }

    for(int i = 1; i <= sz; i++){
        for(auto indx : pos[i]){

            if(arr[indx].size() > root) continue;

            for(auto val : arr[indx]){
                if(val >= i) break;

                if(vis[val] == i){
                    cout << indx << " " << index[val] << endl;
                    return ;
                }

                vis[val] = i;
                index[val] = indx;
            }

        }
    }

    cout << -1 << endl;
    return;
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
    	int x, len;
    	cin >> n;


    	map<int,int>mp;
    	int id = 1, cnt = 0;

        for(int i = 0; i <= n; i++){
            arr[i].clear();
        }

    	for(int i = 1; i <= n; i++){
    		cin >> len;
    		for(int j = 0; j < len; j++){
    			cin >> x;
    			if(!mp[x]) mp[x] = id++;
    			arr[i].push_back(mp[x]);
    			cnt++;
    		}
            sort(arr[i].begin(), arr[i].end());
    	}

    	root = sqrt(cnt);

    	vector<int>big, small;

    	for(int i = 1; i <= n; i++){
    		if(arr[i].size() <= root){
    			small.push_back(i);
    		}else{
    			big.push_back(i);
    		}
    	}
        //debug(arr);

        debug(big, small, mp);

        solve(big, small, id);

    }
    return 0 ;

    runtime();

}
