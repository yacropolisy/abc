#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <deque>
#include <string>
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

const int MAX_N = 100000;

int par[MAX_N];
int rk[MAX_N];
int sz[MAX_N];

void init(int n){
  REP(i,n){
    par[i] = i;
    rk[i] = 0;
    sz[i] = 1;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(rk[x] < rk[y]){
    par[x] = y;
    sz[y] += sz[x];
  }else{
    par[y] = x;
    sz[x] += sz[y];
    if(rk[x] == rk[y]) rk[x]++;
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}


int main(){
  int n, m, q;
  cin >> n >> m;
  int a[m], b[m], y[m];
  REP(i,m) cin >> a[i] >> b[i] >> y[i];
  vpi sort_y;
  REP(i,m) sort_y.push_back(pi(y[i],i));
  sort(sort_y.begin(), sort_y.end(), greater<pi>());
  cin >> q;
  int v[q], w[q];
  REP(i,q) cin >> v[i] >> w[i];
  vpi sort_w;
  REP(i,q) sort_w.push_back(pi(w[i],i));
  sort(sort_w.begin(), sort_w.end(), greater<pi>());

  init(n);

  int ans[q];
  int i = 0;
  REP(j,q){
    int tj = sort_w[j].second;
    while(i < m && y[sort_y[i].second] > w[tj]){
      int ti = sort_y[i].second;
      unite(a[ti], b[ti]);
      // cout << "i " << i << ", ti " << ti << endl;
      i++;
    }
    ans[tj] = sz[find(v[tj])];
    // cout << "j " << j << ", tj " << sort_w[j].second << endl;
  }
  REP(i,q) cout << ans[i] << endl;

  return 0;
}
