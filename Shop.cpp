#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    string itemNames[] = {"apple", "orange", "strawberry"};
    double itemValues[] = {2.50, 2.00, 3.50};


void itemsOfDay(){
    
    for(int i = 0; i < 3; i++){
        cout << itemNames[i] << " , ";
    }
}

void item(){
    
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


void price(){
    
    
    
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


int main(){
    double balance = 50.00;
        srand(time(0));
        cout << setw(50) << "Welcome to the Shop!" << endl << "Here's what's available today: " << endl;
        item();
        price();
        cout << endl;
    

    return 0;
}