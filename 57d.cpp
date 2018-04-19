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

// pascal's triangle // C[n][k] -> nCk //　O(n^2)
const int MAX_N = 10000;
ll C[MAX_N][MAX_N];
void comb_table(int n){
  REP(i,n+1){
    REP(j,i+1){
      if(j==0 || j==i){
        C[i][j]=1LL;
      }else{
        C[i][j]=(C[i-1][j-1]+C[i-1][j]);
      }
    }
  }
}


int main(){
  ll n, a, b;
  cin >> n >>a >> b;
  ll v[n];
  REP(i,n)cin >> v[i];

  sort(v, v+n);

  double ave = 0;

  REP(i,a){
    ave += v[n-1-i];
  }
  ave /= double(a);

  ll x = v[n-a];

  comb_table(51);

  if(ave == x){
    int xnum = upper_bound(v, v+n, x) - lower_bound(v, v+n, x);
    ll ans = 0;
    for(int i = a; i <= min(int(b),xnum); i++){
      ans += C[xnum][i];
    }
    cout.precision(20);
    cout << fixed <<  ave << endl;
    cout << ans << endl;
  }else{
    int xnum = upper_bound(v, v+n, x) - lower_bound(v, v+n, x);
    int xina = (upper_bound(v, v+n, x) - v) - (n - a);
    cout.precision(20);
    cout << fixed <<  ave << endl;
    cout << C[xnum][xina] << endl;
  }

  return 0;
}
