#include "GridTest.h"


void GridTest::setup()
{
	testgrid.AddDoor(3,3);
	testgrid.AddDoor(7,2);
	testgrid.AddDoor(6,5);
	testgrid.AddDoor(5,9);
}

void GridTest::tear_down()
{
	testgrid.ClearGrid();
	testgrid.ClearGrid();
}

void GridTest::TestDoorInsertion()
{
	TEST_ASSERT(testgrid.AddDoor(3,3)==false)
	TEST_ASSERT(testgrid.AddDoor(7,6)==false)
	TEST_ASSERT(testgrid.AddDoor(3,4)==false)
	TEST_ASSERT(testgrid.AddDoor(0,9)==false)
	TEST_ASSERT(testgrid.AddDoor(5,10)==false)
	TEST_ASSERT(testgrid.AddDoor(100, -100)==false)
	TEST_ASSERT(testgrid.AddDoor(3,7))
}

void GridTest::TestRotation90()
{
	TEST_ASSERT(testgrid.RotateGrid(90))
	std::vector<glm::ivec2> doors = testgrid.GetDoorPositions();
	
	TEST_ASSERT(doors.size() == 4)
	TEST_ASSERT(doors.at(0).x == 7)
	TEST_ASSERT(doors.at(0).y == 3)
	TEST_ASSERT(doors.at(1).x == 8)
	TEST_ASSERT(doors.at(1).y == 7)
	TEST_ASSERT(doors.at(2).x == 5)
	TEST_ASSERT(doors.at(2).y == 6)
	TEST_ASSERT(doors.at(3).x == 1)
	TEST_ASSERT(doors.at(3).y == 5)
}

void GridTest::TestRotation180()
{
	TEST_ASSERT(testgrid.RotateGrid(180))
	std::vector<glm::ivec2> doors = testgrid.GetDoorPositions();
	
	TEST_ASSERT(doors.size() == 4)
	TEST_ASSERT(doors.at(0).x == 7)
	TEST_ASSERT(doors.at(0).y == 7)
	TEST_ASSERT(doors.at(1).x == 3)
	TEST_ASSERT(doors.at(1).y == 8)
	TEST_ASSERT(doors.at(2).x == 4)
	TEST_ASSERT(doors.at(2).y == 5)
	TEST_ASSERT(doors.at(3).x == 5)
	TEST_ASSERT(doors.at(3).y == 1)
}

void GridTest::TestRotation270()
{
	TEST_ASSERT(testgrid.RotateGrid(270))
	std::vector<glm::ivec2> doors = testgrid.GetDoorPositions();
	
	TEST_ASSERT(doors.size() == 4)
	TEST_ASSERT(doors.at(0).x == 3)
	TEST_ASSERT(doors.at(0).y == 7)
	TEST_ASSERT(doors.at(1).x == 2)
	TEST_ASSERT(doors.at(1).y == 3)
	TEST_ASSERT(doors.at(2).x == 5)
	TEST_ASSERT(doors.at(2).y == 4)
	TEST_ASSERT(doors.at(3).x == 9)
	TEST_ASSERT(doors.at(3).y == 5)
}

void GridTest::TestMirrorHorizontal()
{
	testgrid.MirrorGridHorizontal();
	std::vector<glm::ivec2> doors = testgrid.GetDoorPositions();
	
	TEST_ASSERT(doors.size() == 4)
	TEST_ASSERT(doors.at(0).x == 3)
	TEST_ASSERT(doors.at(0).y == 7)
	TEST_ASSERT(doors.at(1).x == 7)
	TEST_ASSERT(doors.at(1).y == 8)
	TEST_ASSERT(doors.at(2).x == 6)
	TEST_ASSERT(doors.at(2).y == 5)
	TEST_ASSERT(doors.at(3).x == 5)
	TEST_ASSERT(doors.at(3).y == 1)
}

void GridTest::TestMirrorVertical()
{
	testgrid.MirrorGridVertical();
	std::vector<glm::ivec2> doors = testgrid.GetDoorPositions();
	
	TEST_ASSERT(doors.size() == 4)
	TEST_ASSERT(doors.at(0).x == 7)
	TEST_ASSERT(doors.at(0).y == 3)
	TEST_ASSERT(doors.at(1).x == 3)
	TEST_ASSERT(doors.at(1).y == 2)
	TEST_ASSERT(doors.at(2).x == 4)
	TEST_ASSERT(doors.at(2).y == 5)
	TEST_ASSERT(doors.at(3).x == 5)
	TEST_ASSERT(doors.at(3).y == 9)
}