#include <iostream> 
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> x = {1};
	int power = 2222;
	int ten = 10;
	while(power){
		int aux= 0;
		for (int i=0; i<x.size(); i++){
			int prod= 2*x[i]+aux;
			aux = 0;
			if (x[i]>4){
				prod = prod - ten;
				aux = 1;
			}
			x[i] = prod;
		}
		if (aux==1) x.push_back(1);
		power--;
	}
	int sum = 0;
	for (int i=x.size()-1; i>-1; i--)
		sum += x[i] ;
	cout << "Problem 5: " << sum;
	cout << endl;
}