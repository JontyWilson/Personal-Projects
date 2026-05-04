#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

int main()
{
    // Variable/array declarations
    BST<int, string>* dictionary = new BST<int, string>();
    const string stringArr[] = { "seventy-seven", "seventy", "seventy-five", "sixty-six", "seventy-nine", "sixty-eight", "sixty-seven", "sixty-nine", "ninety", "eighty-five", "eighty-three", "eighty-seven", "sixty-five" };
    const int arr[] = { 77, 70, 75, 66, 79, 68, 67, 69, 90, 85, 83, 87, 65 };
    const int inputs = 13;

    cout << "Testing the insert function to build my tree." << endl;

    for (int i = 0; i < inputs; ++i)
    {
        dictionary->insert(arr[i], stringArr[i]);
    }

    // Output tree size, structure; demonstrate inorder and reverse order print functions
    cout << "My BST tree size is " << dictionary->size() << endl;

    cout << "My tree's structure is (tests my changes to the print function): " << endl;
    dictionary->print();
    cout << endl;
     
    cout << "Inorder printing of my tree" << endl;
    cout << "(tests my right threads and printInorder function):" << endl;
    dictionary->printInorder();
    cout << endl;

    cout << "Reverse order printing of my tree" << endl;
    cout << "(tests my left threads and printReverse function):" << endl;
    dictionary->printReverse();
    cout << endl;

    system("pause");
    return 0;
}
