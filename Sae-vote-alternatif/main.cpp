#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned gagnant(const vector<int> & voix, const vector<int> & secondTour){
    int premier = 0;
    int indiceGagnant = 0;
    /*premier tour*/
    for(int i = 0;i < voix.size();i++){
        if(voix[i] > 50){
            indiceGagnant = i;
            return indiceGagnant;
        }
    }
    /* second tour */
    for(int j = 0;j < secondTour.size();j++){
        if(secondTour[j] > premier){
            premier = secondTour[j];
            indiceGagnant = j;
            }
        }
    return indiceGagnant;
}



void lireEntree(vector<int> & premier, vector<int> & second){
    string ligne;
    bool secondTour = false;

    while(cin >>ligne){
        if(ligne == "//"){
            secondTour = true;
            continue;
        }
        int valeur = stoi(ligne);
        if(!secondTour && premier.size() < 3){
            premier.push_back(valeur);
        }else if(secondTour && second.size() < 3){
            second.push_back(valeur);
        }
    }
}

int main(){
    vector<int> premierTour;
    vector<int> secondTour;

    lireEntree(premierTour,secondTour);

    unsigned gagn = gagnant(premierTour,secondTour);

    //nom des candidats
    vector<string> candidats = {"M.Casali","M.Martin-Nevot","M.Betari"};

    cout << "Premier tour : ";
    for(int j : premierTour){
        cout << j << " ";
    }
    cout << endl;

    cout << "Second tour : ";
    for(int j : secondTour){
        cout << j << " ";
    }
    cout << endl;

    cout << "Le gagnant est : " << candidats[gagn] << endl;

    return 0;
}
