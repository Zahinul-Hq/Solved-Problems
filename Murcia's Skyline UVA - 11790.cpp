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


    int test_cases, cs= 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int x, n;
        vector<int>temp;
        cin >> n;
        vector<ll>arr(n), width(n);
        
            for(int i = 0; i < n; i++){
                cin >> arr[i];
            }
            for(int i = 0; i < n; i++){
                cin >> width[i];
            }
            int max_len = 1, lastIndex = -1;
            vector<ll> pref(n, 0);
            for(int i = 0; i < n; i++){
                int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                if(pos == temp.size()){
                    temp.push_back(arr[i]);
                    pref[pos] = pos ? pref[pos - 1] + width[i] : width[i];
                    
                }else{
                    int pr = pref[pos];
                    pref[pos] = pos ? max(pref[pos - 1] + width[i], pref[pos]) : max(pref[pos],width[i]);
                    if(pr != pref[pos])
                        temp[pos] = arr[i];
                }

                if(lastIndex == -1 || pref[pos] > pref[lastIndex])
                    lastIndex = pos;
        
            }
            ll lis = pref[lastIndex];
            lastIndex = -1;

            pref.assign(n, 0);
            temp.clear();
            reverse(arr.begin(), arr.end());
            reverse(width.begin(), width.end());
            for(int i = 0; i < n; i++){
                int pos = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                if(pos == temp.size()){
                    temp.push_back(arr[i]);
                    pref[pos] = pos ? pref[pos - 1] + width[i] : width[i];
                    
                }else{
                    int pr = pref[pos];
                    pref[pos] = pos ? max(pref[pos - 1] + width[i], pref[pos]) : max(pref[pos], width[i]);

                    //debug(pr, pref[pos]);
                    if(pr != pref[pos])
                        temp[pos] = arr[i];
                }

                if(lastIndex == -1 || pref[pos] > pref[lastIndex])
                    lastIndex = pos;
            }

            ll lds = pref[lastIndex];

            cout << "Case " << cs++ << ". ";

            if(lis >= lds){
                cout << "Increasing (" << lis << "). Decreasing (" << lds << ")." << endl;
            }else{
                 cout << "Decreasing (" << lds << "). Increasing (" << lis << ")." << endl;

            }


            
        
            
    }
    return 0 ;

    runtime();

}
