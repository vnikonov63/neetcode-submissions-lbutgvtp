impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut my_map: HashMap<i32, i32> = HashMap::new();
        for (i, num) in nums.into_iter().enumerate() {
            let desired_complement = target - num;
            if let Some(&idx) = my_map.get(&desired_complement) {
                return vec![idx, i as i32]
            }
            my_map.insert(num, i as i32);
        }
        vec![-1, -1]
    }
}
