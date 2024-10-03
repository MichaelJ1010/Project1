#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const string itemNames[] = {"apple", "orange", "strawberry", "bannanna", "grape"};
const double itemValues[] = {12.50, 12.00, 13.50, 11.50, 13.00};
int dailyQuantity[3];
int points;

    

void randomizeItems(string items[]);
void randomizePrice(double prices[]);
void randomizeQuantity();
void printQuantityItemPrices(int quantity[], string items[], double prices[]);
void buyItems(int itemNumber, int dailyQuantity[], double dailyPrices[], string dailyItems[], double &currentBalance);
void buyItems(int dailyQuantity[], double dailyPrices[], string dailyItems[], double &currentBalance);
void startGame();
string getDay(int day, double &currentBalance);
void assignPoints(string items[], int size);

int main(){
    srand(time(0));
    startGame();
    return 0;
}

void startGame(){ //sets correct day and randomizes shop items
    short int totalDays = 0;  
    short int trackDay = 1;  
    double totalBalance = 50.00;
    string dailyItems[3];
    double dailyPrices[3];
    

    cout << "***************************************************************************************" << endl;
    cout << "This is a new shop that will stay open for 10 days. You can earn special reward points" << endl
    << "when you spend money in the shop. Try to get over 500 points before the shop closes!" << endl;
    
    while(true){
    cout << "***************************************************************************************" << endl;

    if(totalDays < 10){
    cout << "day " << totalDays << ": " << 10 - totalDays << " days left!" << endl;
    totalDays++;
    }else if(totalDays == 10){
        cout << "day " << totalDays << ": " << "last day!" << endl;
        totalDays++;
    }else{
        break;
    }


    cout << "Welcome to the Shop! Today is " << getDay(trackDay++, totalBalance) << endl << "Here's what's available today: " << endl;
    if(trackDay == 8){
        trackDay = 1;
    }


    randomizeItems(dailyItems);
    randomizePrice(dailyPrices);
    randomizeQuantity();
    printQuantityItemPrices(dailyQuantity,dailyItems,dailyPrices);
    buyItems(dailyQuantity, dailyPrices, dailyItems, totalBalance);
    
    }
}


string getDay(int day, double &currentBalance){ //returns the day we are on
    if(day % 7 == 0){
        return "Sunday, your day off. No money added.";
    }
    if(day % 6 == 0){
        return "Saturday, your day off. No money added.";
    }
    if(day % 5 == 0){
        currentBalance += 20;
        return "Friday, you get off early. You earned $20 today.";
    }
    if(day % 4 == 0){
        currentBalance += 30;
        return "a regular Thursday, earned $30.";
    }
    if(day % 3 == 0){
        currentBalance += 30;
        return "discount Wednesday! earned $30";
    }
    if(day % 2 == 0){
        currentBalance += 30;
        return "a normal Tuesday. Earned $30.";
    }
    if(day % 1 == 0){  
        currentBalance += 40;
        return "Monday, and you're starting strong! Earned $40";
    }
}


void randomizeItems(string items[]){ //randomizes items for the current day
        
    for(int i = 0; i < 3; i++){
    
    short int randomNumber  = rand() % size(itemNames);

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
    
    short int randomNumber = rand() % size(itemValues);
    
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
    for(int &item: dailyQuantity){
    item = (rand() % 5) + 3;
    }    
 }


void printQuantityItemPrices(int quantity[], string items[], double prices[]){ //formats items and prices nicely for the user
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ") " << items[i] << " - " << setprecision(2) << fixed << "$" << prices[i]  << " " 
        << quantity[i] << " left"<< setw(10);
    }
}


void buyItems(int itemNumber,int dailyQuantity[], double dailyPrices[], string dailyItems[], double &currentBalance){ //determines if user can buy item
    double futureBalance = currentBalance - dailyPrices[itemNumber - 1];
    if(dailyQuantity[itemNumber - 1] == 0){
            cout << "Oops! There's none left to buy!" << endl;
        }else if(futureBalance < 0 ){
            cout << "Oops! You don't have enough to buy that!" << endl;
        }else{
            currentBalance = futureBalance;
            cout << "Bought " << dailyItems[itemNumber - 1] << " for " << setprecision(2) << fixed << "$" << dailyPrices[itemNumber - 1] << endl;
            dailyQuantity[itemNumber - 1]--;
        }
}


void buyItems(int dailyQuantity[], double dailyPrices[], string dailyItems[], double &currentBalance){ //determines what item user is trying to buy
    bool continueShopping = true;
    cout << endl << "You are starting the day off with $" << currentBalance << endl;
    cout << "Type the number of the item you would like to buy. If you are done today, press 4" << endl;
    do{
        cout << "***************************************************************************************" << endl;
        char playerChoice;
        cin >> playerChoice;
        
        switch(playerChoice){
            case '1':
            buyItems(1, dailyQuantity, dailyPrices, dailyItems, currentBalance);
            break;
            case '2':
            buyItems(2, dailyQuantity, dailyPrices, dailyItems, currentBalance);
            break;
            case '3':
            buyItems(3, dailyQuantity, dailyPrices, dailyItems, currentBalance);
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
// void assignPoints(int points[], int size, string items[]){
//     for(int item: points){

//     }
// }



