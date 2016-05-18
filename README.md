# ConnectX Bug report
[![Build Status](https://travis-ci.org/nmolkeri/ConnectX.svg?branch=master)](https://travis-ci.org/nmolkeri/ConnectX)

- The bug is in the (Piece at(int, int);) function.
- Bug can be found when accessing the width which is out of bound of the board.
- A garbage value is returned when we try to access width out of the bounds.
- This bug originates in (bool inBounds(int,int);) function. 
