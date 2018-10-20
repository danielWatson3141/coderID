function A = solve (infile)

	tic;
	fin=fopen(infile,'r');
	fout=fopen([infile '.out'],'w');
	T=str2num(fgetl(fin))
	
	for t=1:T
		N=fscanf(fin,"%d",1);
		p=fscanf(fin,"%d",N);
		
		A(t) = sum(p(:)'==0:N-1);
		if A(t) > 2
		   s=sprintf("Case #%d: BAD\n",t);
      else
		   s=sprintf("Case #%d: GOOD\n",t);
		endif
		
		fputs(fout,s);
		printf(s);
		fflush(stdout);
	endfor
	
	fclose(fin);
	fclose(fout);
	toc;
endfunction

