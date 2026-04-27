impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut my_map: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            if let Some((complement, idx)) = my_map.get_key_value(&(target - nums[i])) {
                return vec![*idx, i as i32]
            }
            my_map.insert(nums[i], i as i32);
        }        
        vec![-1, -1]
    }
}
