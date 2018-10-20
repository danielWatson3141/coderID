program solution
  integer :: T, i, N, j, x(1000), lx, s
  read *, T
  do i=1,T
     read *, N
     read *, (x(lx), lx=1,N)
     s=0
     do j=0,N-1
        if (x(j) < j) s=s+1
     end do
     if (s > 485) then
        write(*, "('Case #', i0,': GOOD')") i
     else
        write(*, "('Case #', i0,': BAD')") i
     endif
  end do
end program
