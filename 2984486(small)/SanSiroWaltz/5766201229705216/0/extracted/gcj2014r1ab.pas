type
     point=^node;
     node=record
       data:longint;
       next:point;
     end;
var
    n,i,test,t,x,y,ans:longint;
    size,dp:array[0..1010] of longint;
    v:array[0..1010] of boolean;
    head:array[0..1010] of point;

procedure fw;
begin
  assign(input,'gcj2014r1ab.in');reset(input);
  assign(output,'gcj2014r1ab.out');rewrite(output);
end;

procedure push(x,y:longint);
var
    p:point;
begin
  new(p);p^.data:=y;p^.next:=head[x];head[x]:=p;
end;

function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;

function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;

procedure check(var x,y:longint;z:longint);
begin
  if z>x then
    begin
      y:=x;x:=z;
    end
  else
    y:=max(y,z);
end;

procedure dfs(k:longint);
var
    p:point;
    ma1,ma2:longint;
begin
  v[k]:=true;
  p:=head[k];size[k]:=1;
  ma1:=0;ma2:=0;
  while p<>nil do
    begin
      if not v[p^.data] then
        begin
          dfs(p^.data);inc(size[k],size[p^.data]);check(ma1,ma2,size[p^.data]-dp[p^.data]);
        end;
      p:=p^.next;
    end;
  if ma2=0 then dp[k]:=size[k]-1 else dp[k]:=size[k]-1-ma1-ma2;
end;

begin {main}
  fw;
  readln(test);
  for t:=1 to test do
    begin
      readln(n);
      for i:=1 to n do head[i]:=nil;
      for i:=1 to n-1 do
        begin
          readln(x,y);push(x,y);push(y,x);
        end;
      ans:=n+1;
      for i:=1 to n do
        begin
          fillchar(v,sizeof(v),false);
          dfs(i);ans:=min(ans,dp[i]);
        end;
      writeln('Case #',t,': ',ans);
    end;
end.
