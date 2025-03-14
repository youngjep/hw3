#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <vector>

#include "../heap.h"
#include "event.h"
#include "gate.h"

class Circuit 
{
	public:
		Circuit();
		~Circuit();
		void test(); //will directly instantiate the simple AND circuit.
		bool advance(std::ostream&);
		void run(std::ostream&);//will output a log of when certain wires change state.
	    bool parse(const char*); //will read the circuit description and instantiate the various gates and wires required
	    void startUml(std::ostream&);
	    void endUml(std::ostream&);
        //If the user calls Circuit::startUml and Circuit::endUml
        // then the output of the program can be fed into the plantuml Java program to generate a timing diagram.
		
	private:
		uint64_t m_current_time;
	    std::vector<Gate*> m_gates;
	    std::vector<Wire*> m_wires; //pointers to the wires in the circuit

		// we need to add the m_pq data member. It should be a min-heap of Event*;
		Heap<Event*, EventLess> m_pq;// is a Heap object (your code) used as a min-heap (priority queue) to hold the events generated by the gates.
};

#endif
