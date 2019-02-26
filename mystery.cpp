#include <iostream>
#include <vector>
using namespace std;

void print(auto A) {
   for (auto a : A) 
        cout <<a<<" ";
   cout<<endl;
}

void mystery1(auto& Data)
{
  cout<<endl<<"Mystery 1"<<endl<<"---------------------"<<endl;

  for (unsigned int i = 0; i < Data.size(); i++) {
    for (unsigned int j = 0; j < i; j++)
		if (Data[i] < Data[j])
	    	swap(Data[i], Data[j]);
    print(Data);
  }//end outer for (this brace is needed to include the print statement)

}

void mystery2(auto& Data) {
    cout<<endl<<"Mystery 2"<<endl<<"---------------------"<<endl;	
	unsigned int minIndex;
	for (unsigned int i = 0; i < Data.size() - 1; i++) {
		minIndex = i;	
        for (unsigned int j = i + 1; j < Data.size(); j++)
			if (Data[j] < Data[minIndex])
				minIndex = j;
		if (minIndex != i)
			swap(Data[i], Data[minIndex]);	
		print(Data);		
	} //end outer loop
}

void mystery3(auto& Data) {
   cout<<endl<<"Mystery 3"<<endl<<"---------------------"<<endl;
	//loop through elements of vector
	for (unsigned int i = 1; i < Data.size(); i++) {
		auto insertVal = Data[i]; //store value of current element
		unsigned int j = i; //initialize location to place element
		//search for location to place current element
		while (j > 0 && Data[--j] > insertVal)
			Data[j+1] = Data[j]; //shift elements one slot to right
		Data[j] = insertVal;
		print(Data);
	}
}

int main() {
    
  vector<int> Data = {36, 18, 22, 30, 29, 25, 12};

  vector<int> D1 = Data;
  vector<int> D2 = Data;
  vector<int> D3 = Data;

  mystery1(D1);
  mystery2(D2);
  mystery3(D3);
}
