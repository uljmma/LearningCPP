#include <iostream>
#include <memory>

using namespace std;

void lambdaValueCapture() {
    int value = 1;

    auto copyValue = [value] {
        return value;
    };

    value = 100;
    auto storedValue = copyValue();
    cout << "storedValue = " << storedValue << endl;
}

void lambdaReferenceCapture() {
    int value = 1;

    auto copyValue = [&value] {
        return value;
    };

    value = 100;
    auto storedValue = copyValue();
    cout << "storedValue = " << storedValue << endl;
}

void lambdaExpressionCapture() {
    auto important = make_unique<int>(1);

    auto add = [v1 = 1, v2 = move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };

    cout << "add(3, 4) = " << add(3, 4) << endl;
}

int main() {
    cout << "lambdaValueCapture: ";
    lambdaValueCapture();

    cout << "\nlambdaReferenceCapture: ";
    lambdaReferenceCapture();

    cout << "\nlambdaExpressionCapture: ";
    lambdaExpressionCapture();

    return 0;
}
