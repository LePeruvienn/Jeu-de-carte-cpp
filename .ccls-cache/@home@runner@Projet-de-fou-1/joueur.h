#include "carte.h"
#include <string>
#include <vector>
#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

using namespace std;

const string NOM_DEFAULT_J = "Yugi";
const int PRESTIGE_DEFAUT = 25;
const vector<carte> PILE_DEFAUT = {
    carte("MainDroite", 1, 0, 0), carte("MainGauche", 0, 1, 0),
    carte("Tête", 1, -2, 0), carte("Bouche", 1, -1, 2),
    carte("Genou", 2, 0, 0)};

class joueur {

private:
  string _nom;
  int _prestige;
  vector<carte> _pile;

public:
  joueur();

  joueur(string nom, int prestige, vector<carte> pile);

  string sonNom();
  int sonPrestige();

  void affichePhrase();

  bool PrestigePos();
  bool EncoreCarte();

  void affichePile();

  void carteSuiv(carte &);

  void jouentUneCarte(joueur &j2);

  void ajouteVingtCarte(const vector<carte>& vec);

  void melange();

  vector<int> vecIndAttaque();

  void choisirCartes();

  void trierAttaque();
  void trierMagie();
  void trierDefense();
};

void melange(vector<carte> &vec);

#endif // JOUEUR_H_INCLUDED