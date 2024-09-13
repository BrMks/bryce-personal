fn main() {
    let s1 = String::from("String");
    let s2 = s1.clone();
    //cannot do `let s2 = s1;` This would result in a `double free` of memory.

    println!("s1 = {s1}, s2 = {s2}");


    //you have to do this for strings but not for numbers:

    let num1 = 2;
    let num2 = num1;
    println!("num1 = {num1}, num2 = {num2}");
}
