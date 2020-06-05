#!/bin/bash


#declare the variable
encode=$(cat $1)
unencode=$(cat $2)
encode_arr=()
unencode_arr=()
encode_array=()
decode_array=()
neweundecode_array=()
newdecode_array=()
enum=0 #for spilt the single letter of the encode
unum=0 #for spilt the single letter of the unencode
len=0 #length for the array ,they are same length i guess
islower=true
check_letter=true
check_same=false


upper=(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)
lower=(a b c d e f g h i j k l m n o p q r s t u v w x y z)


if [[ {$encode} = {$unencode} ]];then
check_same=true;
exit;
fi

#read the line in the txt
#encode part
for line in $encode;
do
    encode_arr[${#encode_arr[@]}]=$line
done
#unencode part
for line in $unencode;
do
    unencode_arr[${#unencode_arr[@]}]=$line
done



#make the every single letter spilt to the array
#encode part
for i in `seq 1 100`
do
    encode_array[$enum]=`echo ${encode_arr[@]}|cut -c$i`
    ((enum++))
done

#unencode part
for i in `seq 1 100`
do
    unencode_array[$unum]=`echo ${unencode_arr[@]}|cut -c$i`
    ((unum++))
done


#delete the space
for((i=0;i<$enum;i++))
do
    if [[ ${encode_array[i]} = " " ]] || [[ ${encode_array[i]} = "" ]] ;then
        unset encode_array[i]
    fi
done
#unencode part
for((i=0;i<$unum;i++))
    do
    if [[ ${unencode_array[i]} = " " ]] || [[ ${unencode_array[i]} = "" ]] ;then
        unset unencode_array[i]
    fi
done


#find the same things in two array
for((i=0;i<100;i++))
do
    if [[ "${unencode_array[i]}" =  "${encode_array[i]}" ]];then
        unset unencode_array[i]
        unset encode_array[i]
    fi
done
len=${#encode_array[@]}
len1=${#unencode_array[@]}

#delete the same things in the one array
#encode part

for((i=0;i<100;i++))
    do
        for((j=100;j>i;j--))
        do
            if [[ ${encode_array[i]} = ${encode_array[j]} ]];then
                unset encode_array[j]
            fi
    done
done

#unencode
for((i=0;i<100;i++))
    do
        for((j=100;j>i;j--))
        do
            if [[ ${unencode_array[i]} = ${unencode_array[j]} ]]  ;then
                unset unencode_array[j]
            fi
    done
done



#check if the encode part is upper letter or lower letter
for((i=0;i<26;i++))
do
    if [ $check_letter = true ];then
        if [[ "${lower[i]}" = "${unencode_array[0]}" ]] || [[ "${lower[i]}" = "${unencode_array[1]}" ]] || [[ "${lower[i]}" = "${unencode_array[2]}" ]];then
        islower=true
        check_letter=false
        elif [[ "${upper[i]}" = "${unencode_array[@]}" ]]|| [[ "${upper[i]}" = "${unencode_array[1]}" ]] || [[ "${upper[i]}" = "${unencode_array[2]}" ]];then
        islower=false
        check_letter=false
        fi
    fi
done

#if the letter is lower
if [ $islower = true ] && [[ $check_same = false ]];then
    intnum=0
    for((i=0;i<100;i++))
    do
        for((j=0;j<26;j++))
        do
            if [[ "${unencode_array[i]}" = "${lower[j]}" ]];then
                newarrfortheint_unencode[intnum]=$j
                ((intnum++))
            fi
        done
    done

    intnum=0
    for((i=0;i<50;i++))
    do
        for((j=0;j<26;j++))
        do
            if [[ "${encode_array[i]}" = "${lower[j]}" ]];then
                newarrfortheint_encode[intnum]=$j
                ((intnum++))
            fi
        done
    done
#copy the other array unencode interger for check the number of the smallest letter
intnum2=0
for((i=0;i<50;i++))
do
for((j=0;j<26;j++))
do
    if [[ "${unencode_array[i]}" = "${lower[j]}" ]];then
        newarrfortheint_unencode2[intnum2]=$j
        ((intnum2++))
    fi
    done
done

l=${#newarrfortheint_unencode[@]}
#length of the array encode interger
l2=${#newarrfortheint_encode[@]}


#sort for the smallest letter
for((i=0;i<l-1;i++))
do
for((j=0;j<l-i-1;j++))
do
if [[ ${newarrfortheint_unencode[j]} -ge ${newarrfortheint_unencode[j+1]} ]];then
    temp=${newarrfortheint_unencode[j]}
    newarrfortheint_unencode[j]=${newarrfortheint_unencode[j+1]}
    newarrfortheint_unencode[j+1]=$temp
fi
done
done

#result equal the smallest part
res=0
for((i=0;i<l;i++))
do
if [[ ${newarrfortheint_unencode[0]} -eq ${newarrfortheint_unencode2[i]} ]];then
res=$i
fi
done

let result1=${newarrfortheint_unencode[0]}+1
let result2=${newarrfortheint_encode[res]}+1
echo $result1 $result2

#the part is the upper letter
elif [ $islower = false ] && [[ $check_same = false ]]; then
    intnum=0

    for((i=0;i<100;i++))
        do
            for((j=0;j<26;j++))
            do
                if [[ "${unencode_array[i]}" = "${upper[j]}" ]];then
                    newarrfortheint_unencode[intnum]=$j
                    ((intnum++))
            fi
        done
    done

    intnum=0
    for((i=0;i<100;i++))
    do
        for((j=0;j<26;j++))
        do
            if [[ "${encode_array[i]}" = "${upper[j]}" ]];then
                newarrfortheint_encode[intnum]=$j
                ((intnum++))
            fi
        done
    done
#copy the other array unencode interger for check the number of the smallest letter
intnum2=0
for((i=0;i<100;i++))
    do
        for((j=0;j<26;j++))
            do
                if [[ "${unencode_array[i]}" = "${upper[j]}" ]];then
                    newarrfortheint_unencode2[intnum2]=$j
                    ((intnum2++))
            fi
        done
    done

#length of the array unencode interger
l=${#newarrfortheint_unencode[@]}
#length of the array encode interger
l2=${#newarrfortheint_encode[@]}


#sort for the smallest letter
for((i=0;i<l-1;i++))
do
for((j=0;j<l-i-1;j++))
do
if [[ ${newarrfortheint_unencode[j]} -ge ${newarrfortheint_unencode[j+1]} ]];then
    temp=${newarrfortheint_unencode[j]}
    newarrfortheint_unencode[j]=${newarrfortheint_unencode[j+1]}
    newarrfortheint_unencode[j+1]=$temp
fi
done
done

#result equal the smallest part
res=0
for((i=0;i<l;i++))
do
if [[ ${newarrfortheint_unencode[0]} -eq ${newarrfortheint_unencode2[i]} ]];then
res=$i
fi
done

let result1=${newarrfortheint_unencode[0]}+1
let result2=${newarrfortheint_encode[res]}+1
echo $result1 $result2 "-u"

fi

