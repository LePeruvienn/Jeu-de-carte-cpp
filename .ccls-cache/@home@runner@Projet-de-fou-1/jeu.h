#include "carte.h"
#include "joueur.h"
#include <string>
#include <vector>
#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

const vector<carte> RESERVE_DEFAUT = {};
const joueur JOUEUR_DEFAUT1 = joueur();
const joueur JOUEUR_DEFAUT2 = joueur();

class jeu {
private:
  vector<carte> _reserve;
  joueur _joueur1;
  joueur _joueur2;

public:
  jeu();
  jeu(vector<carte> &, joueur joueur1, joueur joueur2);
  bool fini(joueur &vainqueur);
  void remplitReserve(const string nomfich);
  void affiche();
  void insertion();

  void jouer();
  bool fini();

  int vainqueur();

  vector<carte> getReserve() const;
};

#endif // JEU_H_INCLUDED