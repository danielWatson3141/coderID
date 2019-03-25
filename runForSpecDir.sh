#SBATCH --array=1-3
#SBATCH --time=00:02:00
#SBATCH --account=def-m2nagapp

module load python/3.6.3
module load clang/3.8.1

numToRun=$SLURM_ARRAY_TASK_ID #this is slurm task id

SourceDir="$1" #this is source directory with a bunch of repos in it

tmp=$SLURM_TMPDIR #this is allocated temp dir

iter=0

for dir in $SourceDir/*/
do
    if [ "$iter" -eq "$numToRun" ]; then
        cp $SourceDir$dir $tmp$dir #copy repo to temp dir for efficiency
        ./runAllExperiments.sh "$tmp$dir" "$dir" 
    fi
    let "iter++"
done