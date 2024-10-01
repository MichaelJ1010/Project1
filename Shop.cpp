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
void printItemsAndPrices(string items[], double prices[]);
void buyItems(int itemNumber, double dailyPrices[], string dailyItems[]);
void buyItems(double dailyPrices[], string dailyItems[]);
void startGame();
string getDay(int day);

int main(){
        srand(time(0));
        startGame();
    return 0;
}

void startGame(){
    int trackDay = 1;
    string dailyItems[3];
    double dailyPrices[3];
    int itemQuantity[3];
    
    while(true){
    
    cout << "*****************************************************************************" << endl;
    cout << "Welcome to the Shop! Today is " << getDay(trackDay++) << endl << "Here's what's available today: " << endl;
    if(trackDay == 8){
        trackDay = 1;
    }
    randomizeItems(dailyItems);
    randomizePrice(dailyPrices);
    randomizeQuantity(itemQuantity);
    printItemsAndPrices(dailyItems, dailyPrices);
    buyItems(dailyPrices, dailyItems);
    if(trackDay == 10){
        break;
    }
    }
}
string getDay(int day){
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


void randomizeItems(string items[]){
        
    for(int i = 0; i < 3; i++){
    
    int n = rand() % 3;

    items[i] = itemNames[n];
    for(int j = 0; j < i; j++){
    if(items[i] == items[j]){
        i--;
        break;
    }
    }   
 }
}

void randomizePrice(double prices[]){
    
    for(int i = 0; i < 3; i++){
    
    int n = rand() % 3;
    
    prices[i] = itemValues[n];
    for(int j = 0; j < i; j++){
    if(prices[i] == prices[j]){
        i--;
        break;
    }
    }    
 }
}

void randomizeQuantity(int quantity[]){
    for(int i = 0; i < 3; i++){
    quantity[i] = (rand() % 3) + 1;
    }    
 }

void printItemsAndPrices(string items[], double prices[]){
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ") " << items[i] << " - " << setprecision(2) << fixed << "$" << prices[i] << setw(10);
    }
}

void buyItems(int itemNumber, double dailyPrices[], string dailyItems[]){
    double futureBalance = currentBalance - dailyPrices[itemNumber - 1];
    if(futureBalance < 0){
            cout << "Oops! You don't have enough to buy that!" << endl;
        }else{
            currentBalance = futureBalance;
            cout << "Bought " << dailyItems[itemNumber - 1] << " for " << setprecision(2) << fixed << "$" << dailyPrices[itemNumber - 1] << endl;
            
        }
}
void buyItems(double dailyPrices[], string dailyItems[]){
    bool continueShopping = true;
    cout << endl << "You are starting the day off with $" << currentBalance << endl;
    cout << "Press the number of the item you would like to buy. If you are done, press 4" << endl;
    do{
        cout << "*****************************************************************************" << endl;
        int playerChoice;
        cin >> playerChoice;
        

        switch(playerChoice){
            case 1:
            buyItems(playerChoice, dailyPrices, dailyItems);
            break;
            case 2:
            buyItems(playerChoice, dailyPrices, dailyItems);
            break;
            case 3:
            buyItems(playerChoice, dailyPrices, dailyItems);
            break;
            case 4:
            continueShopping = false;
            break;
            default:
            cout << "Error, not a valid option." << endl;
            break;
        }
        
        if(continueShopping){
            printItemsAndPrices(dailyItems, dailyPrices);
            cout << setw(0) << endl;  
            cout << "Current balance: " << currentBalance << endl;
        }
        
    
    }while(continueShopping);
}




