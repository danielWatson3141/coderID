var
    n,i,test,cnt,t,j:longint;
    a:array[0..1010] of longint;

procedure fw;
begin
  assign(input,'gcj2014r1ac.in');reset(input);
  assign(output,'gcj2014r1ac.out');rewrite(output);
end;

begin {main}
  fw;
  readln(test);
  for t:=1 to test do
    begin
      readln(n);
      for i:=1 to n do read(a[i]);readln;
      cnt:=0;
      for i:=1 to n-1 do
        for j:=i+1 to n do
          if a[i]>a[j] then inc(cnt);
      write('Case #',t,': ');
      if cnt<245000 then writeln('BAD') else writeln('GOOD');
    end;
end.
