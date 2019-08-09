#!/bin/bash

$repo = $1

sbatch --job-name=${repo} --export=repo="${repo}" singleExpRun.sh