#include <iostream>
#include <cassert>
#include "BinaryTree.h"
#include "NodeQueue.h"

// #define NDEBUG
// Use (void) to silence unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;
int main()
{
    // Node data (potential search values)
    string* data10{ new string("dat0") };
    string* data11{ new string("dat1") };
    string* data12{ new string("dat2") };
    string* data13{ new string("dat3") };
    string* data14{ new string("dat4") };
    string data15{ "dat5" };
    string data16{ "dat6" };
    string data17{ "dat7" };
    string data18{ "dat8" };
    string data19{ "dat9" };


    //NodeQueue<string*,10> queue{ data10 };
    //queue.enqueue(data11);
    //queue.enqueue(data12);
    //queue.enqueue(data13);
    //queue.enqueue(data14);
    //queue.enqueue(&data15);
    //queue.enqueue(&data16);
    //queue.enqueue(&data17);
    //queue.enqueue(&data18);
    //queue.enqueue(&data19);
    //queue.print();

    // Unbalanced Tree definition
    BinaryTree<int> tree(15);
    tree.insert(6);
    tree.insert(23);
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(11);
    tree.insert(71);
    tree.insert(50);

    try {
        tree.insert(23);
    }
    catch (const std::invalid_argument&)
    {
        assertm(tree.size() != 10, "L'exception n'a pas eter lancer.");
        std::cout << "Execution continues past the first assert\n";
    }

    auto value = tree.search(52, tree.root());

    __debugbreak();
}