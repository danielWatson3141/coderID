uses
	math;

type
	tr = array[0..15] of longint;

var
	g:array[0..15,0..15] of boolean;
	used:array[0..15] of longint;
	a,d:tr;
	i,j,n,m,q,k,res,l,r:longint;
	
procedure dfs_ans(v:longint; var answ:boolean);
var
	j:longint;
begin
	used[v]:=1;
	for j:=1 to n do
		begin
			if (used[j] = 0) and (g[v][j]) then
				begin
					dfs_ans(j,answ);
					inc(d[v]);
				end;
		end;
end;
	
function ans(l:longint; var a:tr):boolean;
var
	i,j,k:longint;
	answ:boolean;
begin
	for j:=1 to n do
		begin
			for i:=1 to n do
				begin
					used[i]:=0;
					d[i]:=0;
				end;
			for i:=1 to l do
				used[a[i]]:=1;
			if used[j] <> 1 then
				answ:=true
			else
				answ:=false;
			dfs_ans(j,answ);
			for i:=1 to n do
				begin
				if (d[i] <> 2) and (d[i] <> 0) then
					answ:=false;
				end;
			for i:=1 to n do
				if used[i] = 0 then
					answ:=false;
			if answ then
				exit(true);
		end;
	exit(false);
end;
	
procedure dfs(v,l:longint;var a:tr);
var
	j:longint;
begin
	a[l]:=v;
	if ans(l,a) then
		begin
			res:=min(res,l);
		end;
	for j:=v+1 to n do
		if l < n then
			dfs(j,l+1,a);
end;
	
Begin
	Assign(input,'B-small-attempt0_.in');
	reset(input);
	Assign(output,'output.txt');
	rewrite(output);
	readln(q);
	for k:=1 to q do
		begin
			read(n); res:=maxlongint;
			for i:=1 to n do
				for j:=1 to n do
					g[i][j]:=false;
			for i:=1 to n do
				begin
					used[i]:=1;
					a[i]:=0;
					d[i]:=0;
				end;
			for i:=2 to n do
				begin
					read(l,r);
					g[l][r]:=true;
					g[r][l]:=true;
				end;
			dfs(0,0,a);
			writeln('Case #',k,': ',res);
		end;
end.
