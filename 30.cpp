#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class Edge
{
public:
  int to, from;
  int cost;
  Edge(int n, int c)
  {
    to = n;
    cost = c;
  }
};

vector<Edge> g[100];
int memo[100][100]; //make i needed j

int main()
{
  int n, m;
  cin >> n >> m;
  fill(memo[0], memo[100], 0);
  for (int i = 0; i < m; i++)
  {
    int p, q, r;
    cin >> p >> q >> r;
    //逆辺を張る
    //JP comment, zettai abuse
    p--;
    r--;
    memo[r][p] = q;
    g[r].push_back(Edge(p, q));
  }
  bool f = true;
  while (f)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (memo[i][j] > 0)
        {
          for (int k = 0; k < n; k++)
          {
            int tmp = memo[i][k];
            memo[i][k] = max(memo[i][k], memo[i][j] * memo[j][k]);
            if (tmp != memo[i][k])
              f = true;
          }
        }
      }
    }
  }
  for (int i = 0; i < n - 1; i++)
    cout << memo[n - 1][i] << endl;
  return 0;
}