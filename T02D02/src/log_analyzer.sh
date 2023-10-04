#!/bin/bash
if [[ -f "$1" ]] && [[ "$1"=="*.log" ]]; then
file_log=$1
temp_log=temp.log
number_lines=$(wc -l < $file_log)
number_uniq_files=$(awk -F " - " '{print $1}' $file_log | sort | uniq | wc -l)
$(cat files.log | awk '{print}' | sort > $temp_log)
count_change_sha=0
begin=1
temp_line=""
while read -r line; do
    if [ $begin -eq 1 ]; then
        temp_line="${line}"
        begin=2
    else
        path1=$(echo "${line}" | awk -F " - " '{print $1}')
        path2=$(echo "${temp_line}" | awk -F " - " '{print $1}')
        hash1=$(echo "${line}" | awk -F " - " '{print $4}')
        hash2=$(echo "${temp_line}" | awk -F " - " '{print $4}')
        if [[ "${hash1}" != "${hash2}" ]] && [[ "${path1}" == "${path2}" ]]; then
            ((count_change_sha+=1))
        fi
        temp_line=${line}
    fi
done < $temp_log
echo $((number_lines)) $((number_uniq_files)) $((count_change_sha));
else
	echo "File is not exists or incorrect"
fi
if [ -f "$temp_log" ]; then rm $temp_log; fi
