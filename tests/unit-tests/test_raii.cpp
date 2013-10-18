/*
 * Copyright © 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alan Griffiths <alan@octopull.co.uk>
 */

#include "mir/raii.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace
{
struct RaiiTest : public ::testing::Test
{
    RaiiTest();
    MOCK_METHOD0(create_void, void());
    MOCK_METHOD0(destroy_void, void());

    MOCK_METHOD0(create_ptr, RaiiTest*());
    MOCK_METHOD1(destroy_ptr, void (RaiiTest*));

    MOCK_METHOD0(test_call, void());
};

RaiiTest* self = nullptr;

RaiiTest::RaiiTest() { self = this; }
void create_void()   { return self->create_void(); }
void destroy_void()  { self->destroy_void(); }
RaiiTest* create_ptr()          { return self->create_ptr(); }
void destroy_ptr(RaiiTest* p)   { self->destroy_ptr(p); }

}

using namespace testing;

TEST_F(RaiiTest, free_create_free_destroy_ptr)
{
    InSequence seq;
    EXPECT_CALL(*this, create_ptr()).Times(1).WillRepeatedly(Return(this));
    EXPECT_CALL(*this, test_call()).Times(1);
    EXPECT_CALL(*this, destroy_ptr(this)).Times(1);

    auto const raii = mir::raii::paired_calls(
        ::create_ptr,
        ::destroy_ptr);

    raii->test_call();

    EXPECT_EQ(this, raii.get());
}

TEST_F(RaiiTest, lambda_create_free_destroy_ptr)
{
    InSequence seq;
    EXPECT_CALL(*this, create_ptr()).Times(1).WillRepeatedly(Return(this));
    EXPECT_CALL(*this, test_call()).Times(1);
    EXPECT_CALL(*this, destroy_ptr(this)).Times(1);

    auto const raii = mir::raii::paired_calls(
        [this] { return create_ptr(); },
        ::destroy_ptr);

    raii->test_call();

    EXPECT_EQ(this, raii.get());
}

TEST_F(RaiiTest, free_create_lambda_destroy_ptr)
{
    InSequence seq;
    EXPECT_CALL(*this, create_ptr()).Times(1).WillRepeatedly(Return(this));
    EXPECT_CALL(*this, test_call()).Times(1);
    EXPECT_CALL(*this, destroy_ptr(this)).Times(1);

    auto const raii = mir::raii::paired_calls(
        ::create_ptr,
        [this] (RaiiTest*p){ ::destroy_ptr(p); });

    raii->test_call();

    EXPECT_EQ(this, raii.get());
}

TEST_F(RaiiTest, lambda_create_lambda_destroy_ptr)
{
    InSequence seq;
    EXPECT_CALL(*this, create_ptr()).Times(1).WillRepeatedly(Return(this));
    EXPECT_CALL(*this, test_call()).Times(1);
    EXPECT_CALL(*this, destroy_ptr(this)).Times(1);

    auto const raii = mir::raii::paired_calls(
        [this] { return create_ptr(); },
        [this] (RaiiTest*p){ destroy_ptr(p); });

    raii->test_call();

    EXPECT_EQ(this, raii.get());
}

TEST_F(RaiiTest, free_create_free_destroy_void)
{
    InSequence seq;
    EXPECT_CALL(*this, create_void()).Times(1);

    auto const raii = mir::raii::paired_calls(
        ::create_void,
        ::destroy_void);

    Mock::VerifyAndClearExpectations(this);
    EXPECT_CALL(*this, destroy_void()).Times(1);
}

TEST_F(RaiiTest, lambda_create_free_destroy_void)
{
    InSequence seq;
    EXPECT_CALL(*this, create_void()).Times(1);
    EXPECT_CALL(*this, destroy_void()).Times(1);

    auto const raii = mir::raii::paired_calls(
        [this] { return create_void(); },
        ::destroy_void);
}

TEST_F(RaiiTest, free_create_lambda_destroy_void)
{
    InSequence seq;
    EXPECT_CALL(*this, create_void()).Times(1);
    EXPECT_CALL(*this, destroy_void()).Times(1);

    auto const raii = mir::raii::paired_calls(
        ::create_void,
        [this] (){ destroy_void(); });
}

TEST_F(RaiiTest, lambda_create_lambda_destroy_void)
{
    InSequence seq;
    EXPECT_CALL(*this, create_void()).Times(1);
    EXPECT_CALL(*this, destroy_void()).Times(1);

    auto const raii = mir::raii::paired_calls(
        [this] { return create_void(); },
        [this] (){ destroy_void(); });
}

TEST_F(RaiiTest, deleter_for_free_destroy_ptr)
{
    EXPECT_CALL(*this, destroy_ptr(this)).Times(1);

    auto const raii = mir::raii::deleter_for(
        static_cast<RaiiTest*>(this),
        ::destroy_ptr);

    EXPECT_EQ(this, raii.get());
}

TEST_F(RaiiTest, deleter_for_lambda_destroy_ptr)
{
    EXPECT_CALL(*this, destroy_ptr(this)).Times(1);

    auto const raii = mir::raii::deleter_for(
        static_cast<RaiiTest*>(this),
        [this] (RaiiTest*p){ destroy_ptr(p); });

    EXPECT_EQ(this, raii.get());
}
