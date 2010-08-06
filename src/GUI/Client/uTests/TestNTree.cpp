#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>
#include <boost/iterator.hpp>

#include "GUI/Client/NTree.hpp"

////////////////////////////////////////////////////////////////////////////////

struct NTree_Fixture
{
  /// common setup for each test case
  NTree_Fixture()
  {
    // int*    argc = &boost::unit_test::framework::master_test_suite().argc;
    // char*** argv = &boost::unit_test::framework::master_test_suite().argv;
  }

  /// common tear-down for each test case
  ~NTree_Fixture()
  {
  }

  /// possibly common functions used on the tests below

  /// common values accessed by all tests goes here

};

////////////////////////////////////////////////////////////////////////////////

BOOST_FIXTURE_TEST_SUITE( Client_TestSuite, NTree_Fixture )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( constructor )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( setRoot )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( setCurrentIndex )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( getNodeParams )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( setAdvancedMode )
{
 // + test signal
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( areFromSameNode )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( haveSameData )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( getNodeByPath )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( getIndexByPath )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( nodeToIndex )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( modifyOptions )
{
  // testable ?
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( data )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( index )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( parent )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( rowCount )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( columnCount )
{
  // testable ?
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( headerData )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( showMenu )
{
  // testable ?
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( setDebugModeEnabled )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( list_tree )
{

}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()

