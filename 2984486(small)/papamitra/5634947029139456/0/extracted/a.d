
import std.stdio;
import std.conv;
import std.string;
import std.range;
import std.array;
import std.algorithm;

int calcbit(int i){
  int ret = 0;
  do{
    ret += i & 0x1;
    i = i >> 1;
  }while(i);

  return ret;
}

void solve(int i){
  auto l1st = readln().chomp().split();
  auto n = to!int(l1st[0]);
  auto l = to!int(l1st[1]);

  int[] l2nd = array(map!(a => to!int(a,2))(readln().chomp().split()));
  sort(l2nd);
  int[] l3rd = array(map!(a => to!int(a,2))(readln().chomp().split()));

  int max = int.max;
  do{
    int xor = l2nd[0] ^ l3rd[0];
    bool allof = true;
    foreach(j,v; l2nd){
      if(xor != (v ^ l3rd[j])){
	allof = false;
	break;
      }
    }
    if(allof){
      int bits = calcbit(xor);
      if(max > bits){
	max = bits;
      }
    }
  } 
  while(l2nd.nextPermutation());

  if(max < int.max){
    writefln("Case #%d: %d", i+1, max);
  }else{
    writefln("Case #%d: NOT POSSIBLE", i+1);
  }
    

}

void main(){

  auto caseNum = to!(int)(chomp(readln()));

  foreach(i; iota(0, caseNum)){
    solve(i);
  }

}
