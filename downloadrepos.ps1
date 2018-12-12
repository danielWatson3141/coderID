$target = $args[0] #target repo
$outputDir = $args[1]
cd $outputDir

$url  = -join("https://github.com/",$target,".git")

git clone $url