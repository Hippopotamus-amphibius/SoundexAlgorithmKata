#include <gmock/gmock.h>
#include "Soundex.h"
using ::testing::Eq;

// Create a test fixture
class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    // Arrange
   // Act
   auto result = soundex.encode("A");
   // Assert
   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    // Arrange
    // Act
    auto result = soundex.encode("I");
    // Assert
    ASSERT_THAT(result, Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
    // Arrange
    // Act
    auto result = soundex.encode("Ab");
    // Assert
    ASSERT_THAT(result, Eq("A100"));
}

