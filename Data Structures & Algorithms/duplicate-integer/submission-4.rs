impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut my_set: HashSet<i32> = HashSet::new();
        for num in nums {
            if my_set.contains(&num) {
                return true;
            }
            my_set.insert(num);
        }
        false
    }
}
