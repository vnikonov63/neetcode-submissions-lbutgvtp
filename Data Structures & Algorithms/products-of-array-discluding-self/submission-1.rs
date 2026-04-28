impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let l = nums.len();
        let mut prefix = vec![1; l];
        let mut suffix = vec![1; l];
        let mut result = vec![1; l];

        for i in 1..l {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for i in (0..=l-2).rev() {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for i in 0..l {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
}
