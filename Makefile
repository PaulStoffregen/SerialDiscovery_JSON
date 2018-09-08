SerialDiscovery: SerialDiscovery.c
	gcc -O2 -Wall -o SerialDiscovery SerialDiscovery.c -ludev

clean:
	rm -f SerialDiscovery
