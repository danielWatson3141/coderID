#!/bin/bash
#SBATCH --array=1-98
#SBATCH --time=03:00:00
#SBATCH --account=def-m2nagapp
#SBATCH --ntasks=4
#SBATCH --mem-per-cpu=2048 
#SBATCH --job-name=coderID
#SBATCH --output=sloutput/%x-%j.out
#SBATCH --ntasks=2


module load python/3.6.3
module load clang/3.8.1


numToRun=$SLURM_ARRAY_TASK_ID #this is slurm task id

echo $numToRun

tmp=$SLURM_TMPDIR #this is allocated temp dir

#try renaming localscratch to local for gitpython fix
		
iter=1

cp -a ~/ENV $tmp	#copy Python env to make things faster
source $tmp/ENV/bin/activate

cp -a "/home/dj2watso/coderID/" $tmp	#copy over the whole coderID dir to make things quicker

#tail $tmp/coderID/runAllExperiments.sh
#ls $tmp

SourceDir="/home/dj2watso/projects/def-m2nagapp/dj2watso/coderID/savedSets"

echo "Source dir:"$SourceDir

for dir in $SourceDir/*
do
		echo $dir
    if [ "$iter" -eq "$numToRun" ]; then

			base=$(basename $dir)

			rundir=$tmp"/"$base 
			#ls $tmp/coderID

			echo "running "$base" from "$rundir
			#tail $tmp/coderID/runAllExperiments.sh

			oldWD=$PWD

			cd $tmp/coderID

			echo "now in "$PWD
			ls ../

			./runAllExperiments.sh "$base" "$base" #run experiments, hopefully all from tmp

			cp classResults/* $oldWD/classResults/	#copy the results back over
			cp plots/* $oldWD/plots/
			cp savedSets/* $oldWD/savedSets/

			cd $oldWD
    fi
    let "iter++"
done
