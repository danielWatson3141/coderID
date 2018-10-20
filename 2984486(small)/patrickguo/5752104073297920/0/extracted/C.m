% Matlab 7.12.0
function C()
startime = tic;
trial = 2;

if trial == 1
    infilename = 'C.in';
    outfilename = 'C.out';
elseif trial == 2
    infilename = 'C-small-attempt2.in';
    outfilename = 'C-small-attempt2.out';
elseif trial == 3
    infilename = 'C-large.in';
    outfilename = 'C-large.out';
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
    inline = fgetl(infile);
    numbers = str2num(inline);
    
    ref = 0:N-1;
    diff = numbers - ref;
    num = numel(find(diff>=0));
    if num <= 0.515*N
        result = 'GOOD';
    else
        result = 'BAD';
    end

    fprintf(outfile,'Case #%d: %s\n',casenum,result);
end


fclose(infile);
fclose(outfile);
toc(startime);
end