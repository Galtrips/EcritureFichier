#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

void lire_mot() {
	bool espace = false;
	ifstream entree("DicFra.txt", ios::in);
	ofstream sortie("mots.txt", ios::app);
	char ligne[10000];
	char mot_a_trouver[10000];
	if (!entree)
		cout << "probleme ouverture fichier" << endl;
	else {
		while (!entree.eof()) {
			espace = false;
			entree.getline(mot_a_trouver, 200, ',');
			entree.getline(ligne, 10000);

			int i = 0;
			int lg = strlen(mot_a_trouver);
			for (i = 0; i < lg; i++)
				if (mot_a_trouver[i] == ' ' || mot_a_trouver[0] == '-') {
					espace = true;
				}


			if (!sortie)
				cout << "probleme ouverture fichier" << endl;
			else {
				if (espace == false) {
					sortie << "    {\n      \"type\": \"dét.\",\n      \"frequency\": 1050561, " << endl;
					sortie << "      \"label\": " << mot_a_trouver << endl;
					sortie << "    }," << endl;
				}

			}

		}
		sortie.close();
		entree.close();


	}
}

int main() {
	lire_mot();
	return 0;
}