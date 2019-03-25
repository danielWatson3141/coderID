#!/bin/bash
file="$1"
numToRun=1
if [ "$#" -ge 2 ]; then
    numToRun="$2"
fi

iter=0

while IFS= read -r var
do
    if [ "$iter" -eq "$numToRun" ]; then
        repoName="$(cut -d',' -f1 <<<"$var")"
        ./runAllExperiments.sh "$repoName"
    fi
    let "iter++"
done < "$file"