program Alex;
var
    t, tt, n, l, i, j, ans, tmp : longint;
    c : char;
    a, b : array [0 .. 200] of string;
    ca, cb : array [0 .. 50, '0' .. '1'] of longint;
    flg : boolean;

function inv(c : char) : char;
begin
    if c = '0' then exit('1');
    exit('0');
end;

procedure bsort(l, r : longint);
var
    i, j : longint;
    x, y : string;
begin
    i := l; j := r; x := b[(l + r) shr 1];
    repeat
        while b[i] < x do i := i + 1;
        while b[j] > x do j := j - 1;
        if i <= j then begin
            y := b[i]; b[i] := b[j]; b[j] := y;
            i := i + 1; j := j - 1;
        end;
    until i > j;
    if l < j then bsort(l, j);
    if i < r then bsort(i, r);
end;

procedure asort(l, r : longint);
var
    i, j : longint;
    x, y : string;
begin
    i := l; j := r; x := a[(l + r) shr 1];
    repeat
        while a[i] < x do i := i + 1;
        while a[j] > x do j := j - 1;
        if i <= j then begin
            y := a[i]; a[i] := a[j]; a[j] := y;
            i := i + 1; j := j - 1;
        end;
    until i > j;
    if l < j then asort(l, j);
    if i < r then asort(i, r);
end;

function check : boolean;
var
    i : longint;
begin
    for i := 1 to n do if a[i] <> b[i] then exit(false);
    exit(true);
end;

procedure dfs(d : longint);
var
    i : longint;
begin
    if d = l + 1 then begin
        if check then begin
            flg := true;
            ans := tmp;
        end;
        exit;
    end;
    bsort(1, n);
    if (ca[d, '0'] = cb[d, '0']) then dfs(d + 1);
    if flg then exit;
    if (ca[d, '0'] = cb[d, '1']) then begin
        tmp := tmp + 1;
        for i := 1 to n do b[i, d] := inv(b[i, d]);
        bsort(1, n);
        dfs(d + 1);
        tmp := tmp - 1;
        for i := 1 to n do b[i, d] := inv(b[i, d]);
        bsort(1, n);
    end;
end;

begin
    assign(input, 'in3.in'); reset(input);
    assign(output, 'output.txt'); rewrite(output);
    readln(t);
    for tt := 1 to t do begin
        fillchar(ca, sizeof(ca), 0);
        fillchar(cb, sizeof(cb), 0);
        readln(n, l);
        for i := 1 to n do begin
            a[i] := stringofchar('0', l);
            b[i] := stringofchar('0', l);
        end;
        for i := 1 to n do begin
            for j := 1 to l do begin
                read(b[i, j]);
                cb[j, b[i, j]] := cb[j, b[i, j]] + 1;
            end;
            if i < n then read(c)
                     else readln;
        end;
        for i := 1 to n do begin
            for j := 1 to l do begin
                read(a[i, j]);
                ca[j, a[i, j]] := ca[j, a[i, j]] + 1;
            end;
            if i < n then read(c)
                     else readln;
        end;
        asort(1, n);
        write('Case #', tt, ': ');
        ans := 0;
        for i := 1 to l do begin
            if (ca[i, '0'] = cb[i, '0']) then continue;
            if (ca[i, '0'] = cb[i, '1']) then begin
                ans := ans + 1;
                continue;
            end;
            ans := -1; break;
        end;
        if ans = -1 then begin
            writeln('NOT POSSIBLE');
            continue;
        end;
        flg := false; tmp := 0;
        dfs(1);
        if not flg then writeln('NOT POSSIBLE')
        else writeln(ans);
    end;
    close(input); close(output);
end.
