#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    string itemNames[] = {"apple", "orange", "strawberry"};
    double itemValues[] = {2.50, 2.00, 3.50};




void randomizeItems(string items[]){
    
    string temp[3];
    
    for(int i = 0; i < 3; i++){
    
    int n = rand() % 3;
    

    temp[i] = itemNames[n];
    for(int j = 0; j < i; j++){
    if(temp[i] == temp[j]){
        i--;
    }
    }   
}
    for(string item: temp){
            cout << item << " ";
        }
}


void randomizePrice(double prices[]){
    
    
    
    double temp[3];
    
    for(int i = 0; i < 3; i++){
    
    int n = rand() % 3;
    

    temp[i] = itemValues[n];
    for(int j = 0; j < i; j++){
    if(temp[i] == temp[j]){
        i--;
        break;
    }
    }   
    
}
    for(double item: temp){
        cout << setprecision(2) << fixed << "$" << item << " ";
    }
    

}
void buyItems(){
    bool continueShopping = true;
    do{
        int playerChoice;
        cout << "Press the number of the item you would like to buy. If you are done, press 0" << endl;
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
        cout << setw(50) << "Welcome to the Shop!" << endl << "Here's what's available today: " << endl;
        randomizeItems(dailyItems);
        randomizePrice(dailyPrices);
        buyItems();
        cout << endl;
    

    return 0;
}