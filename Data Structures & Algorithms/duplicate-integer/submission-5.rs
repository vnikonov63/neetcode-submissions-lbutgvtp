impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut hash_set = HashSet::new();
        !nums.into_iter().all(|num| hash_set.insert(num))
    }
}
