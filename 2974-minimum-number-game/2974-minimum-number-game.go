func numberGame(nums []int) []int {
    slices.Sort(nums)
    n := len(nums)
    for idx := 0; idx+1 < n; idx+=2{
        nums[idx], nums[idx+1] = nums[idx+1], nums[idx]
    }
    return nums
}