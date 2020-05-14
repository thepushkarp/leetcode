class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColour) {
        int rowSize = image.size();
        int colSize = image[0].size();
        int prevColour = image[sr][sc];
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        queue<pair<int, int>> pixelToColour;
        pixelToColour.push(make_pair(sr, sc));
        while(pixelToColour.size() > 0) {
            int r = pixelToColour.front().first;
            int c = pixelToColour.front().second;
            image[r][c] = newColour;
            visited[r][c] = 1;
            if (r > 0) {
                if (image[r-1][c] == prevColour and !visited[r-1][c]) {
                    pixelToColour.push(make_pair(r-1, c));
                }
            }
            if (r < rowSize - 1) {
                if (image[r+1][c] == prevColour and !visited[r+1][c]) {
                    pixelToColour.push(make_pair(r+1, c));
                }
            }
            if (c > 0) {
                if (image[r][c-1] == prevColour and !visited[r][c-1]) {
                    pixelToColour.push(make_pair(r, c-1));
                }
            }
            if (c < colSize  - 1) {
                if (image[r][c+1] == prevColour and !visited[r][c+1]) {
                    pixelToColour.push(make_pair(r, c+1));
                }
            }
            pixelToColour.pop();
        }
        return image;
    }
};
