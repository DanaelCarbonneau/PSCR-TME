#include "Banque.h"
#include <iostream>

using namespace std;

/*Q1 Ecrivez un programme, qui crée N threads de transaction, qui bouclent 1000 fois sur
le comportement est suivant :
• Choisir i et j deux indices de comptes aléatoires, et un montant aléatoire m compris entre 1
et 100.
• Essayer de transférer le montant m de i à j .
• Dormir une durée aléatoire de 0 à 20 ms.*/


const int NB_TRANSCACT = 1000;
void comportement_thread(pr::Banque& b){

	for (int k = 0; k < NB_TRANSCACT ; ++k ){
		int i = ::rand()%b.size()/2;				//Encourage les transferts problématiques pour la comptabilisation
		int j = ::rand()%b.size()/2 + b.size()/2 ;		
		int m = ::rand()%98 +1;
		b.transfert(i,j,m);
		auto r = ::rand()%21;
		std::this_thread::sleep_for(std::chrono::milliseconds(r));
	}
	
}

const int NB_THREAD = 10;
const int NB_COMPTES = 10;
const int SOLDE_BASE = 420;
int main () {
	vector<thread> threads;
	vector<thread> comptables;
	pr::Banque bq(NB_COMPTES,SOLDE_BASE);
	for (int i = 0 ; i < NB_THREAD; ++i){
		threads.emplace_back(comportement_thread, ref(bq));
		
		if (i%2 == 0) comptables.emplace_back(&pr::Banque::comptabiliser,&bq,bq.size()*SOLDE_BASE);
	}

	bq.comptabiliser(bq.size()*SOLDE_BASE);

	for (auto & t : threads) {
		t.join();
	}
	for (auto & c : comptables){
		c.join();
	}

	

	// TODO : tester solde = NB_THREAD * JP
	if(bq.comptabiliser(bq.size() * SOLDE_BASE))
		cout<< "Solde de la banque OK !" << endl;
	return 0;
}
