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
  int n, k, l;
  cin >> n >> k >> l;
  int p[k], q[k], r[l], s[l];
  map<int, map<int,int> > mp;
  REP(i,k){
    cin >> p[i] >> q[i];
    mp[p[i]-1][q[i]-1]++;
    mp[q[i]-1][p[i]-1]++;
  }
  REP(i,l){
    cin >> r[i] >> s[i];
    mp[r[i]-1][s[i]-1]++;
    mp[s[i]-1][r[i]-1]++;
  }



  REP(i,n){
    ll ans = 1;
    for(auto &y: mp[i]){
      if(y.second==2)ans++;
    }
    cout << ans << endl;
  }


  return 0;
}
