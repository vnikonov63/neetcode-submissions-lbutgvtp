impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0; 
        let mut r = nums.len() as i32 - 1;

        while l <= r {
            let mid = (l + r) / 2;
            if nums[mid as usize] == target {
                return mid as i32;
            } else if nums[mid as usize] > target { 
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        -1
    }
}
