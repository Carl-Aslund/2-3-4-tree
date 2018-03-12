#include "tree-234.hpp"
#include "testing-logger.hpp"

#include <iostream>

using namespace std;

/** \brief Test default constructor for TreeString Set
 */
bool defaultConstructorTest()
{
    TestingLogger log("default");

    Tree234Set myTree;

    affirm(myTree.size() == 0);
    affirm(myTree.height() == -1);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test insert and size
 *  \detail Run a test by inserting elements repeatedly into a tree and then
 *          checking that it worked with size.
 */
bool insertSizeTest()
{
    TestingLogger log("insertSize");

    Tree234Set myTree;
    affirm(myTree.size() == 0);

    myTree.insert("hello");
    affirm(myTree.size() == 1);

    myTree.insert("world");
    affirm(myTree.size() == 2);

    myTree.insert("testing");
    affirm(myTree.size() == 3);

    myTree.insert("abra");
    affirm(myTree.size() == 4);

    myTree.insert("world");
    affirm(myTree.size() == 4);

    myTree.insert("kadabra");
    affirm(myTree.size() == 5);

    myTree.insert("black");
    affirm(myTree.size() == 6);

    myTree.insert("panther");
    affirm(myTree.size() == 7);

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test height
 *  \detail Tests whether or not the height function is accurate.
 */
 bool heightTest()
 {
    TestingLogger log("height");

    Tree234Set myTree;
    affirm(myTree.height() == -1);

    myTree.insert("hello");
    affirm(myTree.height() == 0);

    myTree.insert("world");
    affirm(myTree.height() == 0);

    myTree.insert("testing");
    affirm(myTree.height() == 0);

    myTree.insert("abra");
    affirm(myTree.height() == 1);

    myTree.insert("world");
    affirm(myTree.height() == 1);

    myTree.insert("kadabra");
    affirm(myTree.height() == 1);

    myTree.insert("black");
    affirm(myTree.height() == 1);

    myTree.insert("panther");
    affirm(myTree.height() == 1);

    myTree.insert("apple");
    affirm(myTree.height() == 1);

    myTree.insert("banana");
    affirm(myTree.height() == 1);

    myTree.insert("pear");
    affirm(myTree.height() == 2);

    // myTree.showStatistics(cout);
    cout << endl;

    //Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

int main()
{
    TestingLogger alltests("All tests");

    affirm(defaultConstructorTest());
    affirm(insertSizeTest());
    affirm(heightTest());
    // affirm(existsTest());

  // Print a summary of the all the affirmations and exit the program.
    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means tests failed.
    }
}
