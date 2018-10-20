uses
	math;

type
	tr = array[0..20] of longint;

var
	r:tr;
	c,d,cur_c,cur_d:array[0..20] of ansistring;
	i,j,n,m,q,k,ce,de,res:Longint;
	a,b,temp:ansistring;
	
function ans(l:longint; var r:tr):boolean;
var
	i,j:longint;
	temp:ansistring;
begin
	cur_c:=c;
	for i:=1 to n do
		for j:=1 to l do
			cur_c[i][r[j]]:=chr(49 + 48 - ord(cur_c[i][r[j]]));
	for i:=1 to n do
		for j:=i+1 to n do
			if cur_c[i] > cur_c[j] then
				begin
					temp:=cur_c[i];
					cur_c[i]:=cur_c[j];
					cur_c[j]:=temp;
				end;
	for i:=1 to n do
		if d[i] <> cur_c[i] then
			exit(false);
	exit(true);
end;
	
procedure dfs(v,l:Longint; var r:tr);
var
	j:longint;
begin
	r[l]:=v;
	if ans(l,r) then
		res:=min(res,l);
	for j:=v+1 to m do
		if l < m then
			dfs(j,l+1,r);
end;
	
Begin
	Assign(input,'A-small-attempt0_.in');
	reset(input);
	Assign(output,'output.txt');
	rewrite(output);
	readln(q);
	for k:=1 to q do
		begin
			ce:=1; de:=1; res:=maxlongint;
			c[ce]:=''; d[de]:='';
			readln(n,m);
			readln(a);
			readln(b);
			for i:=1 to length(a) do
				if i mod (m+1) = 0 then
					begin
						inc(ce);
						c[ce]:='';
					end
				else
					c[ce]:=c[ce]+a[i];
			for i:=1 to length(b) do
				if i mod (m+1) = 0 then
					begin
						inc(de);
						d[de]:='';
					end
				else
					d[de]:=d[de]+b[i];
			for i:=1 to n do
				for j:=i+1 to n do
					if d[i] > d[j] then
						begin
							temp:=d[i];
							d[i]:=d[j];
							d[j]:=temp;
						end;
			dfs(0,0,r);
			write('Case #',k,': ');
			if res = maxlongint then
				write('NOT POSSIBLE')
			else
				write(res);
			writeln;
		end;
end.
