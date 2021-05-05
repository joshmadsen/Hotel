#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"

using namespace std;

class Hotel{
private:
    int hrooms;
    string hname;
    int hmoney;
    int hroomsBooked;
public:
    int currentRoomInfo[4];
    Room* HotelRooms[100];
    Hotel(string name);

    void setMembers(string name);
    string getName()const{return hname;}
    int getRooms(){return hrooms;}
    int getMoney(){return hmoney;}

    void populateRoomsList(int totalRooms, Room* roomsList[]);
    void printHotelInfo();

    void getRoomInfo(int roomToCheck, int roomInfo[]);
    void printRoomInfo(int room, int roomInfo[]);

    void checkIn(int room);
    void checkOut(int room);
    void editMoney(int changedMoney){hmoney = hmoney + changedMoney;};

    void addRoom();
    void buyRoom();
};

#endif // HOTEL_H
