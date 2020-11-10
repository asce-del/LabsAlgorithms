#include <stdexcept>
#include "stdio.h"

struct TFuzzyNumber {
    float x;
    float e1;
    float e2;
};

TFuzzyNumber init(float a, float b, float c) {
    TFuzzyNumber result;
    result.e1 = a;
    result.x = b;
    result.e2 = c;
    return result;
}

TFuzzyNumber input() {
    TFuzzyNumber result;
    printf("Enter three random numbers");
    scanf("%f %f %f", &result.e1, &result.x, &result.e2);
    return result;
}

void output(TFuzzyNumber Ob) {
    printf("%.2f, %.2f, %.2f", Ob.x - Ob.e1, Ob.x, Ob.x + Ob.e2);
}

TFuzzyNumber add(TFuzzyNumber Ob1, TFuzzyNumber Ob2) {
    TFuzzyNumber result;
    result.e1 = Ob1.x + Ob2.x - Ob1.e1 - Ob2.e1;
    result.x = Ob1.x + Ob2.x;
    result.e2 = Ob1.x + Ob2.x + Ob1.e2 + Ob1.e2;
    return result;
}

TFuzzyNumber minus(TFuzzyNumber Ob1, TFuzzyNumber Ob2) {
    TFuzzyNumber result;
    result.e1 = Ob1.x - Ob2.x - Ob1.e1 - Ob2.e1;
    result.x = Ob1.x - Ob2.x;
    result.e2 = Ob1.x - Ob2.x + Ob1.e2 + Ob1.e2;
    return result;
}

TFuzzyNumber multiple(TFuzzyNumber Ob1, TFuzzyNumber Ob2) {
    TFuzzyNumber result;
    result.e1 = Ob1.x * Ob2.x - Ob2.x * Ob1.e1 - Ob1.x * Ob2.e1 + Ob1.e1 * Ob2.e1;
    result.x = Ob1.x * Ob2.x;
    result.e2 = Ob1.x * Ob2.x + Ob2.x * Ob1.e2 + Ob1.x * Ob2.e2 + Ob1.e2 * Ob2.e2;
    return result;
}


TFuzzyNumber divideByOne(TFuzzyNumber Ob1) {
    TFuzzyNumber result;
    if (Ob1.x > 0) {
        result.e1 = (1 / (Ob1.x + Ob1.e1));
        result.x = 1 / Ob1.x;
        result.e2 = 1 / (Ob1.x - Ob1.e2);
        return result;
    } else {
        printf("A is =< 0\n");
        throw std::invalid_argument( "received null value" );
    }
}

TFuzzyNumber division(TFuzzyNumber Ob1, TFuzzyNumber Ob2) {
    TFuzzyNumber result;
    if (Ob2.x > 0) {
        result.e1 = ((Ob1.x - Ob1.e1) / (Ob2.x + Ob2.e1));
        result.x = Ob1.x / Ob2.x;
        result.e2 = (Ob1.x + Ob1.e2) / (Ob2.x - Ob2.e2);
        return result;
    } else {
        printf("B is =< 0\n");
        throw std::invalid_argument( "received null value" );
    };
}

int main() {
    TFuzzyNumber EzNumber = init(5, 6, 3);
    TFuzzyNumber HardNumber = input();
    output(division(EzNumber, HardNumber));
    return 0;
}