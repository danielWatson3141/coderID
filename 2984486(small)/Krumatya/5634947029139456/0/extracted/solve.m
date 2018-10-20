function solve (infile)

	tic;
	fin=fopen(infile,'r');
	fout=fopen([infile '.out'],'w');
	T=str2num(fgetl(fin))
	
	for t=1:T
		disp('********************')
		t
		N=fscanf(fin,"%d",1)
		L=fscanf(fin,"%d",1)

		outs=fscanf(fin,"%s",N);
		outs=reshape(outs,[L N])';
		outs=outs=='1'
		devs=fscanf(fin,"%s",N);
		devs=reshape(devs,[L N])';
		devs=devs=='1'
		
		devs=sortrows(devs);
		
		souts = sum(outs,1);
		sdevs = sum(devs,1);
		
		if !all ( souts == sdevs | souts == N-sdevs )
		   s=sprintf("Case #%d: not possible\n",t);
		else
         idx = souts!=sdevs;
         y = sum(idx);
         outs(:,idx) = !outs(:,idx);
         if all(sortrows(outs)(:)==devs(:))
            success = true;
         else
            idx = souts==sdevs;
            idx = find(idx)
            success = false;
            for i=1:length(idx)
               p = nchoosek(idx,i);
               for j=1:rows(p)
                  temp = outs;
                  temp(:,p(j,:)) = !temp(:,p(j,:));
                  if all(sortrows(temp)(:)==devs(:))
                     y+=i;
                     success = true;
                     break;
                  endif
               endfor
               if success
                  break
               endif
            endfor
         endif
         if success
   		   s=sprintf("Case #%d: %d\n",t,y);
   		else
   		   s=sprintf("Case #%d: not possible\n",t);
   		endif
		endif
		
		fputs(fout,s);
		printf(s);fflush(stdout);
	endfor
	
	fclose(fin);
	fclose(fout);
	toc;
endfunction

