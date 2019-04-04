#!/bin/bash
REPO="$1"
SESSION="$2"
MIN_FUNCTIONS=50

echo "running session "$SESSION" for "$REPO
echo "from "$PWD

# Parse command line args
if [ "$#" -gt 3 ] || [ "$#" -lt 1 ]; then
    echo "Invalid number of parameters. Usage: ./$0 repopath [ sessionName ] [ minFunctions ]"
    exit 1
fi

if [ "$#" -ge 2 ]; then
    SESSION="$2"
fi
if [ "$#" -ge 3 ]; then
    MIN_FUNCTIONS="$3"
fi

# Create script file
FILE="allExperiments.cid"

cat > $FILE <<- EOM
load ${REPO}
displayGitAuthors
pruneGit 1000 ${MIN_FUNCTIONS} 1000
multiClassSingleModelTest
multiClassTest
twoClassTest
quit
EOM

# Run experiments
echo "Running session ${SESSION}"
python coderID.py allExperiments.cid
