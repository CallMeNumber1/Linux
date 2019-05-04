#!/bin/bash
for i in `w -h | awk '{print $2}'`; do
    echo "`who am i`" >> /dev/$i
    echo $1 >> /dev/$i
done
