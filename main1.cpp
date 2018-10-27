#include <iostream>
#include <deque>
#include <vector>
#include <limits.h>
#include <utility>
const int inf = INT_MAX/100;
using namespace std;
void bfs(char ** graph, bool ** used,int ** dist,  pair <int, int> firstVertex, int n, int m)
{
    deque< pair<int ,int> > d;
    d.push_back(firstVertex);
    used[firstVertex.first][firstVertex.second] = true;
    dist[firstVertex.first][firstVertex.second] = 0;
    while(!d.empty())
    {
        pair<int, int> cur = d.front();
        d.pop_front();
        if(cur.first - 1 >= 0 && graph[cur.first - 1][cur.second] != '#' && !used[cur.first - 1][cur.second])
        {
            if(graph[cur.first - 1][cur.second] != '.')
            {
                d.push_front(make_pair(cur.first - 1, cur.second));
                dist[cur.first - 1][cur.second] = dist[cur.first][cur.second];
                used[cur.first - 1][cur.second] = true;
            }
            else
            {
                d.push_back(make_pair(cur.first - 1,cur.second));
                dist[cur.first - 1][cur.second] = dist[cur.first][cur.second] + 1;
                used[cur.first - 1][cur.second] = true;
            }
        }
        if(cur.first + 1 < n && graph[cur.first + 1][cur.second] != '#' && !used[cur.first + 1][cur.second])
        {
            if(graph[cur.first + 1][cur.second] != '.')
            {
                d.push_front(make_pair(cur.first + 1, cur.second));
                dist[cur.first + 1][cur.second] = dist[cur.first][cur.second];
                used[cur.first + 1][cur.second] = true;
            }
            else
            {
                d.push_back(make_pair(cur.first + 1,cur.second));
                dist[cur.first + 1][cur.second] = dist[cur.first][cur.second] + 1;
                used[cur.first + 1][cur.second] = true;
            }
        }
        if(cur.second + 1 < m && graph[cur.first][cur.second + 1] != '#' && !used[cur.first][cur.second + 1])
        {
            if(graph[cur.first][cur.second + 1] != '.')
            {
                d.push_front(make_pair(cur.first, cur.second + 1));
                dist[cur.first][cur.second + 1] = dist[cur.first][cur.second];
                used[cur.first][cur.second + 1] = true;
            }
            else
            {
                d.push_back(make_pair(cur.first, cur.second + 1));
                dist[cur.first][cur.second + 1] = dist[cur.first][cur.second] + 1;
                used[cur.first][cur.second + 1] = true;
            }
        }
        if(cur.second - 1 >= 0 && graph[cur.first][cur.second - 1] != '#' && !used[cur.first][cur.second - 1])
        {
            if(graph[cur.first][cur.second - 1] != '.')
            {
                d.push_front(make_pair(cur.first, cur.second - 1));
                dist[cur.first][cur.second - 1] = dist[cur.first][cur.second];
                used[cur.first][cur.second - 1] = true;
            }
            else
            {
                d.push_back(make_pair(cur.first, cur.second - 1));
                dist[cur.first][cur.second - 1] = dist[cur.first][cur.second] + 1;
                used[cur.first][cur.second - 1] = true;
            }
        }
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char ** graph = new char *[n];
    int ** dist1 = new int*[n];
    int ** dist2 = new int*[n];
    int ** dist3 = new int*[n];
    for(int i = 0; i < n; i++)
    {
        graph[i] = new char[m];
        dist1[i] = new int[m];
        dist2[i] = new int[m];
        dist3[i] = new int[m];
    }
    pair<int, int> vertex1, vertex2, vertex3;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == '1')
            {
                vertex1.first = i;
                vertex2.second = j;
            }
            else if(graph[i][j] == '2')
            {
                vertex2.first = i;
                vertex2.second = j;
            }
            else if(graph[i][j] == '3')
            {
                vertex3.first = i;
                vertex3.second = j;
            }
        }
    }
    bool ** used = new bool *[n];
    for(int i = 0; i < n; i++)
        used[i] = new bool[m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            used[i][j] = false;
            dist1[i][j] = inf;
            dist3[i][j] = inf;
            dist2[i][j] = inf;
        }
    }
    bfs(graph, used, dist1, vertex1, n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            used[i][j] = false;
        }
    }
    bfs(graph, used, dist2, vertex2, n, m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            used[i][j] = false;
        }
    }
    bfs(graph, used, dist3, vertex3, n, m);
    int min = inf;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            min = (min > dist1[i][j] + dist2[i][j] + dist3[i][j])? dist1[i][j] + dist2[i][j] + dist3[i][j]: min;
        }
    }
    if(min == inf)
        cout << -1;
    else
        cout << min;

    return 0;
}
