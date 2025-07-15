#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
    cout << "=== TSP MENGGUNAKAN GREEDY ALGORITHM (NEAREST NEIGHBOR) ===" << endl;
    cout << "NIM: 23533780 (angka 0 diganti dengan 11)" << endl;
    cout << "Graf berdasarkan gambar dalam soal" << endl << endl;
    
    int n = 7; 
    char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
        
    vector<vector<int>> graph = {
        
        {0,  2, 11, 0, 3,  0, 0},
        {2,  0, 5,  3, 0,  0, 0}, 
        {11, 5, 0,  0, 0,  7, 0}, 
        {0,  3, 0,  0, 0,  8, 3}, 
        {3,  0, 0,  0, 0,  0, 11}, 
        {0,  0, 7,  8, 0,  0, 0}, 
        {0,  0, 0,  3, 11, 0, 0}  
    };
    
    cout << "Adjacency Matrix:" << endl;
    cout << "   ";
    for (int i = 0; i < n; i++) {
        cout << setw(3) << vertices[i];
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << vertices[i] << ": ";
        for (int j = 0; j < n; j++) {
            cout << setw(3) << graph[i][j];
        }
        cout << endl;
    }
    cout << endl;
   
 
    int start = 0;
    vector<bool> visited(n, false);
    vector<int> path;
    int totalCost = 0;
    int current = start;
    
    path.push_back(current);
    visited[current] = true;
    
    cout << "Proses Nearest Neighbor Algorithm:" << endl;
    cout << "===================================" << endl;
    cout << "Mulai dari vertex " << vertices[start] << endl;
    
    for (int step = 0; step < n - 1; step++) {
        int nearest = -1;
        int minCost = INT_MAX;
        
        cout << "\nLangkah " << (step + 1) << ":" << endl;
        cout << "Dari vertex " << vertices[current] << ", cari tetangga terdekat:" << endl;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] > 0) {
                cout << "  Ke " << vertices[i] << " dengan cost " << graph[current][i] << endl;
                if (graph[current][i] < minCost) {
                    minCost = graph[current][i];
                    nearest = i;
                }
            }
        }
        
        if (nearest != -1) {
            cout << "Pilih vertex " << vertices[nearest] << " dengan cost " << minCost << endl;
            path.push_back(nearest);
            visited[nearest] = true;
            totalCost += minCost;
            current = nearest;
        }
    }
    
    if (graph[current][start] > 0) {
        cout << "\nKembali ke vertex " << vertices[start] << " dengan cost " << graph[current][start] << endl;
        path.push_back(start);
        totalCost += graph[current][start];
    }
    
    cout << "\nHASIL AKHIR:" << endl;
    cout << "============" << endl;
    cout << "Path yang dilalui: ";
    for (int i = 0; i < path.size(); i++) {
        cout << vertices[path[i]];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
    cout << "Total cost: " << totalCost << endl;
    
    cout << "\nCatatan: Ini adalah solusi greedy yang tidak selalu optimal." << endl;
    cout << "Untuk TSP, solusi optimal memerlukan algoritma yang lebih kompleks." << endl;
    
    return 0;
}
