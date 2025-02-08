#include "jeu.h"
#include "carte.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

jeu::jeu() {
  _reserve = RESERVE_DEFAUT;
  _joueur1 = JOUEUR_DEFAUT1;
  _joueur2 = JOUEUR_DEFAUT2;
}

jeu::jeu(vector<carte> &reserve, joueur joueur1, joueur joueur2) {
  _reserve = reserve;
  _joueur1 = joueur1;
  _joueur2 = joueur2;
}

bool jeu::fini(joueur &vainqueur) { return vainqueur.sonPrestige() == 0; }

void jeu::remplitReserve(const string nomfich) {
  ifstream fich;
  fich.open(nomfich);
  string ligne;
  for (int i = 0; i < 25 && !fich.eof(); i++) {
    getline(fich, ligne);
    carte c;
    for (int i = 0; i < ligne.size(); i++) {
      ligne[i] = tolower(ligne[i]);
    }
    c.remplir(ligne);
    _reserve.push_back(c);
  }
  insertion();
}

void jeu::insertion() {
  int numPlace, position;
  carte tmp;
  for (position = 1; position <= _reserve.size() - 1; position++) {
    // on sauvegarde le nombre à déplacer dans tmp
    tmp = _reserve[position];
    // on calcule le futur numPlace
    numPlace = position;
    while (numPlace > 0 && _reserve[numPlace - 1].getNom() > tmp.getNom()) {
      numPlace--;
    }
    // à ce stade, numPlace a pour valeur le futur indice où on placera tmp
    // maintenant on crée la place pour insérer tmp.
    for (int i = position; i > numPlace; i--) {
      _reserve[i] = _reserve[i - 1]; // décalage vers la droite
    }
    // et ensuite on place tmp à l'indice numPlace
    _reserve[numPlace] = tmp;
  }
}

void jeu::affiche() {
  for (int i = 0; i < _reserve.size(); i++) {
    _reserve[i].afficheC();
  }
}

void jeu::jouer() { _joueur1.jouentUneCarte(_joueur2); }

bool jeu::fini() {
  return (!(_joueur1.PrestigePos() && _joueur2.PrestigePos()));
}

int jeu::vainqueur(){

  cout << _joueur1.sonPrestige() << " ; " << _joueur2.sonPrestige() << endl;
  
  if (_joueur1.sonPrestige() > _joueur2.sonPrestige()) {
    return 1;
  }

  if (_joueur1.sonPrestige() < _joueur2.sonPrestige()) {
    return -1;
  }

  if (_joueur1.sonPrestige() == _joueur2.sonPrestige()) {
    return 0;
  }
}

vector<carte> jeu::getReserve() const{
  return(_reserve);
}