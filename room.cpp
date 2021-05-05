#include "room.h"

Room::Room(int roomNum){
    setRoomNumber(roomNum);
    setRoomSize("Small");
    roomOccupied = false;
}

void Room::setRoomNumber(int num){
    roomNumber = num;
}

void Room:: setRoomSize(string Size){
    roomSize = Size;
    if(roomSize== "Small"){roomCost = 100;}
    else if(roomSize == "Medium"){roomCost = 200;}
    else{roomCost = 300;}
}

bool Room::roomcheckIn(){
    if(getRoomOccupied() == 0){
        roomOccupied = true;
        return true;
    }
    else{return false;}
}

bool Room::roomcheckOut(){
    if(getRoomOccupied() == 1){
        roomOccupied = false;
        return true;
    }
    else{return false;}
}
