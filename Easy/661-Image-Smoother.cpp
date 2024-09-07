class Solution {
public:
    // Function to compute average of neighbors for each cell
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        // Result matrix initialized with zeros
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        // Iterate through each cell in the image
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int sum = 0;
                int count = 0;

                // Iterate through the 3x3 grid centered at (i, j)
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;

                        // Check if the neighboring cell (ni, nj) is within bounds
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                            sum += img[ni][nj];
                            count++;
                        }
                    }
                }

                // Store the floored average in the result matrix
                result[i][j] = floor(sum / count);
            }
        }

        return result;
    }
};
