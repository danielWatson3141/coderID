{$r+,q+,s+,i+}
{$ifdef fpc}
{$MODE delphi}
{$endif}
{$ASSERTIONS ON}
const testId='b-small-attempt0';
var ntest:integer;
    test:integer;
    f,g:text;
    curres,res:integer;
    gr:array[1..1000] of array of integer;
    ans:array[1..1000] of integer;
    i,j:integer;
    n:integer;
    u,v:integer;
    
procedure add(u,v:integer);
begin
setlength(gr[u],length(gr[u])+1);
gr[u][length(gr[u])-1]:=v;
end;

function find(i:integer):integer;
var j:integer;
    max,max2:integer;
    t:integer;
begin
assert(ans[i]=-1);
ans[i]:=1;
max:=0;
max2:=0;
for j:=0 to length(gr[i])-1 do begin
    if ans[gr[i][j]]<>-1 then continue;
    t:=find(gr[i][j]);
    if t>max then begin
       max2:=max;
       max:=t;
    end else if t>max2 then
        max2:=t;
end;
if max2<>0 then
   ans[i]:=1+max+max2;
find:=ans[i];
end;

begin
assign(f,testId+'.in');reset(f);
assign(g,testId+'.out');rewrite(g);
read(f,ntest);
for test:=1 to ntest do begin
    writeln(test);
    for i:=1 to 1000 do setlength(gr[i],0);
    read(f,n);
    res:=n;
    for i:=1 to n-1 do begin
        read(f,u,v);
        add(u,v);
        add(v,u);
    end;
    for i:=1 to n do begin
        fillchar(ans,sizeof(ans),255);
        find(i);
        //write(i,':');
        //for j:=1 to n do write(' ',ans[j]);
        //writeln;
        curres:=n-ans[i];
        if curres<res then 
           res:=curres;
    end;
    writeln(g,'Case #',test,': ',res);
    flush(g);
end;
close(f);
close(g);
end.
