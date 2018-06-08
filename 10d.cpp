#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <cstring>
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

// ford-fulkerson O(FE) F:Flow
// maximum flow problem
// 1. init G[V] by add_edge
// 2. max_flow(s, t) return the max flow

const int MAX_V = 101;

struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, int(G[to].size())});
  G[to].push_back((edge){from, 0, int(G[from].size() -1)});
}

int dfs(int v, int t, int f){
  if(v == t) return f;
  used[v] = true;
  for (int i = 0; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow = 0;
  for(;;){
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INFi);
    if(f == 0) return flow;
    flow += f;
  }
}




int main(){
  int n, g ,e;
  cin >> n >> g >> e;
  int p[g];
  REP(i,g) cin >> p[i];
  int a[e], b[e];
  REP(i,e) {
    cin >> a[i] >> b[i];
    add_edge(a[i], b[i], 1);
    add_edge(b[i], a[i], 1);
  }
  REP(i,g){
    add_edge(p[i], 100, 1);
  }

  cout << max_flow(0,100) << endl;


  return 0;
}
