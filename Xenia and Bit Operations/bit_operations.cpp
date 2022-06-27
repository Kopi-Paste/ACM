#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
 
struct Node{
	int line;
	int value;
	Node * brother;
	Node * parent;
	Node(int l, int v){
		line = l;
		value = v;
	}
	~Node(){
		if (parent){
			delete parent;
			parent = nullptr;
			brother->parent = nullptr;
		}
	}
	void addParent(Node * p){
		parent = p;
	}
	void addOther(Node * otherNode){
		brother = otherNode;
		otherNode->brother = this;
	}
	int updateTree(int newValue, int & currentResult){
		if (value == newValue)
			return currentResult;
		value = newValue;
		if (!parent){
			currentResult = newValue;
			return newValue;
		}
		else if (line & 1)
			return parent->updateTree(value | brother->value, currentResult);
		else
			return parent->updateTree(value ^ brother->value, currentResult);
	}
};
 
vector<Node *> getInput(int inputLen){
	vector<Node *> retValue;
	int num;
	for (int i = 0; i < inputLen; i++){
		cin >> num;
		retValue.push_back(new Node(1, num));
		if (i & 1)
			retValue[i]->addOther(retValue[i - 1]);
	}
	return retValue;
}
 
vector<Node *>  generateLine(vector<Node *> & previous, int & length, bool exclusive){
	length /= 2;
	vector<Node *> retValue;
	for (int i = 0; i < length; i++){
		int newNum;
		if (exclusive)
			newNum = previous[2*i]->value ^ previous[2*i + 1]->value;
		else
			newNum = previous[2*i]->value | previous[2*i + 1]->value;
		Node * newNode = new Node(previous[2*i]->line + 1, newNum);
		retValue.push_back(newNode);
		if (i & 1)
			newNode->addOther(retValue[i - 1]);
		previous[2*i]->addParent(newNode);
		previous[2*i + 1]->addParent(newNode);
	}
	return retValue;
}
 
int generateTree(vector<Node *> leafs, int inputLen, int depth){
	vector<Node *> current = leafs;
	for (int i = 0; i < depth; i++){
		current = generateLine(current, inputLen, i & 1);
	}
	current[0]->addParent(nullptr);
	return current[0]->value;
}
 
void handleQuery(vector<Node *> & leafs, int & root, int position, int value){
	cout << leafs[position - 1]->updateTree(value, root) << endl;
}
 
void handleQueries(vector<Node *> & leafs, int & root, int queries){
	int position, value;
	for (int i = 0; i < queries; i++){
		cin >> position >> value;
		handleQuery(leafs, root, position, value);
	}
}
 
int main(){
	int depth, queries, root;
	cin >> depth >> queries;
	int inputLen = pow(2, depth);
	vector<Node *> leafs = getInput(inputLen);
	root = generateTree(leafs, inputLen, depth);
	handleQueries(leafs, root, queries);
	for (auto x : leafs){
		delete x;
	}
	return 0;
}