#include <cstdio>

// Memory
void TestReadWrite8();
void TestReadWrite16();

// Stack
void TestPushPop8();
void TestPushPop16();

// Flags
void TestZeroFlag();
void TestNegativeFlag();
void TestCarryFlag();
void TestOverflowFlag();

// CPU
void TestReset();

int main()
{
    printf("AzureEngine Tests\n\n");

    TestReadWrite8();
    TestReadWrite16();

    TestPushPop8();
    TestPushPop16();

    TestZeroFlag();
    TestNegativeFlag();
    TestCarryFlag();
    TestOverflowFlag();

    TestReset();

    printf("All tests passed successfully.\n");

    return 0;
}