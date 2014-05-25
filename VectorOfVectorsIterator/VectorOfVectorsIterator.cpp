#include <iostream>
#include <vector>
using namespace std;

class VectorOfVectorsIteractor{
private:
	vector<vector<int> >::iterator end;
	vector<vector<int> >::iterator row;
	vector<int>::iterator col;
	
	void reachNext(){
		while(row != end && (*row).begin() == (*row).end())
			row++;
		
		if(row != end)
			col = (*row).begin();		
	}
	
public:
	VectorOfVectorsIteractor(vector<vector<int> >& vv){
		end = vv.end();
		row = vv.begin();
		reachNext();
	}
	
	bool hasNext(){
		if(row == end)
			return false;
		
		if(col == (*row).end())
			return false;
		
		return true;
	}
	
	int next(){
		int val = *col;
		
		col++;
		if(col == (*row).end()){
			row++;
			reachNext();
		}
		
		return val;
	}
};

int main(){
	vector<vector<int> > vv;
	vector<int> v1;
	v1.push_back(1);
	
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	
	vector<int> v3;
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);

	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	
	VectorOfVectorsIteractor it(vv);

	while(it.hasNext())
		cout << it.next() << " ";
	cout << "\n";
	
	return 0;
}