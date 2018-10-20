var
    ans,n,i,tmp,p,j,l,t,k,test:longint;
    temp,ch:char;
    ok:boolean;
    a,b,c:array[0..151,0..41] of char;
    d:array[0..41] of longint;

procedure fw;
begin
  assign(input,'gcj2014r1aa.in');reset(input);
  assign(output,'gcj2014r1aa.out');rewrite(output);
end;

function cmp1(x,y:longint):boolean;
var
    i:longint;
begin
  for i:=1 to l do
    begin
      if c[x,i]>c[y,i] then exit(true);
      if c[x,i]<c[y,i] then exit(false);
    end;
  exit(false);
end;

function cmp2(x,y:longint):boolean;
var
    i:longint;
begin
  for i:=1 to l do
    begin
      if b[x,i]>b[y,i] then exit(true);
      if b[x,i]<b[y,i] then exit(false);
    end;
  exit(false);
end;

begin {main}
  fw;
  readln(test);
  for t:=1 to test do
    begin
      readln(n,l);
      for i:=1 to n-1 do
        begin
          for j:=1 to l do read(a[i,j]);
          read(ch);
        end;
      for j:=1 to l do read(a[n,j]);
      readln;
      for i:=1 to n-1 do
        begin
          for j:=1 to l do read(b[i,j]);
          read(ch);
        end;
      for j:=1 to l do read(b[n,j]);
      readln;
      for i:=1 to n do
        for j:=i+1 to n do
          if cmp2(i,j) then
            begin
              for k:=1 to l do begin temp:=b[i,k];b[i,k]:=b[j,k];b[j,k]:=temp;end;
            end;
      ans:=l+1;
      for i:=1 to n do
        begin
          for j:=1 to l do if a[1,j]=b[i,j] then d[j]:=0 else d[j]:=1;
          for j:=1 to n do
            for k:=1 to l do
              if d[k]=0 then c[j,k]:=a[j,k] else c[j,k]:=chr(97-ord(a[j,k]));
          for j:=1 to n do
            for k:=j+1 to n do
              if cmp1(j,k) then
                begin
                  for p:=1 to l do begin temp:=c[j,p];c[j,p]:=c[k,p];c[k,p]:=temp;end;
                end;
          ok:=true;
          for j:=1 to n do
            for k:=1 to l do
              if b[j,k]<>c[j,k] then ok:=false;
          if ok then
            begin
              tmp:=0;
              for j:=1 to l do inc(tmp,d[j]);
              if tmp<ans then ans:=tmp;
            end;
        end;
      write('Case #',t,': ');
      if ans<=l then writeln(ans) else writeln('NOT POSSIBLE');
    end;
  close(input);close(output);
end.
