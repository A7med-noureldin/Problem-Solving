func maximumProduct(nums []int) int {
    slices.Sort(nums)
    n := len(nums)
    return int(math.Max(float64(nums[0]*nums[1]*nums[len(nums)-1]), float64(nums[n-1]*nums[n-2]*nums[n-3])))
}