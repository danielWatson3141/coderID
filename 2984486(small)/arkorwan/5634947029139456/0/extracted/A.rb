def f(l,i)
  #p l
  return 0 if i>=l[0][0][0].size
  ok0=true
  ok1=true
  m0=[]
  m1=[]
  l.each{|g|
    break if !ok0 && !ok1
    a0=[]
    a1=[]
    b0=[]
    b1=[]
    g[0].each{|x|
      a= (x[i] == "0") ? a0 : a1
      a<<x
    }
    g[1].each{|x|
      b= (x[i] == "0") ? b0 : b1
      b<<x
    }
    if ok0
      if a0.size == b0.size
	m0<<[a0,b0] unless a0.empty?
	m0<<[a1,b1] unless a1.empty?
      else 
	ok0 = false
      end
    end
    
    if ok1
      if a0.size == b1.size
	m1<<[a0,b1] unless a0.empty?
	m1<<[a1,b0] unless a1.empty?
      else 
	ok1 = false
      end
    end
  }
  
  c0=-1
  c1=-1
  if ok0
    c0 = f(m0,i+1)
    #p "c0 #{c0}"
  end
  if ok1
    c1 = f(m1,i+1)
    c1+=1 if c1>=0
    #p "c1 #{c1}"
  end
  
  r=[c0,c1]
  r.delete(-1)
  if r.size == 0
    return -1
  else 
    return r.min
  end
end

gets.to_i.times{|t|
  gets
  a=gets.split
  b=gets.split
  n=f([[a,b]],0)
  puts "Case ##{t+1}: #{n==-1 ? "NOT POSSIBLE": n}"
}
