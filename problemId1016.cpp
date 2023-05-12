#include<iostream>
#include<vector>

using namespace std;

int permutation_num = 0;

bool in(vector<int> line, int item) {
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

void permutation(int n, int k, vector<int> *line) {
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

	for(int i = 1; i <= n; i ++) {
		if(in((*line), i) == true) {
			continue;
		}
		(*line).push_back(i);

		permutation(n, k, line);

		(*line).pop_back();
	}
}

int main() {
	int n;
	int k;

	cin >> n >> k;

	vector<int> line;

	permutation(n, k, &line);
}


