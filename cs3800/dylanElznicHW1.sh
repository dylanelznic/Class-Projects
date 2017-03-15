#!/bin/bash
# Dylan Elznic
# Homework 1 CS3800

dispMenu() {
	echo "select a menu option"
	echo "1- ancestry history"
	echo "2- who is online"
	echo "3- what process any user is running"
	echo "4- exit"
}

#Creates Process Ancestry Tree
ancestry() {
	ps -acefl > testFile.txt
	echo
	echo THE ANCESTRY TREE FOR CURRENT PROCESS IS....
	echo ""
	current=$$
	grep $current testFile.txt | awk '{if ($4=='$current') print $4 "\t" $14;}'
	while [ $current -ne 1 ]
	do
		echo " |"
		current=$(grep $current testFile.txt | awk '{if ($4=='$current') print $5;}')
		grep $current testFile.txt | awk '{if ($4=='$current') print $4 "\t" $14;}'
	done
	rm testFile.txt
	echo
}

#Displays which users are currently using the machine
usersOn() {
	echo
	users | sort | uniq > testFile.txt
	cat testFile.txt
	echo
}

#Displays selected user's processes
processes() {
	echo
	echo -n "Select a currently online user to view his processes: (Type in their username)"
	echo
	users | sort | uniq | tr ' ' '\n' > testFile.txt
	cat -n testFile.txt
	echo
	read select
	ps -acefl | grep $select > testFile.txt
	cat testFile.txt
	echo
	echo
}

#Switch case that calls respective function
selectOpt() {
	read choice
	case $choice in
		1) ancestry ;;
		2) usersOn ;;
		3) processes ;;
		4) exit 0;;	
	esac
}

#Main()
echo "WELCOME"
echo "---------------------------------------------------------"
while true
do
	dispMenu
	selectOpt 
done

chmod 755 h1_01.sh