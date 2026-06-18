#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct position {
    int lin, col;
};

int bfs() {
    return 0;
}

int main () {

    vector<string> table;
    string line;

    ifstream file("casos de teste/caso0.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            table.push_back(line);
        }
        file.close();
    } 
    else {
        cout << "nao abriu" << endl;
        return 1;
    }
    int knight_moves;
    
    if (knight_moves != -1) {
        cout << knight_moves << endl;
    } 
    else {
        cout << "-" << endl;
    }
    return 0;
}