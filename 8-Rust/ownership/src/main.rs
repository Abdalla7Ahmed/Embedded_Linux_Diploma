fn main() {
    let s = String::from("hello");

    let len = s.len();

    let slice = &s[0..len];
    println!("{slice}");

    let slice = first_word(&s);

    println!("{slice}");
}

fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}
