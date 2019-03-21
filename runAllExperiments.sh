#!/bin/bash
REPO="$1"
MIN_COMMITS=50
if [ "$#" -eq 2 ]; then
    MIN_COMMITS="$2"
fi
FILE="allExperiments.cid"

cat > $FILE <<- EOM
new experimentSession
loadGit ${REPO}
compile
pruneGit 1000 50 1000
multiClassSingleModelTest
multiClassTest
twoClassTest
quit
EOM

python3 coderID.py allExperiments.cid
