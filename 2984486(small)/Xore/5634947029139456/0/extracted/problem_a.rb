require 'debugger'
def parse_problemset input_file
  problem = {}
  datastream = ''
  File.open(input_file) do |f|
    datastream = f.read.split("\n")
  end
  problem['size'] = datastream.shift.to_i
  problem['inputs'] = problem['size'].times.map do
    parse_problem(datastream)
  end
  problem
end

def parse_problem datastream
  n, l = datastream.shift.split.map(&:to_i)
  initial = datastream.shift.split.map do |binary_string|
    convert_to_int binary_string.split("").map(&:to_i)
  end
  required = datastream.shift.split.map do |binary_string|
    convert_to_int binary_string.split("").map(&:to_i)
  end
  {:n => n, :l => l, :initial => initial, :required => required}
end

# optimization is to be able to represent the inputs as integers and do bitwise XOR,
# then comparing permutations of initial vs required to have all equal inputs
def convert_to_int binary_array
  n = 0
  until binary_array.empty?
    n <<= 1
    n += binary_array.shift
  end
  n
end

def solve_problem input
  # recursive approach work here?
  # problem the first: determine if there is a solution
  # problem the second: determine optimal solution (which in turn means we need to deal with all potential solutions, therefore... )
  first = input[:initial].shift
  valid_solutions = input[:required].map do |first_match|
    remaining_input = input[:initial].dup
    remaining_req = input[:required].dup
    remaining_req.delete_at(remaining_req.index(first_match))
    checksum = first ^ first_match
    #puts checksum
    #require 'debugger'; debugger
    fail = false
    remaining_input.each do |initial_element|
      required = initial_element ^ checksum
      if found = remaining_req.index(required)
        remaining_req.delete_at(found)
      else
        fail = true
        break
      end
    end
    fail ? nil : checksum
  end
  valid_solutions.compact.map do |bitmask|
    n = 0
    while bitmask > 0
      n += bitmask % 2
      bitmask >>= 1
    end
    n
  end
end

def display_result result, index
  not_possible = "NOT POSSIBLE"
  if result.empty?
    result = not_possible
  else
    result = result.sort.first
  end
  puts "Case ##{index+1}: #{result}"
end

data = parse_problemset(ARGV[0])
data['inputs'].each_with_index do |input,ind|
  result = solve_problem(input)
  display_result(result,ind)
end
