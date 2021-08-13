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

public class Zsys {
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
    Initialize CZMQ zsys layer; this happens automatically when you create
    a socket or an actor; however this call lets you force initialization
    earlier, so e.g. logging is properly set-up before you start working.
    Not threadsafe, so call only from main thread. Safe to call multiple
    times. Returns global CZMQ context.
    */
    native static long __init ();
    public static long init () {
        return __init ();
    }
    /*
    Optionally shut down the CZMQ zsys layer; this normally happens automatically
    when the process exits; however this call lets you force a shutdown
    earlier, avoiding any potential problems with atexit() ordering, especially
    with Windows dlls.
    */
    native static void __shutdown ();
    public static void shutdown () {
        __shutdown ();
    }
    /*
    Get a new ZMQ socket, automagically creating a ZMQ context if this is
    the first time. Caller is responsible for destroying the ZMQ socket
    before process exits, to avoid a ZMQ deadlock. Note: you should not use
    this method in CZMQ apps, use zsock_new() instead.
    *** This is for CZMQ internal use only and may change arbitrarily ***
    */
    native static long __socket (int type, String filename, long lineNbr);
    public static long socket (int type, String filename, long lineNbr) {
        return __socket (type, filename, lineNbr);
    }
    /*
    Destroy/close a ZMQ socket. You should call this for every socket you
    create using zsys_socket().
    *** This is for CZMQ internal use only and may change arbitrarily ***
    */
    native static int __close (long handle, String filename, long lineNbr);
    public static int Close (long handle, String filename, long lineNbr) {
        return __close (handle, filename, lineNbr);
    }
    /*
    Return ZMQ socket name for socket type
    *** This is for CZMQ internal use only and may change arbitrarily ***
    */
    native static String __sockname (int socktype);
    public static String sockname (int socktype) {
        return __sockname (socktype);
    }
    /*
    Create a pipe, which consists of two PAIR sockets connected over inproc.
    The pipe is configured to use the zsys_pipehwm setting. Returns the
    frontend socket successful, NULL if failed.
    */
    native static long __createPipe (long backendP);
    public static Zsock createPipe (Zsock backendP) {
        return new Zsock (__createPipe (backendP.self));
    }
    /*
    Reset interrupt handler, call this at exit if needed
    */
    native static void __handlerReset ();
    public static void handlerReset () {
        __handlerReset ();
    }
    /*
    Set default interrupt handler, so Ctrl-C or SIGTERM will set
    zsys_interrupted. Idempotent; safe to call multiple times.
    Can be suppressed by ZSYS_SIGHANDLER=false
    *** This is for CZMQ internal use only and may change arbitrarily ***
    */
    native static void __catchInterrupts ();
    public static void catchInterrupts () {
        __catchInterrupts ();
    }
    /*
    Check if default interrupt handler of Ctrl-C or SIGTERM was called.
    Does not work if ZSYS_SIGHANDLER is false and code does not call
    set interrupted on signal.
    */
    native static boolean __isInterrupted ();
    public static boolean isInterrupted () {
        return __isInterrupted ();
    }
    /*
    Set interrupted flag. This is done by default signal handler, however
    this can be handy for language bindings or cases without default
    signal handler.
    */
    native static void __setInterrupted ();
    public static void setInterrupted () {
        __setInterrupted ();
    }
    /*
    Return 1 if file exists, else zero
    */
    native static boolean __fileExists (String filename);
    public static boolean fileExists (String filename) {
        return __fileExists (filename);
    }
    /*
    Return file modification time. Returns 0 if the file does not exist.
    */
    native static long __fileModified (String filename);
    public static long fileModified (String filename) {
        return __fileModified (filename);
    }
    /*
    Return file mode; provides at least support for the POSIX S_ISREG(m)
    and S_ISDIR(m) macros and the S_IRUSR and S_IWUSR bits, on all boxes.
    Returns a mode_t cast to int, or -1 in case of error.
    */
    native static int __fileMode (String filename);
    public static int fileMode (String filename) {
        return __fileMode (filename);
    }
    /*
    Delete file. Does not complain if the file is absent
    */
    native static int __fileDelete (String filename);
    public static int fileDelete (String filename) {
        return __fileDelete (filename);
    }
    /*
    Check if file is 'stable'
    */
    native static boolean __fileStable (String filename);
    public static boolean fileStable (String filename) {
        return __fileStable (filename);
    }
    /*
    Create a file path if it doesn't exist. The file path is treated as
    printf format.
    */
    native static int __dirCreate (String pathname);
    public static int dirCreate (String pathname []) {
        return __dirCreate (pathname [0]);
    }
    /*
    Remove a file path if empty; the pathname is treated as printf format.
    */
    native static int __dirDelete (String pathname);
    public static int dirDelete (String pathname []) {
        return __dirDelete (pathname [0]);
    }
    /*
    Move to a specified working directory. Returns 0 if OK, -1 if this failed.
    */
    native static int __dirChange (String pathname);
    public static int dirChange (String pathname) {
        return __dirChange (pathname);
    }
    /*
    Set private file creation mode; all files created from here will be
    readable/writable by the owner only.
    */
    native static void __fileModePrivate ();
    public static void fileModePrivate () {
        __fileModePrivate ();
    }
    /*
    Reset default file creation mode; all files created from here will use
    process file mode defaults.
    */
    native static void __fileModeDefault ();
    public static void fileModeDefault () {
        __fileModeDefault ();
    }
    /*
    Return the CZMQ version for run-time API detection; returns version
    number into provided fields, providing reference isn't null in each case.
    */
    native static void __version (int major, int minor, int patch);
    public static void version (int major, int minor, int patch) {
        __version (major, minor, patch);
    }
    /*
    Format a string using printf formatting, returning a freshly allocated
    buffer. If there was insufficient memory, returns NULL. Free the returned
    string using zstr_free(). The hinted version allows to optimize by using
    a larger starting buffer size (known to/assumed by the developer) and so
    avoid reallocations.
    */
    native static String __sprintfHint (int hint, String format);
    public static String sprintfHint (int hint, String format) {
        return __sprintfHint (hint, format);
    }
    /*
    Format a string using printf formatting, returning a freshly allocated
    buffer. If there was insufficient memory, returns NULL. Free the returned
    string using zstr_free().
    */
    native static String __sprintf (String format);
    public static String sprintf (String format) {
        return __sprintf (format);
    }
    /*
    Handle an I/O error on some socket operation; will report and die on
    fatal errors, and continue silently on "try again" errors.
    *** This is for CZMQ internal use only and may change arbitrarily ***
    */
    native static void __socketError (String reason);
    public static void socketError (String reason) {
        __socketError (reason);
    }
    /*
    Return current host name, for use in public tcp:// endpoints. Caller gets
    a freshly allocated string, should free it using zstr_free(). If the host
    name is not resolvable, returns NULL.
    */
    native static String __hostname ();
    public static String hostname () {
        return __hostname ();
    }
    /*
    Move the current process into the background. The precise effect depends
    on the operating system. On POSIX boxes, moves to a specified working
    directory (if specified), closes all file handles, reopens stdin, stdout,
    and stderr to the null device, and sets the process to ignore SIGHUP. On
    Windows, does nothing. Returns 0 if OK, -1 if there was an error.
    */
    native static int __daemonize (String workdir);
    public static int daemonize (String workdir) {
        return __daemonize (workdir);
    }
    /*
    Drop the process ID into the lockfile, with exclusive lock, and switch
    the process to the specified group and/or user. Any of the arguments
    may be null, indicating a no-op. Returns 0 on success, -1 on failure.
    Note if you combine this with zsys_daemonize, run after, not before
    that method, or the lockfile will hold the wrong process ID.
    */
    native static int __runAs (String lockfile, String group, String user);
    public static int runAs (String lockfile, String group, String user) {
        return __runAs (lockfile, group, user);
    }
    /*
    Returns true if the underlying libzmq supports CURVE security.
    Uses a heuristic probe according to the version of libzmq being used.
    */
    native static boolean __hasCurve ();
    public static boolean hasCurve () {
        return __hasCurve ();
    }
    /*
    Configure the number of I/O threads that ZeroMQ will use. A good
    rule of thumb is one thread per gigabit of traffic in or out. The
    default is 1, sufficient for most applications. If the environment
    variable ZSYS_IO_THREADS is defined, that provides the default.
    Note that this method is valid only before any socket is created.
    */
    native static void __setIoThreads (long ioThreads);
    public static void setIoThreads (long ioThreads) {
        __setIoThreads (ioThreads);
    }
    /*
    Configure the scheduling policy of the ZMQ context thread pool.
    Not available on Windows. See the sched_setscheduler man page or sched.h
    for more information. If the environment variable ZSYS_THREAD_SCHED_POLICY
    is defined, that provides the default.
    Note that this method is valid only before any socket is created.
    */
    native static void __setThreadSchedPolicy (int policy);
    public static void setThreadSchedPolicy (int policy) {
        __setThreadSchedPolicy (policy);
    }
    /*
    Configure the scheduling priority of the ZMQ context thread pool.
    Not available on Windows. See the sched_setscheduler man page or sched.h
    for more information. If the environment variable ZSYS_THREAD_PRIORITY is
    defined, that provides the default.
    Note that this method is valid only before any socket is created.
    */
    native static void __setThreadPriority (int priority);
    public static void setThreadPriority (int priority) {
        __setThreadPriority (priority);
    }
    /*
    Configure the numeric prefix to each thread created for the internal
    context's thread pool. This option is only supported on Linux.
    If the environment variable ZSYS_THREAD_NAME_PREFIX is defined, that
    provides the default.
    Note that this method is valid only before any socket is created.
    */
    native static void __setThreadNamePrefix (int prefix);
    public static void setThreadNamePrefix (int prefix) {
        __setThreadNamePrefix (prefix);
    }
    /*
    Return thread name prefix.
    */
    native static int __threadNamePrefix ();
    public static int threadNamePrefix () {
        return __threadNamePrefix ();
    }
    /*
    Configure the numeric prefix to each thread created for the internal
    context's thread pool. This option is only supported on Linux.
    If the environment variable ZSYS_THREAD_NAME_PREFIX_STR is defined, that
    provides the default.
    Note that this method is valid only before any socket is created.
    */
    native static void __setThreadNamePrefixStr (String prefix);
    public static void setThreadNamePrefixStr (String prefix) {
        __setThreadNamePrefixStr (prefix);
    }
    /*
    Return thread name prefix.
    */
    native static String __threadNamePrefixStr ();
    public static String threadNamePrefixStr () {
        return __threadNamePrefixStr ();
    }
    /*
    Adds a specific CPU to the affinity list of the ZMQ context thread pool.
    This option is only supported on Linux.
    Note that this method is valid only before any socket is created.
    */
    native static void __threadAffinityCpuAdd (int cpu);
    public static void threadAffinityCpuAdd (int cpu) {
        __threadAffinityCpuAdd (cpu);
    }
    /*
    Removes a specific CPU to the affinity list of the ZMQ context thread pool.
    This option is only supported on Linux.
    Note that this method is valid only before any socket is created.
    */
    native static void __threadAffinityCpuRemove (int cpu);
    public static void threadAffinityCpuRemove (int cpu) {
        __threadAffinityCpuRemove (cpu);
    }
    /*
    Configure the number of sockets that ZeroMQ will allow. The default
    is 1024. The actual limit depends on the system, and you can query it
    by using zsys_socket_limit (). A value of zero means "maximum".
    Note that this method is valid only before any socket is created.
    */
    native static void __setMaxSockets (long maxSockets);
    public static void setMaxSockets (long maxSockets) {
        __setMaxSockets (maxSockets);
    }
    /*
    Return maximum number of ZeroMQ sockets that the system will support.
    */
    native static long __socketLimit ();
    public static long socketLimit () {
        return __socketLimit ();
    }
    /*
    Configure the maximum allowed size of a message sent.
    The default is INT_MAX.
    */
    native static void __setMaxMsgsz (int maxMsgsz);
    public static void setMaxMsgsz (int maxMsgsz) {
        __setMaxMsgsz (maxMsgsz);
    }
    /*
    Return maximum message size.
    */
    native static int __maxMsgsz ();
    public static int maxMsgsz () {
        return __maxMsgsz ();
    }
    /*
    Configure whether to use zero copy strategy in libzmq. If the environment
    variable ZSYS_ZERO_COPY_RECV is defined, that provides the default.
    Otherwise the default is 1.
    */
    native static void __setZeroCopyRecv (int zeroCopy);
    public static void setZeroCopyRecv (int zeroCopy) {
        __setZeroCopyRecv (zeroCopy);
    }
    /*
    Return ZMQ_ZERO_COPY_RECV option.
    */
    native static int __zeroCopyRecv ();
    public static int zeroCopyRecv () {
        return __zeroCopyRecv ();
    }
    /*
    Configure the threshold value of filesystem object age per st_mtime
    that should elapse until we consider that object "stable" at the
    current zclock_time() moment.
    The default is S_DEFAULT_ZSYS_FILE_STABLE_AGE_MSEC defined in zsys.c
    which generally depends on host OS, with fallback value of 5000.
    */
    native static void __setFileStableAgeMsec (long fileStableAgeMsec);
    public static void setFileStableAgeMsec (long fileStableAgeMsec) {
        __setFileStableAgeMsec (fileStableAgeMsec);
    }
    /*
    Return current threshold value of file stable age in msec.
    This can be used in code that chooses to wait for this timeout
    before testing if a filesystem object is "stable" or not.
    */
    native static long __fileStableAgeMsec ();
    public static long fileStableAgeMsec () {
        return __fileStableAgeMsec ();
    }
    /*
    Configure the default linger timeout in msecs for new zsock instances.
    You can also set this separately on each zsock_t instance. The default
    linger time is zero, i.e. any pending messages will be dropped. If the
    environment variable ZSYS_LINGER is defined, that provides the default.
    Note that process exit will typically be delayed by the linger time.
    */
    native static void __setLinger (long linger);
    public static void setLinger (long linger) {
        __setLinger (linger);
    }
    /*
    Configure the default outgoing pipe limit (HWM) for new zsock instances.
    You can also set this separately on each zsock_t instance. The default
    HWM is 1,000, on all versions of ZeroMQ. If the environment variable
    ZSYS_SNDHWM is defined, that provides the default. Note that a value of
    zero means no limit, i.e. infinite memory consumption.
    */
    native static void __setSndhwm (long sndhwm);
    public static void setSndhwm (long sndhwm) {
        __setSndhwm (sndhwm);
    }
    /*
    Configure the default incoming pipe limit (HWM) for new zsock instances.
    You can also set this separately on each zsock_t instance. The default
    HWM is 1,000, on all versions of ZeroMQ. If the environment variable
    ZSYS_RCVHWM is defined, that provides the default. Note that a value of
    zero means no limit, i.e. infinite memory consumption.
    */
    native static void __setRcvhwm (long rcvhwm);
    public static void setRcvhwm (long rcvhwm) {
        __setRcvhwm (rcvhwm);
    }
    /*
    Configure the default HWM for zactor internal pipes; this is set on both
    ends of the pipe, for outgoing messages only (sndhwm). The default HWM is
    1,000, on all versions of ZeroMQ. If the environment var ZSYS_ACTORHWM is
    defined, that provides the default. Note that a value of zero means no
    limit, i.e. infinite memory consumption.
    */
    native static void __setPipehwm (long pipehwm);
    public static void setPipehwm (long pipehwm) {
        __setPipehwm (pipehwm);
    }
    /*
    Return the HWM for zactor internal pipes.
    */
    native static long __pipehwm ();
    public static long pipehwm () {
        return __pipehwm ();
    }
    /*
    Configure use of IPv6 for new zsock instances. By default sockets accept
    and make only IPv4 connections. When you enable IPv6, sockets will accept
    and connect to both IPv4 and IPv6 peers. You can override the setting on
    each zsock_t instance. The default is IPv4 only (ipv6 set to 0). If the
    environment variable ZSYS_IPV6 is defined (as 1 or 0), this provides the
    default. Note: has no effect on ZMQ v2.
    */
    native static void __setIpv6 (int ipv6);
    public static void setIpv6 (int ipv6) {
        __setIpv6 (ipv6);
    }
    /*
    Return use of IPv6 for zsock instances.
    */
    native static int __ipv6 ();
    public static int ipv6 () {
        return __ipv6 ();
    }
    /*
    Test if ipv6 is available on the system. Return true if available.
    The only way to reliably check is to actually open a socket and
    try to bind it. (ported from libzmq)
    */
    native static boolean __ipv6Available ();
    public static boolean ipv6Available () {
        return __ipv6Available ();
    }
    /*
    Set network interface name to use for broadcasts, particularly zbeacon.
    This lets the interface be configured for test environments where required.
    For example, on Mac OS X, zbeacon cannot bind to 255.255.255.255 which is
    the default when there is no specified interface. If the environment
    variable ZSYS_INTERFACE is set, use that as the default interface name.
    Setting the interface to "*" means "use all available interfaces".
    */
    native static void __setInterface (String value);
    public static void setInterface (String value) {
        __setInterface (value);
    }
    /*
    Return network interface to use for broadcasts, or "" if none was set.
    */
    native static String __interface ();
    public static String Interface () {
        return __interface ();
    }
    /*
    Set IPv6 address to use zbeacon socket, particularly for receiving zbeacon.
    This needs to be set IPv6 is enabled as IPv6 can have multiple addresses
    on a given interface. If the environment variable ZSYS_IPV6_ADDRESS is set,
    use that as the default IPv6 address.
    */
    native static void __setIpv6Address (String value);
    public static void setIpv6Address (String value) {
        __setIpv6Address (value);
    }
    /*
    Return IPv6 address to use for zbeacon reception, or "" if none was set.
    */
    native static String __ipv6Address ();
    public static String ipv6Address () {
        return __ipv6Address ();
    }
    /*
    Set IPv6 milticast address to use for sending zbeacon messages. This needs
    to be set if IPv6 is enabled. If the environment variable
    ZSYS_IPV6_MCAST_ADDRESS is set, use that as the default IPv6 multicast
    address.
    */
    native static void __setIpv6McastAddress (String value);
    public static void setIpv6McastAddress (String value) {
        __setIpv6McastAddress (value);
    }
    /*
    Return IPv6 multicast address to use for sending zbeacon, or "" if none was
    set.
    */
    native static String __ipv6McastAddress ();
    public static String ipv6McastAddress () {
        return __ipv6McastAddress ();
    }
    /*
    Set IPv4 multicast address to use for sending zbeacon messages. By default
    IPv4 multicast is NOT used. If the environment variable
    ZSYS_IPV4_MCAST_ADDRESS is set, use that as the default IPv4 multicast
    address. Calling this function or setting ZSYS_IPV4_MCAST_ADDRESS
    will enable IPv4 zbeacon messages.
    */
    native static void __setIpv4McastAddress (String value);
    public static void setIpv4McastAddress (String value) {
        __setIpv4McastAddress (value);
    }
    /*
    Return IPv4 multicast address to use for sending zbeacon, or NULL if none was
    set.
    */
    native static String __ipv4McastAddress ();
    public static String ipv4McastAddress () {
        return __ipv4McastAddress ();
    }
    /*
    Set multicast TTL default is 1
    */
    native static void __setMcastTtl (byte value);
    public static void setMcastTtl (byte value) {
        __setMcastTtl (value);
    }
    /*
    Get multicast TTL
    */
    native static byte __mcastTtl ();
    public static byte mcastTtl () {
        return __mcastTtl ();
    }
    /*
    Configure the automatic use of pre-allocated FDs when creating new sockets.
    If 0 (default), nothing will happen. Else, when a new socket is bound, the
    system API will be used to check if an existing pre-allocated FD with a
    matching port (if TCP) or path (if IPC) exists, and if it does it will be
    set via the ZMQ_USE_FD socket option so that the library will use it
    instead of creating a new socket.
    */
    native static void __setAutoUseFd (int autoUseFd);
    public static void setAutoUseFd (int autoUseFd) {
        __setAutoUseFd (autoUseFd);
    }
    /*
    Return use of automatic pre-allocated FDs for zsock instances.
    */
    native static int __autoUseFd ();
    public static int autoUseFd () {
        return __autoUseFd ();
    }
    /*
    Print formatted string. Format is specified by variable names
    in Python-like format style

    "%(KEY)s=%(VALUE)s", KEY=key, VALUE=value
    become
    "key=value"

    Returns freshly allocated string or NULL in a case of error.
    Not enough memory, invalid format specifier, name not in args
    */
    native static String __zprintf (String format, long args);
    public static String zprintf (String format, Zhash args) {
        return __zprintf (format, args.self);
    }
    /*
    Return error string for given format/args combination.
    */
    native static String __zprintfError (String format, long args);
    public static String zprintfError (String format, Zhash args) {
        return __zprintfError (format, args.self);
    }
    /*
    Print formatted string. Format is specified by variable names
    in Python-like format style

    "%(KEY)s=%(VALUE)s", KEY=key, VALUE=value
    become
    "key=value"

    Returns freshly allocated string or NULL in a case of error.
    Not enough memory, invalid format specifier, name not in args
    */
    native static String __zplprintf (String format, long args);
    public static String zplprintf (String format, Zconfig args) {
        return __zplprintf (format, args.self);
    }
    /*
    Return error string for given format/args combination.
    */
    native static String __zplprintfError (String format, long args);
    public static String zplprintfError (String format, Zconfig args) {
        return __zplprintfError (format, args.self);
    }
    /*
    Set log identity, which is a string that prefixes all log messages sent
    by this process. The log identity defaults to the environment variable
    ZSYS_LOGIDENT, if that is set.
    */
    native static void __setLogident (String value);
    public static void setLogident (String value) {
        __setLogident (value);
    }
    /*
    Sends log output to a PUB socket bound to the specified endpoint. To
    collect such log output, create a SUB socket, subscribe to the traffic
    you care about, and connect to the endpoint. Log traffic is sent as a
    single string frame, in the same format as when sent to stdout. The
    log system supports a single sender; multiple calls to this method will
    bind the same sender to multiple endpoints. To disable the sender, call
    this method with a null argument.
    */
    native static void __setLogsender (String endpoint);
    public static void setLogsender (String endpoint) {
        __setLogsender (endpoint);
    }
    /*
    Enable or disable logging to the system facility (syslog on POSIX boxes,
    event log on Windows). By default this is disabled.
    */
    native static void __setLogsystem (boolean logsystem);
    public static void setLogsystem (boolean logsystem) {
        __setLogsystem (logsystem);
    }
    /*
    Log error condition - highest priority
    */
    native static void __error (String format);
    public static void error (String format) {
        __error (format);
    }
    /*
    Log warning condition - high priority
    */
    native static void __warning (String format);
    public static void warning (String format) {
        __warning (format);
    }
    /*
    Log normal, but significant, condition - normal priority
    */
    native static void __notice (String format);
    public static void notice (String format) {
        __notice (format);
    }
    /*
    Log informational message - low priority
    */
    native static void __info (String format);
    public static void info (String format) {
        __info (format);
    }
    /*
    Log debug-level message - lowest priority
    */
    native static void __debug (String format);
    public static void debug (String format) {
        __debug (format);
    }
    /*
    Self test of this class.
    */
    native static void __test (boolean verbose);
    public static void test (boolean verbose) {
        __test (verbose);
    }
}
