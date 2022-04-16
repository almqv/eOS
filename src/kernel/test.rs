#![no_std] 
#![no_main] 

extern "C" {
    fn println(text: &str);
}

fn rust_test() {
    unsafe {println("RUST!")};
}

fn main() {}
