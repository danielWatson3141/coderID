#!ruby2.0

require "memoize"
include Memoize

require "algorithms"
include Containers
include Algorithms

require "narray"

def write(s)
  $num||=0
  $num+=1
  s=("Case \#%d: "%$num)+s.to_s
  puts s
  #$stderr.puts(s) 
end

def debug(s)
  $stderr.puts(s)
end

#memoize(:func)
#a=NArray.int(5,2)
#minheap=MinHeap.new

def pop(n)
	ret=0
	until n==0
		ret+=1 if n%2==1
		n/=2
	end
	ret
end

gets.to_i.times{
	n,l=gets.split.map(&:to_i)
	ans=9999
	outlet=gets.split.map{|s|s.to_i 2}
	device=gets.split.map{|s|s.to_i 2}.sort

	0.upto(2**l-1){|t|
		ol=outlet.map{|c|c^t}

		if ol.sort==device
			_pop=pop(t)
			ans=_pop if _pop<ans
		end
	}
	ans==9999 ? write("NOT POSSIBLE") : write(ans)

}




