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
struct node{
    int a, b, c;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inout() ;

    int test_cases ;
    cin >> test_cases ;

    while (test_cases--)
    {
        int n, m, one = 0, total = 0;
        cin >> n >> m;

        int arr[n][m];
        map<int,int>mp;
        vector<pair<int, int>>pos;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
                mp[i] += arr[i][j];
            }
            total += mp[i];
            pos.push_back({mp[i], i});
        }
        if(total % n){
            cout << "-1" << endl;
            continue;
        }
        total = total / n;
        sort(pos.begin(), pos.end());
        int i = 0, j = pos.size() - 1;



        vector<node>ans;

        while(i < j){
            //cout << i << " " << j << endl;
            for(int l = 0; l < m; l++){
                if(mp[pos[i].S] == total || mp[pos[j].S] == total)
                    break;
                if(arr[pos[i].S][l] == 0 && arr[pos[j].S][l] == 1){
                    swap(arr[pos[i].S][l], arr[pos[j].S][l]);
                    mp[pos[i].S]++;
                    mp[pos[j].S]--;
                    ans.push_back({pos[i].S, pos[j].S, l});
                }

            }

            if(mp[pos[i].S] == total)
                i++;
            if(mp[pos[j].S] == total)
                j--;

        }

        cout << ans.size() << endl;

        for(int i = 0 ; i < ans.size(); i++){
            cout << ans[i].a + 1<< " " << ans[i].b + 1 << " " << ans[i].c + 1<< endl;
        }
    }
    return 0 ;
}
