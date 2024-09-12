fn main() {
    println!("Hello, world!");

    another_function(5, 'h');

    //--// Statements (no ret) vs Expressions (will ret a val)
    let y = 6; //statement
    //thus, you cannot do this `let x = (let y: i32 = 6)` bc `let y: i32 = 6` doesn't return anything
    let z = {
        let x = 3;
        x + 1
    };
    println!{"{y},{z}"}

    //--// executing a function that returns something
    let a = five();

    println!("The value of a is {a}");
}

//--// example non-main function
fn another_function(x: i32, unit_label: char) {
    println!("This is another function!\nIt has a passed through value of {x}{unit_label}");
}

//--// ex fn with ret val
fn five() -> i32 {
    5
}

