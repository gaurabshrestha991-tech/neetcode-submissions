class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while (left < right)
        {
            int width = right - left;

            int currentHeight = min(height[left], height[right]);

            int currentWater = width * currentHeight;

            if (currentWater > maxWater) {
                maxWater = currentWater;
            }

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;

    }
       
};
