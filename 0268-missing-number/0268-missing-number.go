func missingNumber(nums []int) int {
    n := len(nums)
    sum, tot := 0, n * (n+1)/2 

    for i := 0; i < n; i++{
        sum += nums[i]
    }
    return (tot-sum)
}