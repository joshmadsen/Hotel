#include "hotel.h"

int hotelCount(Hotel* hotels[]){
    int count = 0;
    for(int i = 0; i < 100; i++){
        if(hotels[i] != NULL){count++;}
        else{return count;}
    }
    return count;
}

void addHotel(Hotel* hotels[], string name){
    int hCount = hotelCount(hotels);
    hotels[hCount] = new Hotel(name);
}

void buyHotel(Hotel* hotels[], string name, int hotelLocation){ // all hotels, name for new hotel, which hotel is paying for new hotel.
    int coef = (((hotelCount(hotels)/2) > 1) ? (hotelCount(hotels)/2) : 1);
    int newHotelCost = 20000 * hotelCount(hotels) * coef;
    if(hotels[hotelLocation]->getMoney() >= newHotelCost){
        cout << "Successfully purchased new hotel for $" << newHotelCost << "." << endl << endl;
        addHotel(hotels, name);
        hotels[hotelLocation]->editMoney(-newHotelCost);

    }else{cout << "You do not have enough money for a new hotel. A new hotel costs $" << newHotelCost << "." << endl << endl;}
}

int main(){
    Hotel* hotels[100] = {NULL};
    addHotel(hotels, "Josh's Hotel");
    cout << hotelCount(hotels);
    hotels[0]->printHotelInfo();
    hotels[0]->checkIn(0);
    hotels[0]->checkIn(0);
    hotels[0]->checkOut(0);
    hotels[0]->checkOut(0);
    buyHotel(hotels, "J", 0);
    hotels[0]->editMoney(19900);
    buyHotel(hotels, "J", 0);
    hotels[0]->printHotelInfo();
    cout << "Adding Room..." << endl << endl;
    hotels[0]->addRoom();
    cout << "All done" << endl;
    return 0;
}





