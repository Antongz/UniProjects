#!/bin/bash

while read i
do
docommand=$(./create_pattern.sh $1 $2 $3 $4)
echo $i | $docommand
done


