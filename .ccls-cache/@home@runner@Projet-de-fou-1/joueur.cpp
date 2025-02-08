#include "joueur.h"
#include "carte.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

joueur::joueur() {
  _nom = NOM_DEFAULT_J;
  _prestige = PRESTIGE_DEFAUT;
  _pile = PILE_DEFAUT;
}

joueur::joueur(string nom, int prestige, vector<carte> pile) {
  _nom = nom;
  _prestige = prestige;
  _pile = pile;
}

string joueur::sonNom() { return _nom; }

int joueur::sonPrestige() { return _prestige; }

void joueur::affichePhrase() {
  cout << "Le  Joueur " << _nom << " a " << _prestige
       << " points de prestige, il reste " << _pile.size()
       << " cartes dans sa pile." << endl;
}

bool joueur::PrestigePos() { return (_prestige > 0); }

bool joueur::EncoreCarte() { return (_pile.size() > 0); }

void joueur::carteSuiv(carte &c) {
  c = _pile[_pile.size() - 1];
  _pile.pop_back();
}

void joueur::affichePile() {
  cout << endl
       << "* -- Cartes de la pile du joueur : " << _nom << " -- *" << endl
       << endl;
  for (int i = 0; i < _pile.size(); i++) {
    cout << "\t";
    _pile[i].afficheC();
  }
  cout << endl;
}

void joueur::jouentUneCarte(joueur& j2) {
  carte c1;
  carte c2;

  int degP, degM;

  c1 = _pile[_pile.size() - 1];
  _pile.pop_back();

  j2.carteSuiv(c2);

  cout << endl
       << "Les Joueurs " << _nom << " et " << j2.sonNom()
       << " vont s'affrontez !" << endl
       << endl;
  cout << _nom << " à piocher la carte : " << endl;
  c1.afficheL();
  cout << j2.sonNom() << " à piocher la carte : " << endl;
  c2.afficheL();

  cout << endl << "* __ Début du combat __ *" << endl << endl;

  if (c1.getAttaque() > c2.getAttaque()){
    degP = c1.degatPhysique(c2);
  }

  if (c1.getAttaque() < c2.getAttaque()){
    degP = c2.degatPhysique(c1);
  }
  
  degM = c1.degatMagique(c2);

  cout << endl
       << "-> Les 2 joueurs commence par s'attaquer avec leurs dégats physique ! " << endl << endl;

  if (degP < 0) {

    cout << _nom << " subit " << degP << " dégats physique !" << endl;

    _prestige = _prestige + degP;

    cout << "Son prestige passe à " << _prestige << endl;

  }
  else {

    cout << j2.sonNom() << " subit " << degP << " dégats physique !" << endl;

    j2._prestige = j2._prestige - degP;

    cout << "Son prestige passe à " << j2._prestige << endl;
  }

  cout << endl << " -> Les 2 joueurs utilise la magie ! " << endl << endl;

  if (degM > 0) {

    cout << _nom << " subit " << degM << " dégats magique !" << endl;

    _prestige = _prestige - degM;

    cout << "Son prestige passe à " << _prestige << endl;

  } 
  if (degM < 0) {

    cout << j2.sonNom() << " subit " << degM << " dégats magique !" << endl;

    j2._prestige = j2._prestige + degM;

    cout << "Son prestige passe à " << j2._prestige << endl;
  }

  if(degM == 0) {
    cout << "Leurs magie est a égalité ! Aucun joueur ne subit de dégats." << endl;
  }

  cout << endl << "* __ FIN DU COMBAT __ *" << endl << endl;
  cout << "\tRésultat :" << endl << endl;
  cout << "Prestige " << _nom << " : " << _prestige << " ;" << endl;
  cout << "Prestige " << j2.sonNom() << " : " << j2._prestige << " ;" << endl;
}

void joueur::ajouteVingtCarte(const vector<carte>& vec){

  int n;
  
  if (vec.size() < 20){
    n = vec.size();
  }
  else {
    n = 20;
  }

  for (int i = 0 ; i < n ; i++ ){
    _pile.push_back(vec[i]);
  }
}


void joueur::melange(){

  random_device rd;
  default_random_engine rng(rd());
  shuffle(_pile.begin(), _pile.end(), rng);
  
}

void melange(vector<carte>& vec){

  random_device rd;
  default_random_engine rng(rd());
  shuffle(vec.begin(), vec.end(), rng);
  
}

void joueur::trierAttaque(){

  int i;
  int fin;
  int fintemp;
  carte temp;

  fin = _pile.size();

  while (fin > 1){
    fintemp = 1;

    for (i = 1 ; i < fin ; i ++){
      if ( _pile[i-1].getAttaque() > _pile[i].getAttaque() ){
        temp = _pile[i-1];
        _pile[i-1] = _pile[i];
        _pile[i] = temp;
        fintemp = i;
      }
    }
    fin = fintemp;
  }
}

void joueur::trierMagie(){

  int i;
  int fin;
  int fintemp;
  carte temp;

  fin = _pile.size();

  while (fin > 1){
    fintemp = 1;

    for (i = 1 ; i < fin ; i ++){
      if ( _pile[i-1].getMagie() > _pile[i].getMagie() ){
        temp = _pile[i-1];
        _pile[i-1] = _pile[i];
        _pile[i] = temp;
        fintemp = i;
      }
   }
    fin = fintemp;
  }
}

void joueur::trierDefense(){

  int i;
  int fin;
  int fintemp;
  carte temp;

  fin = _pile.size();

  while (fin > 1){
    fintemp = 1;

    for (i = 1 ; i < fin ; i ++){
      if ( _pile[i-1].getDefense() > _pile[i].getDefense() ){
        temp = _pile[i-1];
        _pile[i-1] = _pile[i];
        _pile[i] = temp;
        fintemp = i;
      }
    }
    fin = fintemp;
  }
}

vector<int> joueur::vecIndAttaque(){
  vector<int> vec = {};
  int ind;
  int min;
  bool trouve;

  for (int j = 0 ; j < _pile.size() ; j++){

    min = _pile[j].getAttaque();
    
    for (int i = 1 ; i < _pile.size() ; i++ ){

      trouve = false;

      for(int p = 0 ; p < vec.size() ; p++){
        if (i = vec[p]){
          trouve = true;
        }
      }

      if (!(trouve)){
      
        if (_pile[i].getAttaque() < min){
          ind = i;
        }
      }
    }
    vec.push_back(ind);
  }
}



void joueur::choisirCartes(){

  string nomcarte;
  carte c;

  for (int i = 0 ; i < 20 ; i++){
    cin >> nomcarte;
    c.remplir(nomcarte);
    _pile.push_back(c);
  }
}

/*

void joueur::remplirVingtAttaque(vector<carte>){
  
}

*/