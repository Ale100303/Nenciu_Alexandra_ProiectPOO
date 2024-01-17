// Nenciu Alexandra - domeniul culiNAr

#include <iostream>
#include <fstream>
using namespace std;

class Produs {
	string nume;
public:
	virtual void descrieProdus() = 0;

	Produs() {
		this->nume = "Nume produs";
	}
	
	string getNume() {
		return nume;
	}

	void setNume(string nume) {
		this->nume = nume;
	}
};



class Tigaie :public Produs{
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

	Tigaie(const Tigaie& t) : Produs(), nrInventar(nrGenerator++) {
		this->producator = t.producator;
		this->greutate = t.greutate;
		this->nrMateriale = t.nrMateriale;
		this->material = new string[t.nrMateriale];
		for (int i = 0; i < t.nrMateriale; i++) {
			this->material[i] = t.material[i];
		}
		this->esteCeramica = t.esteCeramica;
	}

	Tigaie() : Produs(), nrInventar(nrGenerator++) {
		this->producator = "Lodge";
		this->greutate = 2.54;
		this->nrMateriale = 0;
		this->material = NULL;
		this->esteCeramica = false;
	}

	Tigaie(string producator, float greutate) : Produs(), nrInventar(nrGenerator++) {
		this->producator = producator;
		this->greutate = greutate;
		this->nrMateriale = 0;
		this->material = NULL;
		this->esteCeramica = false;
	}

