
for dir in $1/*/
do
    ./runAllExperiments.sh $dir $(basename $dir)
done