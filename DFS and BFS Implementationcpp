#include <iostream>
using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1},
    {0,1,0,0,0},
    {0,0,1,0,0}
};

bool visited[5];

// DFS
void DFS(int node) {
    cout << node << " ";
    visited[node] = true;

    for (int i = 0; i < 5; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start) {
    int queue[5], front = 0, rear = 0;

    for (int i = 0; i < 5; i++)
        visited[i] = false;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < 5; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

int main() {

    // DFS
    for (int i = 0; i < 5; i++)
        visited[i] = false;

    cout << "DFS: ";
    DFS(0);

    // BFS
    cout << "\nBFS: ";
    BFS(0);

    return 0;
}
