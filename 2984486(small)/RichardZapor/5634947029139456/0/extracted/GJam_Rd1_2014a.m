function GJam_Rd1_2014a
% 
%Circuit
fn='A-small-attempt3.in';
%fn='A-small-practice.in';
%fn='A-large-practice.in';
[data] = read_file(fn); % 

fidG = fopen('A-small-output3.out', 'w');
%fidG = fopen('B-large-output.out', 'w');
%fidC = fopen('B-small-Cody1.out', 'w');
%fidC = fopen('B-large-Cody.out', 'w');

 
tic
for i=1:size(data,2) % Cell array has N rows of cases
 val = switches(data{i}) ;%  
 %data{i}
 
  if val<0
   fprintf(fidG,'Case #%i: NOT POSSIBLE\n',i);
   fprintf('Case #%i: NOT POSSIBLE\n',i);
  else
   fprintf(fidG,'Case #%i: %i\n',i,val);
   fprintf('Case #%i: %i\n',i,val);
  end
  
end
toc

fclose(fidG);
end

function val=switches(m)
 val=0;
 [nr,nc]=size(m);
 v1=sortrows(m(:,1:nc/2));
 v2=sortrows(m(:,nc/2+1:end));
 nc=nc/2;
%  for j=1:nc
%   c1=nnz(v1(:,j));
%   c2=nnz(v2(:,j));
%   if c1==c2 || nr-c1==c2,continue;end % must match to make 
%   return; % fail
%  end
 
 % brute force try all binary vectors and see min that gets match
if isequal(v1,v2),return;end
val=nc+1;
for i=0:2^nc-1

 v1t=v1;
 v=dec2bin(i,nc)-'0';
 vnz=nnz(v);
 if vnz>val,continue;end
 for j=1:nc
  if v(j)
   v1t(:,j)=1-v1t(:,j);
  end
 end
 v1t=sortrows(v1t);
 if isequal(v1t,v2)
%   v1t
%   v2
  val=vnz;
 end
 
end

if val>nc,val=-1;end
 
 
 
 
 
 
  
end


function [d] = read_file(fn)
d={};
fid=fopen(fn);
fgetl(fid); % Total Count ignore
ptr=0;
while ~feof(fid)
 ptr=ptr+1;
 v=str2num(fgetl(fid)); % cols,elements
 str=fgetl(fid);
 str=reshape(strrep(str,' ',''),v(2),v(1))';
 m=str-'0';

 str=fgetl(fid);
 str=reshape(strrep(str,' ',''),v(2),v(1))';
 m=[m str-'0'];
 
 d{ptr}=m;
 
end % feof
 fclose(fid);

end % read_file


%{
% fast odd solver
 val=0;
 if mod(nr,2)
  for j=1:nc
   c1=nnz(v1(:,j));
   c2=nnz(v2(:,j));
   if c1~=c2
    v1(:,j)=1-v1(:,j);
    val=val+1;
   end
  end
 
  v1=sortrows(v1);
  v2=sortrows(v2);
  if ~isequal(v1,v2)
   v1
   v2
   val=-1;
  end
  return;
 end
 
 % even row cases
%}





