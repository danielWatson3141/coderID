require 'json'
def read_input
  fin = File.open "in.txt"
  fout = File.open "out.txt", "w"
  cases = fin.readline.to_i
  (1..cases).each do |prob|
    fout.write "Case ##{prob}: #{solve_case fin}\n"
  end
  fin.close
  fout.close
end

def solve_case(f)
  specs = f.readline.split(" ")
  devices = specs[0]
  length_of_charge = specs[1].to_i
  
  initial_charges = f.readline.split(" ").sort
  target_charges = f.readline.split(" ").sort
  
  return "0" if initial_charges == target_charges
  combinations = []
  (1..length_of_charge).each do |index|
    combinations << index
  end
  
  combinations.each do |combination_number|
    cases = combinations.combination(combination_number).to_a
    cases.each do |caze|
      new_charges = flip(initial_charges.clone, caze)
      if caze == [1,2,3,4,5,7,8,9]
        #puts JSON.generate caze
        #puts JSON.generate(new_charges)
      end
      if new_charges == target_charges
        #puts JSON.generate(new_charges)
        #puts JSON.generate(caze)
        return caze.length 
      end
    end
  end
  
  "NOT POSSIBLE"
end

def flip(charges, index_array)
  #puts JSON.generate(charges) if index_array == [1,2,3,4,5,7,8,9]
  new_charges = []
  charges.each do |charge|
    charge = charge.clone
    #puts charge if index_array == [1,2,3,4,5,7,8,9]
    index_array.each do |index|
      charge[index-1] = charge[index-1] == "0" ? "1" : "0"
      #puts charge if index_array == [1,2,3,4,5,7,8,9]
    end
    #puts "=============" if index_array == [1,2,3,4,5,7,8,9]
    new_charges << charge
  end
  new_charges.sort
end

read_input
