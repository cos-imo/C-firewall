#include "connect.h"

int main(int argc, char* *argv) {

	int msg = messages();

	return msg;

}

int messages(){
	char errbuf[PCAP_ERRBUF_SIZE];

	pcap_if_t* *alldevsp;
	int dev;

	dev = pcap_findalldevs(alldevsp, errbuf);
	if (dev == PCAP_ERROR) {
		fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
		return(2);
	}


	return 0;
}


