

// #include "maze/utils.h"
#include "maze/room.h"
#include <gmock/gmock.h>
#include "maze/base.h"

using namespace maze;
namespace maze{
class RoomTest : public ::testing::Test {
 protected:
  RoomTest()
      : _room{Position{15, 10}}
  {
    _room.visits_from() = {Direction::UP, Direction::RIGHT};
    _room.used_exits() ={Direction::UP,Direction::UP,  Direction::RIGHT, Direction::RIGHT, Direction::RIGHT};
    _room.available_exits() = {Direction::UP, Direction::RIGHT, Direction::DOWN};
    // builder = Builder(_maze);
    // builder.build_maze();
    // solver = Solver(builder.maze(), Position{1, 1}, Position{10, 10});
    // solver.solve_maze();
    // You can do set-up work for each test here.
  }

  virtual ~RoomTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }
  Room _room;
};


TEST_F(RoomTest, is_exit_free) {

  printf("Left is not free exit\n");
  ASSERT_TRUE( !_room.is_exit_free(Direction::LEFT));

  printf("Down is a free exit\n");
  ASSERT_TRUE( _room.is_exit_free(Direction::DOWN));

}

TEST_F(RoomTest, is_visited) {

  printf("The room has been visited\n");
  ASSERT_TRUE( _room.visited());

}

TEST_F(RoomTest, times_used_to_exits) {
  auto times_used_to_exits = _room.times_used_to_exits();
  printf("Down used zero times. \n");
  ASSERT_EQ( times_used_to_exits[0], std::vector<Direction>({ Direction::DOWN }));
  printf("Up used two times. \n");
  ASSERT_EQ( times_used_to_exits[2], std::vector<Direction>({ Direction::UP }));
  printf("Right  used three times. \n");
  ASSERT_EQ( times_used_to_exits[3], std::vector<Direction>({ Direction::RIGHT }));
}


TEST_F(RoomTest, less_used_available_exits) {
  printf("Less used available exit is Down, (zero times). \n");
  ASSERT_EQ( _room.less_used_available_exits(), std::vector<Direction>({ Direction::DOWN }));
}

TEST_F(RoomTest, unused_available_exits) {
  printf("Unused available exit is Down. \n");
  ASSERT_EQ( _room.unused_available_exits(), std::vector<Direction>({ Direction::DOWN }));
}

}




