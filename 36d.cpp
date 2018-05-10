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

const int MAX_N = 100000;
vi G[MAX_N];

pll dfs(int from, int to){
  pll res = pll(1,1);
  for (int i = 0; i < G[to].size(); i++){
    if(G[to][i] == from) continue;
    pll next = dfs(to, G[to][i]);
    res.first = res.first * (next.first + next.second) % MOD;
    res.second = res.second * next.first % MOD;
  }
  return res;
}


int main(){
  int n;
  cin >> n;
  int a[n], b[n];
  REP(i,n-1){
    cin >> a[i] >> b[i];
    G[a[i]-1].push_back(b[i]-1);
    G[b[i]-1].push_back(a[i]-1);
  }

  pll ans = dfs(-1, 0);
  cout << (ans.first + ans.second) % MOD << endl;

  return 0;
}
