#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;


// lca : O(n log n) for init , O(log n) for a query
// 1. setting graph root and G
// 2. use lca

// depth can be used for calc the distance

const int MAX_V = 100000;
const int MAX_LOG_V = 20;

vi G[MAX_V];
int root;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void lca_dfs(int v, int p, int d){
  parent[0][v] = p;
  depth[v] = d;
  REP(i, G[v].size()){
    if(G[v][i] != p) lca_dfs(G[v][i], v, d+1);
  }
}

void lca_init(int V){
  lca_dfs(root, -1, 0);

  REP(k, MAX_LOG_V-1){
    REP(v, V){
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }
}

int lca(int u, int v){
  if(depth[u] > depth[v]) swap(u,v);
  REP(k, MAX_LOG_V){
    if((depth[v] - depth[u]) >> k & 1){
      v = parent[k][v];
    }
  }
  if(u==v) return u;

  for(int k = MAX_LOG_V -1; k >= 0; k--){
    if(parent[k][u] != parent[k][v]){
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];

}



int main(){
  int n;
  cin >> n;
  int x[n-1], y[n-1];
  REP(i,n-1){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    G[x[i]].push_back(y[i]);
    G[y[i]].push_back(x[i]);
  }
  int q;
  cin >> q;
  int a[q], b[q];
  REP(i,q){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  root = 0;
  lca_init(n);

  REP(i,q){
    int l = lca(a[i], b[i]);
    cout << depth[a[i]] + depth[b[i]] - 2 * depth[l] + 1 << endl;
  }

  return 0;
}
