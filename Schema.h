#ifndef _SCHEMA_H
#define _SCHEMA_H

#include "Lagrangienne.h"

class Schema
{
protected:
    // Pas de temps à recalculer à chaque itération
    double _dt;
    // Temps en cours
    double _t;
    // Vecteur initial et vecteur solution
    std::vector<double> _sol0, _sol;
    // Pointeur vers le système d'EDO
    Lagrangienne* _sys;

public:
    // Constructeur par défaut
    Schema();
    // Destructeur par défaut
    virtual ~Schema();
    // Initialisation des différentes variables
    void Initialize(double t0, double dt, std::vector<double>& sol0, const std::string& name_file, Lagrangienne* sys);
    // Enregistre la solution dans un fichier
    void SaveSolution();
    // Effectue une étape du schéma en temps
    void Advance();
    // Permet de récupérer _sol
    const std::vector<double>& GetIterateSolution() const;
};

#endif // _SCHEMA_H
