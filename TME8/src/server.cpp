#include "ServerSocket.h"
#include <iostream>
#include <unistd.h>


/**
 * Indications pour faire le TP
 * 
 * cf : https://www.geeksforgeeks.org/socket-programming-cc/
 * 
 * man 7 socket(sockaddr)
 * man 7 tcp (TCP)
 * man 7 ip (sockaddr_in)
 * 
 * server 
 * 		socket
 * 		bind
 * 		listen
 * 		sock = accept
 * 		while( ) {
 * 		read (sock)
 * 		decode (liste ou up ou down ou exit)
 * 		decode arg
 * 		execute operation
 * }
 * 
 * Pour transférer les fichiers, il faut faire une fonction de copie block par block du fichier
 * 
 * 
 */

void copy( int fdsrc, int fddst){
	char buff [256];			//À VOIR QUELLE TAILLE DE BLOCK
	while (1){		// TODO : condition du while
		read(fdsrc,buff, 256);
		write(fddst,buff,256);
	}
	
}

int main00() {
	pr::ServerSocket ss(1664);

	while (1) {
		pr::Socket sc = ss.accept();

		int fd = sc.getFD();

		int lu;
		read(fd, &lu, sizeof(int));
		std::cout << "lu =" << lu << std::endl;
		lu++;
		write(fd, &lu, sizeof(int));
		sc.close();
	}
	ss.close();
	return 0;
}

int main() {
	pr::ServerSocket ss(1664);

	while (1) {
		pr::Socket sc = ss.accept();

		int fd = sc.getFD();

		ssize_t msz = sizeof(int);
		while (1) {
			int lu;
			auto nblu = read(fd, &lu, msz);
			if (nblu == 0) {
				std::cout << "Fin connexion par client" << std::endl;
				break;
			} else if (nblu < msz) {
				perror("read");
				break;
			}
			std::cout << "lu =" << lu << std::endl;

			if (lu == 0) {
				break;
			}
			lu++;
			if (write(fd, &lu, msz) < msz) {
				perror("write");
				break;
			}
			std::cout << "envoyé =" << lu << std::endl;
		}
		sc.close();
	}

	ss.close();
	return 0;
}

