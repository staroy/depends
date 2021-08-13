/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
package org.zeromq.czmq;

import org.zeromq.tools.ZmqNativeLoader;

import java.util.LinkedHashMap;
import java.util.Map;

public class Ztimerset implements AutoCloseable {
    static {
        Map<String, Boolean> libraries = new LinkedHashMap<>();
        libraries.put("zmq", false);
        libraries.put("uuid", true);
        libraries.put("libsystemd", true);
        libraries.put("lz4", true);
        libraries.put("curl", true);
        libraries.put("nss", true);
        libraries.put("microhttpd", true);
        libraries.put("czmq", false);
        libraries.put("czmqjni", false);
        ZmqNativeLoader.loadLibraries(libraries);
    }
    public long self;
    /*
    Create new timer set.
    */
    native static long __new ();
    public Ztimerset () {
        /*  TODO: if __new fails, self is null...            */
        self = __new ();
    }
    public Ztimerset (long pointer) {
        self = pointer;
    }
    /*
    Destroy a timer set
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }
    /*
    Cancel a timer. Returns 0 if OK, -1 on failure.
    */
    native static int __cancel (long self, int timerId);
    public int cancel (int timerId) {
        return __cancel (self, timerId);
    }
    /*
    Set timer interval. Returns 0 if OK, -1 on failure.
    This method is slow, canceling the timer and adding a new one yield better performance.
    */
    native static int __setInterval (long self, int timerId, long interval);
    public int setInterval (int timerId, long interval) {
        return __setInterval (self, timerId, interval);
    }
    /*
    Reset timer to start interval counting from current time. Returns 0 if OK, -1 on failure.
    This method is slow, canceling the timer and adding a new one yield better performance.
    */
    native static int __reset (long self, int timerId);
    public int reset (int timerId) {
        return __reset (self, timerId);
    }
    /*
    Return the time until the next interval.
    Should be used as timeout parameter for the zpoller wait method.
    The timeout is in msec.
    */
    native static int __timeout (long self);
    public int timeout () {
        return __timeout (self);
    }
    /*
    Invoke callback function of all timers which their interval has elapsed.
    Should be call after zpoller wait method.
    Returns 0 if OK, -1 on failure.
    */
    native static int __execute (long self);
    public int execute () {
        return __execute (self);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}
