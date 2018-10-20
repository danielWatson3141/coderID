t = gets.to_i

def max_binary(root, tree, visited)
  unvisited = 0
  tree[root].each do |node|
    unvisited +=1 unless visited[node]
  end

  if visited[root]
    return 0
  elsif unvisited < 2
    visited[root] = true
    return 1
  else
    visited[root] = true
    max1 = 0
    max2 = 0
    tree[root].each do |node|
      tmp = max_binary(node, tree, visited)
      if tmp > max1
        max2 = max1
        max1 = tmp
      elsif tmp > max2
        max2 = tmp
      end
    end

    return max1 + max2 + 1
  end
end

1.upto(t) do |i|
  ans = 5000

  n = gets.to_i

  tree = Array.new(n){Array.new}

  1.upto(n-1) do
    x,y = gets.split(" ").map(&:to_i)
    tree[x-1] << y-1
    tree[y-1] << x-1
  end


  0.upto(n-1) do |j|
    visited = Array.new(n){false}
    tmp = max_binary(j, tree, visited)
    ans = (n-tmp) if (n-tmp) < ans
  end

  puts "Case ##{i}: #{ans}"
end
