#include <iostream>
using namespace std;
// Simple Example to Demonstrate Singelton Design Pattern.
// In Singelton Design Pattern the class will always have Single Instance
// The class provide the mechanism to achieve that. See getinstance() function
// in below class filesystem. The Instance variable is taken as static to 
// retain the address of Instantiated object.
class filesystem
{
  static filesystem *Instance;
  int size;
  int count;
  filesystem()
  { size = 0; count = 0;}
  
  public:
    static filesystem* getinstance()
    {
      if (Instance == NULL)
        Instance = new filesystem();
      return Instance;
    }
    
    int getsize()
    {
      return size;
    }
    
    int getcount()
    {
      return count;
    }
    
    int setsize(int temp)
    {
      size += temp;
    }
    
    int setcount(int temp)
    {
      count += temp;
    }
};

// Initializing singelton class Instance to NULL
filesystem * filesystem::Instance = NULL;

void user1()
{
  filesystem *obj1 = filesystem::getinstance();
  obj1->setsize(100);
  obj1->setcount(100);
  cout << "size of file system = " << obj1->getsize() << endl;
  cout << "count of file system = " << obj1->getcount() << endl;
    
}

void user2()
{
  filesystem *obj2 = filesystem::getinstance();
  obj2->setsize(100);
  obj2->setcount(100);
  cout << "size of file system = " << obj2->getsize() << endl;
  cout << "count of file system = " << obj2->getcount() << endl;
}

int main() {
  // your code goes here
  user1();
  user2();
  return 0;
}
