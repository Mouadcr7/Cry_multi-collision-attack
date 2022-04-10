#!/bin/bash
counter=1
while [ $counter -le 10 ]
do
./test >> res.txt
counter=$(($counter + 1))
done

