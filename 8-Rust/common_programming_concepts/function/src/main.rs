fn main() {
    my_function();
    pass_parameters(10, 20);

    println!("the sum value is {}", return1(10, 20));
    println!("the sum value is {}", return2(50, 20));
}

fn my_function() {
    println!("another function");
}

fn pass_parameters(x: i32, y: i32) {
    println!("the value of x is {}", x);
    println!("the value of y is {}", y);
}

fn return1(x: i32, y: i32) -> i32 {
    let sum = x + y;
    return sum;
}

fn return2(x: i32, y: i32) -> i32 {
    // let sum = x + y;
    // sum

    x + y
}
