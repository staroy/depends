/*
    Copyright 2013 Christian Henning
    Use, modification and distribution are subject to the Boost Software License,
    Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt).
*/

#ifndef BOOST_GIL_IO_UNIT_TEST_MANDEL_HPP
#define BOOST_GIL_IO_UNIT_TEST_MANDEL_HPP

#include <boost/gil.hpp>

using namespace std;
using namespace boost;
using namespace gil;

// Models a Unary Function
template <typename P>   // Models PixelValueConcept
struct mandelbrot_fn {
    typedef point2<std::ptrdiff_t>    point_t;

    typedef mandelbrot_fn        const_t;
    typedef P                    value_type;
    typedef value_type           reference;
    typedef value_type           const_reference;
    typedef point_t              argument_type;
    typedef reference            result_type;
    BOOST_STATIC_CONSTANT(bool, is_mutable=false);

    value_type                    _in_color,_out_color;
    point_t                       _img_size;
    static const int MAX_ITER=100;        // max number of iterations

    mandelbrot_fn() {}
    mandelbrot_fn(const point_t& sz, const value_type& in_color, const value_type& out_color) : _in_color(in_color), _out_color(out_color), _img_size(sz) {}

    std::ptrdiff_t width()  { return _img_size.x; }
    std::ptrdiff_t height() { return _img_size.y; }

    result_type operator()(const point_t& p) const {
        // normalize the coords to (-2..1, -1.5..1.5)
        // (actually make y -1.0..2 so it is asymmetric, so we can verify some view factory methods)
        double t=get_num_iter(point2<double>(p.x/(double)_img_size.x*3-2, p.y/(double)_img_size.y*3-1.0f));//1.5f));
        t=pow(t,0.2);

        value_type ret;
        for (int k=0; k<num_channels<P>::value; ++k)
            ret[k]=(typename channel_type<P>::type)(_in_color[k]*t + _out_color[k]*(1-t));
        return ret;
    }

private:
    double get_num_iter(const point2<double>& p) const {
        point2<double> Z(0,0);
        for (int i=0; i<MAX_ITER; ++i) {
            Z = point2<double>(Z.x*Z.x - Z.y*Z.y + p.x, 2*Z.x*Z.y + p.y);
            if (Z.x*Z.x + Z.y*Z.y > 4)
                return i/(double)MAX_ITER;
        }
        return 0;
    }
};

template< typename Pixel >
struct mandel_view
{
    typedef mandelbrot_fn< Pixel > deref_t;
    typedef virtual_2d_locator<deref_t,false> locator_t;
    typedef image_view<locator_t> my_virt_view_t;

    typedef my_virt_view_t type;
};

template< typename Pixel >
typename mandel_view< Pixel >::type create_mandel_view( unsigned int width
                                                      , unsigned int height
                                                      , const Pixel& in
                                                      , const Pixel& out
                                                      )
{
    typedef typename mandel_view< Pixel >::type      view_t;
    typedef typename mandel_view< Pixel >::deref_t   deref_t;
    typedef typename mandel_view< Pixel >::locator_t locator_t;

    point_t dims( width, height );
    return view_t( dims
                 , locator_t( point_t( 0, 0 )
                            , point_t( 1, 1 )
                            , deref_t( dims
                                     , in
                                     , out
                                     )
                            )
                 );
}

#endif // BOOST_GIL_IO_UNIT_TEST_MANDEL_HPP
