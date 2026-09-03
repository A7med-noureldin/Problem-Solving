func uniformArray(nums1 []int) bool {
    // all odd || all even -> true
    // mix -> for every even num must exist an odd number before it & greater than it
    even, odd := true, true
    for _, val := range nums1{
        if val%2 != 0 {
            even = false
        } else {
            odd = false
        }
    }
    if even || odd{
        return true
    }
    mnOdd := math.MaxInt
    for i := 0; i < len(nums1); i++{
        if nums1[i]%2 != 0{
            mnOdd = min(mnOdd, nums1[i])
        }
    }
    fmt.Println(mnOdd)
    for i := 0; i < len(nums1); i++{
        if nums1[i]%2 != 0{
            continue
        }
        if nums1[i]-mnOdd < 1{
            return false
        }
    }

    return true
}