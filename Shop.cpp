#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    string itemNames[] = {"apple", "orange", "strawberry"};
    double itemValues[] = {2.50, 2.00, 3.50};




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
        cout << setw(50) << items[i] << " - " << setprecision(2) << fixed << "$" << prices[i] << endl;
    }
}


void buyItems(){
    bool continueShopping = true;
    cout << "Press the number of the item you would like to buy. If you are done, press 0" << endl;
    do{
        int playerChoice;
        
        cin >> playerChoice;
        switch(playerChoice){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 0:
            continueShopping = false;
            break;
            default:
            cout << "Error, not a valid option." << endl;
            break;
        }
    
    }while(continueShopping);
}
void buyItems(int itemNumber){
    switch(itemNumber){
        case 1:
        break;
        case 2:
        break;
        case 3:
        break;
    }
}



int main(){
    double balance = 50.00;
        srand(time(0));
        string dailyItems[3];
        double dailyPrices[3];
        cout << "Welcome to the Shop!" << endl << "Here's what's available today: " << endl;
        randomizeItems(dailyItems);
        randomizePrice(dailyPrices);
        printItemsAndPrices(dailyItems, dailyPrices);
        cout << endl;
        buyItems();
        cout << endl;
    

    return 0;
}