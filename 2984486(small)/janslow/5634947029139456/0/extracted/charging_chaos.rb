#!/usr/bin/env ruby
number_of_cases = gets.to_i

cases = []
number_of_cases.times do |i|
  c = {}
  c[:i] = i + 1
  c[:device_count], c[:switch_count] = gets.split.collect(&:to_i)
  c[:outlets] = gets.split.collect {|s| s.to_i(2) }.sort
  c[:devices] = gets.split.collect {|s| s.to_i(2) }.sort
  cases.push c
end

def goal devices, state
  devices == state[:outlets]
end

def result state, action
  outlets = state[:outlets]
  outlets = outlets.collect { |o| o ^ action }.sort
  return { :outlets => outlets, :cost => state[:cost] + 1 }
end
def actions switch_count
  possible_actions = []
  j = 1
  switch_count.times do |i|
    possible_actions.push j
    j = j << 1
  end
  return possible_actions
end

cases.each do |c|
  devices = c[:devices]
  possible_actions = actions c[:switch_count]

  initial_state = { :outlets => c[:outlets], :cost => 0 }

  explored = []
  explored.push initial_state[:outlets]

  queue = []
  queue.push initial_state

  if goal devices, initial_state
    result = initial_state
  end

  until result || queue.empty?
    s = queue.shift
    for a in possible_actions
      r = result s, a
      if goal devices, r
        result = r
      else
        unless explored.include? r[:outlets]
          explored.push r[:outlets]
          queue.push r
        end
      end
    end
  end
  
  if result
    printf "Case \#%d: %d\n", c[:i], result[:cost]
  else
    printf "Case \#%d: NOT POSSIBLE\n", c[:i]
  end
end