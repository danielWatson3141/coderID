% Matlab 7.12.0
function B()
startime = tic;
trial = 2;

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
    edges = zeros(N);
    for i = 1:N-1
        inline = fgetl(infile);
        numbers = str2num(inline);
        x = numbers(1);
        y = numbers(2);
        edges(x,y) = 1;
        edges(y,x) = 1;
    end
    
    num = zeros(1,i)
    for i = 1:N
        edgechild = edges(i,:);
        num(i) = countnodes(edges,i,edgechild);
    end
    result = N - max(num);
    
    
    
    fprintf(outfile,'Case #%d: %d\n',casenum,result);
end


fclose(infile);
fclose(outfile);
toc(startime);
end


function num = countnodes(edges,n,edgechild)
x = find(edgechild);
if numel(x) <= 1
    num = 1;
else
    nums = zeros(1,numel(x))
    for i = 1:numel(x)
        edgechild1 = edges(x(i),:);
        edgechild1(n) = 0;
        nums(i) = countnodes(edges,x(i),edgechild1);
    end
    nums = sort(nums);
    num = 1 + nums(end) + nums(end-1);
end
end
