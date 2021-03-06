#include <gmock/gmock.h>
#include "Soundex.h"
using namespace testing;
// Create a class fixture
class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    // Arrange @ class fixture
   // Act & Assert
   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
    // Note: Require does not fail the test, assert does.
    // Best practice states to only use EXPECT_ when
    // developing the code, not in production.
//     EXPECT_THAT(soundex.encode("Ap"), Eq("A100"));
//    EXPECT_THAT(soundex.encode("Ax"), Eq("A200"));
//    EXPECT_THAT(soundex.encode("Ar"), Eq("A600"));
    ASSERT_THAT(soundex.encode("Ap"), Eq("A100"));
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
    ASSERT_THAT(soundex.encode("Ar"), Eq("A600"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, CombineDuplicateEncodings)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("Abfxgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UpperCaseFirstLetter)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, EmptyReturnsEmpty)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode(""), Eq(""));
}

TEST_F(SoundexEncoding, IgnoreCaseWhenEncodingConsonants)
{
    // Arrange @ class fixture
    // Act & Assert
    ASSERT_THAT(soundex.encode("BCDL"), soundex.encode("bcdl"));
}
