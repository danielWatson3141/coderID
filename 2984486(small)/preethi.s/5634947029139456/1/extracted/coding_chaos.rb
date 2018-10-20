file_name = ARGV[0]
input = IO.readlines file_name
no_of_test_cases = input.shift
input_cases = input.each_slice(3).to_a

def find_min_switch(initial_flow, required_flow, no_of_devices, length_of_flow)
  initial_flow.map! { |i| i.to_i(2) }
  required_flow.map! { |i| i.to_i(2) }
  results = Array.new
  initial_flow.each_with_index do |initial_flow_item, i|
    results[i]= Array.new
    required_flow.each_with_index do |required_flow_item, index|
      result = initial_flow_item ^ required_flow_item
      results[i][index] = result
    end
  end
  result_common = results[0]
  results.each do |item|
    result_common = result_common & item
  end

  if (result_common.length >=1)
    bits = result_common.map{ |item| countSetBits(item) }
    return bits.min
  else
    return "NOT POSSIBLE"
  end
end

def countSetBits(x)
  return 0 if (x<=0)
  return (x %2 == 0 ? 0 : 1) + countSetBits(x/2);
end


input_cases.each_with_index do |input_case, index|
  first_line = input_case[0].gsub("\n", "").split(' ')
  no_of_devices = first_line[0]
  length_of_flow= first_line[1]
  initial_flow = input_case[1].gsub("\n", "").split(' ')
  required_flow = input_case[2].gsub("\n", "").split(' ')
  min_switch = find_min_switch(initial_flow, required_flow, no_of_devices, length_of_flow)
  puts "Case ##{index+1}: #{min_switch}"
end

