// TimeComplexity -> O(n)
// Space Somplexity -> O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right = n-1;
        int sum =0, steps =0;

        while( steps < k=){
            if(cardPoints[left] > cardPoints[right]){
                sum = sum + cardPoints[left];
                left++;
            }else if(cardPoints[left] < cardPoints[right]){
                sum = sum + cardPoints[right];
                right--; 
            }
            else{
                sum = sum + cardPoints[left];
                left++;
                right--;
            }
            steps++;
        }
        return sum;
    }
};

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0;
        int right = n-1;
        int sum = 0, steps = 0;

        while (steps < k) {
            if (cardPoints[left] > cardPoints[right]) {
                sum += cardPoints[left];
                left++;
            } else {
                sum += cardPoints[right];
                right--;
            }
            steps++;
        }
        return sum;
    }
};


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        // Calculate the total of the last k cards
        for (int i = n - k; i < n; i++) {
            total += cardPoints[i];
        }

        int maxScore = total;

        // Slide the window from the end to the start
        for (int i = 0; i < k; i++) {
            total += cardPoints[i] - cardPoints[n - k + i];
            maxScore = max(maxScore, total);
        }

        return maxScore;
    }
};
