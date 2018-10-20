%Prob C
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

matTest = zeros(120,1000);
for i=1:numCases
    vecIn = textscan(cellFullFile{2*i}, '%f', 'Whitespace', ' ');
        vecIn = vecIn{1};
    matTest(i,:) = vecIn;
end
matVerify = 0:size(matTest,2)-1;
matVerify = matVerify(ones(size(matTest,1),1),:);
vecVerify = sum(matVerify.*matTest,2);
vecVerify = sort(vecVerify);
valMean = vecVerify(109);
for i=1:numCases
   if vecVerify(i) > valMean
       cellOut{i} = 'BAD';
   else
       cellOut{i} = 'GOOD';
   end
end

strFinal = '';
for vecNums = 1:numCases;
    strFinal = [strFinal, sprintf('Case #%d: %s\n',vecNums, cellOut{vecNums})];
end

pidFile = fopen(fileOutputFinal, 'w');
fprintf(pidFile, '%s', strFinal);
fclose(pidFile);