require 'pp'

def get_initial_flow(string_input)
   flow = {}
   arr = string_input.split(' ')
   arr.each do |item|
      flow[item.to_i(2)] = true
   end
   return flow
end

def get_final(string_input)
   arr = string_input.split(' ')
   final = []
   arr.each do |item|
      final.push(item.to_i(2))
   end
   return final
end

def get_answer_r(flow, final, curr, l, count)
#   print "curr:#{curr}\n"
   if correct_config(flow, final)
      return count
   end
   if curr >= l
      return nil
   end
   answers = []
   (curr...l).each do |i|
      switch = 1 << i
      new_flow = {}
      flow.each do |key, v|
         new_flow[key ^ switch] = true
      end
      ans = get_answer_r(new_flow, final, i + 1, l, count + 1)
      answers.push(ans) if ans
   end

   return nil if answers.empty?
   return answers.min
end

def correct_config(flow, final)
#   print "Flow:"
#   pp flow
#   print "Final:"
#   pp final
   final.each do |f|
      return false if ! flow[f]
   end
   return true
end

file = File.new('a.in', "r")
# read first line.
num_cases = file.gets.to_i
(0...num_cases).each do |c|
   # for each case
   info = file.gets.split(' ')
   n = info[0].to_i
   l = info[1].to_i
   flow = get_initial_flow(file.gets)
   final = get_final(file.gets)
   response =  get_answer_r(flow, final, 0, l, 0)
   response = "NOT POSSIBLE" if ! response
   puts "Case \##{c + 1}: #{response}"
end
file.close
