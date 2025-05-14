use std::env; // 用于获取命令行参数
use std::process; // 用于退出程序

// 函数：检查一个数字是否为素数
fn is_prime(n: u64) -> bool {
    // 素数定义：大于1的自然数
    if n <= 1 {
        return false;
    }
    // 2 是唯一的偶素数
    if n == 2 {
        return true;
    }
    // 所有大于2的偶数都不是素数
    if n % 2 == 0 {
        return false;
    }
    // 检查从 3 开始的所有奇数因子，直到该数的平方根
    // 我们可以检查 i*i <= n 来避免计算平方根
    let mut i = 3;
    while i * i <= n {
        if n % i == 0 {
            // 找到了一个因子，所以不是素数
            return false;
        }
        i += 2; // 只检查奇数
    }
    // 没有找到因子，所以是素数
    true
}

fn main() {
    // 获取命令行参数
    let args: Vec<String> = env::args().collect();

    // 检查是否提供了正确的参数数量
    if args.len() != 2 {
        eprintln!("用法: {} <整数>", args[0]); // args[0] 是程序名
        process::exit(1); // 退出程序并返回错误码
    }

    // 获取要检查的数字字符串
    let num_str = &args[1];

    // 尝试将字符串解析为无符号 64 位整数 (u64)
    let num: u64 = match num_str.parse() {
        Ok(num) => num, // 解析成功
        Err(_) => { // 解析失败
            eprintln!("错误: 请提供一个有效的整数。");
            process::exit(1);
        }
    };

    // 调用 is_prime 函数检查数字
    if is_prime(num) {
        println!("{} 是一个素数。", num);
    } else {
        println!("{} 不是一个素数。", num);
    }
}