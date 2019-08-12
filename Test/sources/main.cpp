#include <qtest.h>

#include <testeclipsefilereader.h>
#include <testutils.h>

int main(int argc, char** argv)
{
    int status = 0;

    QTEST_SET_MAIN_SOURCE_PATH

    {
        // TESTLIB_SELFCOVERAGE_START(TestUtils)

        TestUtils tc;

        status |= QTest::qExec(&tc, argc, argv);
    }

    {
        // TESTLIB_SELFCOVERAGE_START(TestEclipseFileReader)

        TestEclipseFileReader tc;

        status |= QTest::qExec(&tc, argc, argv);
    }

    return status;
}
