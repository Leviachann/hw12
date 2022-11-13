#include <iostream>
#include <vector>
using namespace std;
class Car {
public:
  static int staticId;
  int id;
  string vendor;
  string model;

  Car(string vend, string mod) {
    id = staticId++;
    vendor = vend;
    model = mod;
  }
  virtual void Show() {
    cout << "Id: " << id << "\nVendor: " << vendor << "\nModel: " << model
         << "\n"
         << endl;
  }
};

class Manual {
public:
  void Start() { cout << "Manual car\n"; }
};

class Automatic {
public:
  void Start() { cout << "Automatic car\n"; }
};

class BMW : public Car, public Manual {
public:
  bool hasSpoiler;
  BMW(string vend, string mod, bool hasSpoiler) : Car(vend, mod) {
    this->hasSpoiler = hasSpoiler;
  }

  void Show() override {
    cout << "*******BMW*******\n";

    Car::Show();
    cout << "Spoiler: " << (hasSpoiler ? "var" : "yox") << endl;
  };
};

class Audi : public Car, public Automatic {
public:
  bool hasSpoiler;
  Audi(string vend, string mod, bool hasSpoiler) : Car(vend, mod) {
    this->hasSpoiler = hasSpoiler;
  }

  void Show() override {
    cout << "*******Audi*******\n";

    Car::Show();
    cout << "Spoiler: " << (hasSpoiler ? "var" : "yox") << endl;
  };
};
int main() { vector<Car *> cars; }