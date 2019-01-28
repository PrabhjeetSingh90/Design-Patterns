#include <iostream>
#include <vector>
using namespace std;

class flybehaviour{
  public:
    virtual void fly()=0;
};

class flybehav1: public flybehaviour{
  public:
    virtual void fly()
    {
      cout << "This duck has fly behaviour of Type 1" << endl;
    }
};

class flybehav2: public flybehaviour{
  public:
    virtual void fly()
    {
      cout << "This duck has fly behaviour of Type 2" << endl;
    }
};

class eatbehaviour{
  public:
    virtual void eat() = 0;
};

class eatbehav1: public eatbehaviour{
  public:
    virtual void eat()
    {
      cout << "This duck has eat behaviour fo Type 1" << endl;
    }
};

class eatbehav2: public eatbehaviour{
  public:
    virtual void eat()
    {
      cout << "This duck had eat behaviour fo Type 2" << endl;
    }
};

class stratergy{
  private:
    flybehaviour* fly_obj;
    eatbehaviour* eat_obj;
  public:
    void set_flybehaviour(flybehaviour* Temp)
    {
      fly_obj = Temp;
    }
    void set_eatbehaviour(eatbehaviour* Temp)
    {
      eat_obj = Temp;
    }
    void fly()
    {
      fly_obj->fly();
    }
    void eat()
    {
      eat_obj->eat();
    }
};

class plastic_Duck{
  flybehav1 fly1;
  eatbehav1 eat1;
  stratergy st;
  public:
    plastic_Duck()
    {
      st.set_flybehaviour(&fly1);
      st.set_eatbehaviour(&eat1);
    }
    void display()
    {
      cout << "This is a Plastic Duck" << endl;
    }
    void fly()
    {
      
      st.fly();
    }
    void eat()
    {
      st.eat();
    }
};

class Real_Duck{
  flybehav2 fly2;
  eatbehav2 eat2;
  stratergy st;
  public:
    Real_Duck()
    {
      st.set_flybehaviour(&fly2);
      st.set_eatbehaviour(&eat2);
    }
    void display()
    {
      cout << "This is a Real Duck" << endl;
    }
    void fly()
    {
      
      st.fly();
    }
    void eat()
    {
      st.eat();
    }
};

class Mountain_Duck{
  flybehav1 fly1;
  eatbehav2 eat2;
  stratergy st;
  public:
    Mountain_Duck()
    {
      st.set_flybehaviour(&fly1);
      st.set_eatbehaviour(&eat2);
    }
    void display()
    {
      cout << "This is a Mountain Duck" << endl;
    }
    void fly()
    {
      
      st.fly();
    }
    void eat()
    {
      st.eat();
    }
};

int main()
{
  plastic_Duck obj1;
  Real_Duck obj2;
  Mountain_Duck obj3;
  
  obj1.display();
  obj1.fly();
  obj1.eat();
  
  obj2.display();
  obj2.fly();
  obj2.eat();
  
  obj3.display();
  obj3.fly();
  obj3.eat();
  return 0;
}