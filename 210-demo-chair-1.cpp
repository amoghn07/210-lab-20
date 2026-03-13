#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

const int MIN = 10000, MAX = 99999, MINLEG = 3, MAXLEG = 4;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        //picking either 3 or 4 legs
        legs = (rand() % (MAXLEG - MINLEG + 1)) + MINLEG;

        for (int i = 0; i < SIZE; i++){
            //initializing prices array with a random double
            double price = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
            prices[i] = price;
        }
    }
    //partial constructor
    Chair(int l) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = 0;
    }

    //changing parameter constructor to include argument for array of doubles
    Chair(int l, double pricearg []) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = pricearg[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    //now using default constructor, which assigns private members random values
    Chair *chairPtr = new Chair;
    chairPtr->print();

    //creating dynamic chair object with constructor, now with 2 parameters
    double price [SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, price);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    
    for (int i = 0; i < SIZE; i++){
        cout << "boom" << endl;
        collection[i].print();
    }
    
    return 0;
}