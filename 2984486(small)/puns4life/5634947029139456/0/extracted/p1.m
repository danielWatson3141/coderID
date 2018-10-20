%%problem A
clear; clc;

%process input
fid = fopen('A-small-attempt4.in','r');

%output file
fid2 = fopen('A-small-attempt4.out','w');

%read first line, has number of cases
numCases = strread(fgetl(fid));

%loop through cases
for i=1:numCases
    %get N and L
    [N L] = strread(fgetl(fid));
    
    %get electric flows
    eFlows = strread(fgetl(fid),'%s');
    
    %get needed flows
    nFlows = strread(fgetl(fid), '%s');
    
    eRatios = zeros(1,L);
    nRatios = zeros(1,L);
    
    %get ratios of 1:0 for each of the needed flows (in decimal form) and
    %for the outlet flows
    for j=1:N
        e = eFlows{j};
        n = nFlows{j};
        
        for k=1:L
            eRatios(k) = eRatios(k) + (e(k)=='1');
            nRatios(k) = nRatios(k) + (n(k)=='1');
        end
    end
    
    %now lets count how many switches we need to flip, and if we can
    canWeDoIt = true;
    numFlips = 0;
    
    for j=1:L
        %check if ratios or 1-ratios are equal
        if eRatios(j) == nRatios(j)
            %check if this works now
            eFlows = sort(eFlows);
            nFlows = sort(nFlows);
            %see if character j matches in all
            s = 0;
            for k=1:N
                if eFlows{k}(j) == nFlows{k}(j)
                    s = s+1;
                end
            end
            if s < length(nFlows)
                canWeDoIt = false;
                break;
            end
            continue;
        elseif eRatios(j) == N-nRatios(j)
            %flip the values for this j
            for k=1:N
                e = eFlows{k};
                if e(j) == '0'
                    e(j) = '1';
                else
                    e(j) = '0';
                end
                eFlows{k} = e;
            end
            
            %check if this works now
            eFlows = sort(eFlows);
            nFlows = sort(nFlows);
            %see if character j matches in all
            s = 0;
            for k=1:N
                if eFlows{k}(j) == nFlows{k}(j)
                    s = s+1;
                end
            end
            if s < length(nFlows)
                canWeDoIt = false;
                break;
            end
            numFlips = numFlips+1;
            continue;
        end
    end
    
    %check if this works now
    eFlows = sort(eFlows);
    nFlows = sort(nFlows);
    s = sum(strcmp(eFlows,nFlows));
    if s < length(nFlows)
        canWeDoIt = false;
    end

    if canWeDoIt
        fprintf(fid2, 'Case #%d: %d\n', i, numFlips);
    else
        fprintf(fid2, 'Case #%d: NOT POSSIBLE\n', i);
    end
end