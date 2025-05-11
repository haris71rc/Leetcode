import java.util.*;
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        int majority = 0;
        for(int i=0;i<nums.length;i++){
            map.put(nums[i], map.getOrDefault(nums[i],0)+1);
            majority = Math.max(majority,map.get(nums[i]));
            System.out.println(map.get(nums[i]));
        }
       for(Map.Entry<Integer,Integer> entry:map.entrySet()){
        if(entry.getValue().equals(majority)){
            return entry.getKey();
        }
       }
       return 0;
    }
}