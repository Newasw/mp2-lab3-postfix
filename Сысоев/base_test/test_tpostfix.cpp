#include "postfix.h"
#include <gtest.h>
#include"postfix.cpp"

TEST(TPostfix, can_create_postfix)
{
    ASSERT_NO_THROW(TPostfix p);
}
TEST(TPostfix, to_inverse_polish_correctly) {
    string p = "5*6+(2-9)";
    TPostfix a(p);
    string h = "5,6,*,2,9,-,+";
    ASSERT_EQ(a.ToPostfix(), h);
}
TEST(TPostfix, can_calculate_correctly) {
    string p = "5*6+(2-9)";
    TPostfix a(p);
    a.ToPostfix();
    double h = 23;
    cout << a.Calculate() << endl;
    ASSERT_EQ(a.Calculate(), h);
 }

TEST(TPostfix, calculate_throw_unknown_symbol) {
    TPostfix a("3+a");
    ASSERT_ANY_THROW(a.Calculate());
}
TEST(TPostfix, postfix_throw_unknown_symbol) {
    TPostfix a("3+a");
    ASSERT_ANY_THROW(a.ToPostfix());
}
TEST(TPostfix, postfix_throw_double) {
    TPostfix a("3++2");
    ASSERT_ANY_THROW(a.ToPostfix());
}

TEST(TPostfix, cannot_divide_by_zero) {
    TPostfix a("3+6/(3-3)");
    ASSERT_ANY_THROW(a.Calculate());
}

TEST(TPostfix, applying_inverse_to_itself_gives_id) {
    TPostfix a("1/(1/2)");
    a.ToPostfix();
    ASSERT_EQ(a.Calculate(), 2.0);
}
TEST(TPostfix, applying_negative_to_itself_gives_id) {
    TPostfix a("0-(0-2)");
    a.ToPostfix();
    ASSERT_EQ(a.Calculate(), 2.0);
}

