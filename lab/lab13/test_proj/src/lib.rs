pub fn lcm(a: u32, b: u32) -> u32 {
    if a == 0 || b == 0 {
        return 0; 
    }
    let gcd_val = gcd(a, b);
    let result = (a / gcd_val) * b;

    result
}

pub fn gcd(a: u32, b: u32) -> u32 {
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
        assert_eq!(lcm(1024, 2), 1024);
        assert_eq!(lcm(256, 2), 256);
        assert_eq!(lcm(256, 0), 0);
    }

    #[test]
    fn test_gcd() {
         assert_eq!(gcd(1, 4), 1);
         assert_eq!(gcd(8, 12), 4);
         assert_eq!(gcd(17, 17), 17);
         assert_eq!(gcd(255, 0), 255); // 测试 gcd(x, 0) = x
         assert_eq!(gcd(0, 128), 128); // 测试 gcd(0, x) = x
         assert_eq!(gcd(0, 0), 0); // 测试 gcd(0, 0) = 0
         assert_eq!(gcd(100, 200), 100);
    }
}