fn main() {
    // let x = 5;
    // println!("the value of x is {}", x);
    // x = 6;
    // println!("the value of x is {}", x); //cannot assign twice to immutable variable
    //  by default variables are immutable.

    let mut x = 5;
    println!("the value of x is {}", x);
    x = 6;
    println!("the value of x is {}", x);

    // const

    const MAX_POINTS: u32 = 100_000;
    println!("the value of MAX_POINTS is {}", MAX_POINTS);

    //shadowing
    let y = 5;
    println!("the value of x is {}", y);
    let y = y + 10;
    println!("the value of x is {}", y);
    let y = "six";
    println!("the value of x is {}", y);
}
