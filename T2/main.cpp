#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct position {
    int lin, col;
};

int l[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int c[] = {-1,  1, -2,  2, -2,  2, -1,  1};

int bfs(const vector<string>& table, position start) {
    int num_lin = table.size();
    int num_col = table[0].size(); 
    
    vector<vector<int>> dist(num_lin, vector<int>(num_col, -1));
    queue<position> q; 
    
    q.push(start);
    dist[start.lin][start.col] = 0;
    
    while (!q.empty()) {
        position current = q.front(); 
        q.pop();                   
        
        if (table[current.lin][current.col] == 'S') {
            return dist[current.lin][current.col];
        }
        
        for (int i = 0; i < 8; i++) {
            int next_lin = (current.lin + l[i] + num_lin) % num_lin;
            int next_col = (current.col + c[i] + num_col) % num_col;
            
            if (table[next_lin][next_col] != 'x' && dist[next_lin][next_col] == -1) {
                dist[next_lin][next_col] = dist[current.lin][current.col] + 1;
                q.push({next_lin, next_col});
            }
        }
    }
    return -1; 
}

int main () {
    vector<string> table;
    string line;

    ifstream file("casos de teste/caso0.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            table.push_back(line);
        }
    } 
    else {
        cout << "nao abriu" << endl;
        return 1;
    }

    position start = {-1, -1};
    if (start.lin == -1 || start.col == -1) {
        cout << "-" << endl;
        return 1;
    }

    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == 'C') {
                start.lin = i;
                start.col = j;
            }
        }
    }
    
    int knight_moves = bfs(table, start);
    
    if (knight_moves != -1) {
        cout << knight_moves << endl;
    } 
    else {
        cout << "-" << endl;
    }
    return 0;
}