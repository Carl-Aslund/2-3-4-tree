#include "234-tree.hpp"
#include "testing-logger.hpp"

using namespace std;

/** \brief Test default constructor for TreeString Set
 */
bool defaultConstructorTest()
{
    // TODO: Add tests for the default constructor
    TestingLogger log("default");

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test insert and size
 *  \detail TODO: Add details
 */
bool insertSizeTest()
{
    // TODO: Add tests for insert() and size()
    TestingLogger log("insertSize");

    // Print a summary of the all the affirmations and return true
    // if they were all successful.
    return log.summarize();
}

/** \brief Test height
 *  \detail Tests whether or not the height function is accurate.
 */
 bool heightTest()
 {
    // TODO: Add tests for height
    TestingLogger log("height");

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
    affirm(existsTest());

  // Print a summary of the all the affirmations and exit the program.
    if (alltests.summarize(true)) {
        return 0;       // Error code of 0 == Success!
    } else {
        return 2;       // Arbitrarily chosen exit code of 2 means tests failed.
    }
}
