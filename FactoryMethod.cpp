#include <iostream>
using namespace std;

// Abstract Signal Class
class Signal
{
  public:
  virtual void createsignal() = 0;
  static Signal* Generatesignal(int type);
  
};
// Concret Signal Classes
class Integer_T : public Signal{
  public:
    void createsignal()
    {
      cout << " Creating the signal of type Integer";
    }
};

class Float_T : public Signal{
  public:
    void createsignal()
    {
      cout << "Create the Signal to type Float";
    }
};

class Boolean_T : public Signal{
  public:
    void createsignal()
    {
      cout <<  "Create the Signal to type Boolean";
    }
};

// Signal Factory Method
Signal* Signal :: Generatesignal(int type)
{
  if (type == 1)
    return new Integer_T();
  else if(type == 2)
    return new Float_T();
  else if (type == 3)
    return new Boolean_T();
  else
    return NULL;
}

// Client Class. Client Need Specific Signal/Product
// There may be different client requesting different
// type of signal. All the request can be manage by
// Factory method Generate Signal
class client{
  private:
  Signal *sig;
  public:
  client()
  {
    sig = Signal :: Generatesignal(3);
  }
  ~client()
  {
    if (sig)
      {
        delete sig;
        sig = NULL;
      }
  }
  Signal* getsignal()
  {
    return sig;
  }
};

int main()
{
  client *objClient = new client();
  Signal * objsig = objClient->getsignal();
  objsig->createsignal();
  return 0;
}