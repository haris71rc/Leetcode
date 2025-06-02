class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> set = new HashSet<>();
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < nums.length-1; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            while(j<k){
if (nums[i] + nums[j] + nums[k] < 0) {
                j++;
            } else if (nums[i] + nums[j] + nums[k] > 0) {
                k--;
            } else {

                List<Integer> triplet = new ArrayList<>();
                triplet.add(nums[i]);
                triplet.add(nums[j]);
                triplet.add(nums[k]);
                set.add(triplet);

                j++;
                k--;
            }
            }
            
        }

        for (List<Integer> value : set) {
            ans.add(value);
        }

        return ans;
    }
}