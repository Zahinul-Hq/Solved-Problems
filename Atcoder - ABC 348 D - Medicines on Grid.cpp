#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	const int INF = 1e9;
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    int sy, sx, ty, tx;
    for (int i = 0; i < H; i++) {
        cin >> A[i];
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'S') {
                sy = i, sx = j;
            } else if (A[i][j] == 'T') {
                ty = i, tx = j;
            }
        }
    }
    int N;
    cin >> N;
    N += 2;
    vector<int> R(N), C(N), E(N);
    R[0] = sy, C[0] = sx, E[0] = 0;
    R[1] = ty, C[1] = tx, E[1] = 0;
    for (int i = 2; i < N; i++) {
        cin >> R[i] >> C[i] >> E[i];
        R[i]--, C[i]--;
    }

    vector<vector<int>> g(N);
    for (int i = 0; i < N; i++) {
        vector<vector<int>> d(H, vector<int>(W, INF));
        d[R[i]][C[i]] = 0;
        queue<pair<int, int>> q;
        q.emplace(R[i], C[i]);
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int dy[] = {0, 1, 0, -1};
            int dx[] = {1, 0, -1, 0};
            for (int j = 0; j < 4; j++) {
                int nr = r + dy[j];
                int nc = c + dx[j];
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                if (A[nr][nc] == '#') continue;
                if (d[nr][nc] > d[r][c] + 1) {
                    d[nr][nc] = d[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
        for (int j = 0; j < N; j++) {
            if (d[R[j]][C[j]] <= E[i]) {
                g[i].push_back(j);
            }
        }
    }

    vector<bool> visited(N);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        for (int u : g[v]) {
            q.push(u);
        }
    }
    cout << (visited[1] ? "Yes" : "No") << endl;

    return 0 ;
}
