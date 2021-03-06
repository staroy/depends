################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
from . import utils
from . import destructors
libczmq_destructors = destructors.lib

class Zsys(object):
    """

    """

    @staticmethod
    def init():
        """
        Initialize CZMQ zsys layer; this happens automatically when you create
        a socket or an actor; however this call lets you force initialization
        earlier, so e.g. logging is properly set-up before you start working.
        Not threadsafe, so call only from main thread. Safe to call multiple
        times. Returns global CZMQ context.
        """
        return utils.lib.zsys_init()

    @staticmethod
    def shutdown():
        """
        Optionally shut down the CZMQ zsys layer; this normally happens automatically
        when the process exits; however this call lets you force a shutdown
        earlier, avoiding any potential problems with atexit() ordering, especially
        with Windows dlls.
        """
        utils.lib.zsys_shutdown()

    @staticmethod
    def socket(type, filename, line_nbr):
        """
        Get a new ZMQ socket, automagically creating a ZMQ context if this is
        the first time. Caller is responsible for destroying the ZMQ socket
        before process exits, to avoid a ZMQ deadlock. Note: you should not use
        this method in CZMQ apps, use zsock_new() instead.
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_socket(type, utils.to_bytes(filename), line_nbr)

    @staticmethod
    def close(handle, filename, line_nbr):
        """
        Destroy/close a ZMQ socket. You should call this for every socket you
        create using zsys_socket().
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_close(handle._p, utils.to_bytes(filename), line_nbr)

    @staticmethod
    def sockname(socktype):
        """
        Return ZMQ socket name for socket type
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_sockname(socktype)

    @staticmethod
    def create_pipe(backend_p):
        """
        Create a pipe, which consists of two PAIR sockets connected over inproc.
        The pipe is configured to use the zsys_pipehwm setting. Returns the
        frontend socket successful, NULL if failed.
        """
        return utils.lib.zsys_create_pipe(utils.ffi.new("zsock_t **", backend_p._p))

    @staticmethod
    def handler_set(handler_fn):
        """
        Set interrupt handler; this saves the default handlers so that a
        zsys_handler_reset () can restore them. If you call this multiple times
        then the last handler will take affect. If handler_fn is NULL, disables
        default SIGINT/SIGTERM handling in CZMQ.
        """
        utils.lib.zsys_handler_set(handler_fn)

    @staticmethod
    def handler_reset():
        """
        Reset interrupt handler, call this at exit if needed
        """
        utils.lib.zsys_handler_reset()

    @staticmethod
    def catch_interrupts():
        """
        Set default interrupt handler, so Ctrl-C or SIGTERM will set
        zsys_interrupted. Idempotent; safe to call multiple times.
        Can be suppressed by ZSYS_SIGHANDLER=false
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        utils.lib.zsys_catch_interrupts()

    @staticmethod
    def is_interrupted():
        """
        Check if default interrupt handler of Ctrl-C or SIGTERM was called.
        Does not work if ZSYS_SIGHANDLER is false and code does not call
        set interrupted on signal.
        """
        return utils.lib.zsys_is_interrupted()

    @staticmethod
    def set_interrupted():
        """
        Set interrupted flag. This is done by default signal handler, however
        this can be handy for language bindings or cases without default
        signal handler.
        """
        utils.lib.zsys_set_interrupted()

    @staticmethod
    def file_exists(filename):
        """
        Return 1 if file exists, else zero
        """
        return utils.lib.zsys_file_exists(utils.to_bytes(filename))

    @staticmethod
    def file_modified(filename):
        """
        Return file modification time. Returns 0 if the file does not exist.
        """
        return utils.lib.zsys_file_modified(utils.to_bytes(filename))

    @staticmethod
    def file_mode(filename):
        """
        Return file mode; provides at least support for the POSIX S_ISREG(m)
        and S_ISDIR(m) macros and the S_IRUSR and S_IWUSR bits, on all boxes.
        Returns a mode_t cast to int, or -1 in case of error.
        """
        return utils.lib.zsys_file_mode(utils.to_bytes(filename))

    @staticmethod
    def file_delete(filename):
        """
        Delete file. Does not complain if the file is absent
        """
        return utils.lib.zsys_file_delete(utils.to_bytes(filename))

    @staticmethod
    def file_stable(filename):
        """
        Check if file is 'stable'
        """
        return utils.lib.zsys_file_stable(utils.to_bytes(filename))

    @staticmethod
    def dir_create(pathname, *pathname_args):
        """
        Create a file path if it doesn't exist. The file path is treated as
        printf format.
        """
        return utils.lib.zsys_dir_create(utils.to_bytes(pathname), *pathname_args)

    @staticmethod
    def dir_delete(pathname, *pathname_args):
        """
        Remove a file path if empty; the pathname is treated as printf format.
        """
        return utils.lib.zsys_dir_delete(utils.to_bytes(pathname), *pathname_args)

    @staticmethod
    def dir_change(pathname):
        """
        Move to a specified working directory. Returns 0 if OK, -1 if this failed.
        """
        return utils.lib.zsys_dir_change(utils.to_bytes(pathname))

    @staticmethod
    def file_mode_private():
        """
        Set private file creation mode; all files created from here will be
        readable/writable by the owner only.
        """
        utils.lib.zsys_file_mode_private()

    @staticmethod
    def file_mode_default():
        """
        Reset default file creation mode; all files created from here will use
        process file mode defaults.
        """
        utils.lib.zsys_file_mode_default()

    @staticmethod
    def version(major, minor, patch):
        """
        Return the CZMQ version for run-time API detection; returns version
        number into provided fields, providing reference isn't null in each case.
        """
        utils.lib.zsys_version(major, minor, patch)

    @staticmethod
    def sprintf_hint(hint, format, *format_args):
        """
        Format a string using printf formatting, returning a freshly allocated
        buffer. If there was insufficient memory, returns NULL. Free the returned
        string using zstr_free(). The hinted version allows to optimize by using
        a larger starting buffer size (known to/assumed by the developer) and so
        avoid reallocations.
        """
        return utils.lib.zsys_sprintf_hint(hint, utils.to_bytes(format), *format_args)

    @staticmethod
    def sprintf(format, *format_args):
        """
        Format a string using printf formatting, returning a freshly allocated
        buffer. If there was insufficient memory, returns NULL. Free the returned
        string using zstr_free().
        """
        return utils.lib.zsys_sprintf(utils.to_bytes(format), *format_args)

    @staticmethod
    def vprintf(format, argptr):
        """
        Format a string with a va_list argument, returning a freshly allocated
        buffer. If there was insufficient memory, returns NULL. Free the returned
        string using zstr_free().
        """
        return utils.lib.zsys_vprintf(utils.to_bytes(format), argptr._p)

    @staticmethod
    def udp_new(routable):
        """
        Create UDP beacon socket; if the routable option is true, uses
        multicast (not yet implemented), else uses broadcast. This method
        and related ones might _eventually_ be moved to a zudp class.
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_udp_new(routable)

    @staticmethod
    def udp_close(handle):
        """
        Close a UDP socket
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_udp_close(handle._p)

    @staticmethod
    def udp_send(udpsock, frame, address, addrlen):
        """
        Send zframe to UDP socket, return -1 if sending failed due to
        interface having disappeared (happens easily with WiFi)
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_udp_send(udpsock._p, frame._p, address._p, addrlen)

    @staticmethod
    def udp_recv(udpsock, peername, peerlen):
        """
        Receive zframe from UDP socket, and set address of peer that sent it
        The peername must be a char [INET_ADDRSTRLEN] array if IPv6 is disabled or
        NI_MAXHOST if it's enabled. Returns NULL when failing to get peer address.
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        return utils.lib.zsys_udp_recv(udpsock._p, utils.to_bytes(peername), peerlen)

    @staticmethod
    def socket_error(reason):
        """
        Handle an I/O error on some socket operation; will report and die on
        fatal errors, and continue silently on "try again" errors.
        *** This is for CZMQ internal use only and may change arbitrarily ***
        """
        utils.lib.zsys_socket_error(utils.to_bytes(reason))

    @staticmethod
    def hostname():
        """
        Return current host name, for use in public tcp:// endpoints. Caller gets
        a freshly allocated string, should free it using zstr_free(). If the host
        name is not resolvable, returns NULL.
        """
        return utils.lib.zsys_hostname()

    @staticmethod
    def daemonize(workdir):
        """
        Move the current process into the background. The precise effect depends
        on the operating system. On POSIX boxes, moves to a specified working
        directory (if specified), closes all file handles, reopens stdin, stdout,
        and stderr to the null device, and sets the process to ignore SIGHUP. On
        Windows, does nothing. Returns 0 if OK, -1 if there was an error.
        """
        return utils.lib.zsys_daemonize(utils.to_bytes(workdir))

    @staticmethod
    def run_as(lockfile, group, user):
        """
        Drop the process ID into the lockfile, with exclusive lock, and switch
        the process to the specified group and/or user. Any of the arguments
        may be null, indicating a no-op. Returns 0 on success, -1 on failure.
        Note if you combine this with zsys_daemonize, run after, not before
        that method, or the lockfile will hold the wrong process ID.
        """
        return utils.lib.zsys_run_as(utils.to_bytes(lockfile), utils.to_bytes(group), utils.to_bytes(user))

    @staticmethod
    def has_curve():
        """
        Returns true if the underlying libzmq supports CURVE security.
        Uses a heuristic probe according to the version of libzmq being used.
        """
        return utils.lib.zsys_has_curve()

    @staticmethod
    def set_io_threads(io_threads):
        """
        Configure the number of I/O threads that ZeroMQ will use. A good
        rule of thumb is one thread per gigabit of traffic in or out. The
        default is 1, sufficient for most applications. If the environment
        variable ZSYS_IO_THREADS is defined, that provides the default.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_set_io_threads(io_threads)

    @staticmethod
    def set_thread_sched_policy(policy):
        """
        Configure the scheduling policy of the ZMQ context thread pool.
        Not available on Windows. See the sched_setscheduler man page or sched.h
        for more information. If the environment variable ZSYS_THREAD_SCHED_POLICY
        is defined, that provides the default.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_set_thread_sched_policy(policy)

    @staticmethod
    def set_thread_priority(priority):
        """
        Configure the scheduling priority of the ZMQ context thread pool.
        Not available on Windows. See the sched_setscheduler man page or sched.h
        for more information. If the environment variable ZSYS_THREAD_PRIORITY is
        defined, that provides the default.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_set_thread_priority(priority)

    @staticmethod
    def set_thread_name_prefix(prefix):
        """
        Configure the numeric prefix to each thread created for the internal
        context's thread pool. This option is only supported on Linux.
        If the environment variable ZSYS_THREAD_NAME_PREFIX is defined, that
        provides the default.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_set_thread_name_prefix(prefix)

    @staticmethod
    def thread_name_prefix():
        """
        Return thread name prefix.
        """
        return utils.lib.zsys_thread_name_prefix()

    @staticmethod
    def set_thread_name_prefix_str(prefix):
        """
        Configure the numeric prefix to each thread created for the internal
        context's thread pool. This option is only supported on Linux.
        If the environment variable ZSYS_THREAD_NAME_PREFIX_STR is defined, that
        provides the default.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_set_thread_name_prefix_str(utils.to_bytes(prefix))

    @staticmethod
    def thread_name_prefix_str():
        """
        Return thread name prefix.
        """
        return utils.lib.zsys_thread_name_prefix_str()

    @staticmethod
    def thread_affinity_cpu_add(cpu):
        """
        Adds a specific CPU to the affinity list of the ZMQ context thread pool.
        This option is only supported on Linux.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_thread_affinity_cpu_add(cpu)

    @staticmethod
    def thread_affinity_cpu_remove(cpu):
        """
        Removes a specific CPU to the affinity list of the ZMQ context thread pool.
        This option is only supported on Linux.
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_thread_affinity_cpu_remove(cpu)

    @staticmethod
    def set_max_sockets(max_sockets):
        """
        Configure the number of sockets that ZeroMQ will allow. The default
        is 1024. The actual limit depends on the system, and you can query it
        by using zsys_socket_limit (). A value of zero means "maximum".
        Note that this method is valid only before any socket is created.
        """
        utils.lib.zsys_set_max_sockets(max_sockets)

    @staticmethod
    def socket_limit():
        """
        Return maximum number of ZeroMQ sockets that the system will support.
        """
        return utils.lib.zsys_socket_limit()

    @staticmethod
    def set_max_msgsz(max_msgsz):
        """
        Configure the maximum allowed size of a message sent.
        The default is INT_MAX.
        """
        utils.lib.zsys_set_max_msgsz(max_msgsz)

    @staticmethod
    def max_msgsz():
        """
        Return maximum message size.
        """
        return utils.lib.zsys_max_msgsz()

    @staticmethod
    def set_zero_copy_recv(zero_copy):
        """
        Configure whether to use zero copy strategy in libzmq. If the environment
        variable ZSYS_ZERO_COPY_RECV is defined, that provides the default.
        Otherwise the default is 1.
        """
        utils.lib.zsys_set_zero_copy_recv(zero_copy)

    @staticmethod
    def zero_copy_recv():
        """
        Return ZMQ_ZERO_COPY_RECV option.
        """
        return utils.lib.zsys_zero_copy_recv()

    @staticmethod
    def set_file_stable_age_msec(file_stable_age_msec):
        """
        Configure the threshold value of filesystem object age per st_mtime
        that should elapse until we consider that object "stable" at the
        current zclock_time() moment.
        The default is S_DEFAULT_ZSYS_FILE_STABLE_AGE_MSEC defined in zsys.c
        which generally depends on host OS, with fallback value of 5000.
        """
        utils.lib.zsys_set_file_stable_age_msec(file_stable_age_msec._p)

    @staticmethod
    def file_stable_age_msec():
        """
        Return current threshold value of file stable age in msec.
        This can be used in code that chooses to wait for this timeout
        before testing if a filesystem object is "stable" or not.
        """
        return utils.lib.zsys_file_stable_age_msec()

    @staticmethod
    def set_linger(linger):
        """
        Configure the default linger timeout in msecs for new zsock instances.
        You can also set this separately on each zsock_t instance. The default
        linger time is zero, i.e. any pending messages will be dropped. If the
        environment variable ZSYS_LINGER is defined, that provides the default.
        Note that process exit will typically be delayed by the linger time.
        """
        utils.lib.zsys_set_linger(linger)

    @staticmethod
    def set_sndhwm(sndhwm):
        """
        Configure the default outgoing pipe limit (HWM) for new zsock instances.
        You can also set this separately on each zsock_t instance. The default
        HWM is 1,000, on all versions of ZeroMQ. If the environment variable
        ZSYS_SNDHWM is defined, that provides the default. Note that a value of
        zero means no limit, i.e. infinite memory consumption.
        """
        utils.lib.zsys_set_sndhwm(sndhwm)

    @staticmethod
    def set_rcvhwm(rcvhwm):
        """
        Configure the default incoming pipe limit (HWM) for new zsock instances.
        You can also set this separately on each zsock_t instance. The default
        HWM is 1,000, on all versions of ZeroMQ. If the environment variable
        ZSYS_RCVHWM is defined, that provides the default. Note that a value of
        zero means no limit, i.e. infinite memory consumption.
        """
        utils.lib.zsys_set_rcvhwm(rcvhwm)

    @staticmethod
    def set_pipehwm(pipehwm):
        """
        Configure the default HWM for zactor internal pipes; this is set on both
        ends of the pipe, for outgoing messages only (sndhwm). The default HWM is
        1,000, on all versions of ZeroMQ. If the environment var ZSYS_ACTORHWM is
        defined, that provides the default. Note that a value of zero means no
        limit, i.e. infinite memory consumption.
        """
        utils.lib.zsys_set_pipehwm(pipehwm)

    @staticmethod
    def pipehwm():
        """
        Return the HWM for zactor internal pipes.
        """
        return utils.lib.zsys_pipehwm()

    @staticmethod
    def set_ipv6(ipv6):
        """
        Configure use of IPv6 for new zsock instances. By default sockets accept
        and make only IPv4 connections. When you enable IPv6, sockets will accept
        and connect to both IPv4 and IPv6 peers. You can override the setting on
        each zsock_t instance. The default is IPv4 only (ipv6 set to 0). If the
        environment variable ZSYS_IPV6 is defined (as 1 or 0), this provides the
        default. Note: has no effect on ZMQ v2.
        """
        utils.lib.zsys_set_ipv6(ipv6)

    @staticmethod
    def ipv6():
        """
        Return use of IPv6 for zsock instances.
        """
        return utils.lib.zsys_ipv6()

    @staticmethod
    def ipv6_available():
        """
        Test if ipv6 is available on the system. Return true if available.
        The only way to reliably check is to actually open a socket and
        try to bind it. (ported from libzmq)
        """
        return utils.lib.zsys_ipv6_available()

    @staticmethod
    def set_interface(value):
        """
        Set network interface name to use for broadcasts, particularly zbeacon.
        This lets the interface be configured for test environments where required.
        For example, on Mac OS X, zbeacon cannot bind to 255.255.255.255 which is
        the default when there is no specified interface. If the environment
        variable ZSYS_INTERFACE is set, use that as the default interface name.
        Setting the interface to "*" means "use all available interfaces".
        """
        utils.lib.zsys_set_interface(utils.to_bytes(value))

    @staticmethod
    def interface():
        """
        Return network interface to use for broadcasts, or "" if none was set.
        """
        return utils.lib.zsys_interface()

    @staticmethod
    def set_ipv6_address(value):
        """
        Set IPv6 address to use zbeacon socket, particularly for receiving zbeacon.
        This needs to be set IPv6 is enabled as IPv6 can have multiple addresses
        on a given interface. If the environment variable ZSYS_IPV6_ADDRESS is set,
        use that as the default IPv6 address.
        """
        utils.lib.zsys_set_ipv6_address(utils.to_bytes(value))

    @staticmethod
    def ipv6_address():
        """
        Return IPv6 address to use for zbeacon reception, or "" if none was set.
        """
        return utils.lib.zsys_ipv6_address()

    @staticmethod
    def set_ipv6_mcast_address(value):
        """
        Set IPv6 milticast address to use for sending zbeacon messages. This needs
        to be set if IPv6 is enabled. If the environment variable
        ZSYS_IPV6_MCAST_ADDRESS is set, use that as the default IPv6 multicast
        address.
        """
        utils.lib.zsys_set_ipv6_mcast_address(utils.to_bytes(value))

    @staticmethod
    def ipv6_mcast_address():
        """
        Return IPv6 multicast address to use for sending zbeacon, or "" if none was
        set.
        """
        return utils.lib.zsys_ipv6_mcast_address()

    @staticmethod
    def set_ipv4_mcast_address(value):
        """
        Set IPv4 multicast address to use for sending zbeacon messages. By default
        IPv4 multicast is NOT used. If the environment variable
        ZSYS_IPV4_MCAST_ADDRESS is set, use that as the default IPv4 multicast
        address. Calling this function or setting ZSYS_IPV4_MCAST_ADDRESS
        will enable IPv4 zbeacon messages.
        """
        utils.lib.zsys_set_ipv4_mcast_address(utils.to_bytes(value))

    @staticmethod
    def ipv4_mcast_address():
        """
        Return IPv4 multicast address to use for sending zbeacon, or NULL if none was
        set.
        """
        return utils.lib.zsys_ipv4_mcast_address()

    @staticmethod
    def set_mcast_ttl(value):
        """
        Set multicast TTL default is 1
        """
        utils.lib.zsys_set_mcast_ttl(value)

    @staticmethod
    def mcast_ttl():
        """
        Get multicast TTL
        """
        return utils.lib.zsys_mcast_ttl()

    @staticmethod
    def set_auto_use_fd(auto_use_fd):
        """
        Configure the automatic use of pre-allocated FDs when creating new sockets.
        If 0 (default), nothing will happen. Else, when a new socket is bound, the
        system API will be used to check if an existing pre-allocated FD with a
        matching port (if TCP) or path (if IPC) exists, and if it does it will be
        set via the ZMQ_USE_FD socket option so that the library will use it
        instead of creating a new socket.
        """
        utils.lib.zsys_set_auto_use_fd(auto_use_fd)

    @staticmethod
    def auto_use_fd():
        """
        Return use of automatic pre-allocated FDs for zsock instances.
        """
        return utils.lib.zsys_auto_use_fd()

    @staticmethod
    def zprintf(format, args):
        """
        Print formatted string. Format is specified by variable names
        in Python-like format style

        "%(KEY)s=%(VALUE)s", KEY=key, VALUE=value
        become
        "key=value"

        Returns freshly allocated string or NULL in a case of error.
        Not enough memory, invalid format specifier, name not in args
        """
        return utils.lib.zsys_zprintf(utils.to_bytes(format), args._p)

    @staticmethod
    def zprintf_error(format, args):
        """
        Return error string for given format/args combination.
        """
        return utils.lib.zsys_zprintf_error(utils.to_bytes(format), args._p)

    @staticmethod
    def zplprintf(format, args):
        """
        Print formatted string. Format is specified by variable names
        in Python-like format style

        "%(KEY)s=%(VALUE)s", KEY=key, VALUE=value
        become
        "key=value"

        Returns freshly allocated string or NULL in a case of error.
        Not enough memory, invalid format specifier, name not in args
        """
        return utils.lib.zsys_zplprintf(utils.to_bytes(format), args._p)

    @staticmethod
    def zplprintf_error(format, args):
        """
        Return error string for given format/args combination.
        """
        return utils.lib.zsys_zplprintf_error(utils.to_bytes(format), args._p)

    @staticmethod
    def set_logident(value):
        """
        Set log identity, which is a string that prefixes all log messages sent
        by this process. The log identity defaults to the environment variable
        ZSYS_LOGIDENT, if that is set.
        """
        utils.lib.zsys_set_logident(utils.to_bytes(value))

    @staticmethod
    def set_logstream(stream):
        """
        Set stream to receive log traffic. By default, log traffic is sent to
        stdout. If you set the stream to NULL, no stream will receive the log
        traffic (it may still be sent to the system facility).
        """
        utils.lib.zsys_set_logstream(stream)

    @staticmethod
    def set_logsender(endpoint):
        """
        Sends log output to a PUB socket bound to the specified endpoint. To
        collect such log output, create a SUB socket, subscribe to the traffic
        you care about, and connect to the endpoint. Log traffic is sent as a
        single string frame, in the same format as when sent to stdout. The
        log system supports a single sender; multiple calls to this method will
        bind the same sender to multiple endpoints. To disable the sender, call
        this method with a null argument.
        """
        utils.lib.zsys_set_logsender(utils.to_bytes(endpoint))

    @staticmethod
    def set_logsystem(logsystem):
        """
        Enable or disable logging to the system facility (syslog on POSIX boxes,
        event log on Windows). By default this is disabled.
        """
        utils.lib.zsys_set_logsystem(logsystem)

    @staticmethod
    def error(format, *format_args):
        """
        Log error condition - highest priority
        """
        utils.lib.zsys_error(utils.to_bytes(format), *format_args)

    @staticmethod
    def warning(format, *format_args):
        """
        Log warning condition - high priority
        """
        utils.lib.zsys_warning(utils.to_bytes(format), *format_args)

    @staticmethod
    def notice(format, *format_args):
        """
        Log normal, but significant, condition - normal priority
        """
        utils.lib.zsys_notice(utils.to_bytes(format), *format_args)

    @staticmethod
    def info(format, *format_args):
        """
        Log informational message - low priority
        """
        utils.lib.zsys_info(utils.to_bytes(format), *format_args)

    @staticmethod
    def debug(format, *format_args):
        """
        Log debug-level message - lowest priority
        """
        utils.lib.zsys_debug(utils.to_bytes(format), *format_args)

    @staticmethod
    def test(verbose):
        """
        Self test of this class.
        """
        utils.lib.zsys_test(verbose)

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
