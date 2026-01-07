#include "Passenger.h"

#include "../../Utilities/StringUtil.hpp"

#include <string>
using namespace std;

Passenger::Passenger()
{
    m_ticketNumber = -1;
    m_name = "UNSET";
    m_enqueueTime = "UNSET";
    m_boardingTime = "UNSET";
    m_arrivalTime = "UNSET";
    m_seat = -1;
}

string Passenger::GetName() const
{
    return m_name;
}

void Passenger::SetName( string val )
{
    m_name = val;
}

int Passenger::GetTicketNumber() const
{
    return m_ticketNumber;
}

void Passenger::SetTicketNumber( int val )
{
    m_ticketNumber = val;
}

string Passenger::GetEnqueueTime() const
{
    return m_enqueueTime;
}

void Passenger::SetEnqueueTime( string val )
{
    m_enqueueTime = val;
}

string Passenger::GetBoardingTime() const
{
    return m_boardingTime;
}

void Passenger::SetBoardingTime( string val )
{
    m_boardingTime = val;
}

string Passenger::GetArrivalTime() const
{
    return m_arrivalTime;
}

void Passenger::SetArrivalTime( string val )
{
    m_arrivalTime = val;
}

void Passenger::SetSeat( int val )
{
    m_seat = val;
}

int Passenger::GetSeat() const
{
    return m_seat;
}

/*
Format:

CUSTOMER_ENQUEUES {
  Time: 12:00
  Ticket: 9351
  Name: Thaer Jonas
}

Name may be more than 2 names
*/
istream& operator>>( istream& in, Passenger& item )
{
    string buffer;
    string name = "";
    string time = "";
    int id;

    while ( getline( in, buffer ) )
    {
        if ( StringUtil::Contains( buffer, "Ticket:" ) )
        {
            buffer = StringUtil::Replace( buffer, "  Ticket: ", "" );
            id = StringUtil::StringToInt( buffer );
            item.SetTicketNumber( id );
        }
        else if ( StringUtil::Contains( buffer, "Name:" ) )
        {
            name = StringUtil::Replace( buffer, "  Name: ", "" );
            item.SetName( name );
        }
        else if ( StringUtil::Contains( buffer, "Time:" ) )
        {
            time = StringUtil::Replace( buffer, "  Time: ", "" );
            item.SetEnqueueTime( time );
        }
        else if ( buffer == "}" )
        {
            return in;
        }
    }

    return in; // it shouldn't get here
}

ostream& operator<<( ostream& out, const Passenger& item )
{
    out << item.GetTicketNumber() << " (" << item.GetName() << ")";
    return out;
}



