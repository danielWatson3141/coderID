N = 1000;
ans = eye(N);

for i = 1:N,
	i
	A = zeros(N, N);
	for j = 1:N,
		if i == j,
			A(i,:) = ones(1, N)*(1./N);
		else
			A(j,i) = 1./N;
			A(j,j) = (N-1)/N;
		end
	end
	ans = ans*A;
end

save("-ascii", "matrix", "ans")
