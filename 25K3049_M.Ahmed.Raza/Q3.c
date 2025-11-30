#include <stdio.h>
#include <string.h>
struct flightInfo{
    int flightNum;
    char departureCity[20];
    char destinationCity[20];
    char date[10];
    int seatsleft;
};
void bookSeat(struct flightInfo *flight, int num){
    if(flight->flightNum == num){
        if(flight->seatsleft > 0){
            flight->seatsleft--;
        }
    }
}
void display(struct flightInfo flight){
    printf("Flight Num: %d\nDeparture From: %s\nDestination To: %s\nFlight Date: %s\nSeats Left: %d", flight.flightNum,flight.departureCity,flight.destinationCity,flight.date,flight.seatsleft);    
}
int main(){
    struct flightInfo flight1 = {001, "Karachi", "Lahore", "29-11-2025", 50};
    int choice;
    struct flightInfo *ptr = &flight1;
    char destination[20];
    printf("Do you want to book a seat or display flight details ? Enter 1 and 2 for each respectively\n");
    scanf("%d", &choice);
    if(choice == 1){
        printf("Where do you want to go ?\n");
        scanf("%s", destination);
        if(strcmp(flight1.destinationCity, destination) == 0){
            bookSeat(ptr, flight1.flightNum);
        }
    }else{
        if(choice == 2){
            display(flight1);
        }
    }
}