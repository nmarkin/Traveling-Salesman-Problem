#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;
int INFINITY = numeric_limits<int>::max();
int bound = INFINITY;

int s = 0;
vector<vector<pair<int , int>>> graph;

int TSP(int pos, int path, vector<bool>& visited, int to_visit) {
    if (path > bound)
        return bound;
    if (pos == 0 && to_visit != 0)
    {
        if (to_visit < s - 1)
            return bound;
        else return path;
    }
    if (pos != 0)
    {
        visited[pos] = true;
        to_visit++;
    }

    for (int i = 0; i < graph[pos].size(); i++)
    {
        if (visited[graph[pos][i].second] == false)
        {
            int next = TSP (graph[pos][i].second,
                    path + graph[pos][i].first,
                    visited, to_visit);
            if (next < bound)
                bound = next;
        }
    }
    visited[pos] = false;
    return bound;
}

int main() {
    cin >> s;
    vector<bool> visited;
    vector<pair<int , int>> node;

    for (int i = 0; i < s; i++)
    {
        visited.push_back(false);
        graph.push_back(node);
        for (int j = 0; j < s; j++)
        {
            int a;
            cin >> a;
            if (a != 0)
                graph[i].push_back({a, j});
        }
    }

    if (s == 1)
    {
        cout << 0;
        return 0;
    }

    int res = TSP(0, 0, visited, 0);
    if (res == INFINITY)
        cout << -1;
    else
        cout << res;

    return 0;
}