	Tigaie(string producator, float greutate, int nrMateriale, string* material, bool esteCeramica) : Produs(), nrInventar(nrGenerator++) {
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

	void descrieProdus() {
		cout << "Tigaia este produsa de " << this->producator << " si are " << this->greutate << " g.";
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

	Tigaie operator=(const Tigaie& t) {
		if (this != &t) {
			Produs::operator=(t);
			this->producator = t.producator;
			this->greutate = t.greutate;
			this->nrMateriale = t.nrMateriale;
			if (this->material != NULL) {
				delete[]this->material;
			}
			this->material = new string[t.nrMateriale];
			for (int i = 0; i < t.nrMateriale; i++) {
				this->material[i] = t.material[i];
			}
			this->esteCeramica = t.esteCeramica;
		}
		return *this;
	}

	Tigaie operator+(int val) {
		Tigaie aux = *this;
		aux.greutate = this->greutate + val;
		return aux;
	}
	friend istream& operator>>(istream& tastatura, Tigaie& t);
	friend ofstream& operator<<(ofstream& fisier, Tigaie t);
	friend ifstream& operator>>(ifstream& fisier, Tigaie& t);
	friend ostream& operator<<(ostream& monitor, const Tigaie& t);
};

ostream& operator<<(ostream& monitor, const Tigaie& t) {
	monitor << "Tigaia cu id-ul " << t.nrInventar << ", produsa de " << t.producator << ", are " << t.greutate << " kg.";
	if (t.nrMateriale != 0) {
		monitor << "Aceasta este fabricata din " << t.nrMateriale << " materiale, si anume: ";
		for (int i = 0; i < t.nrMateriale; i++) monitor << t.material[i] << ", ";
		monitor << ".";
	}
	if (t.esteCeramica == true) {
		monitor << " Tigaia este din ceramica.";
	}
	else {
		monitor << " Tigaia nu este din ceramica.";
	}
	return monitor;
}

ofstream& operator<<(ofstream& fisier, Tigaie t) {
	fisier << t.getProducator() << endl << t.getGreutate() << endl;
	fisier << t.getNrMateriale() << endl;
	if (t.getNrMateriale() != 0) {
		for (int i = 0; i < t.getNrMateriale(); i++) fisier << t.getMaterial(i)<<" ";
	}
	if (t.getEsteCeramica() == true) {
		fisier << "1";
	}
	else {
		fisier << "0";
	}
	fisier << endl;
	return fisier;
}

istream& operator>>(istream& tastatura, Tigaie& t) {
	cout << "Producator: ";
	tastatura >> t.producator;
	cout << endl << "Greutate: ";
	tastatura >> t.greutate;
	cout << endl << "Nr. materiale: ";
	tastatura >> t.nrMateriale;
	if (t.material != NULL) {
		delete[]t.material;
	}
	t.material = new string[t.nrMateriale];
	if (t.nrMateriale > 0) {
		for (int i = 0; i < t.nrMateriale; i++) {
			cout << endl << "Material " << i + 1 << ": ";
			tastatura >> t.material[i];
		}
	}
	cout << endl << "Este ceramica? ";
	tastatura >> t.esteCeramica;
	return tastatura;
}

ifstream& operator>>(ifstream& fisier, Tigaie& t) {;
	fisier >> t.producator;
	fisier >> t.greutate;
	fisier >> t.nrMateriale;
	if (t.material != NULL) {
		delete[]t.material;
	}
	t.material = new string[t.nrMateriale];
	for (int i = 0; i < t.nrMateriale; i++) {
		fisier >> t.material[i];
	}

	fisier >> t.esteCeramica;
	return fisier;
}

int Tigaie::nrGenerator = 1000;

class Cuptor : public Produs {
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

	Cuptor(const Cuptor& c) : Produs(), nrCuptor(nrGenerator++) {
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

	Cuptor() : Produs(), nrCuptor(nrGenerator++) {
		this->producator = "Electrolux";
		this->culoare = "argintiu";
		this->esteSmart = false;
		this->nrPrograme = 0;
		this->numeProgram = NULL;
	}

	Cuptor(string producator, string culoare) : Produs(), nrCuptor(nrGenerator++) {
		this->producator = producator;
		this->culoare = culoare;
		this->esteSmart = false;
		this->nrPrograme = 0;
		this->numeProgram = NULL;
	}

	Cuptor(string producator, string culoare, bool esteSmart, int nrPrograme, string* numeProgram) : Produs(), nrCuptor(nrGenerator++) {
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

	void descrieProdus() {
		cout << "Cuptorul este produs de " << this->producator << " si este culoarea " << this->culoare << "." << endl;
	}

	Cuptor operator=(const Cuptor& c) {
		if (this != &c) {
			Produs::operator=(c);
			this->producator = c.producator;
			this->culoare = c.culoare;
			this->esteSmart = c.esteSmart;
			this->nrPrograme = c.nrPrograme;
			if (this->numeProgram != NULL) {
				delete[]this->numeProgram;
			}
			this->numeProgram = new string[c.nrPrograme];
			for (int i = 0; i < c.nrPrograme; i++) {
				this->numeProgram[i] = c.numeProgram[i];
			}
		}
		return *this;
	}



	bool operator>(const Cuptor& c) {
		return this->nrPrograme > c.nrPrograme;
	}

	bool operator<=(const Cuptor& c) {
		return this->nrPrograme <= c.nrPrograme;
	}

	friend void esteAlb(Cuptor cuptor);
	friend void acelasiProducator(Cuptor& cuptor, Tigaie& tigaie);
	friend istream& operator>>(istream& tastatura, Cuptor& c);
};

ostream& operator<<(ostream& monitor, Cuptor& c) {
	monitor << c.getNrCuptor() << " " << c.getProducator() << " " << c.getCuloare();
	if (c.getEsteSmart() != false) {
		monitor << c.getNrPrograme()<<" ";
		for (int i = 0; i < c.getNrPrograme(); i++) {
			monitor << c.getNumeProgram(i) << " ";
		}
	}
	monitor << endl;
	return monitor;
}

istream& operator>>(istream& tastatura, Cuptor& c) {
	cout << "Producator: ";
	tastatura >> c.producator;
	cout << "Culoare: ";
	tastatura >> c.culoare;
	cout << "Este smart? ";
	tastatura >> c.esteSmart;
	if (c.esteSmart == 1) {
		cout << "Nr. programe: ";
		tastatura >> c.nrPrograme;
		if (c.numeProgram != NULL) {
			delete[]c.numeProgram;
		}
		c.numeProgram = new string[c.nrPrograme];
		for (int i = 0; i < c.nrPrograme; i++) {
			cout << "Program " << i + 1 << ": ";
			tastatura >> c.numeProgram[i];
			cout << endl;
		}
	}
	else {
		c.nrPrograme = 0;
		if (c.numeProgram != NULL) {
			delete[]c.numeProgram;
		}
		c.numeProgram = NULL;
	}
	return tastatura;
}

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

	SetTacamuri operator=(const SetTacamuri& s) {
		if (this != &s) {
			this->material = s.material;
			this->nrComponente = s.nrComponente;
			if (this->componenta != NULL) {
				delete[]this->componenta;
			}
			this->componenta = new string[s.nrComponente];
			for (int i = 0; i < s.nrComponente; i++) {
				this->componenta[i] = s.componenta[i];
			}
		}
		return *this;
	}
	friend istream& operator>>(istream& tastatura, SetTacamuri& s);

	SetTacamuri operator-(int val) {
		SetTacamuri aux = *this;
		if (this->nrComponente > val) {
			aux.nrComponente = this->nrComponente - val;
		}
		else {
			aux.nrComponente = 0;
		}
		return aux;
	}

	void scrieInFisierBinar(fstream& f) {
		f.write((char*)&this->material, sizeof(string));
		f.write((char*)&this->nrComponente, sizeof(int));
		if (this->nrComponente != 0) {
			for (int i = 0; i < this->nrComponente; i++) {
				f.write((char*)&this->componenta[i], sizeof(string));
			}
		}
	}

	void citesteDinFisierBinar(fstream& f) {
		f.read((char*)&this->material, sizeof(string));
		f.read((char*)&this->nrComponente, sizeof(int));
		if (this->nrComponente != 0) {
			for (int i = 0; i < this->nrComponente; i++) {
				f.read((char*)&this->componenta[i], sizeof(string));
			}
		}
	}
};

istream& operator>>(istream& tastatura, SetTacamuri& s) {
	cout << endl << "Material: ";
	tastatura >> s.material;
	cout << endl << "Numar componente: ";
	tastatura >> s.nrComponente;
	if (s.componenta != NULL) {
		delete[]s.componenta;
	}
	s.componenta = new string[s.nrComponente];
	if (s.nrComponente > 0) {
		for (int i = 0; i < s.nrComponente; i++) {
			cout << endl << "Componenta " << i + 1 << ": ";
			tastatura >> s.componenta[i];
		}
	}
	return tastatura;
}

ostream& operator<<(ostream& monitor, SetTacamuri& s) {
	monitor << "Setul de tacamuri cu id-ul " << s.getNrSet() << " este fabricat din " << s.getMaterial() << ". Acesta este alcatuit din " << s.getNrComponente() << " tacamuri, adica ";
	for (int i = 0; i < s.getNrComponente(); i++) {
		monitor << s.getComponenta(i) << ", ";
	}
	monitor << endl;
	return monitor;
}

void acelasiProducator(Cuptor& cuptor, Tigaie& tigaie) {
	if (cuptor.producator == tigaie.getProducator()) cout << "Cele doua au acelasi producator!";
	else cout << "Nu au acelasi producator!";
}

int SetTacamuri::nrGenerator = 3000;

class Bucatarie {
private:
	float suprafata;
	float pret;
	Cuptor cuptor;

public:
	Bucatarie() : suprafata(100), pret(1599.99), cuptor() {
	}

	float getSuprafata() {
		return suprafata;
	}

	float getPret() {
		return pret;
	}

	Cuptor getCuptor() {
		return cuptor;
	}

	void setSuprafata(float suprafata) {
		this->suprafata = suprafata;
	}


	void setPret(float pret) {
		this->pret = pret;
	}

	void setCuptor(Cuptor& c) {
		this->cuptor = c;
	}

	friend class Cuptor;
	friend ostream& operator<<(ostream& monitor, Bucatarie& b);
	friend istream& operator>>(istream& tastatura, Bucatarie& b);
	friend ofstream& operator<<(ofstream& fisier, Bucatarie& b);
	friend ifstream& operator>>(ifstream& fisier, Bucatarie& b);

	Bucatarie operator=(Bucatarie& b) {
		this->suprafata = b.suprafata;
		this->pret = b.pret;
		this->cuptor = b.cuptor;

		return *this;
	}
};

ostream& operator<<(ostream& monitor, Bucatarie& b) {
	monitor << "Bucataria are suprafata " << b.suprafata << " si costa " << b.pret << " lei. Despre cuptorul din bucatarie se cunosc urmatoarele informatii: " << b.cuptor;
	return monitor;
}

ofstream& operator<<(ofstream& fisier, Bucatarie& b) {
	fisier << b.suprafata << " " << b.pret << " " << b.cuptor;
	return fisier;
}

istream& operator>>(istream& tastatura, Bucatarie& b) {
	cout << "DATE GENERALE BUCATARIE" << endl;
	cout << "Suprafata: ";
	tastatura >> b.suprafata;
	cout << "Pret: ";
	tastatura >> b.pret;
	cout << "DATE CUPTOR" << endl;
	tastatura >> b.cuptor;

	return tastatura;
}

ifstream& operator>>(ifstream& fisier, Bucatarie& b) {
	fisier >> b.suprafata;
	fisier >> b.pret;
	fisier >> b.cuptor;

	return fisier;
}

class Wok : public Tigaie {
private: 
	string origine;
	float diametru;
public:
	Wok() : Tigaie() {
		this->origine = "China";
		this->diametru = 25;
	}

	Wok(string origine) : Tigaie() {
		this->origine = origine;
		this->diametru = 25;
	}

	Wok(string origine, float diametru) : Tigaie() {
		this->origine = origine;
		this->diametru = diametru;
	}

	Wok(const Wok& w) : Tigaie(w) {
		this->origine = w.origine;
		this->diametru = w.diametru;
	}

	void setOrigine(string origine) {
		this->origine = origine;
	}

	void setDiametru(float diametru) {
		this->diametru = diametru;
	}

	string getOrigine() {
		return origine;
	}

	float getDiametru() {
		return diametru;
	}
	
	friend ostream& operator<<(ostream& monitor, const Wok& w);
	friend istream& operator>>(istream& tastatura, Wok& w);

};

ostream& operator<<(ostream& monitor, const Wok& w) {
	monitor << (Tigaie)w;
	monitor << "Wok-ul are ca tara de origine " << w.origine << " si are diametrul de " << w.diametru << " cm." << endl;
	return monitor;
}

istream& operator>>(istream& tastatura, Wok& w) {
	cout << "Origine: ";
	tastatura >> w.origine;
	cout << endl << "Diametru: ";
	tastatura >> w.diametru;
	return tastatura;
}

class AirFryer : public Cuptor {
private:
	float capacitate;
	bool touchScreen;
public:
	AirFryer() : Cuptor() {
		this->capacitate = 5;
		this->touchScreen = false;
	}

	AirFryer(float capacitate) :Cuptor() {
		this->capacitate = capacitate;
		this->touchScreen = false;
	}

	AirFryer(float capacitate, bool touchScreen) {
		this->capacitate = capacitate;
		this->touchScreen = touchScreen;
	}

	void setCapacitate(float Capacitate) {
		this->capacitate = capacitate;
	}

	void setTouchScreen(bool touchScreen) {
		this->touchScreen = touchScreen;
	}

	float getCapacitate() {
		return capacitate;
	}

	float getTouchScreen() {
		return touchScreen;
	}

	friend ostream& operator<<(ostream& monitor, AirFryer& a);
	friend istream& operator>>(istream& tastatura, AirFryer& a);
};

ostream& operator<<(ostream& monitor,  AirFryer& a) {
	monitor << "AirFryer-ul are diametrul de " << a.capacitate << " si ";
	if (a.touchScreen = true) {
		monitor << "are touch-screen." << endl;
	}
	else {
		monitor << "nu are touch-screen." << endl;
	}
	return monitor;
}

istream& operator>>(istream& tastatura, AirFryer& a) {
	cout << "Capacitate: ";
	tastatura >> a.capacitate;
	cout << endl << "Are touch-screen? ";
	tastatura >> a.touchScreen;
	return tastatura;
}

class Comanda {
	int nrProduse;
	Produs** produse;
public:
	Comanda() {
		this->nrProduse = 3;
		this->produse = new Produs*[3];
		for (int i = 0; i < 3; i++) {
			this->produse[i] = new Tigaie();
		}
	}

	Comanda(int nrProduse) {
		this->nrProduse = nrProduse;
		this->produse = new Produs * [nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->produse[i] = new Tigaie();
		}
	}

	Produs*& operator[](int i) {
		if (i >= 0 && i < this->nrProduse) {
			return this->produse[i];
		}
	}
};


void main()
{
	//pentru Tigaie

	/*Tigaie tigaie1;
	cout << tigaie1 << endl;

	string producator2 = "Tefal";
	float greutate2 = 1.95;

	Tigaie tigaie2(producator2, greutate2);
	cout << tigaie2 << endl;

	string producator3 = "Electrolux";
	float greutate3 = 1.13;
	int nrMateriale3 = 3;
	string* material3 = new string[nrMateriale3];
	material3[0] = "otel";
	material3[1] = "plastic";
	material3[2] = "ceramica";
	bool esteCeramica3 = true;

	Tigaie tigaie3(producator3, greutate3, nrMateriale3, material3, esteCeramica3);
	cout << tigaie3 << endl;

	cout << endl;

	Tigaie tigaie4;
	cin >> tigaie4;
	cout << tigaie4;

	cout << endl;

	int nrTigai = 0;
	cout << "Nr. obiecte vector Tigai = ";
	cin >> nrTigai;
	Tigaie* vectorTigai = new Tigaie[nrTigai];

	for (int i = 0; i < nrTigai; i++) {
		cin >> vectorTigai[i];
	}

	for (int i = 0; i < nrTigai; i++) {
		cout << vectorTigai[i] << endl;
	}*/

	//pentru Cuptor

	//Cuptor cuptor1;
	//cuptor1.afisareCuptor();

	//string producatorcuptor2 = "Electrolux";
	//string culoare2 = "negru";

	//Cuptor cuptor2(producatorcuptor2, culoare2);
	//cuptor2.afisareCuptor();

	//string producatorcuptor3 = "Samsung";
	//string culoare3 = "alb";
	//bool esteSmart3 = true;
	//int nrPrograme3 = 2;
	//string* numeProgram3 = new string[nrPrograme3];
	//numeProgram3[0] = "defrost";
	//numeProgram3[1] = "pizza";

	//Cuptor cuptor3(producatorcuptor3, culoare3, esteSmart3, nrPrograme3, numeProgram3);
	//cuptor3.afisareCuptor();

	//int adaugPrograme = 2;
	//string* adaugNumePrograme = new string[adaugPrograme];
	//adaugNumePrograme[0] = "pui";
	//adaugNumePrograme[1] = "cartofi";

	//cout << endl;

	//if (cuptor1 > cuptor3) {
	//	cout << "Cuptorul 1 are mai multe programe.";
	//}
	//else {
	//	cout << "Cuptorul 2 are mai multe programe.";
	//}

	//cout << endl;

	//acelasiProducator(cuptor2, tigaie3);


	//esteAlb(cuptor3);

	//cout << endl;

	//int nrCuptoare = 0;
	//cout << "Nr. cuptoare in vector: ";
	//cin >> nrCuptoare;
	//Cuptor* vectorCuptoare = new Cuptor[nrCuptoare];
	//for (int i = 0; i < nrCuptoare; i++) {
	//	cout << "Cuptor " << i + 1 << endl;
	//	cin >> vectorCuptoare[i];
	//}
	//for (int i = 0; i < nrCuptoare; i++) {
	//	cout << "Cuptor " << i + 1 << ":" << endl;
	//	cout << vectorCuptoare[i] << endl;
	//}

	////pentru SetTacamuri

	//SetTacamuri set1;
	//set1.afisareSetTacamuri();

	//string materialTacamuri2 = "argint";
	//SetTacamuri set2(materialTacamuri2);
	//set2.afisareSetTacamuri();

	//string materialTacamuri3 = "argint";
	//int nrComponente = 4;
	//string* componenta = new string[nrComponente];
	//componenta[0] = "lingura";
	//componenta[1] = "furculita";
	//componenta[2] = "cutit";
	//componenta[3] = "lingurita desert";

	//SetTacamuri set3(materialTacamuri3, nrComponente, componenta);
	//set3.afisareSetTacamuri();

	//cout << "Setul de tacamuri cu id-ul " << set3.getNrSet() << " este fabricat din " << set3.getMaterial() << ". Acesta este alcatuit din " << set3.getNrComponente() << " tacamuri.";
	//cout << endl;

	//SetTacamuri aux = set3 - 2;
	//cout << aux;

	//int nrTacamuri = 0;
	//cout << "Nr. seturi tacamuri: ";
	//cin >> nrTacamuri;
	//SetTacamuri* vectorSet = new SetTacamuri[nrTacamuri];

	//for (int i = 0; i < nrTacamuri; i++) {
	//	cout << "Setul " << i + 1 << endl;
	//	cin >> vectorSet[i];
	//}

	//for (int i = 0; i < nrTacamuri; i++) {
	//	cout << vectorSet[i] << endl;
	//}

	//SetTacamuri set;
	//cout << set;
	//fstream fisier("fisier.bin", ios::out | ios::binary);
	//set.scrieInFisierBinar(fisier);
	//
	//SetTacamuri set1("aur");
	//cout << set1;
	//fstream citeste("fisier.bin", ios::in | ios::binary);
	//set1.citesteDinFisierBinar(citeste);
	//cout << set1;

	//Wok wok;
	//cout << wok;
	//cin >> wok;
	//cout << wok;
	//
	//AirFryer airf;
	//cout << airf;
	//cin >> airf;
	//cout << airf;

Comanda c(10);
c[0] = new Cuptor();
c[1] = new Tigaie("Producator", 2);
c[2] = new Tigaie();
c[3] = new Cuptor("Alt producator", "alb");
c[4] = new Cuptor();
c[5] = new Cuptor("Necunoscut", "auriu");
c[6] = new Tigaie();
c[7] = new Tigaie();
c[8] = new Cuptor();
c[9] = new Tigaie("Producator", 2);

for (int i = 0; i < 10; i++) {
	c[i]->descrieProdus();
	cout << endl;
}



	
}
