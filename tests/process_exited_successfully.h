/*
 * Copyright © 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voß <thomas.voss@canonical.com>
 */

#include <core/posix/wait.h>

#include <gtest/gtest.h>

::testing::AssertionResult ProcessExitedSuccessfully(const core::posix::wait::Result& result)
{
    if (core::posix::wait::Result::Status::exited != result.status)
        return ::testing::AssertionFailure();

    if (core::posix::exit::Status::success != result.detail.if_exited.status)
        return ::testing::AssertionFailure();

    return ::testing::AssertionSuccess();
}
