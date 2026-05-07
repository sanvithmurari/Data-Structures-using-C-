#include <iostream>
using namespace std;

int graph[100][100];
int visited[100];
int queueArr[100];
int front = 0, rear = 0;
int n;


void DFSUtil(int vertex) {
    visited[vertex] = 1;
    cout << vertex << " ";

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFSUtil(i);
        }
    }
}

void DFS(int start) {

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFSUtil(start);
    cout << endl;
}


void BFS(int start) {

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }


    front = rear = 0;

    visited[start] = 1;
    queueArr[rear++] = start;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int current = queueArr[front++];
        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queueArr[rear++] = i;
            }
        }
    }

    cout << endl;
}


int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    DFS(start);
    BFS(start);

    return 0;
}