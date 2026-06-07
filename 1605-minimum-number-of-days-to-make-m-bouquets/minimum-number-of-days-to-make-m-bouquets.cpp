class Solution {
private:
    int bouquetMade(vector<int>& bloomDay, int k, int day) {
        int count = 0, bouquet = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {   // flower has bloomed by 'day'
                count++;

                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquet;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k)
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (bouquetMade(bloomDay, k, mid) >= m) {
                ans = mid;          // valid day
                high = mid - 1;    // try to find a smaller valid day
            } else {
                low = mid + 1;     // need more days
            }
        }

        return ans;
    }
};