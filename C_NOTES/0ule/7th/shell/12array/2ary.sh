#!/bin/bash

# ${a[2]}  访问数组的第3个元素
# ${#a[*]} 数组元素的个数
# ${#a[@]} 数组元素的个数


a=(111 2222 "AAAA" 'M')
echo ${a[*]}
echo ${a[0]}
echo ${a[1]}
echo ${a[2]}
echo ${a[3]}

echo "数组中元素的个数为:  ${#a[*]}"
echo "数组中元素的个数为:  ${#a[@]}"
echo "=========================="

#$(())
#$[]
#$((${#a[*]} - 1)  数组元素个数减1
for i in `seq 0 $((${#a[*]} - 1))`
do
    #${a[$i]} 相当于a[i]
    echo "第$i个元素为:  ${a[$i]}"
done


exit 0