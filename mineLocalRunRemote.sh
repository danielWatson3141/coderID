#!/bin/bash

$host = "graham.computecanada.ca"
$user = "dj2watso"

while read repo;
do
    
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
echo "Running session ${repo}"
python coderID.py allExperiments.cid

$repo = ${repo/\//_}

echo "Copying Files"
#copy save files from savedSets to savedSets on remote
sshpass -pf grahampwd scp -o ${repo} ${repo}_counter $user@$host:~/coderID/savedSets/

echo "Launching Graham Analysis on ${repo}"
#launch driver script on remote in detached mode
sshpass -pf grahampwd ssh $user@$host screen -d -m ./runLocal.sh "${repo}"

done < repoList