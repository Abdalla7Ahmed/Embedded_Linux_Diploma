fn main() {
    // Integer
    let a: u8 = 50; // unsigned 8 bits
    let b: i8 = 10; // signed 8 bits
                    //let a2: u8 = 256; // error literal out of range for `u8

    let c: u16 = 50; // unsigned 16 bits
                     //let c2: u16 = -50; // error

    let d: i8 = 10; // signed 16 bits

    let e: u128 = 5000; // unsigned 128 bits

    let a1: u32 = 98_222; // decimal
    println!("{}", a1);

    let a1: u32 = 98_222; // decimal
    println!("{}", a1);

    let a2: u32 = 0xFFAA; // Hexadecimal
    println!("{:X}", a2); //:X  for printing the result as hexa

    let a3: u32 = 0o7720; // octa
    println!("{:o}", a3); //:o  for printing the result as octal

    let a4: u32 = 0b1111_0000_1010; // binary
    println!("{:b}", a4); //:b  for printing the result as binary

    let a5: u8 = b'A'; // character
    println!("{}", a5); //65
    println!("{}", a5 as char); //  A

    // Floating point number
    let b1: f32 = 2221_21.12;
    let b2: f64 = 2221_21.1234_0521_1234_7896;
    let b3 = 2221_21.1234_0521_1234_7896; // by default 64 bits
    println!("{}", b1); //222121.13
    println!("{}", b2); //222121.12340521123
    println!("{}", b3); //222121.12340521123

    // Boolean
    let c1: bool = true;
    let c2 = false;
    println!("{}", c1); //true
    println!("{}", c2); //true

    // Character
    let d1 = 'A';
    let d2: char = 'E';
    println!("{}", d1); //A
    println!("{}", d2); //E
    let emojy = '😂';
    let emojy2: char = '😊';

    println!("{}", emojy); //😂
    println!("{}", emojy2); //😊

    // Compund types
    //1-tup
    let point = (20, 50);
    // to handle the compund type we have two wayes (Destructuring , Dot Notation)
    let (pointx, pointy) = point;
    println!("{}", pointx);
    println!("{}", pointy);

    let pointx = point.0;
    let pointy = point.1;

    println!("{}", pointx);
    println!("{}", pointy);
    println!("============================================");

    // array
    let arr = [10, 20, 30, 40];
    println!("{}", arr[0]);
    println!("{}", arr[1]);
    println!("{}", arr[2]);
    println!("{}", arr[3]);
    // println!("{}", arr[4]);  //index out of bounds: the length is 4 but the index is 4
    println!("============================================");

    let arr2 = [10; 5]; // array of 5 elements has values (10,10,10,10,10)
    println!("{}", arr2[0]);
    println!("{}", arr2[1]);
    println!("{}", arr2[2]);
    println!("{}", arr2[3]);
    println!("{}", arr2[4]);
}
