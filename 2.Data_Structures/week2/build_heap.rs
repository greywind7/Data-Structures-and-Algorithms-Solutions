#[derive(Debug)]
struct pair(usize,usize);

fn main(){
  let mut s = String::new();
  std::io::stdin().read_line(&mut s);
  let n:usize = s.trim().parse().unwrap();
  let mut arr:Vec<i32> = Vec::new();
  let mut swp:Vec<pair> = Vec::new();
  inp(&mut arr);
  let mut swaps = 0;
  let hal = n/2;
  for i in (0..hal+1).rev(){
    sift_down(&mut arr, i, &mut swaps,&mut swp);
  }
  // sift_down(&mut arr, 0, &mut swaps,&mut swp);
  println!("{}",swaps);
  for i in swp.iter(){
    println!("{} {}", i.0,i.1)
  }
}

fn inp(arr:&mut Vec<i32>){
  let mut s = String::new();
  std::io::stdin().read_line(&mut s);
  let it = s.split_whitespace();
  for i in it{
    arr.push(i.parse().unwrap());
  }
}

fn sift_down(arr:&mut Vec<i32>,ind:usize,s:&mut i32,swp:&mut Vec<pair>){
  let mut ch = 0;
  let mut rep = arr.len() +1;
  let a = if 2*ind + 1 < arr.len(){
    ch+=1;
    2*ind + 1
  }
  else{arr.len() + 1};
  
  let b = if 2*ind + 2 < arr.len(){
    ch+=1;
    2*ind + 2
  }
  else{arr.len() + 1};

  if ch == 0{
    return;
  }
  else if ch == 1{
    if a > arr.len(){rep = b;}
    else{rep = a;}
  }
  else{
    if arr[a] < arr[b]{rep = a;}
    else{rep = b;}
  }

  if arr[ind] > arr[rep]{
    let t = arr[ind];
    arr[ind] = arr[rep];
    arr[rep] = t;
    *s+=1;
    swp.push(pair(ind,rep));
    sift_down(arr,rep,s,swp)
  }
}