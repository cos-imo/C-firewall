#include "connect.h"

int main(int argc, char* *argv){

	char errbuf[PCAP_ERRBUF_SIZE];
	memset(errbuf, 0, PCAP_ERRBUF_SIZE);
	pcap_if_t *alldevsp = NULL;
	pcap_t *handle = NULL;
	int activate_status, activate_sign;

	if (pcap_findalldevs(&alldevsp, errbuf) == PCAP_ERROR) {
		printf("failed to scan for devices: %s \n", errbuf);
		exit(PCAP_ERROR);
	}

	handle = pcap_create(alldevsp->name, errbuf);

	if (handle == NULL) {
		printf("Couldn't create handle: %s \n", errbuf);
		exit(1);
	}

	activate_status = pcap_activate(handle);

	switch(SIGN(activate_status)){
		case 1:
			printf("error activating capture: %s \n", pcap_statustostr(activate_status));
			break;
		case -1:
			printf("error activating capture: %s \n", pcap_statustostr(activate_status));
			break;
		default:
			printf("ok");
			break;
	}

	pcap_freealldevs(alldevsp);

	return 0;

}
