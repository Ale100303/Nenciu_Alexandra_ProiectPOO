// Nenciu Alexandra - domeniul culiNAr

#include <iostream>
using namespace std;

class Tigaie {
private:
	static int nrGenerator;
	const int nrInventar;
	string producator;
	float greutate;
	int nrMateriale;
	string* material;
	bool esteCeramica;

public:
	
	static int getNrGenerator() {
		return nrGenerator;
	}

	const int getNrInventar() {
		return nrInventar;
	}

	string getProducator() {
		return producator;
	}

	float getGreutate() {
		return greutate;
	}

	int getNrMateriale() {
		return nrMateriale;
	}

	string* getMateriale() {
		return material;
	}

	string getMaterial(int i) {
		if (i >= 0 && i < nrMateriale)
		{
		return material[i];
		}
	}

	bool getEsteCeramica() {
		return esteCeramica;
	}

	void setProducator(string producator) {
		if (producator.length() > 0) {
			this->producator = producator;
		}
	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
	}

	void setNrMateriale(int nrMateriale) {
		if (nrMateriale > 0) {
			this->nrMateriale = nrMateriale;
		}
	}

	void setMateriale(int nrMateriale, string* material) {
		if (nrMateriale > 0) {
			this->nrMateriale = nrMateriale;
			if (this->material != NULL) {
				delete[]this->material;
			}
			this->material = new string[nrMateriale];
			for (int i = 0; i < nrMateriale; i++) {
				this->material[i] = material[i];
			}
		}
	}

	Tigaie(const Tigaie& t) : nrInventar(nrGenerator++) {
			this->producator = t.producator;
			this->greutate = t.greutate;
			this->nrMateriale = t.nrMateriale;
			this->material = new string[t.nrMateriale];
			for (int i = 0; i < t.nrMateriale; i++) {
				this->material[i] = t.material[i];
			}
			this->esteCeramica = t.esteCeramica;
	}

	Tigaie() : nrInventar(nrGenerator++) {
		this->producator = "Lodge";
		this->greutate = 2.54;
		this->nrMateriale = 0;
		this->material = NULL;
		this->esteCeramica = false;
	}

	Tigaie(string producator, float greutate) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->greutate = greutate;
		this->nrMateriale = 0;
		this->material = NULL;
		this->esteCeramica = false;
	}

	Tigaie(string producator, float greutate, int nrMateriale, string* material, bool esteCeramica) : nrInventar(nrGenerator++) {
		this->producator = producator;
		this->greutate = greutate;
		this->nrMateriale = nrMateriale;
		this->material = new string[nrMateriale];
		for (int i = 0; i < nrMateriale; i++) {
			this->material[i] = material[i];
		}
		this->esteCeramica = esteCeramica;
	}

	~Tigaie() {
		if (this->material != NULL) {
			delete[]this->material;
		}
	}

	void afisareTigaie() {
		cout << "Tigaia cu id-ul " << nrInventar << ", produsa de " << producator << ", are " << greutate << " kg.";
		if (nrMateriale != 0) {
			cout << "Aceasta este fabricata din " << nrMateriale << " materiale, si anume: ";
			for (int i = 0; i < nrMateriale; i++) cout << material[i] << ", ";
			cout << ".";
		}
		if (esteCeramica == true) {
			cout << " Tigaia este din ceramica.";
		}
		else {
			cout << " Tigaia nu este din ceramica.";
		}
		cout << endl;
	}
};

int Tigaie::nrGenerator = 1000;

class Cuptor {
private:
	static int nrGenerator;
	const int nrCuptor;
	string producator;
	string culoare;
	bool esteSmart;
	int nrPrograme;
	string* numeProgram;
public:

	static int getNrGenerator() {
		return nrGenerator;
	}

	const int getNrCuptor() {
		return nrCuptor;
	}

	string getProducator() {
		return producator;
	}

	string getCuloare() {
		return culoare;
	}

	bool getEsteSmart() {
		return esteSmart;
	}

	int getNrPrograme() {
		return nrPrograme;
	}

	string* getNumePrograme() {
		return numeProgram;
	}

	string getNumeProgram(int i) {
		if (i >= 0 && i < nrPrograme) {
			return numeProgram[i];
		}
	}

