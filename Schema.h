#ifndef _SCHEMA_H
#define _SCHEMA_H

#include "Lagrangienne.h"
#include<vector>

class Schema
{
protected:
    // Pas de temps à recalculer à chaque itération
    double _dt;
    // Temps en cours
    double _t;
    // Vecteur initial et vecteur solution
    std::vector _sol0, _sol;
    // Pointeur vers le système d'EDO
    Lagrangienne* _sys;

public:
    // Constructeur par défaut
    Schema();
    // Destructeur par défaut
    virtual ~Schema();
    // Initialisation des différentes variables
    void Initialize(double t0, double dt, std::vector& sol0, const std::string& name_file, Lagrangienne* sys);
    // Enregistre la solution dans un fichier
    void SaveSolution();
    // Effectue une étape du schéma en temps
    virtual void Advance() = 0;
    // Permet de récupérer _sol
    const std::vector& GetIterateSolution() const;
};

class EulerScheme : public TimeScheme
{
  public:
  void Advance();
};

class RungeKuttaScheme4 : public TimeScheme
{
  public:
  void Advance();
};

class ExponentialScheme : public TimeScheme
{
  public:
  void Advance();
};

#endif // _SCHEMA_H
