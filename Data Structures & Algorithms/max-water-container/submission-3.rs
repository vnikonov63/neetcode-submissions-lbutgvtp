impl Solution {
    pub fn max_area(heights: Vec<i32>) -> i32 {
        let mut r = heights.len() as i32 - 1;
        let mut l = 0;
        let mut result = 0;
        while l < r {
            result = result.max(heights[l as usize].min(heights[r as usize]) * (r - l));
            if heights[l as usize] < heights[r as usize] {
                l += 1;
            } else {
                r -= 1;
            }
        }
        return result;
    }
}
