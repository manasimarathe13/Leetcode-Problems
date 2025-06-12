class Solution {
public:
    long getSteps(long curr, long n) {
        long steps = 0;
        long first = curr, last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  // we start with 1, so reduce k by 1

        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                curr++;      // move to next sibling
                k -= steps;  // skip entire subtree
            } else {
                curr *= 10;  // go to first child
                k--;         // move one step deeper
            }
        }
        return curr;
    }
};