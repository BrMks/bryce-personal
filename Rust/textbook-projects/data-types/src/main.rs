use std::io;

fn main() {
    let var: u32 = "42".parse().expect("Not a Number!");
    println!("{var}");

    //--// Floating Point
    let x = 2.0;
    let y: f32 = 3.0;
    println!("{x}, {y}");

    //--// Bool
    let mut z: bool = false;
    if 3 > 2 {
        z = true;
    }
    println!("{z}");

    //--//chars
    let c = 'z';
    let d: char = 'Z';
    let heart_eyed_cat = '😻'; //can handle non-ASCII chars
    println!("{c}, {d}, {heart_eyed_cat}");

    //--// tups combines multiple types
    let tup = (500,6.4,1);
    let (x,y,z) = tup;

    println!("Ther value of x,y,z is: {x},{y},{z}");

    //--// Arrays: have to have the same times constant
    let a = [1,2,3,4,5];
    println!("{}", a[0]);

    //--// textbook code

    println!("Please enter an array index.");

    let mut index = String::new();

    io::stdin()
        .read_line(&mut index)
        .expect("Failed to read line");

    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not a number");

    let element = a[index];

    println!("The value of the element at index {index} is: {element}");

}
