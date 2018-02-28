#ifndef SYSTEM_H
#define SYSTEM_H
#include "Eigen/Dense"
#include "Parameters/parameters.h"
#include <random>
#include <time.h>
#include <math.h>
#include <iostream>

class System
{
public:
    System();
    ~System();

    Eigen::MatrixXd *r;
    Eigen::MatrixXd *next_r;

    Eigen::MatrixXd distance;
    Eigen::MatrixXd next_distance;

    const Eigen::MatrixXd get_position() const;

    void make_grid(double m_alpha);
    void make_move_and_update_non_interacting(const int move);
    void make_move_and_update_interacting(const int move);
    void make_move_and_update(const int move);
    void update();
    double check_acceptance_and_return_energy(int);


    void update_wavefunction(const int move);
    double calculate_energy_noninteracting();
private:
    //Saves all the variables from the parameters to save time
    const int N = Parameters::N;
    const int dimension = Parameters::dimension;
    const double beta = Parameters::beta;
    const double dx = Parameters::dx;
    const double omega = Parameters::omega;
    const double h=1e-8;

    void (System::*make_move)(const int);

    //Vector and double used for holding temp values
    Eigen::VectorXd temp_r;
    Eigen::VectorXd temp_r2;
    //double temp_value;
    //double temp_value2;



    //Functions for calulations involving wavefunction
    double alpha;
    double wavefunction_value;
    double wavefunction_probability;
    double local_energy;
    double kinetic_energy;
    double potential_energy;

    double phi_exponant(const Eigen::VectorXd &r);
    double get_wavefunction();
    double get_probability_ratio(int move);
    double get_probability();
    double get_local_energy();
    void update_probability_ratio();




};

#endif // SYSTEM_H
