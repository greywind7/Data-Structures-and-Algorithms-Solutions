use std::collections::*;

fn inp()-> (String,String,String){
    let mut st = String::new();
    std::io::stdin().read_line(&mut st);
    let mut it = st.split_whitespace();
    let a = it.next().unwrap().to_string();
    if a == "add"{
        return (a,it.next().unwrap().to_string(),it.next().unwrap().to_string());
    }
    (a,it.next().unwrap().to_string(),String::new())
}

fn main(){
    let mut st = String::new();
    std::io::stdin().read_line(&mut st);
    let n:i32 = st.trim().parse().unwrap();

    let mut table = HashMap::new();

    for _ in 0..n{
        let (a,b,c) = inp();
        if a == "add"{
            table.insert(b, c);
        }
        else if a == "find"{
            if let Some(val) = table.get(&b){
                println!("{}",val);
            }
            else{
                println!("not found");
            }
        }
        else{
            table.remove(&b);
        }
    }
}

