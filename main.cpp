#include "carte.h"
#include "jeu.h"
#include "joueur.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  // PARTIE 

  int i;
  char rep;
  string nomJ1;
  string nomJ2;

  string choixCarte;

  int ChoixStrat;

  char ChoixAlea;

  carte ctemp;

  int nbAlea;

  int v;

  char recom = 'o';

  vector<string> nomR = {"Robot 1","Playboy Carti","Maxence le connard","NOS","Ademo","YassEncore","Maxime Biaggi","Emmanuel Macron","BOT Mallory","GrimKujow","DylanKujo2","BOT Olivier","BOT Maxence","BOT Melanchon","BOT Olivier","Roi Doryan","Roi Arthur"};

  vector<carte> pileJ1 = {};
  vector<carte> pileJ2 = {};

  vector<carte> reserve = {};


  while( recom == 'o' ){

    //INITIALISATION DU GENERATEUR DE NOMBRE ALEATOIRE
    srand(time(0));
  
  
    cout << "] | ___ BIENVENUE SUR LE JEU ! ___ | [" << endl;
  
    sautLigne(3);
  
    cout << "\t En quelle mode vous voulez jouez ? " << endl;
    cout << endl << "1 -> Joueur VS Joueur." << endl;
    cout << "2 -> Joueur VS Ordinateur." << endl;
  
    cin >> rep;
  
    while ( rep != '1' && rep != '2'){
      cout << endl << "Je n'ai pas compris la réponse, veuillez recommencer : " << endl;
      cin >> rep;
    }
  
    if (rep == '1'){
  
          cout << endl << "\tMODE SELECTIONE : JOUEUR VS JOUEUR" << endl;
  
      sautLigne(2);
  
      cout << "Salut a toi Joueur 1 ! Comment t'apelle tu ?" << endl;
      cin >> nomJ1;
      cout << nomJ1 << " ? Quelle prénom éclater, c'est pas grave." << endl;
  
      cout << endl;
  
      cout << "Salut a toi Joueur 2 ! Comment t'apelle tu ?" << endl;
  
      cin >> nomJ2;
      cout << nomJ2 << " ? Quelle prénom de fou, quelle bg ce mec." << endl;
  
      joueur j1(nomJ1,25,{});
      joueur j2(nomJ2,25,{});
  
      sautLigne(2);
  
      cout << "Je vais maintenant vous expliquer les regles du jeu ..." << endl;
  
  
      sautLigne(2);
  
      cout << endl << "\t      [__ REGLE DU JEU __]" << endl;
  
      sautLigne(2);

      cout << "\tBienvenue dans notre jeu !" << endl << endl;
      cout << "Ce jeu est un jeu de carte qui peut se jouer Joueur vs Joueur ou Joueur vs Ordi" << endl;
      cout << "Pour gagner une parti c'est simple il faut descendre le prestige de votre adversaire a 0" << endl;
      cout << "Pour cela il faudra il lui infligé des dégats en vous affrontant avec vos cartes" << endl;
      cout << "Chaque joueur possede une pile de carte qu'il peut consitutuer lui meme puis la trier" << endl << endl;
      cout << "Chaque carte possede 3 stats : L'attaque , la defense et la magie" << endl;
      cout << "Durant un combat vous allez tout d'abord vous attaquer avec vos cartes avec vos degats physique puis vos degats magique" << endl;
      cout << "Lorsque que vous vous attaquerez en degats pysique ca sera toujours celui avec le plus de degats d'attaque qui attaquera son adversaire" << endl;
      cout << "Neanmoins pour la magie les 2 joueur s'attaque en meme temps" << endl << endl;
      cout << "Chaque combat se fait automatiquement vous avez juste a constituer votre pile pour jouer" << endl;
      cout << "La strategie pour alors gagner est de a chaque fois prendre les meilleurs cartes de la pile" << endl;
      cout << "Puis de choisir la meilleur strategie de trie." << endl << endl;
      cout << "\t BONNE CHANCE !" << endl;
  
      sautLigne(3);
  
      cout << endl << "\t*-- [_/ CHOIX DES CARTE DE LA PILE \_]  --*" << endl;
  
      
      jeu j(reserve,j1,j2);
      j.remplitReserve("reserve.txt");
  
      cout << endl << "Pour constituer votre pile vous allez devoir selectionnez 20 carte" << endl;
  
      
  
      cout << endl << "Voici la liste de carte disponible : " << endl << endl;
  
      j.affiche();
  
      sautLigne(2);
  
      cout << " * ----- * SETUP POUR J1 """ << nomJ1 << """ * ----- *" << endl << endl;
  
      cout << "Voulez vous sélectionnez vos cartes aleatoirement " << nomJ1 << " ? ['o' = oui ; autres = non ]" << endl;
      cin >> ChoixAlea;
  
      if (ChoixAlea == 'o'){
  
      pileJ1 = j.getReserve();
      
      melange(pileJ1);
        
      }
  
      else {
      
        sautLigne(2);
    
        cout << "Vous allez devoir sélectionnez chacune des cartes de votre pile dans l'ordre que vous voulez" << endl << endl;
        cout << "Pour ajoute une carte à votre pile il suffit de taper le nom de la carte que vous voulez " << endl;
        cout << "Exemple : Pour la carte "" arc [ 4 ; -1 ; 0 ] "" il faut écrire : ""arc,4,-1,0"" " << endl << endl;
    
        for (i = 0 ; i < 20 ; i++ ){
          
          cin >> choixCarte;
        
          ctemp.remplir(choixCarte);
    
          pileJ1.push_back(ctemp);
    
          cout << "la carte ";
          ctemp.afficheC();
          cout << " à été ajouter a votre pile" << endl;
          
        }
  
      }
  
      j1.ajouteVingtCarte(pileJ1);
  
      cout << endl << endl << "Voici votre pile " << nomJ1 << " : " << endl << endl;
  
      j1.affichePile();
  
      sautLigne(4);
  
      cout << "* ----- * SETUP POUR J2 """ << nomJ2 << """ * ----- *" << endl << endl;
  
      cout << "Voulez vous sélectionnez vos cartes aleatoirement " << nomJ2 << " ? ['o' = oui ; autres = non ]" << endl;
      cin >> ChoixAlea;
  
      if (ChoixAlea == 'o'){
  
      pileJ2 = j.getReserve();
      
      melange(pileJ2);
        
      }
  
      else {
      
        sautLigne(2);
    
        cout << "Vous allez devoir sélectionnez chacune des cartes de votre pile dans l'ordre que vous voulez" << endl << endl;
        cout << "Pour ajoute une carte à votre pile il suffit de taper le nom de la carte que vous voulez " << endl;
        cout << "Exemple : Pour la carte "" arc [ 4 ; -1 ; 0 ] "" il faut écrire : ""arc,4,-1,0"" " << endl << endl;
    
        for (i = 0 ; i < 20 ; i++ ){
          
          cin >> choixCarte;
        
          ctemp.remplir(choixCarte);
    
          pileJ2.push_back(ctemp);
    
          cout << "la carte ";
          ctemp.afficheC();
          cout << " à été ajouter a votre pile" << endl;
          
        }
  
      }
  
      j2.ajouteVingtCarte(pileJ2);
  
      cout << endl << endl << "Voici la pile choisi par " << nomJ2 << " :" << endl << endl;
  
      j2.affichePile();
      
      sautLigne(3);
  
  
      cout << endl << "\t*-- [_/ CHOIX DE LA STRATEGIE \_]  --*" << endl;
  
      sautLigne(2);
  
      cout << "Vous devez ici établir la façon dont vous allez ranger vos carte" << endl << endl;
  
      cout << "Vous avez plusieur choix de strategie disponible : " << endl << endl;
  
      cout << "\t1 - > Mélanger votre pile de façon aléatoire" << endl;
      cout << "\t2 - > Trier votre pile de façon croissante par rapport a l'attaque de vos carte" << endl;
      cout << "\t3 - > Trier votre pile de façon croissante par rapport a la défense de vos carte" << endl;
      cout << "\t4 - > Trier votre pile de façon croissante par rapport a la magie de vos carte" << endl;
      cout << "\t5 - > Ne rien faire" << endl;
  
      cout << endl << "* ----- * SETUP POUR J1 """ << nomJ2 << """ * ----- *" << endl << endl;
  
      cout << endl << "Quelle strategie choisie tu " << nomJ1 << " ?" << endl;
  
      cin >> ChoixStrat;
  
      while( !(ChoixStrat >= 1 && ChoixStrat <= 5)){
        cout << endl << "Je n'ai pas compris votre réponse " << nomJ1 << " veuillez recommencer" << endl;
        cin >> ChoixStrat;
      }
  
      if (ChoixStrat == 1) {
        cout << "Vous avez choisi la strategie : Mélanger votre pile de façon aléatoire " << endl;
  
        j1.melange();
  
        sautLigne(2);
        
      }
      if (ChoixStrat == 2) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a l'attaque de vos carte" << endl;
  
        j1.trierAttaque();
  
        sautLigne(2);
        
      }
      if (ChoixStrat == 3) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a la défense de vos carte" << endl;
  
        j1.trierDefense();
  
        sautLigne(2);
        
      }
  
      if (ChoixStrat == 4) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a la magie de vos carte" << endl;
  
        j1.trierMagie();
  
        sautLigne(2);
        
      }
  
      if (ChoixStrat == 5) {
        cout << "Vous avez choisi la strategie : Ne rien faire" << endl;
  
        sautLigne(2);
        
      }
  
      cout << "Voici a quoi ressemble votre pile finale :" << endl;
  
      j1.affichePile();
  
      sautLigne(4);
  
      cout << "* ----- * SETUP POUR J2 """ << nomJ2 << """ * ----- *" << endl << endl;
  
      cout << endl << "Quelle strategie choisie tu " << nomJ2 << " ?" << endl;
  
      cin >> ChoixStrat;
  
      while( !(ChoixStrat >= 1 && ChoixStrat <= 5)){
        cout << endl << "Je n'ai pas compris votre réponse " << nomJ1 << " veuillez recommencer" << endl;
        cin >> ChoixStrat;
      }
  
      if (ChoixStrat == 1) {
        cout << "Vous avez choisi la strategie : Mélanger votre pile de façon aléatoire " << endl;
  
        j2.melange();
  
        sautLigne(2);
        
      }
      if (ChoixStrat == 2) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a l'attaque de vos carte" << endl;
  
        j2.trierAttaque();
  
        sautLigne(2);
        
      }
      if (ChoixStrat == 3) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a la défense de vos carte" << endl;
  
        j2.trierDefense();
  
        sautLigne(2);
        
      }
  
      if (ChoixStrat == 4) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a la magie de vos carte" << endl;
  
        j2.trierMagie();
  
        sautLigne(2);
        
      }
  
      if (ChoixStrat == 5) {
        cout << "Vous avez choisi la strategie : Ne rien faire" << endl;
  
        sautLigne(2);
        
      }
  
      cout << "Voici a quoi ressemble votre pile finale :" << endl;
  
      j2.affichePile();
  
  
      sautLigne(5);
  
  
      cout << "|*********************************************************|" << endl;
      cout << "|*******|         LE COMBAT VA COMMENCER          |*******|" << endl;
      cout << "|*********************************************************|" << endl;
  
      sautLigne(3);
  
      while( (j1.EncoreCarte() && j2.EncoreCarte()) && (j1.PrestigePos() && j2.PrestigePos()) ){
        
        j1.jouentUneCarte(j2);
      
      }
  
      sautLigne(4);
  
      if (j1.sonPrestige() > j2.sonPrestige()){
  
        cout << "|*********************************************************|" << endl;
        cout << "|*******|         VICTOIRE DE " << nomJ1 << " !        |*******|" << endl;
        cout << "|*********************************************************|" << endl;
  
        sautLigne(3);
  
        cout << nomJ1 << " a gagner la partie félcitation ! " << endl;
        
      }
  
      if (j1.sonPrestige() == j2.sonPrestige() ){
        
        cout << "|*********************************************************|" << endl;
        cout << "|*******|                EGALITE                  |*******|" << endl;
        cout << "|*********************************************************|" << endl;
  
        sautLigne(3);
  
        cout << "La partie c'est terminé sur une égalité, c'était une belle partie !" << endl;
        
      }
  
      if (j1.sonPrestige() < j2.sonPrestige() ){
  
        cout << "|*********************************************************|" << endl;
        cout << "|*******|         VICTOIRE DE " << nomJ2 << " !                 |*******|" << endl;
        cout << "|*********************************************************|" << endl;
  
        sautLigne(3);
  
        cout << nomJ2 << " a gagner la partie félcitation ! " << endl;
        
      }
      
      
      
      
      
      
    }
    else {
          cout << endl << "\tMODE SELECTIONE : JOUEUR VS ORDINATEUR" << endl;
  
      sautLigne(2);
  
      cout << "Salut a toi Joueur ! Comment t'apelle tu ?" << endl;
      cin >> nomJ1;
      cout << nomJ1 << " ? Quelle prénom éclater, c'est pas grave." << endl;
  
      nomJ2 = nomR[rand()%(nomR.size()-1)];
  
      cout << endl << "Le nom du robot contre qui tu joura sera : " << nomJ2 << endl;
  
      joueur j1(nomJ1,25,{});
      joueur j2(nomJ2,25,{});
  
      sautLigne(2);
  
      cout << "Je vais maintenant vous expliquer les regles du jeu ..." << endl;
  
  
      sautLigne(2);
  
      cout << endl << "\t      [__ REGLE DU JEU __]" << endl;
  
      sautLigne(2);
  
      cout << "Il faut d'abord etablir une strategie et tout" << endl;
      cout << "Après on se bat avec l'adversaire et tout " << endl;
      cout << "et flemme d'expliquer et tout" << endl;
  
      sautLigne(3);
  
      cout << endl << "\t*-- [_/ CHOIX DES CARTE DE LA PILE \_]  --*" << endl;
  
      
      jeu j(reserve,j1,j2);
      j.remplitReserve("reserve.txt");
  
      cout << endl << "Pour constituer votre pile vous allez devoir selectionnez 20 carte" << endl;
  
      
  
      cout << endl << "Voici la liste de carte disponible : " << endl << endl;
  
      j.affiche();
  
      sautLigne(2);
  
      cout << "Voulez vous sélectionnez vos cartes aleatoirement ? ['o' = oui ; autres = non ]" << endl;
      cin >> ChoixAlea;
  
      if (ChoixAlea == 'o'){
  
      pileJ1 = j.getReserve();
      
      melange(pileJ1);
        
      }
  
      else {
      
        sautLigne(2);
    
        cout << "Vous allez devoir sélectionnez chacune des cartes de votre pile dans l'ordre que vous voulez" << endl << endl;
        cout << "Pour ajoute une carte à votre pile il suffit de taper le nom de la carte que vous voulez " << endl;
        cout << "Exemple : Pour la carte "" arc [ 4 ; -1 ; 0 ] "" il faut écrire : ""arc,4,-1,0"" " << endl << endl;
    
        for (i = 0 ; i < 20 ; i++ ){
          
          cin >> choixCarte;
        
          ctemp.remplir(choixCarte);
    
          pileJ1.push_back(ctemp);
    
          cout << "la carte ";
          ctemp.afficheC();
          cout << " à été ajouter a votre pile" << endl;
          
        }
  
      }
  
      j1.ajouteVingtCarte(pileJ1);
  
      cout << endl << endl << "Voici votre pile : " << endl << endl;
  
      j1.affichePile();
  
      pileJ2 = j.getReserve();
      
      melange(pileJ2);
  
      j2.ajouteVingtCarte(pileJ2);
  
      cout << endl << endl << "Voici la pile choisi par " << nomJ2 << " :" << endl << endl;
  
      j2.affichePile();
      
      sautLigne(3);
  
  
      cout << endl << "\t*-- [_/ CHOIX DE LA STRATEGIE \_]  --*" << endl;
  
      sautLigne(2);
  
      cout << "Vous devez ici établir la façon dont vous allez ranger vos carte" << endl << endl;
  
      cout << "Vous avez plusieur choix de strategie disponible : " << endl << endl;
  
      cout << "\t1 - > Mélanger votre pile de façon aléatoire" << endl;
      cout << "\t2 - > Trier votre pile de façon croissante par rapport a l'attaque de vos carte" << endl;
      cout << "\t3 - > Trier votre pile de façon croissante par rapport a la défense de vos carte" << endl;
      cout << "\t4 - > Trier votre pile de façon croissante par rapport a la magie de vos carte" << endl;
      cout << "\t5 - > Ne rien faire" << endl;
    
  
      cout << endl << "Quelle strategie choisie tu " << nomJ1 << " ?" << endl;
  
      cin >> ChoixStrat;
  
      while( !(ChoixStrat >= 1 && ChoixStrat <= 5)){
        cout << endl << "Je n'ai pas compris votre réponse " << nomJ1 << " veuillez recommencer" << endl;
        cin >> ChoixStrat;
      }
  
      if (ChoixStrat == 1) {
        cout << "Vous avez choisi la strategie : Mélanger votre pile de façon aléatoire " << endl;
  
        j1.melange();
  
        sautLigne(2);
        
      }
      if (ChoixStrat == 2) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a l'attaque de vos carte" << endl;
  
        j1.trierAttaque();
  
        sautLigne(2);
        
      }
      if (ChoixStrat == 3) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a la défense de vos carte" << endl;
  
        j1.trierDefense();
  
        sautLigne(2);
        
      }
  
      if (ChoixStrat == 4) {
        cout << "Vous avez choisi la strategie : Trier votre pile de façon croissante par rapport a la magie de vos carte" << endl;
  
        j1.trierMagie();
  
        sautLigne(2);
        
      }
  
      if (ChoixStrat == 5) {
        cout << "Vous avez choisi la strategie : Ne rien faire" << endl;
  
        sautLigne(2);
        
      }
  
      cout << "Voici a quoi ressemble votre pile finale :" << endl;
  
      j1.affichePile();
  
      sautLigne(3);
  
      nbAlea = rand() % 4;
  
      if (nbAlea == 0){
        cout << nomJ2 << " a choisi la strategie : Mélanger votre pile de façon aléatoire." << endl;
        j2.melange();
      }
  
      if (nbAlea == 1){
        cout << nomJ2 << " a choisi la strategie : Trier votre pile de façon croissante par rapport a l'attaque de vos carte."<< endl; 
        j2.trierAttaque();
      }
  
      if (nbAlea == 2){
        cout << nomJ2 << " a choisi la strategie : Trier votre pile de façon croissante par rapport a la défense de vos carte."<< endl;
        j2.trierDefense();
      }
  
      if (nbAlea == 3){
        cout << nomJ2 << " a choisi la strategie : Trier votre pile de façon croissante par rapport a la magie de vos carte"<< endl;
        j2.trierMagie();
      }
  
      if (nbAlea == 4){
        cout << nomJ2 << " a choisi la strategie : Ne rien faire"<< endl;    
      }
  
      sautLigne(2);
  
      cout << "Voici la pile de votre adversaire " << nomJ2 << " :" << endl << endl;
  
      j2.affichePile();
  
  
      sautLigne(5);
  
  
      cout << "|*********************************************************|" << endl;
      cout << "|*******|         LE COMBAT VA COMMENCER          |*******|" << endl;
      cout << "|*********************************************************|" << endl;
  
      sautLigne(3);
  
      while( (j1.EncoreCarte() && j2.EncoreCarte()) && (j1.PrestigePos() && j2.PrestigePos()) ){
        
        j1.jouentUneCarte(j2);
      
      }
  
      sautLigne(4);
  
      if (j1.sonPrestige() > j2.sonPrestige()){
  
        cout << "|*********************************************************|" << endl;
        cout << "|*******|         VICTOIRE DE " << nomJ1 << " !        |*******|" << endl;
        cout << "|*********************************************************|" << endl;
  
        sautLigne(3);
  
        cout << nomJ1 << " a gagner la partie félcitation ! " << endl;
        
      }
  
      if (j1.sonPrestige() == j2.sonPrestige() ){
        
        cout << "|*********************************************************|" << endl;
        cout << "|*******|                EGALITE                  |*******|" << endl;
        cout << "|*********************************************************|" << endl;
  
        sautLigne(3);
  
        cout << "La partie c'est terminé sur une égalité, c'était une belle partie !" << endl;
        
      }
  
      if (j1.sonPrestige() < j2.sonPrestige() ){
  
        cout << "|*********************************************************|" << endl;
        cout << "|*******|         VICTOIRE DE " << nomJ2 << " !                 |*******|" << endl;
        cout << "|*********************************************************|" << endl;
  
        sautLigne(3);
  
        cout << nomJ2 << " a gagner la partie félcitation ! " << endl;
        
      }

      sautLigne(2);

      cout << "\tVoulez vous refaire une partie ? [ 'o' = Oui ; autres = non]" << endl;

      cin >> recom;
      
    }
  }
}