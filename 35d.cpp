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

// set V in main
// d[MAX_V] shows the answer

const int MAX_V = 100000;

struct edge{int to; ll cost;};
typedef pair<ll, int> P;

int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>  > que;
  fill(d, d + V, INFll);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}


int main(){
  int N, M;
  ll T;
  cin >> N >> M >> T;
  int A[N], a[M], b[M];
  ll c[M];
  REP(i,N) cin >> A[i];
  REP(i,M){
    cin >> a[i] >> b[i] >> c[i];
    G[a[i]-1].push_back(edge{b[i]-1, c[i]});
  }
  int taizai[N];
  REP(i,N) taizai[i] = T;

  V = N;
  dijkstra(0);
  REP(i,N){
    taizai[i] -= d[i];
    G[i].clear();
  }
  REP(i,M){
    G[b[i]-1].push_back(edge{a[i]-1, c[i]});
  }
  dijkstra(0);
  REP(i,N){
    taizai[i] -= d[i];
  }

  ll ans = 0ll;
  REP(i,N){
    if(taizai[i] > 0){
      ans = max(ans, ll(taizai[i]) * A[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
