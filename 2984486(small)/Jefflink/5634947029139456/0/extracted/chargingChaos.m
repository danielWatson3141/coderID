function chargingChaos()
% GOOGLE JAM Bull Eye Exercise

% obtain the location of test file
[fileName,pathName] = uigetfile('*.in','Select the test file');
tic
% open the test file
try
    fid = fopen([pathName,fileName],'r');
catch ME
    error('Error Opening Test File!');
end

% open the solution file
try
    sid = fopen('Solution.txt','w');
catch ME
    error('Error Opening Solution file!');
end

% obtain the number of test cases
numTestCase = str2double(fgetl(fid));
% loop through each test case
for i = 1:numTestCase
    fprintf(sid,'Case #%d: ',i);
    [nDevice,nSwitch,outletCharge,deviceCharge] = readTestCase(fid);
    [nTimes,isFound,currMin] = evaluate(nDevice,nSwitch,outletCharge,deviceCharge);
    if(isFound || currMin>0)
        fprintf(sid,'%d\n',currMin);
    else
        fprintf(sid,'%s\n','NOT POSSIBLE');
    end
end
% close the file
fclose(fid);
fclose(sid);
toc

%% Sub-Function goes here

    function [nDevice,nSwitch,outletCharge,deviceCharge] = readTestCase(fid)
        % obtain the inputs
        input = fscanf(fid,'%d',2)';
        % get the input
        nDevice = input(1);
        nSwitch = input(2);
        % obtain the outlet charge
        outletInput = fscanf(fid,'%s',nDevice);
        deviceInput = fscanf(fid,'%s',nDevice);
        
        % store the values
        idx = 0;
        outletCharge = zeros(nDevice,nSwitch);
        deviceCharge = zeros(nDevice,nSwitch);
        for ii = 1:nDevice
            for jj=1:nSwitch
                idx = idx + 1;
                outletCharge(ii,jj) = str2double(outletInput(idx));
                deviceCharge(ii,jj) = str2double(deviceInput(idx));
            end
        end
    end

    function [nTimes,isFound,currMin] = evaluate(nDevice,nSwitch,outletCharge,deviceCharge)
        nTimes = 0;
        isFound = false;
        currMin = -1;
        % check if it is necessary to switch
        deviceArray = zeros(nDevice,1);
        chargeArray = deviceArray;
        for ii=1:nDevice
            deviceArray(ii,1) = bi2de(deviceCharge(ii,:));
            chargeArray(ii,1) = bi2de(outletCharge(ii,:));
        end
        
        sequence = zeros(1,nSwitch);
        
        % else, have to find the switch
        maxLoop = 2^nSwitch;
        for ii=1:maxLoop
            % update the sequence
            if(ii==1)
                isFound = isCharge(chargeArray);
                if(isFound)
                    currMin = 0;
                    return;
                end
            elseif(ii==maxLoop)
                % set the sequence
                sequence = ones(1,nSwitch);
                nTimes = nSwitch;
                 % update the switch value
                tempArray = updateSwitch();
                tempCharge = calCharge(tempArray);
                isFound = isCharge(tempCharge);
                if(isFound)
                    if(currMin == -1)
                        currMin = nTimes;
                    else
                        if(nTimes < currMin)
                            currMin = nTimes;
                        end
                    end
                end
            else
                % update the sequence
                setBit(nSwitch);
                nTimes = sum(sequence);
                % update the switch value
                tempArray = updateSwitch();
                tempCharge = calCharge(tempArray);
                isFound = isCharge(tempCharge);
                if(isFound)
                    if(currMin == -1)
                        currMin = nTimes;
                    else
                        if(nTimes < currMin)
                            currMin = nTimes;
                        end
                    end
                end
            end
        end
        
        function tempArray = updateSwitch()
            % obtain the sequence
            tempArray = outletCharge;
            for kk=1:nSwitch
                if(sequence(1,kk)==1)
                    % switch
                    isOne = tempArray(:,kk)==1;
                    isZero = tempArray(:,kk)==0;
                    tempArray(isOne,kk) = 0;
                    tempArray(isZero,kk) = 1;
                end
            end
        end
        
        function charge = calCharge(array)
            charge = zeros(nDevice,1);
            for kk=1:nDevice
                charge(kk,1) = bi2de(array(kk,:));
            end
        end
        
        function setBit(idx)
            if(sequence(1,idx)==0)
                sequence(1,idx)=1;
            else
                sequence(1,idx)=0;
                setBit(idx-1);
            end
        end
        
        function isFound = isCharge(compareArray)
            isFound = false;
            % check if it matchs
            uCharge = intersect(deviceArray,compareArray);
            if(~isempty(uCharge))
                if(size(uCharge,1)==nDevice)
                    isFound = true;
                    return;
                end
            end
        end
    end


end

