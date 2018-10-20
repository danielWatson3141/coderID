input_file = File.new(ARGV[0])
output_file = File.new(ARGV[0].sub('in', 'out'), 'w')

T = input_file.gets.to_i
1.upto(T) do |x|
  devices_count, bits_count = input_file.gets.split.map { |s| s.to_i } # N, L
  outlets = input_file.gets.split.map { |s| s.to_i(2) }
  devices = input_file.gets.split.map { |s| s.to_i(2) }

  #TODO: Iterate by number of bits on so I can stop at first match.
  flip_count_min = false
  (2 ** bits_count).times do |i|
    if outlets.map { |o| o ^ i }.sort! == devices.sort!
      flip_count = i.to_s(2).count('1')
      flip_count_min = flip_count_min ? [flip_count_min, flip_count].min : flip_count
    end
  end

  y = flip_count_min || 'NOT POSSIBLE'

  output_file.puts "Case ##{x}: #{y}"
end
