#!/usr/bin/env ruby

Infinity = 1.0/0.0


class Helper
  def self.readints
    gets.split.collect{|x| x.to_i}
  end
  def self.readfloats
    gets.split.collect{|x| x.to_f}
  end
end

class Array
  def sum
    reduce(0, :+)
  end
  def avg
    sum.to_f/count
  end
end

module Codejam
  class Pset
    def initialize
      @n = gets.to_i
    end

    def format_res(res)
      if res.nil?
        "IMPOSSIBLE"
      else
        res.to_s
      end
    end

    def output(i, res)
      $s.puts "Case #%d: %s" % [i, format_res(res)]
      #puts "Case #%d: %s" % [i, format_res(res)]
    end

    def run
      (1..@n).each do |i|
        res = yield
        output i, res
      end
    end
  end

  def self.main(&b)
    pset = Pset.new
    pset.run &b
  end


end




class Prob
  # intialize the input data for each test case
  def initialize()
    @n, @l = Helper.readints
    @current = gets.split()
    @final = gets.split()
  end

  def check_correct(to_check)
    ((to_check & @final).size == @n)
  end

  def flipone(arr, switch)
    ret = Array.new
    arr.each do |out1|
      out = out1
      if out[switch-1].to_i == 1
        out[switch-1] = "0"
      else
        out[switch-1] = "1"
      end
      ret << out
    end
    return ret
  end

  def flipmany(arr, sw)
    arr1 = arr
    sw.each do |i|
      arr1 = flipone(arr1, i)
    end
    return arr1
  end

  # return the answer to be printed with Case
  def solve
    if check_correct(@current)
      return 0
    end
    (1..@l).flat_map{|n| (1..@l).to_a.combination(n)}.each do |kl|
      kl.each do |c|
        temp = @current.map do |e| e.dup end
        f = flipmany(temp, c)
        if check_correct(f)
          return c.size
        end
      end
    end
    return 'NOT POSSIBLE'
  end
end



$s = File.open('A-small-output.txt','w')
#$s = File.open('A-big-output.txt','w')

Codejam::main do
  prob = Prob.new
  prob.solve
end

