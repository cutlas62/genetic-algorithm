#include <cstdio>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

using namespace std;

vector<vector<uint8_t>> grid (9, vector<uint8_t>(9, 0));

void clearGrid (void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
        }
    }
}

void populateGrid (void) {
    ifstream inFile("in/example.txt");
    string tmp;
    int i = 0;
    while(getline(inFile, tmp)) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = (tmp[j] - '0');
        }
        i++;
    }
    inFile.close();
}

void printGrid (vector<vector<uint8_t>> &g) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << (uint)g[i][j] << " ";
        }
        cout << endl;
    }
}

bool validNumber (uint8_t curI, uint8_t curJ, uint8_t n) {
    // Check vertical line
    for (uint8_t j = 0; j < 9; j++) {
        if (grid[curI][j] == n) {
            return false;
        }
    }

    // Check horizontal line
    for (uint8_t i = 0; i < 9; i++) {
        if (grid[i][curJ] == n) {
            return false;
        }
    }

    // Check local 3x3 square
    uint8_t localI = curI / 3;
    uint8_t localJ = curJ / 3;
    for (uint8_t i = 0; i < 3; i++) {
        for(uint8_t j = 0; j < 3; j++) {
            if (grid[3 * localI + i][3 * localJ + j] == n) {
                return false;
            }
        }
    }

    // If all the previous tests passed, the number is valid
    return true;
}

uint32_t solveGrid (vector<vector<vector<uint8_t>>> &sol) {
    for (uint8_t i = 0; i < 9; i++) {
        for (uint8_t j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                for (uint8_t n = 1; n <= 9; n++) {
                    if (validNumber(i, j, n)) {
                        grid[i][j] = n;
                        solveGrid(sol);
                        grid[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }

    sol.push_back(grid);
    return sol.size();
}

int main() {
    clearGrid();
    populateGrid();
    printGrid(grid);

    cout << endl << "Solving it..." << endl;

    vector<vector<vector<uint8_t>>> solutions;
    solveGrid(solutions);

    cout << "Found " << solutions.size() << " solutions:" << endl;
    for (vector<vector<uint8_t>> curGrid : solutions){
    	printGrid(curGrid);
    	cout << endl;
    }

    return 0;
}