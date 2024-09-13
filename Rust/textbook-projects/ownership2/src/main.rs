
fn main() {
    let s1 = "Hello"; //`string literal` hardcoded into the code's text
    let s2 = String::from("Hello");  //will store on heap: unknown number of chars at compile time
    //the `::from("")` function converts a string literal into a string
    println!("s1 = {s1}, s2 = {s2}");

    //More practically, s1 and s2 are immutable
    //HOWEVER, s_mut as follows will be mutable (string literals can never be mutable)
    let mut s_mut= String::from("Hello");
    println!("s_mut (before): {s_mut}");
    s_mut.push_str(", world!");
    println!("s_mut (after): {s_mut}");

    //--// Rust's dynamic memory allocation is different
    // No need to `free` memory, it will do that automatically when you exit a scope!
    //This is called the 'drop' function
    {
        let s = String::from("hello"); // s is valid from this point forward

        // do stuff with s
        println!("S (scoped and after this line, dropped): {s}");
    }                                  // this scope is now over, and s is no
                                       // longer valid 
    

    //--// better understanding stack and heap stuff:

    let x = 5;
    let y = x;
        //will push two 5's onto the stack since they have a fixed, immutable size (32 bits)
    println!("x: {x}, y: {y}");

    let a = String::from("Test!");
    let b = a;
    // after `let b = a`, a is now REMOVED FROM THE SCOPE
        //this is to avoid a double free (a and b would point to the same address in memory)
        //this does NOT copy the heap data
    
    //println!("a: {a}"); //this will not work
    println!("b: {b}"); //this will work

    let c = String::from("Test2!");
    let d = c.clone(); 
        //c and d stay valid and in scope, as the `clone()` function will COPY THE HEAP
    
    println!("c: {c}, d: {d}");


    // -- //

    for i in 1..=3 {
        println!();
        if i == 2 {
            println!("Functions and Ownership:");
        }
    }

    //--//

    let str = String::from("hello");
    takes_ownership(str); //because of this funciton, `str` moves out of scope and cannot be used again in this scope

    let num = 5;
    copy_num(num); // because num is i32, you can still use `num` after this!

    //--// Return Values and Scope

    for i in 1..=3 {
        println!();
        if i == 2 {
            println!("Return Values and Scope: ");
        }
    }

    //--//

    let _s1 = gives_ownership(); //_s1 will inherit the ownership of `yours` through this fn
    let _s2 = String::from("hello"); //_s2 into scope
    let _s3 = takes_and_gives(_s2); //will take ownership from _s2 and give it to _s3
    
    println!("_s1 = {_s1}, _s3 = {_s3}");
    println!("_s2's ownership was taken away and thus, it was dropped by Rust.");
    // _s2 is now out of scope
    // _s1 and _s3 are still in scope and are valid

    let (_s4, len) = cal_len(_s1);
    println!("The length of _s1 ({_s4}), is {len}");

    println!("_s1's ownership was given to _s4 through the function, cal_len(), so it can no longer be printed using that variable.");

} //_s1 and _s3 will be dropped here

fn cal_len(s: String) -> (String, usize) {
    let length = s.len();
    (s, length)
}

fn takes_and_gives(a_string: String) -> String { // a_string comes into
    // scope

a_string  // a_string is returned and moves out to the calling function
}

fn gives_ownership() -> String {
    let some_string = String::from("yours");
    some_string
}

fn takes_ownership(some_string: String) {
    println!("fn(takes_ownership): {some_string}");
}

fn copy_num(some_int: i32) {
    println!("fn(copy_num): {some_int}");
}