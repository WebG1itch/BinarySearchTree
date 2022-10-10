// BTS.cpp


#include <iostream>


struct node {
    int key;
    node* left;
    node* right;
};

node* insert(int insertVal) {
	node* n = NULL;
	n = new node;
	n->key = insertVal;
	n->left = NULL; 
	n->right = NULL;
    return n;
}

node* sort(int * arr, int begin, int end) {

	if (begin > end) {
		return NULL;
	}

	int key = (begin + end) / 2;
	node* n = insert(*(arr + key));

	if(begin <= key - 1) {
		n->left = sort(arr, begin, key - 1);
	}

	if(key + 1 <= end) {
		n->right = sort(arr, key + 1, end);
	}

	return n;
}

void printNum(node* currentNode, std::string spaces) {
	std::string extraSpacing = spaces.append("    ");
	if (currentNode->left != NULL) {
		printNum(currentNode->left, extraSpacing);
	}

	std::cout << spaces << currentNode->key << std::endl;

	if (currentNode->right != NULL) {
		printNum(currentNode->right, extraSpacing);
	}
}

void kSmallest(node* currentNode, int* changes, int k) {
	if (currentNode->left != NULL) {
		kSmallest(currentNode->left, changes, k);
	}
	
	(*changes)++;
	if (*changes == k+1) {
		std::cout << "The " << k << "-th smallest number is " << currentNode->key << std::endl;
	}
	
	if (currentNode->right != NULL) {
		kSmallest(currentNode->right, changes, k);
	}
}

int defineK() {
	int input = 0;
	std::cout << "Define k to find the k-th smallest number in the tree, with 0 being the smallest and 14 being the largest.\nk = ";
	std::cin >> input;
	return input;
}

int main() {
	
	int k = defineK();

    int* defaultNums;
	int p[15] = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
	defaultNums = p;

	node* root = sort(defaultNums, 0, sizeof(p) / sizeof(p[0]) - 1);
	
	printNum(root, "");

	int* changes = new int;
	*changes = 0;
	kSmallest(root, changes, k);
    return 0;
}
