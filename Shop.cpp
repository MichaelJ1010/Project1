#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const string itemNames[] = {"apple", "orange", "strawberry", "bannanna", "grape"};
const double itemValues[] = {2.50, 2.00, 3.50, 1.50, 3.00};
double currentBalance = 50.00;
    

void randomizeItems(string items[]);
void randomizePrice(double prices[]);
void randomizeQuantity(int quantity[]);
void printQuantityItemPrices(int quantity[], string items[], double prices[]);
void buyItems(int itemNumber, int dailyQuantity[], double dailyPrices[], string dailyItems[]);
void buyItems(int dailyQuantity[], double dailyPrices[], string dailyItems[]);
void startGame();
string getDay(int day);

int main(){
        srand(time(0));
        startGame();
    return 0;
}

void startGame(){ //sets correct day and randomizes shop items
    short int trackDay = 1;
    string dailyItems[3];
    double dailyPrices[3];
    int dailyQuantity[3];
    
    while(true){
    
    cout << "*****************************************************************************" << endl;
    cout << "Welcome to the Shop! Today is " << getDay(trackDay++) << endl << "Here's what's available today: " << endl;
    if(trackDay == 8){
        trackDay = 1;
    }

    randomizeItems(dailyItems);
    randomizePrice(dailyPrices);
    randomizeQuantity(dailyQuantity);
   printQuantityItemPrices(dailyQuantity,dailyItems,dailyPrices);
    buyItems(dailyQuantity, dailyPrices, dailyItems);
    
    if(trackDay == 10){
        break;
    }
    }
}


string getDay(int day){ //returns the day we are on
    if(day % 7 == 0){
        return "Sunday";
    }
    if(day % 6 == 0){
        return "Saturday";
    }
    if(day % 5 == 0){
        currentBalance += 30;
        return "Friday";
    }
    if(day % 4 == 0){
        currentBalance += 30;
        return "Thursday";
    }
    if(day % 3 == 0){
        currentBalance += 30;
        return "Wednesday";
    }
    if(day % 2 == 0){
        currentBalance += 30;
        return "Tuesday";
    }
    if(day % 1 == 0){
        currentBalance += 30;
        return "Monday";
    }
}


void randomizeItems(string items[]){ //randomizes items for the current day
        
    for(int i = 0; i < 3; i++){
    
    short int randomNumber  = rand() % 3;

    items[i] = itemNames[randomNumber];
    for(int j = 0; j < i; j++){
    if(items[i] == items[j]){
        i--;
        break;
    }
    }   
 }
}


void randomizePrice(double prices[]){ //randomizes prices for the current day
    
    for(int i = 0; i < 3; i++){
    
    short int randomNumber = rand() % 3;
    
    prices[i] = itemValues[randomNumber];
    for(int j = 0; j < i; j++){
    if(prices[i] == prices[j]){
        i--;
        break;
    }
    }    
 }
}


void randomizeQuantity(int quantity[]){ //randomizes quantities for the current day
    for(int i = 0; i < 3; i++){
    quantity[i] = (rand() % 3) + 1;
    }    
 }


void printQuantityItemPrices(int quantity[], string items[], double prices[]){ //formats items and prices nicely for the user
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ") " << items[i] << " - " << setprecision(2) << fixed << "$" << prices[i] << setw(10);
    }
}


void buyItems(int itemNumber,int dailyQuantity[], double dailyPrices[], string dailyItems[]){ //determines if user can buy item
    double futureBalance = currentBalance - dailyPrices[itemNumber - 1];
    if(itemNumber == 0){
            return;
        }else if(futureBalance < 0 ){
            cout << "Oops! You don't have enough to buy that!" << endl;
        }else{
            currentBalance = futureBalance;
            cout << "Bought " << dailyItems[itemNumber - 1] << " for " << setprecision(2) << fixed << "$" << dailyPrices[itemNumber - 1] << endl;            
        }
}


void buyItems(int dailyQuantity[], double dailyPrices[], string dailyItems[]){ //determines what item user is trying to buy
    bool continueShopping = true;
    cout << endl << "You are starting the day off with $" << currentBalance << endl;
    cout << "Press the number of the item you would like to buy. If you are done, press 4" << endl;
    do{
        cout << "*****************************************************************************" << endl;
        char playerChoice;
        cin >> playerChoice;
        
        switch(playerChoice){
            case '1':
            buyItems(1, dailyQuantity, dailyPrices, dailyItems);
            break;
            case '2':
            buyItems(2, dailyQuantity, dailyPrices, dailyItems);
            break;
            case '3':
            buyItems(3, dailyQuantity, dailyPrices, dailyItems);
            break;
            case '4':
            continueShopping = false;
            break;
            default:
            cout << "Error, not a valid option." << endl;
            break;
        }
        
        if(continueShopping){
            printQuantityItemPrices(dailyQuantity,dailyItems,dailyPrices);
            cout << setw(0) << endl;  
            cout << "Current balance: " << currentBalance << endl;
        }
        
    
    }while(continueShopping);
}




