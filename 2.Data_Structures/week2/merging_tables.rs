#[derive(Debug)]
struct Node(usize,usize);

fn inpi()->(usize,usize){
    let mut inp = String::new();
    std::io::stdin().read_line(&mut inp);
    let mut it = inp.split_whitespace();
    let a = it.next().unwrap().parse::<usize>().unwrap();
    let b = it.next().unwrap().parse::<usize>().unwrap();
    (a,b)
}

fn inp(arr:&mut Vec<Node>) -> usize{
	let mut mx = std::usize::MIN;
	let mut s = String::new();
	std::io::stdin().read_line(&mut s);
	let it = s.split_whitespace();
	let mut ctr = 1;
	for i in it{
		let tmp = i.parse::<usize>().unwrap();
	  	arr.push(Node(ctr,tmp));
	  	ctr+=1;
		mx = std::cmp::max(mx, tmp);
	}
	mx
}

fn main(){
	let (n,m) = inpi();
	let mut arr:Vec<Node> = vec![Node(0,0)];
	let mut mx = inp(&mut arr);
	// println!("{:?}",arr);
	for _ in 0..m{
		let (a,b) = inpi();
		mx = std::cmp::max(union(a, b, &mut arr),mx);
		println!("{}",mx)
	}
}

fn find(val:usize,arr:&mut Vec<Node>) -> usize{
	if val == arr[val].0{
		return val;
	}
	else{
		let tmp = find(arr[val].0, arr);
		arr[val].0 = tmp;
		return tmp;
	}
}

fn union(a:usize,b:usize,arr:&mut Vec<Node>) -> usize{
	let r_1 = find(a, arr);
	let r_2 = find(b, arr);
	if(r_1 == r_2){return arr[r_1].1}
	else{
		arr[r_2].0 = r_1;
		arr[r_1].1 += arr[r_2].1;
		return arr[r_1].1;
	}
}