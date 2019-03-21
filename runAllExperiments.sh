#!/bin/bash
REPO="$1"
SESSION="experimentSession"
MIN_COMMITS=50

if [ "$#" -gt 3 ] || [ "$#" -lt 1 ]; then
    echo "Invalid number of  paramters. Usage: ./$0 repopath [ sessionName ] [ minCommits ]"
    exit 1
fi

if [ "$#" -ge 2 ]; then
    SESSION="$2"
fi
if [ "$#" -ge 3 ]; then
    MIN_COMMITS="$3"
fi

FILE="allExperiments.cid"

cat > $FILE <<- EOM
new ${SESSION}
loadGit ${REPO}
compile
pruneGit 1000 ${MIN_COMMITS} 1000
multiClassSingleModelTest
multiClassTest
twoClassTest
quit
EOM

echo "Running session ${SESSION}"
python3 coderID.py allExperiments.cid
