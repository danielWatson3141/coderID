import std.stdio;
import std.conv;
import std.string;
import std.math;
import std.algorithm;

immutable(char)[] munchStr = " ";

class Panel{
	int bitlength;
	ulong[] outlets;
	ulong[] devices;
	
	this(int[2] NL){
		this.outlets = new ulong[](NL[0]);
		this.devices = new ulong[](NL[0]);
		this.bitlength = NL[1];
	}
	
	public void addOutlets(char[] buf){
		char[][] ol = split(buf," ");
		
		for(int i=bitlength-1;i>=0;i--){
			for(int j=0;j<ol.length;j++){
				if(ol[j][i] == '1')
					outlets[j] |= 2^^i;
			}
		}
	}
	
	public void addDevices(char[] buf){
		char[][] ol = split(buf," ");
		
		for(int i=bitlength-1;i>=0;i--){
			for(int j=0;j<ol.length;j++){
				if(ol[j][i] == '1')
					devices[j] |= 2^^i;
			}
		}
	}
	
	public void flipXor(ulong xr){
		for(int i=0;i<outlets.length;i++){
			outlets[i] ^= xr;
		}
	}
	
	public int bitCount(ulong l){
		int count = 0;
		for(int i=0;l>0;i++){
			if((l & 1) == 1){
				count++;
				l -= 1;
			}
			l /= 2;
		}
		return count;
	}
	
	public int bruteSolve(){
		int flips = 0;
		int minflips = 999;
		sortEm();
		if(devEqual())
			return flips;
			
		bool found = false;
		for(ulong i=0;i<1025;i++){
			flipXor(i);
			sortEm();
			if(devEqual()){
				flips = bitCount(i);
				if(flips < minflips)
					minflips = flips;
			}
			flipXor(i);
		}
		if(minflips < 999)
			return minflips;
		return -1;
		/*
		for(int k=0;k<bitlength;k++){
			for(int i=k;i<bitlength;i++){
				flipBit(i);
				if(devEqual())
					return (flips+1);
				
				for(int j=i+1;j<bitlength;j++){
					flipBit(j);
					sortEm();
					if(devEqual())
						return (flips+2);
					flipBit(j);
				}
				flipBit(i);
			}
			flipBit(k);
			flips++;
		}
		*/
		return -1;
	}
	
	public void sortEm(){
		sort(outlets);
		sort(devices);
	}
	
	public bool devEqual(){
		
		for(int i=0;i<outlets.length;i++){
			if(outlets[i] != devices[i])
				return false;
		}
		return true;
	}
	
	public void flipBit(int b){
		for(int i=0;i<outlets.length;i++){
			outlets[i] ^= 2^^b;
		}

	}
	
	public void printOutlets(){
		writefln("printing outlets:");
		for(int i=0;i<outlets.length;i++){
			writefln("%11b",outlets[i]);
		}
		writefln("----");
	}
	public void printDevices(){
		writefln("printing devices:");
		for(int i=0;i<devices.length;i++){
			writefln("%11b",devices[i]);
		}
		writefln("----");
	}
}

int main(){

	char[] buf;
	
	int cases = 0;
	//total strings, string length
	int[2] NL;

	
	//read case count
	stdin.readln(buf);
	cases = parse!int(buf);
	
	for(int i=0;i<cases;i++){
	
		stdin.readln(buf);
		for(int j=0;j<NL.length;j++){
			NL[j] = parse!int(buf);
			munch(buf,munchStr);
		}
		Panel p = new Panel(NL);
		stdin.readln(buf);
		p.addOutlets(buf);
		
		stdin.readln(buf);
		p.addDevices(buf);
		
		//p.printOutlets();
		//p.printDevices();

		writef("Case #%d: ",(i+1));
		int res = p.bruteSolve();
		if(res == -1)
			writef("NOT POSSIBLE\n");
		else
			writef("%d\n",res);
		
	}
	
	return 0;
}