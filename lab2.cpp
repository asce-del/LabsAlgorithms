#include <iostream>
#include <string>

class TFuzzyNumber {
public:

    float x;
    float e1;
    float e2;

    TFuzzyNumber(float _x, float _e1, float _e2) {
        x = _x;
        e1 = _e1;
        e2 = _e2;
    }

    TFuzzyNumber() {
        printf("Enter three random numbers");
        scanf("%f %f %f", &e1, &x, &e2);
    }

    void output() {
        printf("%.2f, %.2f, %.2f", x - e1, x, x + e2);
    }

    void add(TFuzzyNumber _object) {
        TFuzzyNumber current = *this;

        e1 = current.x + _object.x - current.e1 - _object.e1;
        x = current.x + _object.x;
        e1 = current.x + _object.x + current.e2 + current.e2;
    }

    void minus(TFuzzyNumber _object) {
        TFuzzyNumber current = *this;

        e1 = current.x - _object.x - current.e1 - _object.e1;
        x = current.x - _object.x;
        e2 = current.x - _object.x + current.e2 + current.e2;
    }

    void multiple(TFuzzyNumber _object) {
        TFuzzyNumber current = *this;

        e1 = current.x * _object.x - _object.x * current.e1 - current.x * _object.e1 + current.e1 * _object.e1;
        x = current.x * _object.x;
        e2 = current.x * _object.x + _object.x * current.e2 + current.x * _object.e2 + current.e2 * _object.e2;
    }

    void division(TFuzzyNumber _object) {
        TFuzzyNumber current = *this;

        if (_object.x > 0) {
            e1 = ((current.x - current.e1) / (_object.x + _object.e1));
            x = current.x / _object.x;
            e2 = (current.x + current.e2) / (_object.x - _object.e2);
        } else {
            printf("B is =< 0\n");
            throw std::invalid_argument( "received null value" );
        };
    }

    void divideByOne(TFuzzyNumber _object) {
        if (_object.x > 0) {
            e1 = (1 / (_object.x + _object.e1));
            x = 1 / _object.x;
            e2 = 1 / (_object.x - _object.e2);
        } else {
            printf("A is =< 0\n");
            throw std::invalid_argument( "received null value" );
        }
    }
};


int main()
{
    TFuzzyNumber *EzNumber = new TFuzzyNumber(5, 6, 3);
    TFuzzyNumber *HardNumber = new TFuzzyNumber();

    EzNumber->division(*HardNumber);
    EzNumber->output();

    return 0;
}