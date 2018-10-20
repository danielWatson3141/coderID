{$r+,q+,s+,i+}
{$ifdef fpc}
{$MODE delphi}
{$endif}
{$ASSERTIONS ON}
uses sysutils;
const testId='a-small-attempt0';
type tdata=array[1..150] of int64;
var ntest:integer;
    test:integer;
    f,g:text;
    ans:integer;
    n,l:integer;
    t,inp,outp,inp0:tdata;
    mask:int64;
    i,j:integer;
    
procedure readdata(var a:tdata);
var i,j:integer;
    ch:char;
begin
for i:=1 to n do begin
    a[i]:=0;
    for j:=1 to l do begin
        repeat
           read(f,ch);
        until ch in ['0','1'];
        a[i]:=a[i] shl 1;
        if ch='1' then
           inc(a[i]);
    end;
end;
end;

procedure sort(l,r:integer; var a:tdata);
var i,i1,i2,o:integer;
begin
if l>=r then exit;
o:=(l+r) shr 1;
sort(l,o,a);
sort(o+1,r,a);
i1:=l;
i2:=o+1;
for i:=l to r do 
    if (i2>r)or((i1<=o)and(a[i1]<a[i2])) then begin
       t[i]:=a[i1];
       inc(i1);
    end else begin
        t[i]:=a[i2];
        inc(i2);
    end;
for i:=l to r do begin
    a[i]:=t[i];
    if i<>l then
       assert(a[i]>a[i-1],'Wrong sort '+inttostr(l)+' '+inttostr(r));
end;
end;


procedure check;
var cur:integer;
    i:integer;
begin
sort(1,n,inp);
for i:=1 to n do
    if inp[i]<>outp[i] then exit;
cur:=0;
for i:=1 to l do begin
    if mask and 1<>0 then inc(cur);
    mask:=mask shr 1;
end;
if cur<ans then ans:=cur;
end;

begin
assign(f,testId+'.in');reset(f);
assign(g,testId+'.out');rewrite(g);
read(f,ntest);
for test:=1 to ntest do begin
    writeln(test);
    read(f,n,l);
    ans:=l+1;
    readdata(inp);
    readdata(outp);
    sort(1,n,outp);
    inp0:=inp;
    //for i:=1 to n do writeln(inp0[i],' ',outp[i]);
    for i:=1 to n do begin
        mask:=outp[i] xor inp0[1];
        //writeln('mask:',mask);
        for j:=1 to n do begin
            inp[j]:=inp0[j] xor mask;
            //writeln(inp[j]);
        end;
        assert(inp[1] = outp[i]);
        check;
    end;
    write(g,'Case #',test,': ');
    if ans=l+1 then writeln(g,'NOT POSSIBLE')
    else writeln(g,ans);
    flush(g);
end;
close(f);
close(g);
end.
