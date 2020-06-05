#!/bin/bash

#declare the variable
start=0
temp=0
end=0
#switchs
u="-u"
s="-s"

upper=(A B C D E F G H I J K L M N O P Q R S T U V W X Y Z)
lower=(a b c d e f g h i j k l m n o p q r s t u v w x y z)

#function part

#when there exists 2 letters and one is less than 0
returnone()
{
    if [ $start -lt 1 ];then
    start=1
    fi
}

#when the first input greater than the second input,change the order
size()
{
    if [ $start -gt $end ];then
    temp=$start
    start=$end
    end=$temp
    fi
}
#the result with upper letters
fupper ()
{
    echo -e "tr \c"
    echo -e "'[\c"

    for ((i = $start;i<= $end;i++))
    do
    echo -e "${upper[$i-1]}\c"
    done
    echo -e "]' \c"
    echo -e "'[\c"

    for ((i = $end;i>= $start;i--))
    do
    echo -e "${upper[$i-1]}\c"
    done
    echo "]'"
}

#the result with lower letters
flower ()
{

    echo -e "tr \c"
    echo -e "'[\c"

    for ((i = $start;i<= $end;i++))
    do
    echo -e "${lower[$i-1]}\c"
    done

    echo -e "]' \c"
    echo -e "'[\c"

    for ((i = $end;i>= $start;i--))
    do
    echo -e "${lower[$i-1]}\c"
    done

    echo "]'"
}

#consider the different condition
#the number of parameter <=1
if [ $# -le 1 ];then
    echo "tr '[]' '[]'"
    fi

#the number of parameter =2
if [ $# -eq 2 ];then
    if [ $1 = $s ];then
    start=$2 end=$2
    flower
    else
    echo "tr '[]' '[]'"
    fi
fi

#the number of parameter >2

#single number
if [ $# -eq 3 ];then
    if [ $1 = $u ] && [ $2 = $s ] && [ $3 -gt 0 ];then
        start=$3 end=$3
        size
        fupper
    elif [ $1 = $s ] && [ $2 = $u ] &&[ $3 -gt 0 ];then
        start=$3 end=$3
        size
        fupper
    elif [ $1 = $u ] && [ $2 = $s ] || [ $1 = $s ] && [ $2 = $u ] && [ $3 -lt 0 ];then
    echo "tr '[]' '[]'"
    elif [ $1 = $s ] && [ $3 = $u ] && [ $2 -gt 0 ];then
        start=$2 end=$2
        fupper
    elif [ $1 = $s ] && [ $3 = $u ] && [ $2 -lt 1 ];then
        echo "tr '[]' '[]'"
    elif [ $1! = $s ] || [ $2! = $s ];then
        echo "tr '[]' '[]'"
    elif [ $1 = $s ] && [ $2 != $u ] &&[ $3 != $u ]  ;then
        start=$2 end=$3
        size
        returnone
        flower
    fi
fi

if [ $# -ge 2 ] && [ $# -lt 3 ];then
    if [ $1 = $u ] && [ $2 != $s ];then
    exit 1
        if [ $1 = $s ] && [ $2 != $u ];then
            if [ $2 -gt 0 ];then
            start=$2 end=$2
            flower
            fi
        else
        echo "tr '[]' '[]'"
        fi
    fi
fi


#double number
if [ $# -gt 3 ] && [ $# -le 4 ];
then
    if [ $1 = $u ] && [ $2 = $s ];then  #一定有u的存在
        start=$3 end=$4
        size
        returnone
        fupper
    elif [ $1 = $s ] && [ $2 = $u ];then
        start=$3 end=$4
        size
        returnone
        fupper
    elif [ $1 = $s ] && [ $3 = $u ];then
        start=$2 end=$4
        size
        returnone
        fupper
    elif [ $1 = $s ] && [ $4 = $u ];then
        start=$2 end=$3
        size
        returnone
        fupper
    else
        echo "tr '[]' '[]'"
    fi
fi









