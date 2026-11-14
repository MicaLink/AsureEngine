#include <cstdio>

//-----------------------------------------------------
// Memory
//-----------------------------------------------------

void TestReadWrite8();
void TestReadWrite16();

//-----------------------------------------------------
// Stack
//-----------------------------------------------------

void TestPushPop8();
void TestPushPop16();

//-----------------------------------------------------
// Flags
//-----------------------------------------------------

void TestZeroFlag();
void TestNegativeFlag();
void TestCarryFlag();
void TestOverflowFlag();

//-----------------------------------------------------
// CPU
//-----------------------------------------------------

void TestReset();

//-----------------------------------------------------
// Instructions
//-----------------------------------------------------

void TestMOV();
void TestLOAD();
void TestSTORE();

void TestPUSH();
void TestPOP();
void TestCALL();
void TestRET();

void TestINC();
void TestDEC();
void TestADD();
void TestSUB();

void TestCMP();
void TestJMP();
void TestJZ();
void TestJNZ();

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    printf("========================================\n");
    printf("AzureEngine Test Suite\n");
    printf("========================================\n\n");

    //-------------------------------------------------
    // Memory
    //-------------------------------------------------

    printf("Running Memory Tests...\n");

    TestReadWrite8();
    TestReadWrite16();

    printf("Memory Tests Passed\n\n");

    //-------------------------------------------------
    // Stack
    //-------------------------------------------------

    printf("Running Stack Tests...\n");

    TestPushPop8();
    TestPushPop16();

    printf("Stack Tests Passed\n\n");

    //-------------------------------------------------
    // Flags
    //-------------------------------------------------

    printf("Running Flags Tests...\n");

    TestZeroFlag();
    TestNegativeFlag();
    TestCarryFlag();
    TestOverflowFlag();

    printf("Flags Tests Passed\n\n");

    //-------------------------------------------------
    // Instructions
    //-------------------------------------------------

    printf("Running Instruction Tests...\n");

    TestMOV();
    TestLOAD();
    TestSTORE();

    TestPUSH();
    TestPOP();
    TestCALL();
    TestRET();

    TestINC();
    TestDEC();
    TestADD();
    TestSUB();

    TestCMP();
    TestJMP();
    TestJZ();
    TestJNZ();

    printf("Instruction Tests Passed\n\n");

    //-------------------------------------------------
    // CPU
    //-------------------------------------------------
    
    printf("Running CPU Tests...\n");

    TestReset();

    printf("CPU Tests Passed\n\n");

    //-------------------------------------------------
    // Success
    //-------------------------------------------------

    printf("========================================\n");
    printf("All tests passed successfully.\n");
    printf("========================================\n");

    return 0;
}