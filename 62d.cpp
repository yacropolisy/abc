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

// #define MAX_N 100000
// ll n, a, b;
// ll h[MAX_N];

int main(){
  int n;
  cin >> n;
  ll a[3*n];
  REP(i,3*n)cin >> a[i];

  priority_queue<ll, vll, greater<ll>> pqf;

  ll sum = 0;

  REP(i,n){
    sum += a[i];
    pqf.push(a[i]);
  }
  ll f[n+1];
  f[0] = sum;
  REP(i,n){
    sum += a[n+i];
    pqf.push(a[n+i]);
    sum -= pqf.top();
    pqf.pop();
    f[i+1] = sum;
  }

  //back

  priority_queue<ll> pqb;

  sum = 0;

  REP(i,n){
    sum += a[3*n-1-i];
    pqb.push(a[3*n-1-i]);
  }
  ll b[n+1];
  b[n] = sum;
  REP(i,n){
    sum += a[2*n-1-i];
    pqb.push(a[2*n-1-i]);
    sum -= pqb.top();
    pqb.pop();
    b[n-1-i] = sum;
  }

  ll ma = -INFll;
  REP(i,n+1){
    ma = max((f[i] - b[i]), ma);
    // cout << "i " << i << " f " << f[i] << " b " << b[i] << endl;
  }

  cout << ma << endl;



  return 0;
}
