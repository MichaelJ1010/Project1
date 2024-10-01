#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    string itemNames[] = {"apple", "orange", "strawberry"};
    double itemValues[] = {2.50, 2.00, 3.50};
    string dailyItems[3];
    double dailyPrices[3];




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

void printItemsAndPrices(string items[], double prices[]){
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ") " << items[i] << " - " << setprecision(2) << fixed << "$" << prices[i] << setw(10);
    }
}

void buyItems(int itemNumber){
    switch(itemNumber){
        case 1:
        cout << "Bought " << dailyItems[0] << " for " << setprecision(2) << fixed << "$" << dailyPrices[0] << endl;
        break;
        case 2:
        cout << "Bought " << dailyItems[1] << " for " << setprecision(2) << fixed << "$" << dailyPrices[1] << endl;
        break;
        case 3:
        cout << "Bought " << dailyItems[2] << " for " << setprecision(2) << fixed << "$" << dailyPrices[2] << endl;
        break;
    }
}
void buyItems(){
    bool continueShopping = true;
    cout << "Press the number of the item you would like to buy. If you are done, press 4" << endl;
    do{
        int playerChoice;
        cin >> playerChoice;
        

        switch(playerChoice){
            case 1:
            buyItems(playerChoice);
            break;
            case 2:
            buyItems(playerChoice);
            break;
            case 3:
            buyItems(playerChoice);
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
        }
        
    
    }while(continueShopping);
}




int main(){
    double balance = 50.00;
        srand(time(0));
        cout << "Welcome to the Shop!" << endl << "Here's what's available today: " << endl;
        randomizeItems(dailyItems);
        randomizePrice(dailyPrices);
        printItemsAndPrices(dailyItems, dailyPrices);
        cout << endl;
        buyItems();
        cout << endl;
    

    return 0;
}