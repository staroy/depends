/*
    Copyright 2013 Christian Henning
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#include <boost/test/unit_test.hpp>

#include <boost/gil.hpp>
#include <boost/gil/extension/toolbox/metafunctions/pixel_bit_size.hpp>

using namespace boost;
using namespace gil;

BOOST_AUTO_TEST_SUITE( toolbox_tests )

BOOST_AUTO_TEST_CASE( pixel_bit_size_test )
{
    typedef bit_aligned_image5_type< 16, 16, 16, 8, 8, devicen_layout_t< 5 > >::type image_t;
    BOOST_STATIC_ASSERT(( pixel_bit_size<image_t::view_t::reference>::value == 64 ));
}

BOOST_AUTO_TEST_SUITE_END()
