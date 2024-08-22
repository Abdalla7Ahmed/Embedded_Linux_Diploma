
#!/bin/bash

read -p "enter your name " name
read -p "enter your class name " class_name
read -p "enter your namespace " namespace

echo "your name is : ${name} , class name is : ${class_name} , namespace is ${namespace}"

read -p "do you want to edit anythin ? Y/N " answer

Update_select=("Update_name" "Update_class_name" "Update_namespace")
while [ ${answer} = "Y" ]
do
	echo "1)${Update_select[0]}      2)${Update_select[1]}          3)${Update_select[2]}"
	read -p "what do you want to update " update_number
	if [ ${update_number} -eq 1 ]
	then 
		read -p "enter the new name " name
        elif [ ${update_number} -eq 2 ]
	then
		read -p "enter the new class name " class_name
         elif [ ${update_number} -eq 3 ]
	 then
		read -p "enter the new namespace " namespace
	else  
		echo "wrong option "
	fi
	read -p "do you want to edit anythin ? Y/N " answer
done

echo "the final parameters are : your name is : ${name} , class name is : ${class_name} , namespace is ${namespace}"


echo "
/*************************************************************/
//
//			CopyRight ${name}
//
/*************************************************************/
/*
author : ${name}
date   : `date`
breif  : 
*/
" > ${class_name}.hpp
echo "
namespace ${namespace}{
class ${class_name}{

public:
	${class_name}();
	~${class_name}();
private:
" >> ${class_name}.hpp

read -p "do you want to add any data type ? Y/N " answer
type=("auto" "char" "int" "float" "double" "string")
while [ ${answer} = "Y" ]
do
	echo ${type[@]}
        read -p "please enter the type " data_type 
	for i in ${type[@]}
	do
	
	 	if [ ${data_type} = ${i} ]
		then
			read -p "enter the name " var_name
			if [ ${data_type} = "string" ]
			then
				echo "std::${i} ${var_name} ;"  >> ${class_name}.hpp
			else
				echo "${i} ${var_name} ;"  >> ${class_name}.hpp
			fi
			break
		fi		
	done

	read -p "do you want to add any attributes ? Y/N " answer

done
echo "
};
}
" >> ${class_name}.hpp

echo "
/*************************************************************/
//
//                      CopyRight ${name}
//
/*************************************************************/
/*
author : ${name}
date   : `date`
breif  : 
*/

#include \"${class_name}.hpp\"
namespace ${namespace}{
        ${class_name}::${class_name}() {}
        ~${class_name}::${class_name}() {}

}
" > ${class_name}.cpp

echo " = = = = = = = = the class is created"
