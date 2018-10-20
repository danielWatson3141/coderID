%%problem C
clear; clc;

%process input
fid = fopen('C-small-attempt0.in','r');

%output file
fid2 = fopen('C-small-attempt0.out','w');

%read first line, has number of cases
T = strread(fgetl(fid));

%loop through cases
P = zeros(1,T);

for i=1:T
    %get N
    N = strread(fgetl(fid));

    %get input
    ins = strread(fgetl(fid));
    
    %bad cases tend to have a number n appear in position > n
    %go through all and find ratio of nums which appear >n 
    p = 0;
    for j=1:N
        if ins(j) > j
            p = p+1;
        end
    end
    
    %based on simulations of data, "good" algorithm produced p with a mean
    %of 498 (std: 8) and "bad" produced p with mean 525 (std 8)
    
    %if p > 510, call it bad
    if p > 510
        fprintf(fid2, 'Case #%d: BAD\n', i);
    else
        fprintf(fid2, 'Case #%d: GOOD\n', i);
    end
end