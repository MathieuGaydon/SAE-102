#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct ElecteurAlternatif {
    string nom;
    string prenom;
    vector<int> choix;
};

// --- FONCTIONS UTILITAIRES ---
string lireChaine() {
    string str;
    while (true) {
        getline(cin, str);
        if (!cin) return ""; 
        if (str.empty()) continue; 
        if (str.length() >= 2 && str.substr(0, 2) == "//") continue; 
        return str;
    }
}

int lireEntier() {
    string str;
    while (true) {
        getline(cin, str);
        if (!cin) return -1; 
        if (str.empty()) continue;
        if (str.length() >= 2 && str.substr(0, 2) == "//") continue;
        break;
    }
    return stoi(str);
}
// -----------------------------

int main()
{
    // 1. Lecture Candidats
    int nbCandidats = lireEntier();
    vector<string> candidats(nbCandidats);
    vector<bool> elimine(nbCandidats, false);

    for(int i = 0; i < nbCandidats; i++) {
        candidats[i] = lireChaine();
    }

    // 2. Lecture Electeurs et Preferences
    vector<ElecteurAlternatif> electeurs;
    
    while(true) {
        ElecteurAlternatif e;
        e.nom = lireChaine(); 
        if(e.nom == "") break; 
        
        e.prenom = lireChaine();

        // Lecture securisee de la ligne de choix (ex: "0 2 1")
        string ligneVote;
        while(true) {
            getline(cin, ligneVote);
            if(!cin) break; 
            if(ligneVote.empty()) continue; 
            if(ligneVote.length() >= 2 && ligneVote.substr(0, 2) == "//") continue; 
            break; 
        }
        
        stringstream ss(ligneVote);
        int preference;
        while(ss >> preference) {
            e.choix.push_back(preference);
        }
        electeurs.push_back(e);
    }

    int tour = 1;
    while(true) {
        vector<int> compte(nbCandidats, 0);
        int totalVotesValides = 0;

        // Comptabilisation
        for(size_t i = 0; i < electeurs.size(); i++) {
            for(size_t p = 0; p < electeurs[i].choix.size(); p++) {
                int indexCand = electeurs[i].choix[p];
                if(indexCand >= 0 && indexCand < nbCandidats && !elimine[indexCand]) {
                    compte[indexCand]++;
                    totalVotesValides++;
                    break; 
                }
            }
        }

        cout << "--- Tour " << tour << " ---" << endl;
        int minVotes = totalVotesValides + 1;
        int indexPerdant = -1;

        // Verification Gagnant / Perdant
        for(int i = 0; i < nbCandidats; i++) {
            if(elimine[i]) continue;

            cout << candidats[i] << " : " << compte[i] << endl;

            if(compte[i] > totalVotesValides / 2) {
                cout << "Gagnant : " << candidats[i] << endl;
                return 0;
            }

            if(compte[i] < minVotes) {
                minVotes = compte[i];
                indexPerdant = i;
            }
        }
        
        // Cas s'il ne reste qu'un seul candidat
        int restants = 0;
        int dernierSurvivant = -1;
        for(int i=0; i<nbCandidats; i++) {
            if(!elimine[i]) {
                restants++;
                dernierSurvivant = i;
            }
        }
        
        if (restants == 1) {
             cout << "Gagnant (Dernier restant) : " << candidats[dernierSurvivant] << endl;
             return 0;
        }

        // Elimination
        if(indexPerdant != -1) {
            cout << "Elimination de : " << candidats[indexPerdant] << endl;
            elimine[indexPerdant] = true;
        } else {
            cout << "Erreur ou egalite parfaite." << endl;
            break;
        }
        tour++;
    }

    return 0;
}
