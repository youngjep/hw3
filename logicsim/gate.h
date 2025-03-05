#ifndef GATE_H
#define GATE_H
#include <vector>
#include <queue>
#include <tuple>
#include "event.h"
#include "wire.h"

class Gate 
{
    public:
        Gate(int, Wire*);
        virtual ~Gate();
        virtual Event* update(uint64_t) =0;
        void wireInput(unsigned int,Wire*);
        
    protected:
        Wire* m_output;
        std::vector<Wire*> m_inputs;
        uint32_t m_delay;
        char m_current_state;
};

class And2Gate : public Gate
{
  public:
      And2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);  
};

class Or2Gate : public Gate
{
  public:
      Or2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);
};

/*
In gate.h and gate.cpp add an implementation of a single input NOT gate called NotGate that derives from Gate.
It should implement the following truth table:
NOT('X') -> 'X', NOT('0') -> '1', NOT('1') -> '0'. Model the state change behavior to be the same as the And2Gate and Or2Gate.
*/
class NotGate : public Gate
{
  public:
    NotGate(Wire*, Wire*);
    Event* update(uint64_t);
};


#endif