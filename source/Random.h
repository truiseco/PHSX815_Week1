/*************************************************************
* @author   Triston Ruiseco
* @file     Random.h
* @date     02/08/2021
* @brief    Class to generate pseudo-random numers.
*************************************************************/

#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>

class Random
{
  public:

    /**
    * @pre none
    * @post random object instantiated
    * @param seed: optional starting point for number randomization
    */
    Random(unsigned long long seed = 5555);

    /**
    * @pre none
    * @post none
    * @return random 64 bit int
    */
    unsigned long long int64();

    /**
    * @pre none
    * @post none
    * @return random 32 bit int
    */
    unsigned int32();

    /**
    * @pre none
    * @post none
    * @return uniform random double between 0 and 1
    */
    double rand();

    /**
    * @pre none
    * @post none
    */
    virtual ~Random(){};

  private:

    /*
    * @brief private members to give memory to the RNG sequence
    */
    unsigned long long m_u;
    unsigned long long m_v;
    unsigned long long m_w;
};
#endif
