//
// Created by Left Ranae on 15.04.2023.
//

#include <iostream>

void ThreadFoo();
void ThreadBar();

template <typename T> T Sum(T a, T b) { return a + b; }

static int b = 5;

class StaticTest {
public:
  static int i;
  int j = 5;
}; // class StaticTest

/**
 * The Singleton class defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class Singleton {

  /**
   * The Singleton's constructor should always be private to prevent direct
   * construction calls with the `new` operator.
   */

protected:
  Singleton(const std::string value) : value_(value) {}

  // static Singleton *singleton_;

  std::string value_;

public:
  static int a;
  /**
   * Singletons should not be cloneable.
   */
  Singleton(Singleton &other) = delete;
  /**
   * Singletons should not be assignable.
   */
  void operator=(const Singleton &) = delete;
  /**
   * This is the static method that controls the access to the singleton
   * instance. On the first run, it creates a singleton object and places it
   * into the static field. On subsequent runs, it returns the client existing
   * object stored in the static field.
   */

  static Singleton *GetInstance(const std::string &value);
  /**
   * Finally, any singleton should define some business logic, which can be
   * executed on its instance.
   */
  void SomeBusinessLogic() {
    // ...
    std::cout << "Some important buisness function start." << this << std::endl;
  }
  std::string value() const { return value_; }
  inline int GetCounter() const noexcept { return counter; };
  inline void IncreaseCounter() { ++counter; };

private:
  static inline Singleton *singleton_ = nullptr;
  int counter{};
}; // Class Singleton

int Singleton::a = 5;
// Singleton *Singleton::singleton_ = nullptr;
/**
 * Static methods should be defined outside the class.
 */
Singleton *Singleton::GetInstance(const std::string &value) {
  /**
   * This is a safer way to create an instance. instance = new Singleton is
   * dangeruous in case two instance threads wants to access at the same time
   */
  if (singleton_ == nullptr) {
    singleton_ = new Singleton(value);
  }
  return singleton_;
}

int StaticTest::i = 5;

int main(int argc, char const *argv[]) {
  std::cout << "If you see the same value, then singleton was reused (yay!\n"
            << "If you see different values, then 2 singletons were created "
               "(booo!!)\n\n"
            << "RESULT:\n";
  // Singleton *sing_first = Singleton::GetInstance("First");
  // sing_first->SomeBusinessLogic();
  ThreadFoo();
  ThreadBar();
  if (argc > 0 || argv[0]) {
    std::cout << Sum(4, 4) << " Sum 4 + 4" << std::endl;
    std::cout << Sum(4.5, 4.1) << " Sum 4.5 + 4.1" << std::endl;
  }
  Singleton *sing = Singleton::GetInstance("BOO");
  std::cout << sing->value() << std::endl;
  sing->SomeBusinessLogic();
  Singleton *sing2 = Singleton::GetInstance("BOOooom");
  std::cout << sing2->value() << std::endl;
  sing2->SomeBusinessLogic();

  b = 6;
  StaticTest::i = 6;
  std::cout << StaticTest::i << std::endl;
  return 0;
}

void ThreadFoo() {
  // Following code emulates slow initialization.
  Singleton *singleton = Singleton::GetInstance("FOO");
  std::cout << singleton->value() << singleton->GetCounter() << std::endl;
  singleton->SomeBusinessLogic();
}

void ThreadBar() {
  // Following code emulates slow initialization.
  Singleton *singleton = Singleton::GetInstance("BAR");
  singleton->IncreaseCounter();
  std::cout << singleton->value() << singleton->GetCounter() << std::endl;
  singleton->SomeBusinessLogic();
}
