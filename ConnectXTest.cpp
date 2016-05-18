/**
 * Unit Tests for ConnectX class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "ConnectX.h"
#define DEFAULT_WIDTH 7
#define DEFAULT_HEIGHT 6


using namespace std;

static const Piece INVALID = -1;
static const Piece EMPTY = 0;
static const Piece WHITE = 1;
static const Piece BLACK = 2;


class ConnectXTest : public ::testing::Test
{
	protected:
		ConnectXTest(){}
		virtual ~ConnectXTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(ConnectXTest, sanityCheck)
{
	ASSERT_TRUE(true);
}




//Testing to see if piece is placed.
TEST(ConnectXTest, placePiece)
{
    ConnectX x(10,1,1);
    x.placePiece(1);
    ASSERT_TRUE(x.at(1,0));
}

//placing in one and testing in another place.
TEST(ConnectXTest, noPlacePiece)
{
    ConnectX x(10,1,1);
    x.placePiece(1);
    ASSERT_FALSE(x.at(2,0));
}

//checking for outBounds
TEST(ConnectXTest, outBounds)
{
    ConnectX x(10,10,1);
    x.placePiece(1);
    int flag = x.at(12,12);
    ASSERT_EQ(INVALID, flag);
}

TEST(ConnectXTest, inBoundPlace)
{
    ConnectX x(10,10,1);
    x.placePiece(1);
   // x.showBoard();
    ASSERT_GT(x.at(1,9), EMPTY);
}

TEST(ConnectXTest, blackTurn)
{
    ConnectX x(10,10,1);
    int flag = x.whoseTurn();
    ASSERT_EQ(BLACK,flag);
    //x.showBoard();
}

TEST(ConnectXTest, whiteTurn)
{
    ConnectX x(10,10,1);
    x.placePiece(1);
    int flag = x.whoseTurn();
    ASSERT_EQ(WHITE,flag);
}

TEST(ConnectXTest, invalidPlace)
{
    ConnectX x(10,1,1);
    x.placePiece(1);
    x.placePiece(1);
    ASSERT_EQ(INVALID, x.at(1,1));
}
