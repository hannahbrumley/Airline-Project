#include "AirlineProgram.h"

#include "../../Utilities/StringUtil.hpp"

#include <iomanip>
#include <iostream>
using namespace std;

AirlineProgram::AirlineProgram()
{
    string filename = "../log.txt";
    m_log.open( filename );
    cout << "Saving AirlineProgram log to \"" << filename << "\"" << endl;
    m_time = 0;
}

AirlineProgram::~AirlineProgram()
{
    m_log.close();
}

void AirlineProgram::Run()
{
    // Load event file
    
    string filepath = "../passengerLog.txt";
    ifstream input( filepath );
    if ( input.fail() )
    {
        cout << "Unable to open filepath \"" << filepath << "\"!" << endl;
        return;
    }

    m_log << endl << "ENQUEUING AND BOARDING..." << endl << string(80, '-') << endl;
    // TODO: 1. Enqueue and board
    string buffer; 
    while (getline(input, buffer))
    {
        if (StringUtil::Contains(buffer, "CUSTOMER_ENQUEUES"))
        {
            Passenger passenger; 
            input >> passenger; 
            LineUp(passenger); 
        }

        else if (StringUtil::Contains(buffer, "CUSTOMER_BOARDS"))
        {
            getline(input, buffer); 
            string time = StringUtil::Replace(buffer, " Time: ", ""); 
            Embark(time); 
        }
    }




    // TODO: 2. Disembark
    int hr = 18; 
    float min = 0; 
    string niceTime = NiceTime(hr, int(min)); 
    cout << "Disembarking..." << endl; 
    m_log << endl << "DISEMBARKING..." << endl << string(80, '-') << endl;

    while (m_airplaneSeats.IsEmpty() == false)
    {
        Disembark(niceTime); 
        TimePasses(hr, min); 
    }

    

    // This goes at the end of Run()
    cout << "Printing summary..." << endl;
    Summary();
    cout << "Done, view log file for all details" << endl;
}

void AirlineProgram::LineUp( const Passenger& passenger )
{
    //TODO: Implement

    m_boardingQueue.Push(passenger);
    m_log << "[" << passenger.GetEnqueueTime() << "]: Passenger " << passenger << " lines up" << endl; 
}

void AirlineProgram::Embark( string time )
{
    // TODO: Implement
    Passenger passenger = m_boardingQueue.Front(); 
    
    passenger.SetBoardingTime(time); 
    passenger.SetSeat(m_airplaneSeats.Size()); 
    m_log << "[" << time << "]: Passenger " << m_boardingQueue.Front() << "boards the airplane" << endl; 
    m_airplaneSeats.Push(passenger); 
    m_boardingQueue.Pop(); 

}

void AirlineProgram::Disembark( string time )
{
    // TODO: Implement

    Passenger passenger = m_airplaneSeats.Top(); 
    passenger.SetArrivalTime(time); 
    m_log << "[" << time << "]: Passenger " << m_airplaneSeats.Top() << " disembarks" << endl; 
    m_arrivedPassengers.PushBack(passenger); 
    m_airplaneSeats.Pop(); 
}

void AirlineProgram::Summary() // done
{
    m_log << endl << "SUMMARY" << endl << string( 80, '-' ) << endl;

    m_log << left
        << setw( 10 ) << "TICKET"
        << setw( 30 ) << "NAME"
        << setw( 10 ) << "ENQUEUE"
        << setw( 10 ) << "BOARD"
        << setw( 10 ) << "ARRIVE"
        << setw( 10 ) << "SEAT"
        << endl << string( 80, '-' ) << endl;

   for ( size_t i = 0; i < m_arrivedPassengers.Size(); i++ )
   {
       m_log << left
            << setw( 10 ) << m_arrivedPassengers.GetAt(i).GetTicketNumber()
            << setw( 30 ) << m_arrivedPassengers.GetAt(i).GetName()
            << setw( 10 ) << m_arrivedPassengers.GetAt(i).GetEnqueueTime()
            << setw( 10 ) << m_arrivedPassengers.GetAt(i).GetBoardingTime()
            << setw( 10 ) << m_arrivedPassengers.GetAt(i).GetArrivalTime()
            << setw( 10 ) << m_arrivedPassengers.GetAt(i).GetSeat()
            << endl;
    }
}

string AirlineProgram::NiceTime( int hr, int min ) // done
{
    string nice = StringUtil::ToString( hr ) + ":";
    if ( min < 10 )
    {
        nice += "0";
    }
    nice += StringUtil::ToString( min );
    return nice;
}

void AirlineProgram::TimePasses( int& hr, float& min ) // done
{
    min += 0.05;
    if ( min >= 60 )
    {
        hr++;
        min = 0;
    }
}

