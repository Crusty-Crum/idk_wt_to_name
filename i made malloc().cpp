#include<iostream>
using namespace std;
class A{
	public:
		int x;
}a;
class B{
	public:
		int y;
		B(int y=0){
			(*this).y=y;
		}
}b;

int* malloc(int x,string type){
     if(type=="variable"){
     int *y=new int(x);
       return y;
      }
     if(type=="array"){
         int *a=new int[x];
              return a;
    }
    if(type=="object(B)"){
    	B *obj=new B(x);
    	return (int *)obj;
	}
	else{
		return NULL;
	}
}

// mid way i learnt that we can typecast pointers!!!!!!!!
void* malloc(string type){
    if(type=="object"){
    	A *object=new A();
    	return (void*)object;
	}
	else{
		return NULL;
	}
}
int main(){
	int *x=malloc(10,"variable");
	cout<<"Variable Value: "<<*x<<'\n';	
	
	
	int *y=malloc(3,"array");
	for(int i=0;i<3;i++){
		cout<<"Enter Value "<<i+1<<": ";
		cin>>y[i];	
	}
	for(int i=0;i<3;i++){
		cout<<y[i]<<"->";
	}
	cout<<"Nothing Ahead!"<<endl;
	
	
	//object without consructor
	A *obj=(A*)malloc("object");
	obj->x=10;
	cout<<"A's x: "<<obj->x;
	cout<<endl;
	
	//object with constructor
	B *obj1=(B*)malloc(10,"object(B)");
	cout<<"B's y: "<<obj1->y;
	
	return 0;
}

