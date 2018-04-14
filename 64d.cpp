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

#define MAX_V 100000

vector<int> G[MAX_V];

int main(){
  int n;
  string s;
  cin >> n >> s;

  int i = 0;
  int ct = 0;


  while(1){
    // cout << i << " " << s << " " << s[i] << endl;
    if(s[i] == '\0')break;
    if(s[i] == '('){
      ct++;
    }else{
      if(ct > 0)ct--;
      else{
        s.insert(i, "(");
        i++;
      }
    }
    i++;
  }

  i--;
  ct = 0;



  while(1){
    if(i==0)break;
    if(s[i] == ')'){
      ct++;
    }else{
      if(ct > 0)ct--;
      else{
        s.insert(i+1, ")");
      }
    }
    i--;
  }

  cout << s << endl;

  return 0;
}
