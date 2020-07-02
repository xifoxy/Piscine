ifconfig -a | grep "ether " | cut -d " " -f 2
ifconfig -a | grep 'ether ' | sed 's/.*ether //g' | tr -d ' '