/*  =========================================================================
    zyre_private_selftest.c - run private classes selftests

    Runs all private classes selftests.

    -------------------------------------------------------------------------
    Copyright (c) the Contributors as noted in the AUTHORS file.

    This file is part of Zyre, an open-source framework for proximity-based
    peer-to-peer applications -- See http://zyre.org.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#include "zyre_classes.h"


//  -------------------------------------------------------------------------
//  Run all private classes tests.
//

void
zyre_private_selftest (bool verbose, const char *subtest)
{
// Tests for stable private classes:
    if (streq (subtest, "$ALL") || streq (subtest, "zre_msg_test"))
        zre_msg_test (verbose);
    if (streq (subtest, "$ALL") || streq (subtest, "zyre_peer_test"))
        zyre_peer_test (verbose);
    if (streq (subtest, "$ALL") || streq (subtest, "zyre_group_test"))
        zyre_group_test (verbose);
    if (streq (subtest, "$ALL") || streq (subtest, "zyre_election_test"))
        zyre_election_test (verbose);
    if (streq (subtest, "$ALL") || streq (subtest, "zyre_node_test"))
        zyre_node_test (verbose);
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
