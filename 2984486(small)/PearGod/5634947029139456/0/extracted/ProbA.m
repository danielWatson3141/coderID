%Qual 2014
%Prob A
% Daniel Peirano
% djpeirano@gmail.com

clc
clear
close all

[fileInput, folderInput] = uigetfile('*.in', 'Get input file');
fileInputFull = [folderInput, fileInput];
fileOutputFinal = [folderInput, fileInput(1:end-2), 'out' ];
% fileInputFull = 'C:\Users\Daniel\Dropbox\Projects\Competitions\Google Jam\Round1a\temp.in';
% fileOutputFinal = 'C:\Users\Daniel\Dropbox\Projects\Competitions\Google Jam\Round1a\temp.out';

pid = fopen(fileInputFull);
cellFullFile = textscan(pid, '%s', 'Delimiter', '\n', 'Whitespace', '');
fclose(pid);
cellFullFile = cellFullFile{1};

numCases = str2double(cellFullFile{1});
    cellFullFile = cellFullFile(2:end);
cellOut = cell(numCases,1);


for i=1:numCases
    cellInitial = textscan(cellFullFile{i*3-1}, '%s', 'Whitespace', ' ');
        cellInitial = cellInitial{1};
    matInitial = false(length(cellInitial),length(cellInitial{1}));
    for j=1:length(cellInitial)
        strCurr = cellInitial{j};
        for k=1:length(strCurr)
            if strcmp(strCurr(k),'1')
                matInitial(j,k) = true;
            end
        end
    end
    
    cellRequired = textscan(cellFullFile{i*3}, '%s', 'Whitespace', ' ');
        cellRequired = cellRequired{1};
    matRequired = false(length(cellInitial),length(cellInitial{1}));
    for j=1:length(cellInitial)
        strCurr = cellRequired{j};
        for k=1:length(strCurr)
            if strcmp(strCurr(k),'1')
                matRequired(j,k) = true;
            end
        end
    end
    
%     %Determine if any required switches are present
%     for j=1:size(matInitial)
%         vecTemp = matRequired(:,j);
%         
%     end
    matAll = de2bi([0:2^size(matRequired,2)-1]);
    vecWorks = false(size(matAll,1), 1);
    matDesired = sortrows(matRequired);
    for j =1:length(vecWorks)
        matTemp = matAll(j,:);
        matTemp = matTemp(ones(size(matInitial,1),1),:);
        matTest = xor(matTemp, matInitial);
        matTest = sortrows(matTest);
        vecWorks(j) = all(all(logical(matTest==matDesired)));
    end
    
    if ~any(vecWorks)
        cellOut{i} = 'NOT POSSIBLE';
    else
        vecCounts = sum(matAll,2);
        cellOut{i} = sprintf('%d', min(vecCounts(vecWorks)));
    end
    
end

strFinal = '';
for vecNums = 1:numCases;
    strFinal = [strFinal, sprintf('Case #%d: %s\n',vecNums, cellOut{vecNums})];
end

pidFile = fopen(fileOutputFinal, 'w');
fprintf(pidFile, '%s', strFinal);
fclose(pidFile);