class Solution {
public:
    int maxArea(vector<int>& height) {
        int currWater=0;
        int maxWater=0;
        int n = height.size();

        int Lheight=0;
        int Rheight=n-1;

        while(Lheight < Rheight) {
            int width = Rheight - Lheight;
            int length = min(height[Rheight], height[Lheight]);
            currWater = length*width;

            maxWater = max(maxWater, currWater);

            if(height[Lheight] > height[Rheight]) {
                Rheight--;
            }
            else{
                Lheight++;
            }
        }
        return maxWater;
    }
};