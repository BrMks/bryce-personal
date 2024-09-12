use std::io;
fn main() {
    loop {
        println!("Enter integer (enter 5 to end program):");
        let mut input = String::new();

        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line!");

        let input: u32 = match input.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        if input == 5 {
            println!("Congrats!");
            break
        }
        else {
            println!("Oops");
        }
    }
    //--//
    let mut count = 0;
    'counting_up: loop {
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("End count = {count}");

    //--// For loops are like python:
    let a = [10, 20, 30, 40, 50];

    for element in a {
        println!("the value is: {element}");
    }
    println!("LIFTOFF!!!");

    for number in (1..=20).rev() {
        println!("{number}!");
    }
    println!("LIFTOFF!!!");
}
