fn inp_s() -> usize{
    let mut st = String::new();
    std::io::stdin().read_line(&mut st);
    st.trim().parse::<usize>().unwrap()
}

fn inp()-> (String,String){
    let mut st = String::new();
    std::io::stdin().read_line(&mut st);
    let mut it = st.split_whitespace();
    (it.next().unwrap().to_string(),it.next().unwrap().to_string())
}

fn calc_hash(s:&String,m:usize) -> usize{
    let p:u128 = 1000000007;
    let x:u128 = 263;
    let mut res:u128 = 0;
    let mut ctr = 0;
    for i in s.chars(){
        res+= (i as u128) * x.pow(ctr as u32);
        ctr+=1;
    }
    return ((res%p)%m as u128) as usize; 
}

fn find(s:&String,tab:&mut Vec<Vec<String>>,m:usize) -> (bool,usize,usize){
    let m = calc_hash(s, m);
    for i in 0..tab[m].len() as usize{
        if *s == tab[m][i]{
            return (true,m,i);
        }
    }
    return (false,m,0);
}

fn add(s:String,tab:&mut Vec<Vec<String>>,m:usize){
    let (t,t_i,l_i) = find(&s, tab, m);
    if !t{
        tab[t_i].push(s);
    }
}

fn rem(s:String,tab:&mut Vec<Vec<String>>,m:usize){
    let (t,t_i,l_i) = find(&s, tab, m);
    if t{
        tab[t_i][l_i] = "".to_string();
    }
}

fn check(tab:&mut Vec<Vec<String>>,m:usize){
    if tab[m].len() == 0{
        println!("")
    }
    else{
        for i in tab[m].iter().rev(){
            if i == ""{
                continue;
            }
            print!("{} ",i)
        }
        println!();
    }
}

fn main(){
    let m = inp_s();
    let n = inp_s();
    let mut tab:Vec<Vec<String>> = vec![Vec::new();m];

    for _ in 0..n{
        let (op,val) = inp();
        if op == "add"{
            add(val,&mut tab, m);
        }
        else if op == "check"{
            check(&mut tab, val.trim().parse::<usize>().unwrap());
        }
        else if op == "find"{
            if find(&val, &mut tab, m).0{println!("yes");}
            else {println!("no");}
            
        }
        else{
            rem(val, &mut tab, m);
        }
    }
}