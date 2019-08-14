#!/bin/bash
#SBATCH --time=00:05:00
#SBATCH --account=def-m2nagapp
#SBATCH --ntasks=4
#SBATCH --mem=32G

echo "loading modules..."

module load python/3.6.3
module load clang/3.8.1     #load modules we need

tmp=$SLURM_TMPDIR #this is allocated temp dir

echo "copying environment"
cp -a ~/ENV $tmp	#copy Python env to make things faster
source $tmp/ENV/bin/activate

echo "copying project folder"
cp -a "/home/dj2watso/coderID/" $tmp	#copy over the whole coderID dir to make things quicker

cd $tmp/coderID #switch active dir to temp

# Create script file for experiment
    FILE="experiments.cid"

cat > $FILE <<- EOM
load ${repo}_counter
featureDetect
save
load ${repo}
featureDetect
save
attackWith ${repo}_counter
quit
EOM

echo "running experiments"
# Run experiment file
python coderID.py experiments.cid

cp -a $tmp/coderID/classResults /home/dj2watso/coderID/
cp -a $tmp/coderID/savedSets /home/dj2watso/coderID/
