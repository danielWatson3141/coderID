#!/usr/bin/env ruby

module GoogleCodeJam
  def self.run_solver(test_case)
    File.open test_case do |f|
      total_cases = f.gets.chomp.to_i
      total_cases.times do |case_num|
        n, l = f.gets.chomp.split.map(&:to_i)
        electric_flows = f.gets.chomp.split
        devices = f.gets.chomp.split
        ret = yield [n, l, electric_flows, devices]
        puts "Case ##{case_num + 1}: #{ret}"
      end
    end
  end
end



def solve(args)
  n, l, electric_flows, devices = args
  ret = nil

  l.times do |bit|
    ef = electric_flows.select { |ef| ef[bit] == '0' }.size
    d = devices.select { |d| d[bit] == '0' }.size
    return 'NOT POSSIBLE' if d != ef and d != n - ef
  end

  possible_flips = {}
  electric_flows.each do |ef|
    devices.each do |d|
      flip = '0' * l
      l.times { |bit| flip[bit] = '1' if ef[bit] != d[bit] }
      possible_flips[flip] = true
    end
  end

  flips = possible_flips.keys.sort_by { |flips| flips.count('1') }
  #p flips
  flips.each do |flip|
    #puts flip
    flipped_electric_flows = []
    electric_flows.each do |ef|
      ret = ''
      l.times do |bit|
        if flip[bit] == '0'
          ret << ef[bit]
        else
          ret << ((ef[bit].to_i + 1) % 2).to_s
        end
      end
      flipped_electric_flows << ret
    end

    #p flipped_electric_flows
    if flipped_electric_flows.sort == devices.sort
      return flip.count('1')
    end
  end

  return 'NOT POSSIBLE'
end

def main argv
  GoogleCodeJam.run_solver(argv[0]) { |args| solve args }
end

if __FILE__ == $0
  main ARGV
end