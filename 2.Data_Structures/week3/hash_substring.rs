fn inp_s() -> String{
    let mut st = String::new();
    std::io::stdin().read_line(&mut st);
    st.trim().to_string()
}

fn calc_hash(s:&Vec<char>,m:usize) -> usize{
    let p:u128 = 1000000007;
    let x:u128 = 263;
    let mut res:u128 = 0;
    let mut ctr = 0;
    for i in s.iter(){
        res+= (*i as u128) * x.pow(ctr as u32);
        ctr+=1;
    }
    return ((res%p)%m as u128) as usize; 
}

fn main(){
    let sub = inp_s().chars().collect();
    let st:Vec<char> = inp_s().chars().collect();
    let dhash = calc_hash(&sub,12345678);

    for i in 0..(st.len()-sub.len()+1) {
        let tmp = &st[i..(i+sub.len())].to_vec();
        if dhash == calc_hash(&tmp, 12345678){
            let mut tr = true;
            for(i,j) in sub.iter().zip(tmp.iter()){
                if i == j{
                    continue;
                }
                else {
                    tr = false;
                    break;
                }
            }
            if tr{
                print!("{} ",i);
            }
        }
    }
}