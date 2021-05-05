#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

using namespace std;

class Room{
private:
    int roomNumber;
    string roomSize;
    int roomCost;
    bool roomOccupied;
public:
    Room(int roomNum);
    void setRoomNumber(int num);
    void setRoomSize(string Size);
    int getRoomNumber(){return roomNumber;}
    string getRoomSize(){return roomSize;}
    int getRoomCost(){return roomCost;}
    bool getRoomOccupied(){return roomOccupied;}
    bool roomcheckIn();
    bool roomcheckOut();
};

#endif // ROOM_H
