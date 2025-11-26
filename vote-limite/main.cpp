#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Electeur {
    string nom;
    string prenom;
    int vote;
};

struct ResultatCandidat {
    int id;
    string nom;
    int votes;
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

bool comparerCandidats(const ResultatCandidat &a, const ResultatCandidat &b) {
    return a.votes > b.votes; // Ordre decroissant
}

int main()
{
    int siegesDisponibles = 2;

    // 1. Lecture Candidats
    int nbCandidats = lireEntier();
    vector<ResultatCandidat> resultats(nbCandidats);

    for(int i = 0; i < nbCandidats; i++) {
        resultats[i].id = i;
        resultats[i].nom = lireChaine();
        resultats[i].votes = 0;
    }

    // 2. Lecture Votes
    while(true) {
        string nom = lireChaine();
        if(nom == "") break;

        string prenom = lireChaine();
        int indexVote = lireEntier();

        if(indexVote >= 0 && indexVote < nbCandidats) {
            resultats[indexVote].votes++;
        }
    }

    // 3. Tri des resultats
    sort(resultats.begin(), resultats.end(), comparerCandidats);

    // 4. Affichage
    cout << "Resultats du Vote Limite (" << siegesDisponibles << " sieges) :" << endl;
    for(int i = 0; i < siegesDisponibles; i++) {
        if(i < resultats.size()) {
            cout << "Siege " << i+1 << " : " << resultats[i].nom
                 << " avec " << resultats[i].votes << " votes." << endl;
        }
    }

    return 0;
}
