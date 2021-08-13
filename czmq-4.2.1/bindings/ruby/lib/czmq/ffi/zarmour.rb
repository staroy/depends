################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################

module CZMQ
  module FFI

    # armoured text encoding and decoding
    # @note This class is 100% generated using zproject.
    class Zarmour
      # Standard base 64
      MODE_BASE64_STD = 0

      # URL and filename friendly base 64
      MODE_BASE64_URL = 1

      # Standard base 32
      MODE_BASE32_STD = 2

      # Extended hex base 32
      MODE_BASE32_HEX = 3

      # Standard base 16
      MODE_BASE16 = 4

      # Z85 from ZeroMQ RFC 32
      MODE_Z85 = 5

      # Raised when one tries to use an instance of {Zarmour} after
      # the internal pointer to the native object has been nullified.
      class DestroyedError < RuntimeError; end

      # Boilerplate for self pointer, initializer, and finalizer
      class << self
        alias :__new :new
      end
      # Attaches the pointer _ptr_ to this instance and defines a finalizer for
      # it if necessary.
      # @param ptr [::FFI::Pointer]
      # @param finalize [Boolean]
      def initialize(ptr, finalize = true)
        @ptr = ptr
        if @ptr.null?
          @ptr = nil # Remove null pointers so we don't have to test for them.
        elsif finalize
          @finalizer = self.class.create_finalizer_for @ptr
          ObjectSpace.define_finalizer self, @finalizer
        end
      end
      # @param ptr [::FFI::Pointer]
      # @return [Proc]
      def self.create_finalizer_for(ptr)
        Proc.new do
          ptr_ptr = ::FFI::MemoryPointer.new :pointer
          ptr_ptr.write_pointer ptr
          ::CZMQ::FFI.zarmour_destroy ptr_ptr
        end
      end
      # @return [Boolean]
      def null?
        !@ptr or @ptr.null?
      end
      # Return internal pointer
      # @return [::FFI::Pointer]
      def __ptr
        raise DestroyedError unless @ptr
        @ptr
      end
      # So external Libraries can just pass the Object to a FFI function which expects a :pointer
      alias_method :to_ptr, :__ptr
      # Nullify internal pointer and return pointer pointer.
      # @note This detaches the current instance from the native object
      #   and thus makes it unusable.
      # @return [::FFI::MemoryPointer] the pointer pointing to a pointer
      #   pointing to the native object
      def __ptr_give_ref
        raise DestroyedError unless @ptr
        ptr_ptr = ::FFI::MemoryPointer.new :pointer
        ptr_ptr.write_pointer @ptr
        __undef_finalizer if @finalizer
        @ptr = nil
        ptr_ptr
      end
      # Undefines the finalizer for this object.
      # @note Only use this if you need to and can guarantee that the native
      #   object will be freed by other means.
      # @return [void]
      def __undef_finalizer
        ObjectSpace.undefine_finalizer self
        @finalizer = nil
      end

      # Create a new zarmour
      # @return [CZMQ::Zarmour]
      def self.new()
        ptr = ::CZMQ::FFI.zarmour_new()
        __new ptr
      end

      # Destroy the zarmour
      #
      # @return [void]
      def destroy()
        return unless @ptr
        self_p = __ptr_give_ref
        result = ::CZMQ::FFI.zarmour_destroy(self_p)
        result
      end

      # Encode a stream of bytes into an armoured string. Returns the armoured
      # string, or NULL if there was insufficient memory available to allocate
      # a new string.
      #
      # @param data [::FFI::Pointer, #to_ptr]
      # @param size [Integer, #to_int, #to_i]
      # @return [::FFI::AutoPointer]
      def encode(data, size)
        raise DestroyedError unless @ptr
        self_p = @ptr
        size = Integer(size)
        result = ::CZMQ::FFI.zarmour_encode(self_p, data, size)
        result = ::FFI::AutoPointer.new(result, LibC.method(:free))
        result
      end

      # Decode an armoured string into a chunk. The decoded output is
      # null-terminated, so it may be treated as a string, if that's what
      # it was prior to encoding.
      #
      # @param data [String, #to_s, nil]
      # @return [Zchunk]
      def decode(data)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_decode(self_p, data)
        result = Zchunk.__new result, true
        result
      end

      # Get the mode property.
      #
      # @return [Integer]
      def mode()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_mode(self_p)
        result
      end

      # Get printable string for mode.
      #
      # @return [String]
      def mode_str()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_mode_str(self_p)
        result
      end

      # Set the mode property.
      #
      # @param mode [Integer, #to_int, #to_i]
      # @return [void]
      def set_mode(mode)
        raise DestroyedError unless @ptr
        self_p = @ptr
        mode = Integer(mode)
        result = ::CZMQ::FFI.zarmour_set_mode(self_p, mode)
        result
      end

      # Return true if padding is turned on.
      #
      # @return [Boolean]
      def pad()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_pad(self_p)
        result
      end

      # Turn padding on or off. Default is on.
      #
      # @param pad [Boolean]
      # @return [void]
      def set_pad(pad)
        raise DestroyedError unless @ptr
        self_p = @ptr
        pad = !(0==pad||!pad) # boolean
        result = ::CZMQ::FFI.zarmour_set_pad(self_p, pad)
        result
      end

      # Get the padding character.
      #
      # @return [::FFI::Pointer]
      def pad_char()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_pad_char(self_p)
        result
      end

      # Set the padding character.
      #
      # @param pad_char [::FFI::Pointer, #to_ptr]
      # @return [void]
      def set_pad_char(pad_char)
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_set_pad_char(self_p, pad_char)
        result
      end

      # Return if splitting output into lines is turned on. Default is off.
      #
      # @return [Boolean]
      def line_breaks()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_line_breaks(self_p)
        result
      end

      # Turn splitting output into lines on or off.
      #
      # @param line_breaks [Boolean]
      # @return [void]
      def set_line_breaks(line_breaks)
        raise DestroyedError unless @ptr
        self_p = @ptr
        line_breaks = !(0==line_breaks||!line_breaks) # boolean
        result = ::CZMQ::FFI.zarmour_set_line_breaks(self_p, line_breaks)
        result
      end

      # Get the line length used for splitting lines.
      #
      # @return [Integer]
      def line_length()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_line_length(self_p)
        result
      end

      # Set the line length used for splitting lines.
      #
      # @param line_length [Integer, #to_int, #to_i]
      # @return [void]
      def set_line_length(line_length)
        raise DestroyedError unless @ptr
        self_p = @ptr
        line_length = Integer(line_length)
        result = ::CZMQ::FFI.zarmour_set_line_length(self_p, line_length)
        result
      end

      # Print properties of object
      #
      # @return [void]
      def print()
        raise DestroyedError unless @ptr
        self_p = @ptr
        result = ::CZMQ::FFI.zarmour_print(self_p)
        result
      end

      # Self test of this class.
      #
      # @param verbose [Boolean]
      # @return [void]
      def self.test(verbose)
        verbose = !(0==verbose||!verbose) # boolean
        result = ::CZMQ::FFI.zarmour_test(verbose)
        result
      end
    end
  end
end

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
