#include <cstring>
#include <iostream>
#include <queue>
#include <string>

#define MAXM 100
#define MAXN 100

using namespace std;

int m, n;
string maze[MAXM];
int stX, stY, goalX, goalY;

bool visited[MAXM][MAXN][4];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
char dl[] = { 'v', '>', '^', '<' };

bool inMaze(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

struct State {
  int x, y, rot, dist;

  State(int _x, int _y, int _rot, int _dist):
    x(_x), y(_y), rot(_rot), dist(_dist) {}

  bool onFire() {
    for(int d = 0; d < 4; d++) {
      int currX = x, currY = y;

      while(inMaze(currX, currY) && maze[currX][currY] == '.') {
        currX += dx[d]; currY += dy[d];
      }

      if(!inMaze(currX, currY)) continue;
      if(maze[currX][currY] == dl[(2 + rot + d) % 4])
        return true;
    }
    return false;
  }

  bool isValid() { return inMaze(x, y) && maze[x][y] == '.' && !onFire(); }
  bool isGoal() { return x == goalX && y == goalY; }
  bool wasVisited() { return visited[x][y][rot]; }
  void setVisited() { visited[x][y][rot] = true; }
};

int bfs() {
  queue<State> q;
  q.push(State(stX, stY, 0, 0));
  memset(visited, 0, sizeof(visited));

  while(!q.empty()) {
    State st = q.front(); q.pop();

    if(st.wasVisited()) continue;
    if(st.isGoal()) return st.dist;
    st.setVisited();

    for(int d = 0; d < 4; d++) {
      State next = State(st.x + dx[d], st.y + dy[d],
        (st.rot + 1) % 4, st.dist + 1);

      if(next.isValid()) q.push(next);
    }
  }
  return -1;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
      cin >> maze[i];

      for(int j = 0; j < n; j++) {
        if(maze[i][j] == 'S') { stX = i; stY = j; maze[i][j] = '.'; }
        else if(maze[i][j] == 'G') { goalX = i; goalY = j; maze[i][j] = '.'; }
      }
    }

    int dist = bfs();
    cout << "Case #" << tc << ": ";
    if(dist == -1) cout << "impossible" << endl;
    else cout << dist << endl;
  }
  return 0;
}
