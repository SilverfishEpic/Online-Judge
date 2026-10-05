#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace uva10908 {

class PrefixSumSolver {
 public:
  explicit PrefixSumSolver(const std::vector<std::string>& grid)
      : grid_(grid),
        rows_(static_cast<int>(grid.size())),
        cols_(rows_ == 0 ? 0 : static_cast<int>(grid[0].size())) {
    BuildCharacterIndex();
    BuildPrefixSums();
  }

  int LargestSquareSize(int row, int col) const {
    const char target = grid_[row][col];
    const int max_radius =
        std::min(std::min(row, rows_ - 1 - row),
                 std::min(col, cols_ - 1 - col));

    int left = 0;
    int right = max_radius;
    int best = 0;

    while (left <= right) {
      const int mid = left + (right - left) / 2;
      if (IsValidSquare(row, col, mid, target)) {
        best = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return 2 * best + 1;
  }

 private:
  void BuildCharacterIndex() {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        const char ch = grid_[i][j];
        if (char_to_index_.find(ch) == char_to_index_.end()) {
          const int next_index = static_cast<int>(unique_chars_.size());
          char_to_index_[ch] = next_index;
          unique_chars_.push_back(ch);
        }
      }
    }
  }

  void BuildPrefixSums() {
    const int kinds = static_cast<int>(unique_chars_.size());
    prefix_sums_.assign(
        kinds,
        std::vector<std::vector<int> >(
            rows_ + 1, std::vector<int>(cols_ + 1, 0)));

    for (int k = 0; k < kinds; ++k) {
      const char target = unique_chars_[k];
      for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
          prefix_sums_[k][i + 1][j + 1] =
              prefix_sums_[k][i][j + 1] +
              prefix_sums_[k][i + 1][j] -
              prefix_sums_[k][i][j] +
              (grid_[i][j] == target ? 1 : 0);
        }
      }
    }
  }

  int CountInRectangle(char target,
                       int top,
                       int left,
                       int bottom,
                       int right) const {
    const int index = char_to_index_.at(target);
    const std::vector<std::vector<int> >& prefix = prefix_sums_[index];

    return prefix[bottom + 1][right + 1]
         - prefix[top][right + 1]
         - prefix[bottom + 1][left]
         + prefix[top][left];
  }

  bool IsValidSquare(int row, int col, int radius, char target) const {
    const int top = row - radius;
    const int bottom = row + radius;
    const int left = col - radius;
    const int right = col + radius;

    const int side_length = 2 * radius + 1;
    const int area = side_length * side_length;

    return CountInRectangle(target, top, left, bottom, right) == area;
  }

  std::vector<std::string> grid_;
  int rows_;
  int cols_;

  std::vector<char> unique_chars_;
  std::unordered_map<char, int> char_to_index_;
  std::vector<std::vector<std::vector<int> > > prefix_sums_;
};

}  // namespace uva10908

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int test_case_count = 0;
  std::cin >> test_case_count;

  while (test_case_count-- > 0) {
    int rows = 0;
    int cols = 0;
    int query_count = 0;
    std::cin >> rows >> cols >> query_count;

    std::vector<std::string> grid(rows);
    for (int i = 0; i < rows; ++i) {
      std::cin >> grid[i];
    }

    uva10908::PrefixSumSolver solver(grid);

    std::cout << rows << ' ' << cols << ' ' << query_count << '\n';

    for (int i = 0; i < query_count; ++i) {
      int row = 0;
      int col = 0;
      std::cin >> row >> col;
      std::cout << solver.LargestSquareSize(row, col) << '\n';
    }
  }

  return 0;
}