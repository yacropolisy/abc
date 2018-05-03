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

int main(){
  string s;
  cin  >> s;
  map<char, int> mp;
  char c = 'a';
  REP(i,26){
    mp[c] = -100;
    c++;
  }

  int n = s.size();

  REP(i, n){
    if(mp[s[i]] >= i-2){
      cout << mp[s[i]]+1 << " " << i+1 << endl;
      return 0;
    }
    mp[s[i]] = i;
  }

  cout << "-1 -1" << endl;

  return 0;
}