// int main(int #<{(|argc|)}>#, char* #<{(|argv|)}># []) {
//
//
//
//   // Valid rooms
//   // auto valid_rooms_to_build_ = builder.valid_rooms_to_build();
//   //  logVar(valid_rooms_to_build_.size(), "valid rooms to build size");
//   //  Room& r = valid_rooms_to_build_.front().get();
//   // builder.build_room(r, Direction::UP);
//   // logDirVector( r._visits_from, "visits_from r:");
//
//   // Room& r2 = builder._maze._rooms.at(0);
//   // Room& r2 = valid_rooms_to_build_.front().get();
//   // logVar(r2, "r2");
//   // logDirVector( r2._visits_from, "visits_from r2:");
//
//   // auto r2= builder._maze.find_room(r.position());
//   // logVar(**r2, "r2 from maze");
//   // logDirVector( (**r2)._visits_from, "visits_from r:");
//
//   // auto r_b= builder._maze.find_room(r.position());
//   // // builder.build_room(**r_b, Direction::DOWN);
//   // logDirVector( (**r_b)._visits_from, "visits_from r_b:");
//
//   // Main
//   // std::cout << "========================================" << std::endl;
//   // std::cout << "Main" << std::endl;
//   // std::cout << std::endl;
//   // // printRoom();
//   // // testfunction();
//   // std::vector<int> v{1, 4, 5, 68, 9899, 898};
//   // std::map<std::string, int> m{{"Spiros", 444}, {"Apostolia", 555}};
//   //
//   // Position p{10, 20};
//   // Position p2{23, 45};
//   // Room r{p};
//   // Room r2{p2};
//   // r._visits_from = {Direction::LEFT, Direction::LEFT, Direction::RIGHT,
//   //                   Direction::UP,   Direction::UP,   Direction::UP,
//   //                   Direction::UP};
//   // r._available_exits = {Direction::LEFT, Direction::RIGHT, Direction::UP};
//   // r._used_exits = {Direction::RIGHT, Direction::RIGHT, Direction::LEFT,
//   //                  Direction::UP, Direction::UP};
//   // // Direction::DOWN, Direction::DOWN, Direction::DOWN, Direction::DOWN};
//   //
//   // auto times_used_to_exits = r.times_used_to_exits();
//   // std::vector<Room> vr{r, r2};
//   // // log(vr,"Vector of Rooms");
//   // std::cout << r2 << std::endl;
//   //
//   // logVar(p, "Point Test");
//   // logVar(r, "Room Test");
//   // logVar(r.visited(), "Room visited");
//   // std::cout << std::boolalpha << r.visited() << std::endl;
//   // std::cout << std::boolalpha << r.is_exit_free(Direction::LEFT) <<
//   // std::endl;
//   // logVar(Direction::UP, "Dire");
//   // logDirVector(DIRECTIONS, "DIRECTIONS");
//   // logDirVector(r._used_exits, "USED EXITS");
//   // logDirVector(r._visits_from, "VISITS FROM");
//   // logDirVector(r.less_used_available_exits(),
//   "less_used_available_exits");
//   // if (r.unused_available_exits() != boost::none) {
//   //   logVar(r.unused_available_exits()->size(),
//   //          "SIZE of unused available_exits");
//   //   logDirVector(*(r.unused_available_exits()), "unused_available_exits");
//   // } else {
//   //   logVar("NO UNUSED AVAILABLE EXITS", "");
//   // };
//
//   // logVar(maze.rooms().size(), "Rooms size");
//   // logVar(maze.rooms().front(), "First  room");
//   // logVar(maze.rooms().back(), "Last  room");
//   //
//   // auto r44 = maze.find_room(4,4);
//   // auto r_no = maze.find_room(11,122);
//   //
//   // logVar(*r44, "Room at 4,4");
//   // // logVar(r_no, "No Room");
//   // logVar(r_no == boost::none, "No Room");
//
//   // Testing position equality operator
//   // Position const p12{1,2};
//   // Position const p122{1,2};
//   // Position const p4{4,5};
//   // std::cout << std::boolalpha << (p12 == p4) << std::endl;
//   //
//
//   // logVar(p12 == p122, "Posit Equal");
//   // Position p23{2,3};
//   // Position r23{p23};
//
//   // Testing room mutation
//   // Position const p12{1,2};
//   // auto r12 = maze.find_room(p12);
//   // logDirVector( (**r12)._available_exits, "AVAIL EXITS BEFORE");
//   // (**r12)._available_exits.push_back(Direction::UP);
//   // logDirVector( (**r12)._available_exits, "AVAIL EXITS AFTER");
//   //
//   // auto r12_b = maze.find_room(p12);
//   // logDirVector( (**r12_b)._available_exits, "AVAIL EXITS SECOND ");
//
//   // Testing rooms_to_build
//
//   // auto r23 = maze.find_room(p23);
//
//   // test next position
//
//   //  Position p{8,10};
//   // auto np = builder.next_position(Direction::UP,p );
//   //  logVar(*np, "New Position to ");
//
//   // testing determine direction
//   // logVar(*builder.current_position() , "current position");
//   // logVar(*builder.room_to_right() , "room to right");
//   // logVar(*builder.room_to_left() , "room to left");
//   // logVar(*builder.room_to_up() , "room to up");
//   // logVar(*builder.room_to_down() , "room to down");
//   // auto dir= builder.determine_direction(l);
//   // logVar(dir == boost::none, "dir");
//
//   // logVar(*builder.current_position(), "builder current pos");
//   // logVar(*builder.current_room(), "builder current room");
//
//   // Position p{10,1};
//   // auto rr = builder.room(p);
//
//   // logVar(rr == boost::none, "rr is none");
//   // logVar(*rr, "Room at 10,1 ");
//
//   // logVar(maze.all_rooms_visited(), "all rooms visited");
//   // logVar(builder.path().size(), "Path size");
//
//   return 0;
// }