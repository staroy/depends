// Copyright (C) 2011 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <boost/thread/strict_lock.hpp>

// template <class Lockable>
// strict_lock<Lockable> make_strict_lock(Lockable &);

#define BOOST_THREAD_VERSION 4

#include <boost/thread/strict_lock.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include <boost/detail/lightweight_test.hpp>
#include "../../../../timming.hpp"

#ifdef BOOST_THREAD_USES_CHRONO
typedef boost::chrono::high_resolution_clock Clock;
typedef Clock::time_point time_point;
typedef Clock::duration duration;
typedef boost::chrono::milliseconds ms;
typedef boost::chrono::nanoseconds ns;
#endif

boost::mutex m;

#if ! defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && ! defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && ! defined BOOST_THREAD_NO_MAKE_STRICT_LOCK && defined BOOST_THREAD_USES_CHRONO

const ms max_diff(BOOST_THREAD_TEST_TIME_MS);

void f()
{
  time_point t0 = Clock::now();
  time_point t1;
  {
    const auto&& lg = boost::make_strict_lock(m); (void)lg;
    t1 = Clock::now();
  }
  ns d = t1 - t0 - ms(250);
  BOOST_THREAD_TEST_IT(d, ns(max_diff));
}
#endif

int main()
{

#if ! defined(BOOST_NO_CXX11_AUTO_DECLARATIONS) && ! defined(BOOST_NO_CXX11_RVALUE_REFERENCES) && ! defined BOOST_THREAD_NO_MAKE_STRICT_LOCK
  {
    m.lock();
    boost::thread t(f);
    boost::this_thread::sleep_for(ms(250));
    m.unlock();
    t.join();
  }
#endif
  return boost::report_errors();
}
