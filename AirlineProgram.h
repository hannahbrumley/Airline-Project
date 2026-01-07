#ifndef PROGRAM_H
#define PROGRAM_H

#include "Passenger.h"

#include "../../DataStructure/LinkedList/LinkedList.hpp"
#include "../../DataStructure/Queue/LinkedQueue.hpp"
#include "../../DataStructure/Stack/LinkedStack.hpp"



//#include "ArrayQueue.hpp"
//#include "LinkedStack.hpp"

#include <queue>
#include <stack>
#include <vector>
#include <fstream>
using namespace std;

class AirlineProgram
{
    public:
    AirlineProgram();
    ~AirlineProgram();

    void Run();

    private:
    void LineUp( const Passenger& passenger );
    void Embark( string time );
    void Disembark( string time );
    void Summary();

    // TODO: Add queue of passengers
     
    LinkedQueue<Passenger> m_boardingQueue; 
     

    // TODO: Add stack of airplane seats
    
    LinkedStack<Passenger> m_airplaneSeats; 
    

    

    // TODO: Add list of arrived passengers
    LinkedList<Passenger> m_arrivedPassengers; 
     

    string NiceTime( int hr, int min );
    void TimePasses( int& hr, float& min );

    ofstream m_log;
    int m_time;
};

#endif // PROGRAM_H
