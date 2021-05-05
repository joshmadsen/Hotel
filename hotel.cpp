#include "hotel.h"

Hotel::Hotel(string name){
    setMembers(name);
    populateRoomsList(hrooms, HotelRooms);
}

void Hotel::setMembers(string name){
    hname = name;
    hrooms = 10;
    hmoney = 0;
    hroomsBooked = 0;
}

void Hotel::populateRoomsList(int totalrooms,Room* roomsList[]){
    for (int i = 0; i < totalrooms; i++){
       roomsList[i] =  new Room(i+1);
       if(i >= ((totalrooms/2)+1) && i != (totalrooms - (totalrooms/10))){roomsList[i]->setRoomSize("Medium");}
       else if (i == totalrooms - (totalrooms/10)){roomsList[i]->setRoomSize("Large");}
       else{roomsList[i]->setRoomSize("Small");}
    }
}

void Hotel::printHotelInfo(){
    cout << hname << endl << "-------------------------" << endl;
    cout << "Total Rooms: " << hrooms << endl;
    cout << "Rooms Booked: " << hroomsBooked << endl;
    cout << "Cash: $" << hmoney << endl << endl;
}

void Hotel::getRoomInfo(int roomToCheck, int roomInfo[]){
    if(roomToCheck >= hrooms){cout << "You do not own a 'Room Number " << roomToCheck + 1 << "'." << endl << endl; return;}
    roomInfo[0] = HotelRooms[roomToCheck]->getRoomNumber();
    if(HotelRooms[roomToCheck]->getRoomSize() ==  "Small"){ roomInfo[1] = 0; }
    else if (HotelRooms[roomToCheck]->getRoomSize() ==  "Medium"){ roomInfo[1] = 1; }
    else if (HotelRooms[roomToCheck]->getRoomSize() ==  "Large"){ roomInfo[1] = 2; }
    roomInfo[2] = HotelRooms[roomToCheck]->getRoomCost();
    roomInfo[3] = int(HotelRooms[roomToCheck]->getRoomOccupied());
}

void Hotel::printRoomInfo(int room,int roomInfo[]){
    if(room >= hrooms){cout << "You do not own a 'Room Number " << room + 1 << "'." << endl << endl; return;}
    getRoomInfo(room, roomInfo);
    cout << "Room Number: " << roomInfo[0] << endl;
    string Size;
    switch(roomInfo[1]){case 0: Size = "Small"; break; case 1:Size="Medium";break;case 2:Size="Large";break;}
    cout << "Room Size: " << Size << endl;
    cout << "Room Cost: $" << roomInfo[2] << endl;
    if(roomInfo[3] == 0){cout << "Room Occupied: No" << endl << endl;}
    else{cout << "Room Occupied: Yes" << endl << endl;}
}

void Hotel::checkIn(int room){
    if(HotelRooms[room]->roomcheckIn() == true){
        hroomsBooked++;
        cout << "Check in for Room Number " << room + 1 << " was successful." << endl << endl;
    }
    else{cout << "Room Number " << room + 1 << " is already occupied." << endl << endl;}
}

void Hotel::checkOut(int room){
    if(HotelRooms[room]->roomcheckOut() == true){
        hroomsBooked--;
        cout << "Check out for Room Number " << room + 1 << " was succesful." << endl << endl;
        editMoney(HotelRooms[room]->getRoomCost());
    }
    else{cout << "Room Number " << room + 1 << " was not checked into." << endl << endl;}
}

void Hotel::addRoom(){
    hrooms++;
    populateRoomsList(hrooms, HotelRooms);
    printHotelInfo();
}

void Hotel::buyRoom(){
    int newRoomCost =  200 * hrooms * (hrooms/2);
    if(hmoney >= newRoomCost){
        cout << "Successfully purchased new room for $" << newRoomCost << "." << endl << endl;
        addRoom();
        editMoney(-newRoomCost);
    }else{cout << "You do not have enough money for a new room. A new room costs $" << newRoomCost << "." << endl << endl;}
}



