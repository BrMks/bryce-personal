use std::io; //C++ equiv: #include <stdio.h>
use std::cmp::Ordering;
use rand::Rng;

fn main() { //self-explainatory
    println!("Guess the number!");//self-explainatory

    let secret_number = rand::thread_rng().gen_range(1..=100); //syntax for this in words is `1 to 100`
    //thread_rng is seeded by CPU, gen_range is self-explanatory

    //println!("The secret number is: {secret_number}");

    loop  {    println!("Please input your guess.");//self-explainatory


            let mut guess = String::new();
            io::stdin()
                .read_line(&mut guess)
                .expect("Failed to read line");

            let guess: u32 = match guess.trim().parse() {
                Ok(num) => num,
                Err(_) => continue,
            };
            println!("You guessed: {guess}");

            match guess.cmp(&secret_number) {
                Ordering::Less => println!("Too small!"),
                Ordering::Greater => println!("Too big!"),
                Ordering::Equal => {
                    println!("You win!");
                    break; //same as C++
                }
            }
        }
    
//
//    let mut guess = String::new(); // `let` initializes a variabel, then `mut` allows it to be mutable (able to be changed later)
//    //created a mutable variable that is bound to a new, empty instance of a `String`
//    //^^ the `::` means that `new` is an associated funciton of `String`
//    
//    io::stdin()
//        .read_line(&mut guess) //uses references (code safety)
//        //returns `Result` enum, which if it returns `Err` and not `Ok`, it will trigger the `.expect` line.
//        .expect("Failed to read line");
//    //could be written as:
//    /*
//     io::stdin().readline(&mut guess).expect("Failed to Read Line.")
//     */
//
//    println!("You guessed: {}", guess); // the `{}` is how variables are put into text lines (like %x in C)
//
//    match guess.cmp(&secret_number) {
//        Ordering::Less => println!{"Too small!"}
//        Ordering::Greater => printly!("Too Big")
//        Ordering::Equal => println!("You Win!")
//    }
}