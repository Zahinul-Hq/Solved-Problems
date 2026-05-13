#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define inf 2e18

const int N = 1005;
vector<char> ch{'n', 'a', 'r', 'e', 'k'};
map<char,int> mp;


ll dp[N][5]; 
ll n, m;
vector<string> arr;

ll solve(int i, int pos){

    if(i == n){
        return -pos; 
    }
    if(dp[i][pos] != -inf)
        return dp[i][pos];


    ll ans = solve(i + 1, pos);


    ll cnt = 0;
    

    for(int j = 0; j < m; j++){
        if(arr[i][j] == ch[pos]){
            pos++;
        } else if(mp.count(arr[i][j])){
            cnt--;
        }
        
        if(pos == 5){
            cnt += 5;
            pos = 0; 
        }
    }

    
    ans = max(ans, solve(i + 1, pos) + cnt);

    return dp[i][pos] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    
    mp.clear();
    for(auto chr : ch){
        mp[chr]++;
    }
    
    while (test_cases--)
    {
        cin >> n >> m;
        arr.clear();
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 5; j++){
                dp[i][j] = -inf;
            }
        }

        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            arr.push_back(s); 
        }

        cout << solve(0, 0) << endl;
    }
    return 0;
}