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


int main(){
  ll n, m;
  cin >> n >> m;
  ll x[n], y[m];
  REP(i,n)cin >> x[i];
  REP(j,m)cin >> y[j];


  ll mod = 1000000007;
  cout << ((((n-1) * (m-1) % mod ) * (x[n-1] - x[0]) % mod) * (y[m-1] - y[0]) % mod) << endl;

  return 0;
}
