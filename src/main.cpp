#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

class hMap {
    public:
        vector<string> keys;
        vector<int> values[18];

        int hashFunc(string s) {
            int vone = (int)s[0];
            int vtwo = (int)s[1];

            int d = vtwo - vone;

            if(d < 0) d = d * -2;

            return d;
        }

        vector<int> get(string k) {
            return values[hashFunc(k)];
        }

        void add(string k, vector<int> v) {
            keys.push_back(k);
            values[hashFunc(k)] = v; 
        }

        hMap() {

        }
};

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

        void solve(int maxCycles){
            hMap dic;

            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {

                    string k = to_string(i) + to_string(j);

                    if(sudoku[i][j] == 0) {
                        dic.add(k, {1, 2, 3, 4, 5, 6, 7, 8, 9});
                    }
                }
            }

            int cycles = 0;

            while(isComplete(sudoku) == false && cycles <= maxCycles) {

                for(int i = 0; i < 9; i++) {
                    for(int j = 0; j < 9; j++) {
                        int cur = sudoku[i][j];
                        
                        if(cur == 0) {
                            string k = to_string(i) + to_string(j);

                            if(dic.get(k).size() > 1) {
                                for(int curC = 0; curC < dic.get(k).size(); curC++) {
                                    int curNum = dic.get(k)[curC];

                                    if(rowIncludes(i, curNum, sudoku)) {

                                    }

                                    if(colIncludes(j, curNum, sudoku)) {

                                    }
                                }
                            } else {
                                sudoku[i][j] = dic.get(k)[0];
                            }
                        }
                    }
                }
                cycles++;
            }
        }

        string toAscii() {
            string result = "";

            for(int i = 0; i < 9; i++) {

                string curLine = "";

                for(int j = 0; j < 9; j++) {
                    curLine += to_string(sudoku[i][j]);
                    curLine += " "; 
                }

                result += curLine;
                result += "\n";
            }

            return result;
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
    x.solve(2);

    std::cout << "Solved sudoku: \n";
    std::cout << x.toAscii();

    return 0;
};