class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        // If the new color is the same as the original, nothing changes.
        if (original == color) {
            return image;
        }

        fill(image, sr, sc, original, color);
        return image;
    }

private:
    void fill(vector<vector<int>>& image, int r, int c, int original, int color) {
        int rows = image.size();
        int cols = image[0].size();

        
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if (image[r][c] != original) {
            return;
        }

       
        image[r][c] = color;
        fill(image, r + 1, c, original, color); 
        fill(image, r - 1, c, original, color); 
        fill(image, r, c + 1, original, color); 
        fill(image, r, c - 1, original, color); 
    }
};