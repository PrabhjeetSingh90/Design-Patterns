#include <iostream>
#include <vector>
using namespace std;

class observer{
  public:
    virtual void update(int value) = 0;
};

class stateMachine
{
  int state;
  vector <class observer *> objects;
  
  public:
    void attch(observer *obj )
    {
      objects.push_back(obj);
    }
    void set_state(int value)
    {
      state = value;
      notify();
    }
    void notify()
    {
      for(int i = 0; i < objects.size(); i++)
      {
        objects[i]->update(state);
      }
    }
};

class controller: public observer
{
  int state;
  public:
    controller(stateMachine *st, int value)
    {
      st->attch(this);
      state = value;
    }
    void update(int value)
    {
      state = value;
    }
    void run()
    {
      cout << "controller running with state = " << state << '\n';
    }
};

// Multiple Classes can be added by inheriting the observer class
// and update function can be modified to suit the need

int main() {
  stateMachine st;
  controller cnt(&st, 1);
  st.set_state(2);
  cnt.run();
  st.set_state(5);
  cnt.run();
  return 0;
}