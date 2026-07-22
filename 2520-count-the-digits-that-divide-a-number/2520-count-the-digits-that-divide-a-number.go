func countDigits(num int) int {
    cnt, tmp := 0, num
    for tmp > 0{
        d := tmp%10
        tmp /= 10
        if num%d == 0{
            cnt++
        }
    }  
    return cnt
}