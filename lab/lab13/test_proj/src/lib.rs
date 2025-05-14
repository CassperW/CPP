pub fn lcm(a: u8, b: u8) -> u16 { // 返回 u16
    if a == 0 || b == 0 {
        return 0;
    }
    let gcd_val = gcd(a, b);
    // 使用 u32 或 u16 进行中间计算
    let result = (a as u16 / gcd_val as u16) * (b as u16);
    // 直接返回 u16 结果
    result
}

// gcd 函数保持不变，因为它只处理 u8 输入并返回 u8 结果，欧几里得算法在此范围内是安全的
pub fn gcd(a: u8, b: u8) -> u8 {
    let mut a = a;
    let mut b = b;
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_lcm() {
        assert_eq!(lcm(1, 4), 4);
        assert_eq!(lcm(8, 9), 72);
        assert_eq!(lcm(8, 16), 16);
        // assert_eq!(lcm(1024, 1024), 1024); // 这一行会导致错误
        // 替换为使用 u8 范围内的值进行测试
        assert_eq!(lcm(100, 100), 100);
        assert_eq!(lcm(255, 1), 255);
        assert_eq!(lcm(20, 30), 60); // 20 和 30 的 lcm 是 60，都在 u8 范围内
        // assert_eq!(lcm(256, 2), 256); // 256 超出 u8 范围
        // assert_eq!(lcm(256, 0), 0); // 256 超出 u8 范围
        // 添加 lcm(x, 0) = 0 的测试 (使用 u8 范围内的值)
        assert_eq!(lcm(100, 0), 0);
        assert_eq!(lcm(0, 50), 0);
        assert_eq!(lcm(0, 0), 0);
    }

    #[test]
    fn test_gcd() {
         assert_eq!(gcd(1, 4), 1);
         assert_eq!(gcd(8, 12), 4);
         assert_eq!(gcd(17, 17), 17);
         // assert_eq!(gcd(256, 0), 256); // 这一行会导致错误
         // 替换为使用 u8 范围内的值进行测试
         assert_eq!(gcd(255, 0), 255); // 测试 gcd(x, 0) = x
         assert_eq!(gcd(0, 128), 128); // 测试 gcd(0, x) = x
         assert_eq!(gcd(0, 0), 0); // 测试 gcd(0, 0) = 0
         assert_eq!(gcd(100, 200), 100);
    }
}