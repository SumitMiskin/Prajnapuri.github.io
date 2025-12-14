#include <iostream>
using namespace std;

struct Node {
    string stage;
    Node* left;
    Node* right;
};

int main() {
    Node* root = new Node{"Seedling", NULL, NULL};
    root->left = new Node{"Vegetative", NULL, NULL};
    root->right = new Node{"Harvest", NULL, NULL};

    cout << "Current Stage: " << root->stage << endl;
    return 0;
}