	void setProducator(string producator) {
		if (producator.length() > 0) {
			this->producator = producator;
		}
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setEsteSmart(bool esteSmart) {
		this->esteSmart = esteSmart;
	}

	void setNrPrograme(int nrPrograme) {
		if (nrPrograme > 0) {
			this->nrPrograme = nrPrograme;
		}
	}

	void setPrograme(int nrPrograme, string* numeProgram) {
		if (nrPrograme > 0) {
			this->nrPrograme = nrPrograme;
			if (this->numeProgram != NULL) {
				delete[]this->numeProgram;
			}
			this->numeProgram = new string[nrPrograme];
			for (int i = 0; i < nrPrograme; i++) {
				this->numeProgram[i] = numeProgram[i];
			}
		}
	}

	Cuptor(const Cuptor& c) : nrCuptor(nrGenerator++) {
		this->producator = c.producator;
		this->culoare = c.culoare;
		this->esteSmart = c.esteSmart;
		this->nrPrograme = c.nrPrograme;
		this->numeProgram = new string[c.nrPrograme];
		for (int i = 0; i < c.nrPrograme; i++) {
			this->numeProgram[i] = c.numeProgram[i];
		}
	}

	~Cuptor() {
		if (this->numeProgram != NULL) {
			delete[]this->numeProgram;
		}
	}

	Cuptor() : nrCuptor(nrGenerator++) {
		this->producator = "Electrolux";
		this->culoare = "argintiu";
		this->esteSmart = false;
		this->nrPrograme = 0;
		this->numeProgram = NULL;
	}

	Cuptor(string producator, string culoare) : nrCuptor(nrGenerator++) {
		this->producator = producator;
		this->culoare = culoare;
		this->esteSmart = false;
		this->nrPrograme = 0;
		this->numeProgram = NULL;
	}

	Cuptor(string producator, string culoare, bool esteSmart, int nrPrograme, string* numeProgram) : nrCuptor(nrGenerator++) {
		this->producator = producator;
		this->culoare = culoare;
		this->esteSmart = esteSmart;
		this->nrPrograme = nrPrograme;
		this->numeProgram = new string[nrPrograme];
		for (int i = 0; i < nrPrograme; i++) {
			this->numeProgram[i] = numeProgram[i];
		}
	}

	void afisareCuptor() {
		cout << "Cuptorul cu id-ul " << nrCuptor << ", cu producatorul " << producator << " este culoarea " << culoare << ".";
		if (esteSmart != false) {
			cout << " Cuptorul are " << nrPrograme << " programe smart, si anume: ";
			for (int i = 0; i < nrPrograme; i++) {
				cout << numeProgram[i] << ", ";
			}
		}
		cout << endl;
	}
	friend void esteAlb(Cuptor cuptor);
	friend void acelasiProducator(Cuptor& cuptor, Tigaie& tigaie);
};

void esteAlb(Cuptor cuptor) {
	if (cuptor.culoare == "alb") {
		cout << "Cuptorul este alb.";
	}
	else cout << "Cuptorul nu este alb.";
}

int Cuptor::nrGenerator = 2000;

class SetTacamuri {
private:
	static int nrGenerator;
	const int nrSet;
	string material;
	int nrComponente;
	string* componenta;

public:

	static int getNrGenerator() {
		return nrGenerator;
	}

	const int getNrSet() {
		return nrSet;
	}

	string getMaterial() {
		return material;
	}

	int getNrComponente() {
		return nrComponente;
	}

	string* getComponente() {
		return componenta;
	}

	string getComponenta(int i) {
		if (i >= 0 && i < nrComponente) {
			return componenta[i];
		}
	}

	void setMaterial(string material) {
		if (material.length() > 0) {
			this->material = material;
		}
	}

	void setNrComponente(int nrComponente) {
		if (nrComponente > 0) {
			this->nrComponente = nrComponente;
		}
	}

	void setComponente(int nrComponente, string* componenta) {
		if (nrComponente > 0) {
			this->nrComponente = nrComponente;

		}
	}

	SetTacamuri(const SetTacamuri& s) : nrSet(nrGenerator++) {
		this->material = s.material;
		this->nrComponente = s.nrComponente;
		this->componenta = new string[s.nrComponente];
		for (int i = 0; i < s.nrComponente; i++) {
			this->componenta[i] = s.componenta[i];
			if (this->componenta != NULL) {
				delete[]this->componenta;
			}
			this->componenta = new string[nrComponente];
			for (int i = 0; i < nrComponente; i++) {
				this->componenta[i] = componenta[i];
			}
		}
	}

