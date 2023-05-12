/*
Given 2 integers N, K, output the K-th permutation of N numbers. 

Input:

Two integers N, K

Output:

One line, the k-th permutation of N numbers

Sample Input

5 3

Sample Output

1 2 4 3 5
*/

#include<iostream>
#include<vector>

using namespace std;

int permutation_num = 0;

bool in(const vector<int>& line, int item) {
    for(int i = 0; i < line.size(); i ++) {
        if(line[i] == item) {
            return true;
        }
    }

    return false;
}

void print_vec(vector<int> line) {
    for(int i = 0; i < line.size(); i ++) {
        cout << line[i] << " ";
    }
    cout << endl;
}

bool reached = false;

void permutation(int n, int k, vector<int> *line, vector<bool>* used) {
    if(reached == true) {
        return;
    }

    if(line->size() == n) {
        permutation_num ++;
    }

    if(permutation_num == k) {
        for(int i = 0; i < n; i ++) {
            cout << (*line)[i] << " ";
        }
        cout << endl;

        reached = true;
        
        return;
    }

    for (int i = 0; i < used->size(); i++) {
        if ((*used)[i]) {
            continue;
        }

        (*used)[i] = true;
        line->push_back(i+1);  // 1 based
        permutation(n, k, line, used);
        line->pop_back();
        (*used)[i] = false;
    }
}

int main() {
    int n;
    int k;

    cin >> n >> k;

    vector<int> line;
    vector<bool> used;
    for (int i = 0; i < n; i++) {
        used.push_back(false);
    }

    permutation(n, k, &line, &used);
}
