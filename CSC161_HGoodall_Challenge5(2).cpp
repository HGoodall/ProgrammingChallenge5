#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

int Islands(vector<vector<int>> &map);
void Test();
void DepthFirst(vector<vector<int>> &map, int i, int j, int rows, int cols);


int main()
{
    Test();
}

void Test() {
    vector<vector<int>> map1 = { {0,0,1,1,0,0,0}, { 1,0,1,1,1,0,0 },{ 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0} };
    vector<vector<int>> map2 = { {0,0,1,0,0}, {0,0,1,0,1},{0,0,1,1,1}, {0,0,1,0,1} };
    vector<vector<int>> map3 = { {1,1,0,0,0,0,0}, { 1,1,0,0,0,0,0 },{ 0, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0}, { 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1} };
    vector<vector<int>> map4 = { {0,0,0,0,0}, {0,0,0,0,0},{0,0,0,0,0}, {0,0,0,0,0} };

    assert(Islands(map1) == 4);
    assert(Islands(map2) == 1);
    assert(Islands(map3) == 3);
    assert(Islands(map4) != 1);
    assert(Islands(map3) != 5);
    cout << "Tests successful!";
}

//time complexity = O(N*M)
int Islands(vector<vector<int>> &map) {

    int count = 0;
    int rows = map.size();
    int cols = map[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 1 ) {
                map[i][j] = 0;
                count += 1;
                DepthFirst(map, i + 1, j, rows, cols);
                DepthFirst(map, i - 1, j, rows, cols);
                DepthFirst(map, i, j + 1, rows, cols);
                DepthFirst(map, i, j - 1, rows, cols);
            }
        }
    }
    

    return count;

}

void DepthFirst(vector<vector<int>> &map, int i, int j, int rows, int cols) 
{
    if (i < 0 || j < 0 || i > (rows - 1) || j > (cols - 1) || map[i][j] != 1) {
        return;
    }
    if (map[i][j] == 1) {
        map[i][j] = 0;
        DepthFirst(map, i + 1, j, rows, cols);
        DepthFirst(map, i - 1, j, rows, cols);
        DepthFirst(map, i, j + 1, rows, cols);
        DepthFirst(map, i, j - 1, rows, cols);

    }

}



