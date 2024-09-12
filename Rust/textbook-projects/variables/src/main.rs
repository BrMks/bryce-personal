fn main() {
    let mut x = 5;
    println!("The value of x is: {}", x);
    x=6;
    println!("The value of x is: {x}");

    //--//

    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;
    println!("The value of 3 hours in seconds is {THREE_HOURS_IN_SECONDS}");

    //--//
    
    let y = 5;
    println!{"Stage 1 (mut not used): y = {y}"};

    let y = y + 1;
    println!{"Stage 2 (mut not used): y = {y}"};

    { //scope
        let y = y * 2;
        println!("Stage 3 (scoped) The value of y in the inner scope is: {y}");
    }

    println!("The value of y is {y}");

    //--//
    
    let spaces = "   ";
    println!("spaces: \'{spaces}\'");
    let spaces = spaces.len();
    println!("spaces: {spaces}");

    //--//

    //Cmt for no warning/ let mut spaces2 = "   ";
    //doesn't work: //spaces = spaces.len();

}
