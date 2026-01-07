# Airline Program

## Overview

This project simulates a basic airline boarding and disembarking process. It reads passenger information from a log file, processes it by enqueuing and boarding passengers, and then disembarks them. The program generates a log file with detailed information about each step, and produces a summary of all passengers at the end.

The system includes classes and methods for handling passenger information, a boarding queue, and an airplane seating arrangement.

## Features

- **Enqueueing passengers:** Reads passenger information from a log file and adds them to the queue.
- **Boarding passengers:** Moves passengers from the queue to the airplane seats.
- **Disembarking passengers:** Removes passengers from the airplane seats and logs their departure.
- **Summary:** Outputs a detailed summary of each passenger’s information, including enqueue time, boarding time, arrival time, and seat number.

## Classes

### `AirlineProgram`

- Handles the main operations: loading passenger data, enqueuing, boarding, disembarking, and summarizing the results.
- Writes events and activities to a log file.
  
### `Passenger`

- Stores details about each passenger, such as their name, ticket number, enqueue time, boarding time, and arrival time.
- Supports input and output stream operators to read and write passenger data from/to files.



