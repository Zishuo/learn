/*
 * main.cpp
 *
 *  Created on: Feb 9, 2014
 *      Author: root
 */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory>
using namespace std;
int main(int argc, char * argv[]){
	// ./Demo_inet_h 192.168.0.1
	cout << "Input : " << argv[1] << endl;

	in_addr_t local_na = inet_network(argv[1]);
	cout << "inet_network : " << local_na << endl;

	in_addr_t netwk_na = htonl(local_na);
	cout << "htonl : " << netwk_na << endl;

	local_na = ntohl(netwk_na);
	cout << "ntohl : " <<  local_na << endl;


	in_addr ip;
	inet_aton(argv[1],&ip);
	cout <<  "inet_aton : " << ip.s_addr << endl;
	//inet_ntoa return a static memory that is required by kernel.
	//Thus we should copy out the result.
	char * p = inet_ntoa(ip);
	//This is a bad example.
	//free(p);

	cout << "inet_ntoa : " << p  <<endl;

	in_addr_t host = inet_lnaof(ip),net = inet_netof(ip);
	cout << "inet_lnaof : " << host <<endl;
	cout << "inet_netof : " << net <<endl;

	in_addr combined = inet_makeaddr(net,host);
	cout << "inet_makeaddr : " << combined.s_addr << endl;

	return 0;
}

