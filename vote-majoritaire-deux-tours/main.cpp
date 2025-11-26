#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Electeur {
    string nom;
    string prenom;
    int vote;
};

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

int main() {
    // 1. Lecture des Candidats
    int nbCandidats = lireEntier();
    vector<string> candidats(nbCandidats);
    vector<int> compteVotes(nbCandidats, 0);

    for(int i = 0; i < nbCandidats; i++) {
        candidats[i] = lireChaine();
    }

    // 2. Lecture des Electeurs
    vector<Electeur> electeurs;
    while(true) {
        Electeur e;
        string nomL = lireChaine();
        if(nomL == "") break;

        e.nom = nomL;
        e.prenom = lireChaine();
        e.vote = lireEntier();
        electeurs.push_back(e);
    }

    // 3. Comptage des votes
    int totalVotesValides = 0;
    for (size_t i = 0; i < electeurs.size(); i++) {
        int indexCandidat = electeurs[i].vote;

        if(indexCandidat >= 0 && indexCandidat < nbCandidats) {
            compteVotes[indexCandidat]++;
            totalVotesValides++;
        }
    }

    // 4. Resultats
    cout << "Votes Totaux : " << totalVotesValides << endl;

    // Verification Majorite Absolue (> 50%)
    for(int i = 0; i < nbCandidats; i++) {
        if(compteVotes[i] > totalVotesValides / 2) {
            cout << "Gagnant par majorite absolue : " << candidats[i] << endl;

            return 0;
        }
    }

    // 5. Sinon, trouver les 2 meilleurs (Ballottage)
    int premierIndex = -1, secondIndex = -1;
    int premierScore = -1, secondScore = -1;

    for(int i = 0; i < nbCandidats; i++) {
        if (compteVotes[i] > premierScore) {
            // L'ancien premier devient second
            secondScore = premierScore;
            secondIndex = premierIndex;

            // Nouveau premier
            premierScore = compteVotes[i];
            premierIndex = i;
        } else if (compteVotes[i] > secondScore) {
            secondScore = compteVotes[i];
            secondIndex = i;
        }
    }

    cout << "Pas de majorite absolue." << endl;
    cout << "Qualifies pour le second tour : " << endl;
    cout << "1. " << candidats[premierIndex] << " (" << premierScore << " votes)" << endl;
    cout << "2. " << candidats[secondIndex] << " (" << secondScore << " votes)" << endl;

    return 0;
}
