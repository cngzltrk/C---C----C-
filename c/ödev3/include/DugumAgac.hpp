#ifndef DUGUMAGAC_HPP
#define DUGUMAGAC_HPP
#include<KuyrukListe.hpp>
class DugumAgac{
	public:
		KuyrukListe *liste;
		DugumAgac *sol;
		DugumAgac *sag;
		DugumAgac(KuyrukListe *lt,DugumAgac *sl=NULL,DugumAgac *sg=NULL){
			liste=lt;
			sol=sl;
			sag=sg;
		}
};

#endif
