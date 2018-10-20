fs = require 'fs'

intersection = (a, b) ->
  [a, b] = [b, a] if a.length > b.length
  value for value in a when value in b

fs.readFile 'A-small-attempt2.in',
  encoding:  'utf8'
  , (err, data) -> 
    dataArray = data.split '\n'
    for i in [0...parseInt(dataArray[0])]
      deviceNo = parseInt(dataArray[1+(i*3)].split(" ")[0])
      switches = parseInt(dataArray[1+(i*3)].split(" ")[1])
      map = dataArray[2+(i*3)].split(" ").map (elemt) -> parseInt(elemt,2)
      startMap = dataArray[2+(i*3)].split(" ").map (elemt) -> parseInt(elemt,2)
      requiredMap = dataArray[3+(i*3)].split(" ").map (elemt) -> parseInt(elemt,2)

      counter = 0
      boundCounter = Math.pow 2, switches

      intersectionLength = intersection(map, requiredMap).length

      while (intersectionLength < requiredMap.length) and (counter < boundCounter)
        ++counter
        map = startMap.map (elemt) ->
          Number(elemt ^ counter)
        console.log startMap, map, requiredMap, counter, Number(counter).toString(2).split('1').length - 1
        intersectionLength = intersection(map, requiredMap).length




      if counter >= boundCounter
        response =  "Case ##{i+1}: NOT POSSIBLE\n"
      else
        response =  "Case ##{i+1}: #{Number(counter).toString(2).split('1').length - 1}\n"

      fs.appendFile "output.out", response, ->