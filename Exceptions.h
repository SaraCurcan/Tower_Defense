#include<stdexcept>
#include<string>
using namespace std;
class ValueException : public runtime_error {
public:
    explicit ValueException(const string& msg): runtime_error(msg) {}
};

class NegativeValue: public ValueException {
    double badValue;
public:
    NegativeValue(const string& field,double badValue): ValueException("Incorrect value: " + to_string(badValue) + " for " + field + +" ; "+field + "'s value should be positive"), badValue(badValue) {}
    double getBadValue() const {return badValue;}
};