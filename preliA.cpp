#include<bits/stdc++.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
void inout()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt" ,"r" , stdin);
        freopen("output.txt" , "w" ,stdout);
        cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    #endif
}
void combo(string &S, int index, string current, vector<string> &combinations) {
    if (index == S.size()) {
        combinations.push_back(current);
        return;
    }


    combo(S, index + 1, current + S[index], combinations);


    if (index != S.size() - 1) {
       combo(S, index + 1, current + S[index] + '+', combinations);
    }
}


ll ans(string &expression) {
    ll sum = 0;
    ll curr = 0;

    for (char c : expression) {
        if (c == '+') {
            sum += curr;
            curr = 0;
        } else {
            curr = curr * 10 + (c - '0');
        }
    }

    sum += curr;
    return sum;
}

int main() {
    string S;

    cin >> S;

    vector<string> combinations;
    combo(S, 0, "", combinations);
    for(auto a : combinations){
        cout << a << " ";
    }
    int totalSum = 0;
    for (string &combination : combinations) {
        totalSum += ans(combination);
    }

    cout <<  totalSum << endl;

    return 0;
}
