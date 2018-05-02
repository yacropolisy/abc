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
  ll n, s;
  cin >> n >> s;

  if(n < s){
    cout << -1 << endl;
    return 0;
  }

  if(n==s){
    cout << n+1 << endl;
    return 0;
  }

  ll rn = sqrt(n);

  REP(i,rn-1){
    ll x = n;
    ll ans = 0;
    while(x>0){
      ans += x % (i+2);
      x /= (i+2);
    }
    if(ans == s){
      cout << i+2 << endl;
      return 0;
    }
  }

  rn = floor(sqrt(n));

  for(int p = rn; p >= 0; p--){
    if((n-s) % (p+1) == 0){
      ll b = 1 + (n-s) / (p+1);
      ll x = n;
      ll ans = 0;
      while(x>0){
        ans += x % (b);
        x /= (b);
      }
      if(ans == s){
        cout << b << endl;
        return 0;
      }

    }
  }

  cout << -1 << endl;



  return 0;
}
