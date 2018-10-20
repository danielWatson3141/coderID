% Matlab 7.12.0

function B1()
global treenodes edges;

startime = tic;
trial = 3;

if trial == 1
    infilename = 'B.in';
    outfilename = 'B.out';
elseif trial == 2
    infilename = 'B-small-attempt0.in';
    outfilename = 'B-small-attempt0.out';
elseif trial == 3
    infilename = 'B-large.in';
    outfilename = 'B-large.out';
else
    return;
end

infile = fopen(infilename,'r');
testcase = str2num(fgetl(infile));
outfile = fopen(outfilename,'w');

result = 0;

for casenum = 1:testcase
    inline = fgetl(infile);
	N = str2num(inline);
    edges = zeros(N+1);
    for i = 1:N-1
        inline = fgetl(infile);
        numbers = str2num(inline);
        x = numbers(1);
        y = numbers(2);
        edges(x,y) = 1;
        edges(y,x) = 1;
    end
    
    num = zeros(1,i);
    treenodes = zeros(N+1);
    treenodes(:) = -1;
    % construct treenodes with memoize
    % treenodes(i,j) = # of node in complete sub-tree with j as root, i is j's parent
    % i==N+1 means j is root
    
    
    for i = 1:N
        num(i) = countnodes(i,N+1);
    end
    result = N - max(num);
    
    fprintf(outfile,'Case #%d: %d\n',casenum,result);
end


fclose(infile);
fclose(outfile);
toc(startime);
end


function num = countnodes(n,parent)
global treenodes edges;
if treenodes(parent,n) > -1
    num = treenodes(parent,n);
    return;
end
x = find(edges(n,:));
x(x==parent) = [];
if numel(x) <= 1
    num = 1;
else
    nums = zeros(1,numel(x));
    for i = 1:numel(x)
        nums(i) = countnodes(x(i),n);
    end
    nums = sort(nums);
    num = 1 + nums(end) + nums(end-1);
end
treenodes(parent,n) = num;
end
