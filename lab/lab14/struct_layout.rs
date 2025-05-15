use std::mem::{size_of_val, align_of_val};
use std::ptr; // 引入 ptr 模块用于指针操作

// Rust 默认的结构体布局 (优化后的布局)
struct RustStyle {
    a: u8,  // 1 BYTE
    b: u32, // 4 BYTES
    c: u16, // 2 BYTES
    d: f64, // 8 BYTES
}

// #[repr(C)] 结构体布局 (模拟 C 语言的布局，按成员声明顺序，考虑对齐)
#[repr(C)]
struct CStyle {
    a: u8,  // 1 BYTE
    b: u32, // 4 BYTES
    c: u16, // 2 BYTES
    d: f64, // 8 BYTES
}

// 修改后的 print_struct 函数
// 为了能够通过 T 访问成员 a, b, c, d，T 需要是 RustStyle 或 CStyle
// 但泛型 T 并不知道成员的名称。一种方法是让函数不泛型，或者使用不安全代码和偏移量。
// 鉴于任务是打印特定成员的地址，最简单且安全的方式是为这两个结构体分别实现打印逻辑，
// 或者使用宏，或者在调用时传递成员的引用。
// 根据截图原有的 print_struct 签名，它只打印大小和对齐。
// 为了打印成员地址，我们需要更具体的方式。
// 我们直接在 main 函数中或者一个辅助函数中完成打印成员地址的逻辑。

// 辅助函数来打印结构体及其成员信息
fn print_struct_details<T>(instance: &T, name: &str) {
    println!("\n=== {} Structure ===", name);
    println!("  Size: {} Bytes", size_of_val(instance));
    println!("  Align based on: {} Bytes", align_of_val(instance));

    // 注意：下面的成员地址打印需要知道 T 的具体类型
    // 由于我们在 main 中分别处理 RustStyle 和 CStyle，我们可以在 main 中完成这部分。
    // 或者修改函数签名，使其知道类型信息。
    // 考虑到截图中的 print_struct 设计，我们可能需要修改它或直接在 main 里打印。
    // 直接在 main 中打印成员地址更符合逐步完成任务的思路。
}

fn main() {
    let rust_struct = RustStyle { a: 1, b: 2, c: 3, d: 4.0 };
    let c_struct = CStyle { a: 1, b: 2, c: 3, d: 4.0 };

    // 打印 RustStyle 信息和成员地址
    print_struct_details(&rust_struct, "Rust optimized layout");
    println!("  Member addresses (relative to struct start):");
    unsafe {
        let base_ptr: *const RustStyle = &rust_struct;
        let base_addr = base_ptr as usize; // 结构体起始地址

        let a_ptr: *const u8 = &rust_struct.a;
        let a_addr = a_ptr as usize;
        println!("    a: {} (Offset: {})", a_addr, a_addr - base_addr);

        let b_ptr: *const u32 = &rust_struct.b;
        let b_addr = b_ptr as usize;
        println!("    b: {} (Offset: {})", b_addr, b_addr - base_addr);

        let c_ptr: *const u16 = &rust_struct.c;
        let c_addr = c_ptr as usize;
        println!("    c: {} (Offset: {})", c_addr, c_addr - base_addr);

        let d_ptr: *const f64 = &rust_struct.d;
        let d_addr = d_ptr as usize;
        println!("    d: {} (Offset: {})", d_addr, d_addr - base_addr);
    }


    // 打印 CStyle 信息和成员地址
    print_struct_details(&c_struct, "C layout");
     unsafe {
        let base_ptr: *const CStyle = &c_struct;
        let base_addr = base_ptr as usize; // 结构体起始地址

        let a_ptr: *const u8 = &c_struct.a;
        let a_addr = a_ptr as usize;
        println!("    a: {} (Offset: {})", a_addr, a_addr - base_addr);

        let b_ptr: *const u32 = &c_struct.b;
        let b_addr = b_ptr as usize;
        println!("    b: {} (Offset: {})", b_addr, b_addr - base_addr);

        let c_ptr: *const u16 = &c_struct.c;
        let c_addr = c_ptr as usize;
        println!("    c: {} (Offset: {})", c_addr, c_addr - base_addr);

        let d_ptr: *const f64 = &c_struct.d;
        let d_addr = d_ptr as usize;
        println!("    d: {} (Offset: {})", d_addr, d_addr - base_addr);
    }
}