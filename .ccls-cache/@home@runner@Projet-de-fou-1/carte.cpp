#include "carte.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// CONSTRUCTEUR
carte::carte() {

  _nom = NOM_DEFAUT;
  _attaque = ATTAQUE_DEFAUT;
  _defense = DEFENSE_DEFAUT;
  _magie = MAGIE_DEFAUT;
}

carte::carte(string nom, int attaque, int defense, int magie) {
  _nom = nom;
  _attaque = attaque;
  _defense = defense;
  _magie = magie;
}

// AFFICHE
void carte::afficheL() const {

  cout << endl;
  cout << "Nom : " << _nom << endl;
  cout << "Attaque : " << _attaque << endl;
  cout << "Defense : " << _defense << endl;
  cout << "Magie : " << _magie << endl << endl;
  cout << endl;
}

void carte::afficheC() const {
  cout << _nom << " [ " << _attaque << " ; " << _defense << " ; " << _magie
       << " ]" << endl;
}

// GET
int carte::getMagie() const { return _magie; }

int carte::getAttaque() const { return _attaque; }

int carte::getDefense() const { return _defense; }

string carte::getNom() const { return _nom; }

// DEGAT
int carte::degatPhysique(const carte &c) const {

  if (_attaque <= c.getDefense()){
    return 0;
  }

  else {
    return _attaque - c.getDefense() ;
  }
}

int carte::degatMagique(const carte &c) const {
  return (c.getMagie() - _magie);
}

void sautLigne(int n) {
  for (int i = 0; i < n; i++) {
    cout << endl;
  }
}

void parser(const string &ligne, string &nom, int &a, int &d, int &m) {
  unsigned int i = 0;
  a = d = m = 0;
  nom = "";
  int signe = 1;
  while (i < ligne.size() && ligne[i] != ',') {
    if (!((ligne[i] >= 'A' && ligne[i] <= 'Z') ||
          (ligne[i] >= 'a' && ligne[i] <= 'z') || (ligne[i] == '_'))) {
      throw(invalid_argument("ligne incorrecte"));
    }
    nom.push_back(ligne[i]);
    i++;
  }
  i++;
  if (ligne[i] == '-') {
    signe = -1;
    i++;
  }
  while (i < ligne.size() && ligne[i] != ',') {
    if (ligne[i] < '0' || ligne[i] > '9')
      throw(invalid_argument("ligne incorrecte"));
    a = a * 10 + ((int)ligne[i] - '0');
    i++;
  }
  a *= signe;
  signe = 1;
  i++;
  if (ligne[i] == '-') {
    signe = -1;
    i++;
  }
  while (i < ligne.size() && ligne[i] != ',') {
    if (ligne[i] < '0' || ligne[i] > '9')
      throw(invalid_argument("ligne incorrecte"));
    d = d * 10 + ((int)ligne[i] - '0');
    i++;
  }
  d *= signe;
  signe = 1;
  i++;
  if (ligne[i] == '-') {
    signe = -1;
    i++;
  }
  while (i < ligne.size()) {
    if (ligne[i] < '0' || ligne[i] > '9')
      throw(invalid_argument("ligne incorrecte"));
    m = m * 10 + ((int)ligne[i] - '0');
    i++;
  }
  m *= signe;
}

void carte::remplir(const string &ligne) {
  string nom;
  int a, d, m;
  parser(ligne, nom, a, d, m);
  _nom = nom;
  _attaque = a;
  _defense = d;
  _magie = m;
}

int carte::valCarte() { return (_attaque + _defense + _magie); }

void triVal(vector<carte> &vec) {
  int i;
  int fin;
  int fintemp;
  carte temp;

  fin = vec.size();

  while (fin > 1) {
    fintemp = 1;

    for (i = 1; i < fin; i++) {
      if (vec[i - 1].valCarte() < vec[i].valCarte()) {
        temp = vec[i - 1];
        vec[i - 1] = vec[i];
        vec[i] = temp;
        fintemp = i;
      }
    }
    fin = fintemp;
  }
}