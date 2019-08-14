#!/bin/bash

host="graham.computecanada.ca"
user="dj2watso"

echo "running"

readarray a < repoList

for repo in $a
do
    
echo "Running session ${repo}"
# Create script file for extraction
    FILE="allExperiments.cid"

cat > $FILE <<- EOM
load ${repo}
compile
pruneAuthors
save
getCounterSet
compile
save
quit
EOM

# Run extraction
python3 coderID.py allExperiments.cid

repo=${repo/\//_}

echo "Copying Files for ${repo}"
#copy save files from savedSets to savedSets on remote
sshpass -pf grahampwd scp -o savedSets/${repo} savedSets/${repo}_counter $user@$host:~/coderID/savedSets/

echo "Launching Graham Analysis on ${repo}"
#launch driver script on remote in detached mode
sshpass -pf grahampwd ssh $user@$host screen -d -m ./runLocal.sh "${repo}"

done