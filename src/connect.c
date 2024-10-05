#include "connect.h"

int main(int argc, char* *argv){

	char errbuf[PCAP_ERRBUF_SIZE];
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);
	pcap_if_t *alldevsp = NULL;

	if (pcap_findalldevs(&alldevsp, errbuf) == PCAP_ERROR) {
		printf("failed to scan for devices: %s \n", errbuf);
		exit(PCAP_ERROR);
	}

	pcap_freealldevs(alldevsp);

	return 0;
}
