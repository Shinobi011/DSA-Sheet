// Time Complexity -> O(n)
// Space Somplexity -> O(n)
class Solution {
private:
    
    vector<int> NextSmallerElement(vector<int> &arr_given, int size_given_array ){

        stack<int> nextStack;
        nextStack.push(-1);
        vector<int> ans(size_given_array);
        for (int i = size_given_array -1; i >= 0; i--)
        {
            int curr = arr_given[i];
            while (nextStack.top() != -1 && arr_given[nextStack.top()] >= curr)
            {
                nextStack.pop();
            }
            ans[i] = nextStack.top();
            nextStack.push(i);
        }
        return ans;
    }


    vector<int> prevSmallerElement(vector<int> &arr_given, int size_given_array){
        stack<int> prevStack;
        prevStack.push(-1);
        vector<int> ans(size_given_array);


        for (int i = 0; i < size_given_array; i++)
        {
            int curr = arr_given[i];
            while (prevStack.top() != -1 && arr_given[prevStack.top()] >= curr)
            {
                prevStack.pop();
            }
            ans[i] = prevStack.top();
            prevStack.push(i);
        }
        return ans;
    }


    
public:
    int LargestAreaHistogram(vector<int> &heights){
    int length_array = heights.size();

    vector<int> right(length_array);
    right = NextSmallerElement(heights, length_array);

    vector<int> left(length_array);
    left = prevSmallerElement(heights, length_array);

    int area = INT_MIN;
    for(int i =0; i<length_array; i++){
        int length = heights[i];

        if(right[i] == -1){
            right[i] = length_array; 
        }
        int width = right[i] - left[i] -1;
        int newArea = length * width;
        area = max(area, newArea);
    }
    return area;
}
    
    int largestRectangleArea(vector<int>& heights) {
        return LargestAreaHistogram(heights);
    }
};