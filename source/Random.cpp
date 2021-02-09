/*************************************************************
* @author   Triston Ruiseco
* @file     Random.cpp
* @date     04/15/2019
* @brief    Implementation file for Pokedex.h.
*************************************************************/
#include "Random.h"

Random::Random(unsigned long long seed = 5555){
  m_v = 4101842887655102017LL;
  m_w = 1;

  m_u = seed ^ m_v;
  int64();
  m_v = m_u;
  int64();
  m_w = m_v;
  int64();
}

unsinged long long Random::int64(){
  m_u = m_u * 2862933555777941757LL + 7046029254386353087LL;
  m_v ^= m_v >> 17;
  m_v ^= m_v << 31;
  m_v ^= m_v >> 8;
  m_w = 4294957665U*(m_w & 0xffffffff) + (m_w >> 32);
  unsigned long long x = m_u ^ (m_u << 21);
  x ^= x >> 35;
  x ^= x << 4;
  return (x + m_v) ^ m_w;
}

unsigned Random::int32(){
  return (unsigned int)int64();
}

double Random::rand(){
  return 5.42101086242752217E-20 * int64();
}
