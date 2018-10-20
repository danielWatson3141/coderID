% Matlab 7.12.0
function A()
startime = tic;
trial = 3;

if trial == 1
    infilename = 'A.in';
    outfilename = 'A.out';
elseif trial == 2
    infilename = 'A-small-attempt2.in';
    outfilename = 'A-small-attempt2.out';
elseif trial == 3
    infilename = 'A-large.in';
    outfilename = 'A-large.out';
else
    return;
end

infile = fopen(infilename,'r');
testcase = str2num(fgetl(infile));
outfile = fopen(outfilename,'w');

result = 0;
for casenum = 1:testcase
    inline = fgetl(infile);
    numbers = str2num(inline);
    N = numbers(1);
    L = numbers(2);
    outlet = fgetl(infile);
    device = fgetl(infile);
    
    outlet(L+1:L+1:end) = '';
    outlet = reshape(outlet,L,N)';
    outlet = uint64(bin2dec(outlet));
    device(L+1:L+1:end) = '';
    device = reshape(device,L,N)';
    device = uint64(bin2dec(device));
        
    outlet = sort(outlet);
    device = sort(device);
    num = zeros(1,N);
    for i = 1:N
        swt = bitxor(outlet(1),device(i));
        device1 = device;
        for j = 1:N
            device1(j) = bitxor(device(j),swt);
        end
        device1 = sort(device1);
        if isequal(device1,outlet)
            num(i) = numel(find(dec2bin(swt)=='1'));
        else
            num(i) = L+1;
        end
    end
    x = min(num);
    if x <= L
        result = num2str(x);
    else
        result = 'NOT POSSIBLE';
    end
    
    
    fprintf(outfile,'Case #%d: %s\n',casenum,result);
end


fclose(infile);
fclose(outfile);
toc(startime);
end