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

public class ZhttpRequest implements AutoCloseable {
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
    Create a new http request.
    */
    native static long __new ();
    public ZhttpRequest () {
        /*  TODO: if __new fails, self is null...            */
        self = __new ();
    }
    public ZhttpRequest (long pointer) {
        self = pointer;
    }
    /*
    Destroy an http request.
    */
    native static void __destroy (long self);
    @Override
    public void close () {
        __destroy (self);
        self = 0;
    }
    /*
    Receive a new request from zhttp_server.
    Return the underlying connection if successful, to be used when calling zhttp_response_send.
    */
    native static long __recv (long self, long sock);
    public long recv (Zsock sock) {
        return __recv (self, sock.self);
    }
    /*
    Send a request to zhttp_client.
    Url and the request path will be concatenated.
    This behavior is useful for url rewrite and reverse proxy.

    Send also allow two user provided arguments which will be returned with the response.
    The reason for two, is to be able to pass around the server connection when forwarding requests or both a callback function and an arg.
    */
    native static int __send (long self, long client, int timeout, long arg, long arg2);
    public int send (ZhttpClient client, int timeout, long arg, long arg2) {
        return __send (self, client.self, timeout, arg, arg2);
    }
    /*
    Get the request method
    */
    native static String __method (long self);
    public String method () {
        return __method (self);
    }
    /*
    Set the request method
    */
    native static void __setMethod (long self, String method);
    public void setMethod (String method) {
        __setMethod (self, method);
    }
    /*
    Get the request url.
    When receiving a request from http server this is only the path part of the url.
    */
    native static String __url (long self);
    public String url () {
        return __url (self);
    }
    /*
    Set the request url
    When sending a request to http client this should be full url.
    */
    native static void __setUrl (long self, String url);
    public void setUrl (String url) {
        __setUrl (self, url);
    }
    /*
    Get the request content type
    */
    native static String __contentType (long self);
    public String contentType () {
        return __contentType (self);
    }
    /*
    Set the request content type
    */
    native static void __setContentType (long self, String contentType);
    public void setContentType (String contentType) {
        __setContentType (self, contentType);
    }
    /*
    Get the content length of the request
    */
    native static long __contentLength (long self);
    public long contentLength () {
        return __contentLength (self);
    }
    /*
    Get the headers of the request
    */
    native static long __headers (long self);
    public Zhash headers () {
        return new Zhash (__headers (self));
    }
    /*
    Get the content of the request.
    */
    native static String __content (long self);
    public String content () {
        return __content (self);
    }
    /*
    Get the content of the request.
    */
    native static String __getContent (long self);
    public String getContent () {
        return __getContent (self);
    }
    /*
    Set the content of the request..
    The content is assumed to be constant-memory and will therefore not be copied or deallocated in any way.
    */
    native static void __setContentConst (long self, String content);
    public void setContentConst (String content) {
        __setContentConst (self, content);
    }
    /*
    Set the content to NULL
    */
    native static void __resetContent (long self);
    public void resetContent () {
        __resetContent (self);
    }
    /*
    Match the path of the request.
    Support wildcards with '%s' symbol inside the match string.
    Matching wildcards until the next '/', '?' or '\0'.
    On successful match the variadic arguments will be filled with the matching strings.
    On successful match the method is modifying the url field and break it into substrings.
    If you need to use the url, do it before matching or take a copy.

    User must not free the variadic arguments as they are part of the url.

    To use the percent symbol, just double it, e.g "%%something".

    Example:
    if (zhttp_request_match (request, "POST", "/send/%s/%s", &name, &id))
    */
    native static boolean __match (long self, String method, String path);
    public boolean match (String method, String path []) {
        return __match (self, method, path [0]);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}
