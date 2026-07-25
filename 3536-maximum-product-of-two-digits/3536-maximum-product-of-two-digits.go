func maxProduct(n int) int {
    v := make([]int, 0)
    for n > 0{
        v = append(v, n%10)
        n /= 10
    }

    slices.Sort(v)
    n = len(v)
    return v[n-1]*v[n-2]
}