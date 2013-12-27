An airline seat reservation system that keeps a record of seat
availability for its flights in a file seatfile. The file contains flight numbers &
number of seats currently available for that flight. To reserve a seat/s on a
particular flight we must perform the following operations:
1) Open the seat file
2) Seek to the record for the required flight
3) Read the current number of seats.
4) Decrement it
5) Write it back to the file.
Write a program to perform the above scenario. Take care of the concurrent user
accessing the Database(seatfile).

