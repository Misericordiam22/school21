#!/bin/sh

#check file
if [ ! -f $1 ];
then
    echo "File not found!" && exit 0
else
        continue
fi

# check empty
if [ -s $1 ];
then
    continue
else
    echo "File is empty" && exit 0
fi

sed -i.bak "s/$2/$3/g" $1
rm *.bak
FILESIZE=$(stat -f%z $1)
FILESHA=$(shasum -a 256 $1  | awk '{ print $1 }')
TIMEEDIT=$(date "+%Y-%m-%d %H:%M")
echo "$1 - $FILESIZE - $TIMEEDIT - $FILESHA - sha256" >> files.log

