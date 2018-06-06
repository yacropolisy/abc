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
const int MAX_N = 1001;
double C[MAX_N][MAX_N];
void comb_table(int n){
  REP(i,n+1){
    REP(j,i+1){
      if(j==0 || j==i){
        if(i==0){
          C[i][j] = 1.0;
        }else{
          C[i][j] = C[i-1][0] / 2.0;
        }
      }else{
        C[i][j]=(C[i-1][j-1]+C[i-1][j]) / 2.0;
      }
    }
  }
}

int main(){
  ll n, d, x, y;
  cin >> n >> d >> x >> y;
  if(x % d != 0 || y % d != 0){
    cout << 0 << endl;
    return 0;
  }
  x /= d; y /= d;
  x = abs(x); y = abs(y);

  if(x+y > n || (n-x-y) % 2 != 0){
    cout << 0 << endl;
    return 0;
  }

  comb_table(n);

  int c = (n - x - y) / 2;

  double ans = 0.0;

  REP(i,c+1){
    int lr = 2 * i + x;
    int ll = i;
    int ud = n - lr;
    int dd = c-i;
    ans += C[n][lr] * C[lr][ll] * C[ud][dd];
  }

  cout << setprecision(20);
  cout << ans << endl;

  return 0;
}
