//---------------------
// TestingDarwin.c++
// Stephen Cook
//---------------------


/*
Run the program:
% ls /usr/include/cppunit/
...
HelperMacros.h
...
% locate libcppunit.a
/usr/lib/libcppunit.a
% g++ -pedantic -std=c++0x -lcppunit -ldl -Wall TestDarwin.c++ -o TestDarwin.c++.app
% valgrind TestDarwin.c++.app >& TestDarwin.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#define private public
#define protected public
#include "Darwin.h"


// -----------
// TestDarwin
// -----------

struct TestDarwin : CppUnit::TestFixture {
	
	
	void test_add_instruction_1() {
        
	}
	void test_add_instruction_2() {
        
	}
	void test_add_instruction_3() {
        
	}
	
	void test_next_instruction_1(){
		
	}
	void test_next_instruction_2(){
		
	}
	void test_next_instruction_3(){
		
	}
	
	void test_species_abbreviation_1(){
		
	}
	void test_species_abbreviation_2(){
		
	}
	void test_species_abbreviation_3(){
		
	}
	
	void test_creature_constructor_1(){
		
	}
	void test_creature_constructor_2(){
		
	}
	void test_creature_constructor_3(){
		
	}
	
	void test_creature_run_1(){
		
	}
	void test_creature_run_2(){
		
	}
	void test_creature_run_3(){
		
	}
	
	void test_creature_hop_1(){
		
	}
	void test_creature_hop_2(){
		
	}
	void test_creature_hop_3(){
		
	}
	
	void test_creature_left_1(){
		
	}
	void test_creature_left_2(){
		
	}
	void test_creature_left_3(){
		
	}
	
	void test_creature_right_1(){
		
	}
	void test_creature_right_2(){
		
	}
	void test_creature_right_3(){
		
	}
	
	void test_creature_infect_1(){
		
	}
	void test_creature_infect_2(){
		
	}
	void test_creature_infect_3(){
		
	}
	
	void test_creature_left_1(){
		
	}
	void test_creature_left_2(){
		
	}
	void test_creature_left_3(){
		
	}
	
	void test_creature_ifempty_1(){
		
	}
	void test_creature_ifempty_2(){
		
	}
	void test_creature_ifempty_3(){
		
	}
	
	void test_creature_ifwall_1(){
		
	}
	void test_creature_ifwall_2(){
		
	}
	void test_creature_ifwall_3(){
		
	}
	
	void test_creature_ifrandom_1(){
		
	}
	void test_creature_ifrandom_2(){
		
	}
	void test_creature_ifrandom_3(){
		
	}
	
	void test_creature_ifenemy_1(){
		
	}
	void test_creature_ifenemy_2(){
		
	}
	void test_creature_ifenemy_3(){
		
	}
	
	void test_creature_go_1(){
		
	}
	void test_creature_go_2(){
		
	}
	void test_creature_go_3(){
		
	}
	
	void test_creature_reset_1(){
		
	}
	void test_creature_reset_2(){
		
	}
	void test_creature_reset_3(){
		
	}
	
	void test_grid_constructor_1(){
		
	}
	void test_grid_constructor_2(){
		
	}
	void test_grid_constructor_3(){
		
	}
	
	void test_grid_move_1(){
		
	}
	void test_grid_move_2(){
		
	}
	void test_grid_move_3(){
		
	}
	
	void test_grid_infection_1(){
		
	}
	void test_grid_infection_2(){
		
	}
	void test_grid_infection_3(){
		
	}
	
	void test_grid_iswall_1(){
		
	}
	void test_grid_iswall_2(){
		
	}
	void test_grid_iswall_3(){
		
	}
	
	void test_grid_isenemy_1(){
		
	}
	void test_grid_isenemy_2(){
		
	}
	void test_grid_isenemy_3(){
		
	}
	
	void test_grid_isempty_1(){
		
	}
	void test_grid_isempty_2(){
		
	}
	void test_grid_isempty_3(){
		
	}
	
	void test_grid_newcoordinate_1(){
		
	}
	void test_grid_newcoordinate_2(){
		
	}
	void test_grid_newcoordinate_3(){
		
	}
	
	void test_grid_place_1(){
		
	}
	void test_grid_place_2(){
		
	}
	void test_grid_place_3(){
		
	}
	
	void test_grid_simulate_1(){
		
	}
	void test_grid_simulate_2(){
		
	}
	void test_grid_simulate_3(){
		
	}
	
	void test_print_output_1(){
		
	}
	void test_print_output_2(){
		
	}
	void test_print_output_3(){
		
	}
	
	
	
	CPPUNIT_TEST_SUITE(TestDarwin);
	CPPUNIT_TEST(test_add_instruction_1);
	CPPUNIT_TEST(test_add_instruction_2);
	CPPUNIT_TEST(test_add_instruction_3);
	CPPUNIT_TEST(test_next_instruction_1);
	CPPUNIT_TEST(test_next_instruction_2);
	CPPUNIT_TEST(test_next_instruction_3);
	CPPUNIT_TEST(test_species_abbreviation_1);
	CPPUNIT_TEST(test_species_abbreviation_2);
	CPPUNIT_TEST(test_species_abbreviation_3);
	CPPUNIT_TEST(test_creature_constructor_1);
	CPPUNIT_TEST(test_creature_constructor_2);
	CPPUNIT_TEST(test_creature_constructor_3);
	CPPUNIT_TEST(test_creature_run_1);
	CPPUNIT_TEST(test_creature_run_2);
	CPPUNIT_TEST(test_creature_run_3);
	CPPUNIT_TEST(test_creature_hop_1);
	CPPUNIT_TEST(test_creature_hop_2);
	CPPUNIT_TEST(test_creature_hop_3);
	CPPUNIT_TEST(test_creature_left_1);
	CPPUNIT_TEST(test_creature_left_2);
	CPPUNIT_TEST(test_creature_left_3);
	CPPUNIT_TEST(test_creature_right_1);
	CPPUNIT_TEST(test_creature_right_2);
	CPPUNIT_TEST(test_creature_right_3);
	CPPUNIT_TEST(test_creature_infect_1);
	CPPUNIT_TEST(test_creature_infect_2);
	CPPUNIT_TEST(test_creature_infect_3);
	CPPUNIT_TEST(test_creature_left_1);
	CPPUNIT_TEST(test_creature_left_2);
	CPPUNIT_TEST(test_creature_left_3);
	CPPUNIT_TEST(test_creature_ifempty_1);
	CPPUNIT_TEST(test_creature_ifempty_2);
	CPPUNIT_TEST(test_creature_ifempty_3);
	CPPUNIT_TEST(test_creature_ifwall_1);
	CPPUNIT_TEST(test_creature_ifwall_2);
	CPPUNIT_TEST(test_creature_ifwall_3);
	CPPUNIT_TEST(test_creature_ifrandom_1);
	CPPUNIT_TEST(test_creature_ifrandom_2);
	CPPUNIT_TEST(test_creature_ifrandom_3);
	CPPUNIT_TEST(test_creature_ifenemy_1);
	CPPUNIT_TEST(test_creature_ifenemy_2);
	CPPUNIT_TEST(test_creature_ifenemy_3);
	CPPUNIT_TEST(test_creature_go_1);
	CPPUNIT_TEST(test_creature_go_2);
	CPPUNIT_TEST(test_creature_go_3);
	CPPUNIT_TEST(test_creature_reset_1);
	CPPUNIT_TEST(test_creature_reset_2);
	CPPUNIT_TEST(test_creature_reset_3);
	CPPUNIT_TEST(test_grid_constructor_1);
	CPPUNIT_TEST(test_grid_constructor_2);
	CPPUNIT_TEST(test_grid_constructor_3);
	CPPUNIT_TEST(test_grid_move_1);
	CPPUNIT_TEST(test_grid_move_2);
	CPPUNIT_TEST(test_grid_move_3);
	CPPUNIT_TEST(test_grid_infection_1);
	CPPUNIT_TEST(test_grid_infection_2);
	CPPUNIT_TEST(test_grid_infection_3);
	CPPUNIT_TEST(test_grid_iswall_1);
	CPPUNIT_TEST(test_grid_iswall_2);
	CPPUNIT_TEST(test_grid_iswall_3);
	CPPUNIT_TEST(test_grid_isenemy_1);
	CPPUNIT_TEST(test_grid_isenemy_2);
	CPPUNIT_TEST(test_grid_isenemy_3);
	CPPUNIT_TEST(test_grid_isempty_1);
	CPPUNIT_TEST(test_grid_isempty_2);
	CPPUNIT_TEST(test_grid_isempty_3);
	CPPUNIT_TEST(test_grid_newcoordinate_1);
	CPPUNIT_TEST(test_grid_newcoordinate_2);
	CPPUNIT_TEST(test_grid_newcoordinate_3);
	CPPUNIT_TEST(test_grid_place_1);
	CPPUNIT_TEST(test_grid_place_2);
	CPPUNIT_TEST(test_grid_place_3);
	CPPUNIT_TEST(test_grid_simulate_1);
	CPPUNIT_TEST(test_grid_simulate_2);
	CPPUNIT_TEST(test_grid_simulate_3);
	CPPUNIT_TEST(test_print_output_1);
	CPPUNIT_TEST(test_print_output_2);
	CPPUNIT_TEST(test_print_output_3);
	CPPUNIT_TEST_SUITE_END();
};


int main );
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestDarwin.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDarwin::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}