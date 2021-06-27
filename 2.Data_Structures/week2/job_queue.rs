use std::collections::*;

#[derive(Debug)]
struct pair(i32,i32);

fn inp(arr:&mut VecDeque<i32>){
  let mut s = String::new();
  std::io::stdin().read_line(&mut s);
  let it = s.split_whitespace();
  for i in it{
    arr.push_back(i.parse().unwrap());
  }
}

fn main(){
  let mut s = String::new();
  std::io::stdin().read_line(&mut s);
  let mut sp = s.split_whitespace();
  let th:i32 = sp.next().unwrap().parse().unwrap();
  let n:i32 = sp.next().unwrap().parse().unwrap();
  let mut arr:VecDeque<i32> = VecDeque::new();
  inp(&mut arr);
  if(th >= n){
    for i in 0..n{
      println!("{} {}",i,0)
    }
    return;
  }
  let mut res:Vec<pair> = Vec::new();
  let mut map:BTreeMap<i32,BinaryHeap<i32>> = BTreeMap::new();
  map.insert(0,BinaryHeap::new());
  // println!("{:?},{}{}",arr,th,n);
  
  for i in 0..th{
    if let Some(x) = map.get_mut(&0){
    x.push(-1*i);
    }
  }
  let mut time_pass = 0;
  loop{
    let mut f = 0;
    {
      let mut it = map.iter();
      f = *it.next().unwrap().0;
      time_pass = f;
    }
    let mut hp = map.get(&f).unwrap().clone();
    
    while let Some(t) = hp.pop(){
      let time = arr.pop_front().unwrap();
      res.push(pair(-1*t,time_pass));
      if let Some(x) = map.get_mut(&(time+time_pass)){
        x.push(t);
      }
      else{
        map.insert(time+time_pass, BinaryHeap::from(vec![t]));
      }
    }
    map.remove(&f);
    if arr.is_empty(){
      break;
    }
  }
  
  for i in res.iter(){
    println!("{} {}", i.0,i.1)
  }
  // println!("{:?}",res);
}