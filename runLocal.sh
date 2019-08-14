#!/bin/bash

cd coderID

sbatch --job-name=${repo} --export=repo=$1 singleExpRun.sh

