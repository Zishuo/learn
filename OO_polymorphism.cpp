#include <iostream>
using std::cout; using std::endl;

class baseClass{
	
public:
	baseClass(){}
	void func(){ cout << "bass::func()" << endl;}
	virtual void virtualFunc(){ cout << "bass::virtualFunc()" << endl;}
private:
	//  VS2012 does not support.
	//	baseClass & operator = (const baseClass &) = delete; 
	//	baseClass(const baseClass &) = delete;
	//	To disable default copy constructor and assignment copyer, you have to do
	baseClass & operator = (const baseClass &);
	baseClass(const baseClass &);
};

class noneClass{
public:
	void func(){ cout << "noneClass::func()" << endl;};
};

class derivedClass:public baseClass{

public:
	derivedClass(){}
	void func(){ cout << "derived::func()" << endl;}
	void virtualFunc(){ cout << "derived::virtualFunc()" << endl;}
};


int main(int argc, char * argv[]){
	
	derivedClass * C = new derivedClass();
	C->func();

	baseClass * B = C;
	B->func();

	dynamic_cast<noneClass *>(C)->func();
	B->func();

	B->virtualFunc();

	system("PAUSE");
	return 0;
}