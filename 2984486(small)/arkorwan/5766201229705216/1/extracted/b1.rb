@a=nil

@chc={}
@chb={}


def ky(r,parent)
  y=parent == nil ? -1 : parent
  return r*2000+y
end

def cnt(r,parent)
  k=@chc[ky(r,parent)]
  return k if k
  l=@a[r].clone
  l.delete(parent) if parent
  co=1
  l.each{|c| co+=cnt(c,r)} 
  @chc[ky(r,parent)] = co
  return co
end

def bt(r,parent)
  k=@chb[ky(r,parent)]
  return k if k

  l=@a[r].clone
  l.delete(parent) if parent
  x=0
  if l.size == 0
    x=0
  elsif l.size == 1
    x=cnt(l[0],r)
  elsif l.size == 2
    x=bt(l[0],r)+bt(l[1],r)
  else
  
    e=[]
    f=0
    l.size.times{|i|
      g=cnt(l[i],r)
      f+=g
      b=g-bt(l[i],r)
      e<<b
    }
    e.sort!
    x=f-e[-1]-e[-2]
  end
  #p [r,parent,x]
  @chb[ky(r,parent)]=x
  return x
end

gets.to_i.times{|t|
  n=gets.to_i
  @a=[]
  @chc={}
  @chb={}
  n.times{|i|
    @a<<[]
  }
  (n-1).times{|i|
    x,y=gets.split.map(&:to_i)
    @a[x-1]<<y-1
    @a[y-1]<<x-1
  }
  
  #p @a
  
  x=(0..n-1).to_a.map{|m| bt(m,nil)}.min
  puts "Case ##{t+1}: #{x}"
}