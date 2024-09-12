#include<iostream>
using namespace std;

class Array
{
	private: 
		int capacity;
		int lastIndex;
		int *ptr;
		
	public:
		Array(); 
		Array(Array &); 
		Array& operator=(Array &);
		void createArray(int);
		void insert(int , int);
		void append(int);
		int getItem(int);
		bool isFull();
		bool isEmpty();
		void del(int);
		void edit(int,int);
		int count();
		int getcapacity();
		void doubleArray();		
		~Array();
		
};
Array::Array(){
	ptr=NULL;
}


Array::Array(Array&arr)
{
	capacity=arr.capacity;
	lastIndex=arr.lastIndex;
	ptr = new int[capacity];
	for(int i=0;i<=lastIndex;i++)
		ptr[i]=arr.ptr[i];
}

Array& Array::operator=(Array &arr)
{
	capacity=arr.capacity;
	lastIndex=arr.lastIndex;
	if(ptr!=NULL)
		delete []ptr;
	ptr = new int[capacity];
	for(int i=0;i<=lastIndex;i++)
		ptr[i]=arr.ptr[i];
	return (*this);
}

void Array::createArray(int cap)
{
	capacity=cap;
	lastIndex=-1;
	if(ptr!=NULL)
		delete []ptr;
	ptr= new int[capacity];
}


void Array::append(int value)
{
	if(!isFull())
	{
		lastIndex++;
		ptr[lastIndex]=value;
	}
	else
	{
		cout<<"Capacity Increess : ";
		doubleArray();
		ptr[lastIndex]=value;
	}
}

void Array::doubleArray()
{
	
	int *temp= new int[capacity*2];
	int i;
	for(i=0;i<=lastIndex;i++)
	{
		temp[i]=ptr[i];
	}
 
	delete &ptr;
	
	ptr=temp;
	
	
}

void Array::insert(int index,int data)
{ int i;
	try
	{
		if(index<0 || index>lastIndex+1)
			throw 1;
		if(isFull())
			throw 2;
		for(i=lastIndex; i>=index; i--)
		{
			ptr[i+1]=ptr[i];
		}
		ptr[index]=data;
		lastIndex++;
	}
	catch(int e)
	{
		if(e==1)
		{
			cout<<"invalid index";
		}
		else if(e==2)
			cout<<"OverFlow : ";
	}
	 
}


bool Array::isFull(){
	return lastIndex==capacity-1;
}
bool Array::isEmpty()
{
	return lastIndex==-1;
}

int Array::getItem(int index)
{
	try{
		 if(index<0 || index>lastIndex)
		 	throw 1;
		return ptr[index];
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvailid Index or Array is Empty";
		
	}
	return 0;
}

int Array::getcapacity()
{
	return capacity;
}

int Array::count()
{  
	return lastIndex+1;
}

void Array::edit(int index,int newData)
{
	try{
		if(index<0  || index>lastIndex)
			throw 1;
		ptr[index]=newData;
		
	}
	catch(int e){
		if(e==1)
			cout<<"\nInvalid index";
	}
	
}

void Array::del(int index)
{ int i;
	try{ 
		if(index<0  || index>lastIndex)
			throw 1;
		for(i=index;i<=lastIndex;i++)
		{
			ptr[i]=ptr[i+1];
		}
		lastIndex--;
	}
	catch(int e)
	{
		if(e==1)
			cout<<"\nInvalid index or underFlow";
	}
}

Array::~Array()
{
	delete []ptr;
}


int main()
{
	Array a1;
	a1.createArray(3);
	a1.append(4);
	a1.append(7);
	a1.append(5);
	a1.append(7);
	a1.getItem(2);
	cout<<a1.count();
}
