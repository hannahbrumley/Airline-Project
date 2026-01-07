#ifndef PASSENGER_H
#define PASSENGER_H

#include <istream>
using namespace std;

class Passenger
{
public:
    Passenger();

    string GetName() const;
    void SetName( string val );
    int GetTicketNumber() const;
    void SetTicketNumber( int val );
    string GetEnqueueTime() const;
    void SetEnqueueTime( string val );
    string GetBoardingTime() const;
    void SetBoardingTime( string val );
    string GetArrivalTime() const;
    void SetArrivalTime( string val );
    void SetSeat( int val );
    int GetSeat() const;

    friend istream& operator>>( istream& in, Passenger& item );
    friend ostream& operator<<( ostream& out, const Passenger& item );

private:
    string m_name;
    int m_ticketNumber;
    string m_enqueueTime;
    string m_boardingTime;
    string m_arrivalTime;
    int m_seat;
};

#endif // PASSENGER_H
