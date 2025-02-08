#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

const string NOM_DEFAUT = "Mains nues";
const int ATTAQUE_DEFAUT = 1;
const int DEFENSE_DEFAUT = 1;
const int MAGIE_DEFAUT = 0;

class carte {

private:
  string _nom;
  int _attaque;
  int _defense;
  int _magie;

public:
  carte();
  carte(string nom, int attaque, int defense, int magie);
  void afficheC() const;
  void afficheL() const;
  int degatPhysique(const carte &c) const;
  int degatMagique(const carte &c) const;

  int getMagie() const;
  int getAttaque() const;
  int getDefense() const;
  string getNom() const;

  void remplir(const string &ligne);

  int valCarte();
};

void sautLigne(int n);

void testremplir(string mot);

void parser(const string &ligne, string &nom, int &a, int &d, int &m);

void triVal(vector<carte> &vec);

#endif // CARTE_H_INCLUDED