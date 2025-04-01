fn main() {
    let number = 5;
    if number < 10 {
        println!("the number is less than 10");
    } else if number == 10 {
        println!("the number is equal than 10");
    } else {
        println!("the number is grater than 10");
    }

    let coondition = true;

    let number = if coondition { 5 } else { 10 };
    println!("the value of number is {}", number);

    let mut counter = 0;
    let result = loop {
        counter += 1;
        if counter == 10 {
            break counter;
        }
    };

    println!("the counter is {}", result);

    let mut number = 3;

    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }

    println!("ending the loop");

    let arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

    for element in arr.iter() {
        println!("the value is {} ", element);
    }

    for element in 1..4 {
        println!("the value is {} ", element);
    }
}
