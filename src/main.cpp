#include<iostream>
#include<map>
#include<vector>
using namespace std;

int practiceSet[9][9] = {
    {0, 0, 0, 7, 3, 6, 0, 5, 4},
    {4, 0, 3, 0, 8, 0, 0, 7, 2},
    {0, 8, 6, 0, 4, 5, 0, 0, 3},
    {8, 6, 0, 0, 0, 0, 2, 0, 5},
    {5, 9, 0, 4, 0, 0, 0, 0, 0},
    {2, 0, 0, 6, 0, 8, 9, 4, 0},
    {0, 0, 5, 0, 0, 4, 7, 2, 0},
    {9, 0, 2, 0, 0, 0, 4, 6, 0},
    {6, 0, 0, 9, 0, 0, 5, 0, 0}
};

int practiceSetSolution[9][9] = {
    {1, 2, 9, 7, 3, 6, 8, 5, 4},
    {4, 5, 3, 1, 8, 9, 6, 7, 2},
    {7, 8, 6, 2, 4, 5, 1, 9, 3},
    {8, 6, 4, 3, 9, 7, 2, 1, 5},
    {5, 9, 7, 4, 2, 1, 3, 8, 6},
    {2, 3, 1, 6, 5, 8, 9, 4, 7},
    {3, 1, 5, 8, 6, 4, 7, 2, 9},
    {9, 7, 2, 5, 1, 3, 4, 6, 8},
    {6, 4, 8, 9, 7, 2, 5, 3, 1}
};

bool rowIncludes(int row, int x, int s[9][9]) {
    for(int i = 0; i < 9; i++) {
        if(s[row][i] == x) return true;
    }
    return false;
}

bool colIncludes(int column, int x, int s[9][9]) {
    for(int i = 0; i < 9; i++) {
        if(s[i][column] == x) return true;
    }
    return false;
}

vector<int> removeX(vector<int> v, int x) {
    vector<int> res;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] != x) res.push_back(v[i]);
    }

    return res;
}

bool isComplete(int sudoku[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(sudoku[i][j] == 0) return false;
        }
    }
    return true;
}

class sudokuSolver {
    public:

        int sudoku[9][9];

        void solve(int sudoku[9][9]){
            map<string, vector<int>> candids;

            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {

                    string k = to_string(i) + to_string(j);

                    if(sudoku[i][j] == 0) {
                        candids.insert(k, {1, 2, 3, 4, 5, 6, 7, 8, 9});
                    }
                }
            }

            while(isComplete(sudoku) == false) {

                for(int i = 0; i < 9; i++) {
                    for(int j = 0; j < 9; j++) {
                        int cur = sudoku[i][j];
                        
                        if(cur == 0) {
                            string k = to_string(i) + to_string(j);

                            if(candids[k].size() > 1) {
                                for(int curC = 0; curC < candids[k].size(); curC++) {
                                    int curNum = candids[k][curC];

                                    if(rowIncludes(i, curNum, sudoku)) {
                                        candids[k] = removeX(candids[k], curNum);
                                    }

                                    if(colIncludes(j, curNum, sudoku)) {
                                        candids[k] = removeX(candids[k], curNum);
                                    }
                                }
                            } else {
                                sudoku[i][j] = candids[k][0];
                            }
                        }
                    }
                }
            }
        }

        sudokuSolver(int s[9][9]) {

            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    sudoku[i][j] = s[i][j];
                }
            }

        };
};

int main() {
    sudokuSolver x(practiceSet);
    return 0;
};