	~SetTacamuri() {
		if (this->componenta != NULL) {
			delete[]this->componenta;
		}
	}

	SetTacamuri() : nrSet(nrGenerator++), material("otel"), nrComponente(3) {
		this->componenta = new string[3];
		this->componenta[0] = "lingura";
		this->componenta[1] = "furculita";
		this->componenta[2] = "cutit";
	}

	SetTacamuri(string material) : nrSet(nrGenerator++), material(material) {
		this->nrComponente = 3;
		this->componenta = new string[3];
		this->componenta[0] = "lingura";
		this->componenta[1] = "furculita";
		this->componenta[2] = "cutit";
	}

	SetTacamuri(string material, int nrComponente, string* componenta) : nrSet(nrGenerator++), material(material), nrComponente(nrComponente) {
		this->componenta = new string[nrComponente];
		for (int i = 0; i < nrComponente; i++) {
			this->componenta[i] = componenta[i];
		}
	}

	void afisareSetTacamuri() {
		cout << "Setul de tacamuri cu id-ul " << nrSet << " este fabricat din " << material << ". Acesta este alcatuit din " << nrComponente << " tacamuri, adica ";
		for (int i = 0; i < nrComponente; i++) {
			cout << componenta[i] << ", ";
		}
		cout << endl;
	}
};

void acelasiProducator(Cuptor& cuptor, Tigaie& tigaie) {
	if (cuptor.producator == tigaie.getProducator()) cout << "Cele doua au acelasi producator!";
	else cout << "Nu au acelasi producator!";
}

int SetTacamuri::nrGenerator = 3000;

void main()
{
	//pentru Tigaie

	Tigaie tigaie1;
	tigaie1.afisareTigaie();

	string producator2 = "Tefal";
	float greutate2 = 1.95;

	Tigaie tigaie2(producator2, greutate2);
	tigaie2.afisareTigaie();

	string producator3 = "Electrolux";
	float greutate3 = 1.13;
	int nrMateriale3 = 3;
	string* material3 = new string[nrMateriale3];
	material3[0] = "otel";
	material3[1] = "plastic";
	material3[2] = "ceramica";
	bool esteCeramica3 = true;

	Tigaie tigaie3(producator3, greutate3, nrMateriale3, material3, esteCeramica3);
	tigaie3.afisareTigaie();

	cout << endl;

	//pentru Cuptor

	Cuptor cuptor1;
	cuptor1.afisareCuptor();

	string producatorcuptor2 = "Electrolux";
	string culoare2 = "negru";

	Cuptor cuptor2(producatorcuptor2, culoare2);
	cuptor2.afisareCuptor();

	string producatorcuptor3 = "Samsung";
	string culoare3 = "alb";
	bool esteSmart3 = true;
	int nrPrograme3 = 2;
	string* numeProgram3 = new string[nrPrograme3];
	numeProgram3[0] = "defrost";
	numeProgram3[1] = "pizza";

	Cuptor cuptor3(producatorcuptor3, culoare3, esteSmart3, nrPrograme3, numeProgram3);
	cuptor3.afisareCuptor();

	int adaugPrograme = 2;
	string* adaugNumePrograme = new string[adaugPrograme];
	adaugNumePrograme[0] = "pui";
	adaugNumePrograme[1] = "cartofi";

	acelasiProducator(cuptor2, tigaie3);
	cout << endl;

	esteAlb(cuptor3);

	cout << endl;

	//pentru SetTacamuri

	SetTacamuri set1;
	set1.afisareSetTacamuri();

	string materialTacamuri2 = "argint";
	SetTacamuri set2(materialTacamuri2);
	set2.afisareSetTacamuri();

	string materialTacamuri3 = "argint";
	int nrComponente = 4;
	string* componenta = new string[nrComponente];
	componenta[0] = "lingura";
	componenta[1] = "furculita";
	componenta[2] = "cutit";
	componenta[3] = "lingurita desert";

	SetTacamuri set3(materialTacamuri3, nrComponente, componenta);
	set3.afisareSetTacamuri();

	cout << "Setul de tacamuri cu id-ul " << set3.getNrSet() << " este fabricat din " << set3.getMaterial() << ". Acesta este alcatuit din " << set3.getNrComponente() << " tacamuri.";
	cout << endl;
}

