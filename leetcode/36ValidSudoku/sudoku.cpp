#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Solution {
public:
    int BOARD_WIDTH = 9;
    int BOARD_HEIGHT = 9;
    char EMPTY = '.';

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> cols;
        std::unordered_map<int, std::unordered_set<char>> boxes;

        for (int row = 0; row < this->BOARD_HEIGHT; row++) {
            for (int col = 0; col < this->BOARD_WIDTH; col++) {
                char currentVal = board[row][col];
                if (currentVal == this->EMPTY) {
                    continue;
                }

                int boxId = row / 3 * 10 + col / 3;
                if ((rows[row].find(currentVal) != rows[row].end()) ||
                    (cols[col].find(currentVal) != cols[col].end()) ||
                    (boxes[boxId].find(currentVal) != boxes[boxId].end())
                    ) {
                    return false;
                }
                rows[row].insert(currentVal);
                cols[col].insert(currentVal);
                boxes[boxId].insert(currentVal);
            }
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();
    std::vector<std::vector<char>> input = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
    std::cout << (sol.isValidSudoku(input) ? "true" : "false") << std::endl;
}