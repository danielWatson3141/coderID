uses math;

var s1,s2:array[0..1001]of string;
    a:array[0..201,0..201]of string;
    t,q,i,n,l,ind,ans:longint;
    ps,s:string;


  procedure swap(var a,b:longint);
   var c:longint;
    begin
      c:=a;
      a:=b;
      b:=c;
    end;

  procedure init();
   var i,j,u:longint;
    begin
      for i:=1 to n do
        for j:=1 to n do
          a[i][j]:='';
      for i:=1 to n do
        for j:=1 to n do
          for u:=1 to l do
            if (s1[i][u]<>s2[j][u]) then a[i][j]:=a[i][j]+'1'
              else a[i][j]:=a[i][j]+'0';
    end;


  function can(s:string):longint;
   var x,y:array[0..201]of boolean;
       kol,num:array[0..201]of longint;
       ost,i,j,p,add:longint;
    begin
      fillchar(x,sizeof(x),false);
      fillchar(y,sizeof(y),false);
      ost:=n;
      while true do
        begin
          if (ost=0) then break;
          fillchar(kol,sizeof(kol),0);
          for i:=1 to n do
            if (x[i]=false) then
              for j:=1 to n do
                if (y[j]=false) then
                  if (a[i][j]=s) then inc(kol[j]);
          for j:=1 to n do
            num[j]:=j;
          for i:=1 to n do
            for j:=i+1 to n do
              if (kol[i]>kol[j]) then
                begin
                  swap(kol[i],kol[j]);
                  swap(num[i],num[j]);
                end;
          p:=-1;
          for i:=1 to n do
            if (kol[i]<>0) then
              begin
                p:=num[i];
                break;
              end;
          if (p=-1) then exit(maxlongint);
          for i:=1 to n do
            if (x[i]=false) and (a[i][p]=s) then
              begin
                x[i]:=true;
                y[p]:=true;
                break;
              end;
          dec(ost);
        end;
      add:=0;
      for i:=1 to length(s) do
        if (s[i]='1') then inc(add);
      exit(add);
    end;





begin

  assign(input,'input.txt');
  assign(output,'output.txt');
  reset(input);
  rewrite(output);

  readln(t);

  for q:=1 to t do
    begin
      readln(n,l);
      ind:=0;readln(ps);
      s:='';
      for i:=1 to length(ps) do
        if (ps[i]=' ') then
          begin
            inc(ind);
            s1[ind]:=s;
            s:='';
          end
        else s:=s+ps[i];
      inc(ind);
      s1[ind]:=s;
      ind:=0;s:='';
      readln(ps);
      for i:=1 to length(ps) do
        if (ps[i]=' ') then
          begin
            inc(ind);
            s2[ind]:=s;
            s:='';
          end
        else s:=s+ps[i];
      inc(ind);
      s2[ind]:=s;
      init();
      ans:=maxlongint;
      for i:=1 to n do
        ans:=min(ans,can(a[1][i]));
      write('Case #',q,': ');
      if (ans=maxlongint) then writeln('NOT POSSIBLE')
        else writeln(ans);
    end;

  close(input);
  close(output);

end.