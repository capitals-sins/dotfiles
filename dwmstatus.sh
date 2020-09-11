#!/bin/bash
# Network speed stuff stolen from http://linuxclues.blogspot.sg/2009/11/shell-script-show-network-speed.html

print_bat(){
	hash acpi || return 0
	onl="$(grep "on-line" <(acpi -V))"
	charge="$(awk '{ sum += $1 } END { print sum }' /sys/class/power_supply/BAT1/capacity)"
	if test -z "$onl"
	then
		# suspend when we close the lid
		#systemctl --user stop inhibit-lid-sleep-on-battery.service
		echo -e "${charge}"
	else
		# On mains! no need to suspend
		#systemctl --user start inhibit-lid-sleep-on-battery.service
		echo -e "${charge}"
	fi
}

print_date(){
	date "+%a-%d-%b-%Y|TIME:%I:%M"
}

while true
do
	xsetroot -name "BATTERY:$(print_bat)|$(print_date)"
	sleep 1
done
