#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end());
        int res_shots = 0;
        int i = points.size() - 1;
        while (i >= 0) {
            int shot = points[i][0];
            res_shots++;
            while (i > 0 && points[i - 1][1] >= shot) {
                i--;
            }
            i--;
        }
        return res_shots;
    }
};

int main() {
    // Input array
    std::vector<std::vector<int>> points;

    // Read input line by line
    int n; // Number of points
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        points.push_back({x, y});
    }

    // Call the function with the input array
    int result = Solution::findMinArrowShots(points);

    // Output the result
    std::cout << result << std::endl;

    return 0;
}