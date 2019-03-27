#!/bin/bash
#SBATCH --array=1-3
#SBATCH --time=00:05:00
#SBATCH --account=def-m2nagapp
#SBATCH --mem-per-cpu=1024 
#SBATCH --job-name=coderID
#SBATCH --output=sloutput/%x-%j.out

module load python/3.6.3
module load clang/3.8.1


numToRun=$SLURM_ARRAY_TASK_ID #this is slurm task id

echo $numToRun

tmp=$SLURM_TMPDIR #this is allocated temp dir

iter=1

cp -a ~/ENV $tmp	#copy Python env to make things faster
source $tmp/ENV/bin/activate

cp -a "/home/dj2watso/coderID/" $tmp	#copy over the whole coderID dir to make things quicker

#tail $tmp/coderID/runAllExperiments.sh
#ls $tmp

SourceDir="/home/dj2watso/projects/def-m2nagapp/dj2watso/repos"

echo "Source dir:"$SourceDir

for dir in $SourceDir/*/
do
    if [ "$iter" -eq "$numToRun" ]; then

		base=$(basename $dir)

		echo "copying "$dir" to "$tmp

		rundir=$tmp"/"$base 
		#ls $tmp/coderID

		echo "running "$base" from "$rundir
		tail $tmp/coderID/runAllExperiments.sh
		$tmp/coderID/runAllExperiments.sh $rundir "$base" #run experiments, hopefully all from tmp

		cp $tmp/coderID/classResults/* classResults/	#copy the results back over
		cp $tmp/coderID/plots/* plots/
		cp $tmp/coderID/savedSets/* savedSets/
		
    fi
    let "iter++"
done
