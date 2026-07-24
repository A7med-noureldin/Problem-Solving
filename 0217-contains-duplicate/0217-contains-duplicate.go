func containsDuplicate(nums []int) bool {
    mp := make(map[int]int)
    for _, x := range nums{
        mp[x]++
        if mp[x] > 1{
            return true
        }
    }
    return false
}