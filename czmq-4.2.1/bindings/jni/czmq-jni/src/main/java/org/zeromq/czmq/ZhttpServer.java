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

public class ZhttpServer implements AutoCloseable {
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
    Create a new http server
    */
    native static long __new (long options);
    public ZhttpServer (ZhttpServerOptions options) {
        /*  TODO: if __new fails, self is null...            */
        self = __new (options.self);
    }
    public ZhttpServer (long pointer) {
        self = pointer;
    }
    /*
    Destroy an http server
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }
    /*
    Return the port the server is listening on.
    */
    native static int __port (long self);
    public int port () {
        return __port (self);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}
