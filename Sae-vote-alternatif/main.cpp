#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <vector>
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



vector<int> lireValeur(){
    vector<int> valeurPremierTour;
    ifstream fichier("entreePremierTest.txt");
    //ifstream fichier("entreeSecondTest.txt");
    string ligne;
    /* On met les valeurs dans le tab du premier tour */
    while(getline(fichier,ligne)){
        if(ligne.empty() || ligne.substr(0,2) == "//"){
            continue;
        }
        if(valeurPremierTour.size() < 3){
            valeurPremierTour.push_back(stoi(ligne));
        }
        if(valeurPremierTour.size()==3){
            break;
        }
    }
    fichier.close();
    return valeurPremierTour;
}

vector<int> lireValeur2(){
    vector<int> valeurSecondTour;
    ifstream fichier("entreePremierTest.txt");
    //ifstream fichier("entreeSecondTest.txt");
    string ligne;
    /* On met les valeurs dans le tab du premier tour */
    while (getline(fichier, ligne)) {
        if (ligne == "//deuxième tour")
            break;
    }
    while(getline(fichier,ligne)){
        if(ligne.empty() || ligne.substr(0,2) == "//"){
            continue;
        }
        if(valeurSecondTour.size() < 3){
            valeurSecondTour.push_back(stoi(ligne));
        }
        if(valeurSecondTour.size()==3){
            break;
        }
    }

    fichier.close();
    return valeurSecondTour;

}

int main(){
    vector<int> tabPremierTour = lireValeur();
    vector<int> tabSecondTour = lireValeur2();
    unsigned indice = gagnant(tabPremierTour,tabSecondTour);

    cout << "valeurs du premier tour : ";
    for(int j = 0;j < tabPremierTour.size();j++){
        cout << tabPremierTour[j] << " ";
    }
    cout << endl;
    /*
    cout << "valeurs du Second tour : ";
    for(int k = 0;k < tabSecondTour.size();k++){
        cout << tabSecondTour[k] << " ";
    }
    cout << endl; */

    if(indice == 0){
        cout << "Le gagnant est : M.Casali" << endl;
    }
    else if(indice == 1){
        cout << "Le gagnant est : M.Martin-Nevot" << endl;
    }
    else{
        cout << "Le gagnant est : M.Betari" << endl;
    }


}
